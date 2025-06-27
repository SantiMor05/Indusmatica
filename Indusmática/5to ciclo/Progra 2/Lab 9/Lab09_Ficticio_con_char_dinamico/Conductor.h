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
    map<string, vector<Infracciones> > infracciones;
    char *nombre;

public:
    Conductor();

    Conductor(const Conductor &conductor);

    virtual ~Conductor();

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nomb) const;

    void set_nombre(const char *nomb);

    void imprimirPlacas(ofstream &out) const;

    void insertarPlaca(const char *str);

    void imprimir(ofstream &arch) const;

    void cargarPlaca(const char *nombArch);

    string buscarTipoMulta(int get_num, const vector<Multa> &multas);

    void cargarMultas(const char *nombArch, const vector<Multa> &multas);

    void imprimirInfracciones(ofstream &out) const;

    void operator=(const Conductor &conductor);
};

void operator<<(ofstream &out, const Conductor &conductor);


#endif //CONDUCTOR_H
