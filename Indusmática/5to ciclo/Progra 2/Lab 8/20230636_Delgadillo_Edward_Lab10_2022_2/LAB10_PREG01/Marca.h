/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Marca.h
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:47 PM
 */

#ifndef MARCA_H
#define MARCA_H

#include <fstream>
#include "Medicamento.h"
using namespace std;

class Marca:public Medicamento {
public:
    Marca();
//    Marca(const Marca& orig);
    virtual ~Marca();
    
    void SetLaboratorio(char* laboratorio);
    void GetLaboratorio(char*) const;
    void SetLote(int lote);
    int GetLote() const;
    
    void leer(ifstream& arch);
    void imprimir(ofstream& arch);
    
    bool esDeMarca();

private:
    int lote;
    char*laboratorio;
};

#endif /* MARCA_H */

