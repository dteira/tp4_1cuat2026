#ifndef TABLA_HASH_ABIERTA_HPP
#define TABLA_HASH_ABIERTA_HPP

#include <iostream>
#include <string>
#include "Alumno.hpp"

// Clase TablaHashAbierta
class TablaHashAbierta {
private:
    int funcionHash(int clave) const;

public:
    // Constructor
    TablaHashAbierta(int tamanoInicial = 7);

    // Métodos principales pedidos en el enunciado
    void insertar(Alumno a);
    bool eliminar(int legajo);
    Alumno* buscar(int legajo);
    float calcularFactorCarga() const;

    // Sobrecarga del operador << para visualizar el estado completo de la tabla
    friend std::ostream& operator<<(std::ostream& os, const TablaHashAbierta& th);
};

#endif // TABLA_HASH_ABIERTA_HPP