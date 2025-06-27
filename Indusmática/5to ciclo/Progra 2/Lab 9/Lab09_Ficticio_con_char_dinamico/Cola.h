//
// Created by kenyi on 25/06/2025.
//

#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

#include <fstream>

#include "Multa.h"
using namespace std;

class Cola {
private:
    Nodo *cabeza;
    Nodo *cola;
    vector<Multa> multas;

public:
    Cola();

    void insertarConductores(ifstream &arch);

    void encolar(Conductor &conductor);

    void cargarConductores(const char *nombArch);

    Conductor desencola();

    ~Cola();

    void imprimirConductores(const char *nombArch);

    void insertarMultar(ifstream &arch);

    void cargarMultas(const char *nombArch);
};


#endif //COLA_H
