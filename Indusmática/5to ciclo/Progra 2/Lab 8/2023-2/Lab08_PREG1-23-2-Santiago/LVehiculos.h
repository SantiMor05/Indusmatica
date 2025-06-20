/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LVehiculos.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:32
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H

#include "NodoLista.h"
#include <fstream>
using namespace std;

class LVehiculos {
private:
    NodoLista *lini;
    NodoLista *lfin;
    
public:
    LVehiculos();
    LVehiculos(const LVehiculos& orig);
    virtual ~LVehiculos();
    void inicializa();
    void cargaFlota(ifstream &arch);
    void inserta(ifstream &arch,char tipo);
    void imprime(ofstream &arch);
    bool buscaActaulizaCliente(ifstream &arch, int cli);
};

#endif /* LVEHICULOS_H */

