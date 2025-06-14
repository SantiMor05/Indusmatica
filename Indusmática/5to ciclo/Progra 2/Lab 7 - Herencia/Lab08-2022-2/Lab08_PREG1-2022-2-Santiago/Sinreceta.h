/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sinreceta.h
 * Author: santi
 *
 * Created on 12 de junio de 2025, 22:16
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "Medicamento.h"
#include <fstream>
using namespace std;


class Sinreceta : public Medicamento{
private:
    int dni;
    char *nombre;
    

public:
    Sinreceta();
//    Sinreceta(const Sinreceta& orig);
    virtual ~Sinreceta();
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void SetDni(int dni);
    int GetDni() const;
    void inicializa();
    void asigna(ifstream &arch, int medicamento, int cantidad, int doc, 
            char *nomb, int fecha);
    void imprimir(ofstream &arch);
};

#endif /* SINRECETA_H */

