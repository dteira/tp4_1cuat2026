#ifndef ALUMNO_DEFINIDO
#define ALUMNO_DEFINIDO

struct Alumno {
    int legajo;
    std::string nombre;

    Alumno() : legajo(0), nombre("") {}
    Alumno(int l, std::string n) : legajo(l), nombre(n) {}

    friend std::ostream& operator<<(std::ostream& os, const Alumno& a) {
        os << "[" << a.legajo << " - " << a.nombre << "]";
        return os;
    }
};

#endif