/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.h
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:33
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <string>
using namespace std;

class NPedido {
private:
    string codigo;
    int cantidad;
    double peso;
    
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;

};

#endif /* NPEDIDO_H */

