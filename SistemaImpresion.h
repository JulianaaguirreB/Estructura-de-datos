#ifndef SISTEMAIMPRESION_H
#define SISTEMAIMPRESION_H

#include <list>
#include <string>
#include "Impresora.h"
using namespace std;

class SistemaImpresion
{
   private:
       list<Impresora> impresoras;

   public:
    SistemaImpresion();
    SistemaImpresion(const list<Impresora>& impresoras);


    const list<Impresora>& getImpresoras() const;
    void setImpresoras(const list<Impresora>& impresoras);


    void crear();
    void agregarImpresora( const Impresora& imp);
    bool eliminarImpresora( const string& nombre);

    void agregarTrabajo( const string documento, const string usuario,int cantidadPaginas);
    void visualizarEstado()const;
    void tick();
};

#endif // SISTEMAIMPRESION_H
