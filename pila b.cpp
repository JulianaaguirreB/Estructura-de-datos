/*Utilice una pila para evaluar una expresión en notación postfija dada como parámetro en
un string. Por ejemplo string expresion = "231*+9-". Utilice una pila, cada vez que
encuentra un digito agréguelo a la pila, cuando encuentre un operador saque los dos
últimos elementos agregados a la pila, haga la operación dada por el operador recibido
y guarde el resultado de la operación en la pila.*/

#include <iostream>
#include <stack>
using namespace std;

int evaluar(const string& expresion) {
    stack<int> pila;
    
    for (char c : expresion) {
        if (c >= '0' && c <= '9') {
            pila.push(c - '0');
        } else {
            int b = pila.top(); pila.pop();
            int a = pila.top(); pila.pop();
            
            switch (c) {
                case '+': pila.push(a + b); break;
                case '-': pila.push(a - b); break;
                case '*': pila.push(a * b); break;
                case '/': pila.push(a / b); break;
                default: cout << "Operador desconocido: " << c << endl; break;
            }
        }
    }
    
    return pila.top();
}

int main() {
    string expresion = "231*+9-";
    int resultado = evaluar(expresion);
    cout << "El resultado de la expresion es: " << resultado << endl;
    return 0;
}


