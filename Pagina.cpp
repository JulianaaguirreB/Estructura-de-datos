#include "Pagina.h"
using namespace std;

Pagina::Pagina(){
  this->numero=0;
}

Pagina::Pagina(int numero){
this->numero=numero;
}

int Pagina::getNumero() const {
    return numero;
}

void Pagina::setNumero(int numero) {
   this->numero=numero;
}
