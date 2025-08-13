/*Utilice una pila para validar si una expresión aritmética dada como parámetro de tipo
string ,en la que cada operador y operando corresponden a un carácter, tiene
balanceados los paréntesis. Ejemplo la expresión string expresion = "((a+b)*c)" tiene
balanceados los paréntesis. (Cada vez que encuentra un paréntesis abriendo se
almacena en la pila, cada vez que encuentra uno cerrando saca de la pila el
elemento que está en el tope. ¿Cómo sabremos si la expresión está balanceada?)*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool parentesis(const string& expresion) {
    stack<char> pila;  
    for (char c : expresion) {
        if (c == '(') {
            pila.push(c);  
        } else if (c == ')') {
            if (pila.empty()) {
                return false;  
            }
            pila.pop();  
        }
    }
    return pila.empty();  
}

int main() {
    string expresion = "((a+b)*c)";
    cout<<"la expresion ((a+b)*c)"<<endl;
    if (parentesis(expresion)) {
        cout << "La expresion tiene los parentesis balanceados." << endl;
    } else {
        cout << "La expresion no tiene los parentesis balanceados." << endl;
    }
    return 0;
}

