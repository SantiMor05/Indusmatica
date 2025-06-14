/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Lenovo
 *
 * Created on 3 de junio de 2025, 08:11 PM
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
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *cod) const;
    void operator =(const class Pedido &orig);
    Pedido(const Pedido &orig);

};

bool operator >>(ifstream &arch, class Pedido &predido);

#endif /* PEDIDO_H */

