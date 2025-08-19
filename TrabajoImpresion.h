#ifndef TRABAJOIMPRESION_H
#define TRABAJOIMPRESION_H

#include <string>
#include <stack>
#include "Pagina.h"
using namespace std;

class TrabajoImpresion
{
    private:
    string documento;
    string usuario;
    stack<Pagina> paginas;

    public:
    TrabajoImpresion();
    TrabajoImpresion( string documento, string usuario, int cantidadPaginas);

    const string& getDocumento()const;
    void setDocumento(const string &documento);
   const string& getUsuario()const;
    void setUsuario(const string& usuario);
   const stack<Pagina>& getPaginas()const;
    void setPaginas(const stack<Pagina>& paginas);

   Pagina retirarPagina();
   int paginasPendientes()const;
   bool terminado()const;


};

#endif // TRABAJOIMPRESION_H
