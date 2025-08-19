#include <iostream>
#include <list>
#include "SistemaImpresion.h"
using namespace std;

int main() {
    // 1) Crear sistema y agregar impresoras
    SistemaImpresion sis;
    sis.crear();
    sis.agregarImpresora(Impresora("HP-Laser", true));
    sis.agregarImpresora(Impresora("Epson-Color", true));
    sis.agregarImpresora(Impresora("Brother-BN", false)); // inactiva

    cout << "\n[Estado inicial]\n";
    sis.visualizarEstado();

    // 2) Agregar trabajos: debe asignarlos a la impresora con menor carga
    sis.agregarTrabajo("ReporteFinanzas.pdf", "Ana", 3);
    sis.agregarTrabajo("Contrato.docx", "Luis", 2);
    sis.agregarTrabajo("Planos.dwg", "Marta", 5);

    cout << "\n[Tras agregar 3 trabajos]\n";
    sis.visualizarEstado();

    // 3) Simular impresión por “ticks” (cada tick imprime 1 página del trabajo en curso)
    for (int i = 1; i <= 6; ++i) {
        sis.tick();
        cout << "\n[TICK " << i << "]\n";
        sis.visualizarEstado();
    }

    // 4) Activar la impresora inactiva y enviarle un trabajo
    cout << "\n[Activando Brother-BN y agregando trabajo]\n";
    // Nota: activar/desactivar es sobre cada impresora; aquí lo haríamos recorriendo la lista
    for (Impresora &imp : const_cast<list<Impresora>&>(sis.getImpresoras())) {
        if (imp.getNombre() == "Brother-BN") imp.activar();
    }
    sis.agregarTrabajo("Presentacion.pptx", "Sara", 4);

    cout << "\n[Después de activar y agregar 1 trabajo]\n";
    sis.visualizarEstado();

    // 5) Más ticks para observar nuevos despachos
    for (int i = 7; i <= 12; ++i) {
        sis.tick();
        cout << "\n[TICK " << i << "]\n";
        sis.visualizarEstado();
    }

    return 0;
}

