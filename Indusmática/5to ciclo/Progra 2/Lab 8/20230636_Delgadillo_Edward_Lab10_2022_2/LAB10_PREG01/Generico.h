/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Generico.h
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:47 PM
 */

#ifndef GENERICO_H
#define GENERICO_H

#include <fstream>
#include "Medicamento.h"
using namespace std;


class Generico:public Medicamento {
public:
    Generico();
//    Generico(const Generico& orig);
    virtual ~Generico();
    
    void SetPais(char* pais);
    void GetPais(char*) const;
    void leer(ifstream& arch);
    void imprimir(ofstream& arch);
    bool esDeMarca();
private:
    char*pais;
};

#endif /* GENERICO_H */

