/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadAlta.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 23:49
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H

#include "Pedido.h"
#include <fstream>
using namespace std;

class PrioridadAlta : public Pedido{

private:
    double recargo;
    double total;

public:
    PrioridadAlta();
    //PrioridadAlta(const PrioridadAlta& orig);
    virtual ~PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* PRIORIDADALTA_H */

