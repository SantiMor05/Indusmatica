/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:17
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

//#include "Vehiculo.h"
#include <fstream>
using namespace std;

class NPedido {

private:
    char *codigo;
    int cantidad;
    double peso;
    NPedido *sig;

public:
    NPedido();
//    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *buffer) const;
    void inicializa();
    void leerPedido(ifstream &arch);
    void operator =(const NPedido &orig);
    void imprimir(ofstream &arch);

    friend class Vehiculo;
};

#endif /* NPEDIDO_H */

