#ifndef TABLA_HASH_CERRADA_HPP
#define TABLA_HASH_CERRADA_HPP

#include <iostream>
#include "Alumno.hpp"

class TablaHashCerrada {
private:

    //La función de Hash e privada.
    int hashDivision(int clave) const {
    }

public:
    // Constructor
    TablaHashCerrada(int tamano) {
    }

    bool insertarLineal(Alumno a);
    Alumno* buscarLineal(int legajo);
    bool insertarDobleHash(Alumno a);
    
    float calcularFactorCarga() const;

    // Sobrecarga del operador << para depurar la tabla
    friend std::ostream& operator<<(std::ostream& os, const TablaHashCerrada& th);
};

#endif // TABLA_HASH_CERRADA_HPP