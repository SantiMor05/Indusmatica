/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: santi
 *
 * Created on 5 de junio de 2025, 14:45
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "ProductoEntregado.h"
#include "Pedido.h"
#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[50];
    int cantidad_productos_entregados;
    double monto_total;
    
public:
    Cliente();
//    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void SetDni(int dni);
    int GetDni() const;
    void inicializa();
    void operator =(const Cliente &cli);
    void operator += (const Pedido &pedido);
};


bool operator >> (ifstream &arch, Cliente &cliente);


#endif /* CLIENTE_H */

