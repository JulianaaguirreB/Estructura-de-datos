#include "TrabajoImpresion.h"
using namespace std;

TrabajoImpresion::TrabajoImpresion(){}

TrabajoImpresion::TrabajoImpresion(string documento, string usuario, int cantidadPaginas){
    this->documento=documento;
    this->usuario=usuario;
    for (int i = 1; i <= cantidadPaginas; i++) {
        paginas.push(Pagina(i));
    }
}


const string& TrabajoImpresion::getDocumento() const {
    return documento;
}

void TrabajoImpresion::setDocumento(const string& documento) {
    this->documento = documento;
}

const string& TrabajoImpresion::getUsuario() const {
    return usuario;
}

void TrabajoImpresion::setUsuario(const string& usuario) {
    this->usuario = usuario;
}

const stack<Pagina>& TrabajoImpresion::getPaginas() const {
    return paginas;
}

void TrabajoImpresion::setPaginas(const stack<Pagina>& paginas) {
    this->paginas = paginas;
}

Pagina TrabajoImpresion::retirarPagina() {
    if (paginas.empty()) {
        return Pagina(-1);
    }
    Pagina top = paginas.top();
    paginas.pop();
    return top;
}

int TrabajoImpresion::paginasPendientes() const {
    return paginas.size();
}

bool TrabajoImpresion::terminado() const {
    return paginas.empty();
}
