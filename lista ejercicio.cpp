#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    list<string> elementos;
    string input;
    int numInserciones, posicion;
    
    cout << "Cuantos elementos iniciales desea agregar a la lista? ";
    cin >> numInserciones;
    cin.ignore();

    for (int i = 0; i < numInserciones; ++i) {
        cout << "Ingrese el elemento #" << (i + 1) << " (puede ser un numero o una letra): ";
        getline(cin, input);
        elementos.push_back(input);
    }

    cout << "\nLista inicial: ";
    for (const string& item : elementos) {
        cout << item << " ";
    }
    cout << endl;

    list<string>::iterator it = elementos.begin();

    cout << "\nDesea insertar mas elementos? (0 = no, 1 = si): ";
    int respuesta;
    cin >> respuesta;
    cin.ignore();
    if (respuesta == 1) {
        while (true) {
            cout << "Ingrese el elemento a insertar (puede ser un numero o una letra): ";
            getline(cin, input);
            
            cout << "Ingrese la posicion donde desea insertar (comenzando desde 0): ";
            cin >> posicion;
            cin.ignore();

            if (posicion < 0 || posicion > elementos.size()) {
                cout << "Posicion invalida. Intente de nuevo." << endl;
                continue;
            }

            it = elementos.begin();
            advance(it, posicion);
            it = elementos.insert(it, input);

            cout << "\nLista después de insertar el elemento '" << input << "' en la posición " << posicion << ": ";
            for (const string& item : elementos) {
                cout << item << " ";
            }
            cout << endl;

            cout << "Iterador apunta al valor: " << *it << endl;

            cout << "\nDesea insertar otro elemento? (0 = no, 1 = si): ";
            cin >> respuesta;
            cin.ignore();
            if (respuesta == 0) {
                break;
            }
        }
    }

    return 0;
}

