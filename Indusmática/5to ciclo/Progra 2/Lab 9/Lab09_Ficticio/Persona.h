//
// Created by kenyi on 22/06/2025.
//

#ifndef PERSONA_H

#define PERSONA_H

#include <iostream>

using namespace std;

class Persona {
private:
    int Edad;
    char *Nombre;
    char *apellido;
    int codigo;
public:
    int get_edad() const;

    void set_edad(int edad);

    void get_nombre(char *nomb) const;

    void set_nombre(const char *nombre);

    void get_apellido(char *apell) const;

    void set_apellido(const char *apellido);

    int get_codigo() const;

    void set_codigo(int codigo);

    Persona();

    Persona(const Persona &orig);

    ~Persona();

    void inicializa();

    void imprime(ostream &out) const;
};


void operator<<(ostream &out, const Persona &persona);

#endif //PERSONA_H
