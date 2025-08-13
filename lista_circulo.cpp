/* Si tenemos una lista de clase circulo (list<circulo>) cuyos atributos son float x e y
correspondientes a las coordenadas del centro y otro float correspondiente al radio.
Implemente la clase circulo con operaciones área, circunferencia, además implemente
una función que reciba una lista de círculos y multiplique por 3 el radio de cada elemento
de la lista. Pruebe con iterador forward y con for each.*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Circulo {
public:
    float x, y, radio;
    Circulo(float x_, float y_, float radio_) : x(x_), y(y_), radio(radio_) {}
    float area() const {
        return 3.1415 * radio * radio;
    }
    float circunferencia() const {
        return 2 * 3.1415 * radio;
    }
    void multiplicarRadioPor3() {
        radio *= 3;
    }
    void imprimir() const {
        cout << "Circulo en (" << x << ", " << y << ") con radio " << radio << " - "
             << "Area: " << area() << ", Circunferencia: " << circunferencia() << endl;
    }
};
void multiplicarRadioIterador(list<Circulo>& circulos) {
    for (auto it = circulos.begin(); it != circulos.end(); ++it) {
        it->multiplicarRadioPor3();
    }
}
void multiplicarRadioForEach(list<Circulo>& circulos) {
    for_each(circulos.begin(), circulos.end(), [](Circulo& c) {
        c.multiplicarRadioPor3();
    });
}

int main() {
    list<Circulo> circulos;
    circulos.push_back(Circulo(0, 0, 5));
    circulos.push_back(Circulo(2, 3, 10));
    circulos.push_back(Circulo(-1, -1, 2));
    cout << "Antes de multiplicar el radio por 3:" << endl;
    for (const Circulo& c : circulos) {
        c.imprimir();
    }
    multiplicarRadioIterador(circulos);
    cout << "\nDespues de multiplicar el radio por 3 usando iterador:" << endl;
    for (const Circulo& c : circulos) {
        c.imprimir();
    }
    circulos.clear();
    circulos.push_back(Circulo(0, 0, 5));
    circulos.push_back(Circulo(2, 3, 10));
    circulos.push_back(Circulo(-1, -1, 2));
    
    multiplicarRadioForEach(circulos);
    cout << "\nDespues de multiplicar el radio por 3 usando for_each:" << endl;
    for (const Circulo& c : circulos) {
        c.imprimir();
    }

    return 0;
}

