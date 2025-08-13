/*Implemente la función colarElemento que coloca un elemento dado en una posición
determinada de la cola */

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void colarElemento(queue<char>& cola, char elemento, int posicion) {
    queue<char> colaTemporal;
    int contador = 0;
    while (!cola.empty() && contador < posicion) {
        colaTemporal.push(cola.front());
        cola.pop();
        contador++;
    }
    colaTemporal.push(elemento);
    while (!cola.empty()) {
        colaTemporal.push(cola.front());
        cola.pop();
    }
    while (!colaTemporal.empty()) {
        cola.push(colaTemporal.front());
        colaTemporal.pop();
    }
}
int main() {
    queue<char> cola;
    string palabra;
    char nuevoElemento;
    int posicion;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    for (char c : palabra) {
        cola.push(c);
    }
    cout << "Ingrese el carácter a agregar: ";
    cin >> nuevoElemento;
    cout << "Ingrese la posición en la que desea agregar el carácter: ";
    cin >> posicion;
    colarElemento(cola, nuevoElemento, posicion);
    cout << "Palabra modificada: ";
    while (!cola.empty()) {
        cout << cola.front();
        cola.pop();
    }
    cout << endl;

    return 0;
}


