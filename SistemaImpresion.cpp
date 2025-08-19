#include "SistemaImpresion.h"
#include <sstream>
#include <iostream>
using namespace std;

// ==== Constructores ====
SistemaImpresion::SistemaImpresion() {}

SistemaImpresion::SistemaImpresion(const list<Impresora>& impresoras)
{
    this->impresoras = impresoras;
}

// ==== Getters / setters ====
const list<Impresora>& SistemaImpresion::getImpresoras() const
{
    return impresoras;
}

void SistemaImpresion::setImpresoras(const list<Impresora>& impresoras)
{
    this->impresoras = impresoras;
}

// ==== Comportamiento ====
void SistemaImpresion::crear()
{
    impresoras.clear();
}

void SistemaImpresion::agregarImpresora(const Impresora& imp)
{
    impresoras.push_back(imp);
}

bool SistemaImpresion::eliminarImpresora(const string& nombre)
{

    list<Impresora>::iterator it;
    for (it = impresoras.begin(); it != impresoras.end(); ++it)
    {
        if (it->getNombre() == nombre)
        {
            if (!it->colaVacia() || !it->getActual().empty())
            {
                return false;
            }
            impresoras.erase(it);
            return true;
        }
    }
    return false;
}

void SistemaImpresion::agregarTrabajo(const string documento,const string usuario,int cantidadPaginas)
{
    if (impresoras.empty()) return;

    list<Impresora>::iterator mejor = impresoras.begin();
    int minCola=-1;

    list<Impresora>::iterator it;
    for ( it= impresoras.begin(); it != impresoras.end(); ++it)
    {
        if (it->getActiva())
        {
            int t = it->tamCola() + (!it->getActual().empty() ? 1 : 0);
            if (minCola == -1 || t < minCola) {
                minCola = t;
                mejor = it;
            }
        }
    }

    if (mejor == impresoras.end()) return;

    TrabajoImpresion trabajo(documento, usuario, cantidadPaginas);
    mejor->encolar(trabajo);
    mejor->despachar();
}

void SistemaImpresion::visualizarEstado() const
{

    cout << "=== Estado del Sistema de Impresion ===\n";
    list<Impresora>::const_iterator it;
    for (it = impresoras.begin(); it != impresoras.end(); ++it)
    {


        int espera = it->tamCola();
        int enCurso = it->getActual().empty() ? 0 : 1;
        int total = espera + enCurso;

        cout << "- " << it->getNombre()
             << " | activa: " << (it->getActiva() ? "si" : "no")
             << " | cola (espera): " << espera
             << " | total (incl. en curso): " << total;



        if (!it->getActual().empty())
        {
            const queue<TrabajoImpresion>& q = it->getActual();
            const TrabajoImpresion& t = q.front();
            cout << " | imprimiendo: " << t.getDocumento()
                 << " (pendientes: " << t.paginasPendientes() << ")";
        }
        cout << "\n";
    }
}

void SistemaImpresion::tick()
{
    list<Impresora>::iterator it;
    for (it = impresoras.begin(); it != impresoras.end(); ++it)
    {
        it->imprimirPaso();
    }
}
