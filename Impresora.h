#ifndef IMPRESORA_H
#define IMPRESORA_H

#include <string>
#include <queue>
#include "TrabajoImpresion.h"

using namespace std;

class Impresora
{
    private:
    string nombre;
    bool activa;
    queue <TrabajoImpresion> cola;
    queue<TrabajoImpresion> actual;

    public:
    Impresora();
    Impresora(string nombre, bool activa);

    // Getters y setters
    const string& getNombre() const;
    void setNombre(const string& nombre);

    bool getActiva() const;
    void setActiva(bool activa);

    const queue<TrabajoImpresion>& getCola() const;
    void setCola(const queue<TrabajoImpresion>& cola);

    const queue<TrabajoImpresion>& getActual() const;
    void setActual(const queue<TrabajoImpresion>& actual);

    // Métodos de comportamiento
    bool disponible() const;
    int tamCola() const;
    void encolar(const TrabajoImpresion& t);
    void despachar();
    bool imprimirPaso();
    bool colaVacia() const;

    void activar();
    void desactivar();
};

#endif // IMPRESORA_H
