/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:34
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <fstream>
using namespace std;

class Vehiculo {
private:
    int cliente;
    string placa;
    double maxcarga;
    double actcarga;
    
    
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetCliente(int cliente);
    int GetCliente() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void cargadeposito(ifstream &arch) = 0;
};

#endif /* VEHICULO_H */

