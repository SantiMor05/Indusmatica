//
// Created by kenyi on 24/06/2025.
//

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <string>
#include  <fstream>
#include <map>
#include <vector>
#include "Infracciones.h"
#include "Automovil.h"
#include "Multa.h"
using namespace std;

class Conductor {
private:
    int dni;
    vector<Automovil> placas;
    map<string, vector<Infracciones>> infracciones;
    string nombre;

public:
    int get_dni() const;

    void set_dni(int dni);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    void imprimirPlacas(ofstream &out) const;

    void insertarPlaca(const string str);

    void imprimir(ofstream &arch) const;

    void cargarPlaca(const char *nombArch);

    string buscarTipoMulta(int get_num, const vector<Multa> &multas);

    void cargarMultas(const char *nombArch, const vector<Multa> &multas);

    void imprimirInfracciones(ofstream & out) const;
};

void operator<<(ofstream &out, const Conductor &conductor);


#endif //CONDUCTOR_H
