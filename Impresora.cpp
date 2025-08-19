#include "Impresora.h"
using namespace std;

// ==== Constructores ====
Impresora::Impresora()
{
  this->nombre="";
  this->activa=true;
}

Impresora::Impresora(string nombre, bool activa)
{
this->nombre=nombre;
  this->activa=activa;
}

// ==== Getters / setters ====
const string& Impresora::getNombre() const { return nombre; }
void Impresora::setNombre(const string& nombre) { this->nombre = nombre; }

bool Impresora::getActiva() const { return activa; }
void Impresora::setActiva(bool activa) { this->activa = activa; }

const queue<TrabajoImpresion>& Impresora::getCola() const { return cola; }
void Impresora::setCola(const queue<TrabajoImpresion>& cola) { this->cola = cola; }

//bool Impresora::tieneActual() const { return !actual.empty(); }
const queue<TrabajoImpresion>& Impresora::getActual() const { return actual; }
void Impresora::setActual(const queue<TrabajoImpresion>& actual) { this->actual = actual; }

// ==== Comportamiento ====
bool Impresora::disponible() const {

if(activa && actual.empty()) return true;
else return false;

}

int Impresora::tamCola() const {
    queue<TrabajoImpresion> copia = cola;
    int cont = 0;
    while (!copia.empty()) {
        copia.pop();
        cont++;
    }
    return cont;
}

void Impresora::encolar(const TrabajoImpresion& t) {
    cola.push(t);
}

void Impresora::despachar() {
    if (activa && actual.empty() && !cola.empty()) {
        actual.push(cola.front());
        cola.pop();
    }
}

bool Impresora::imprimirPaso() {
    if (!activa) return false;

    if (actual.empty()) {
        despachar();
        if (actual.empty()) return false;
    }

    TrabajoImpresion& t = actual.front();
    t.retirarPagina();

    if (t.terminado()) {
        actual.pop();
        despachar();
    }
    return true;
}

bool Impresora::colaVacia() const {
    return cola.empty();
}

void Impresora::activar() { activa = true; }
void Impresora::desactivar() { activa = false; }
