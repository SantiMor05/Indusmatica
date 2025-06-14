/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: santi
 *
 * Created on 5 de junio de 2025, 15:00
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <fstream>
using namespace std;

class Pedido {
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
    
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *buffer) const;
    void inicializa();
    void operator =(const Pedido &pedido);

};

bool operator >> (ifstream &arch, Pedido &pedido);

#endif /* PEDIDO_H */

