/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:22
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include "NPedido.h"
#include <fstream>
using namespace std;

class Vehiculo {
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    NPedido *ped;
    
public:
    Vehiculo();
//    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* placa);
    void GetPlaca(char *buffer) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    void inicializa();
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    void imprimePedidos(ofstream &arch);
    void leePedido(ifstream &arch);
    
    bool pilaVacia();
    void push(NPedido &pedido);
};

#endif /* VEHICULO_H */

