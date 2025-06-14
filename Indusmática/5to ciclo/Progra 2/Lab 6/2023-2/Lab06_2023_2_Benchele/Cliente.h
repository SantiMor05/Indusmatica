/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Lenovo
 *
 * Created on 3 de junio de 2025, 08:11 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
#include "ProductoEntregado.h"
#include "Pedido.h"
using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    class ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void inicializar();
    void operator =(const class Cliente &orig);
    
    void operator +=(class Pedido pedido);
    ProductoEntregado *GetProductos_entregados();

};

bool operator >>(ifstream &arch, class Cliente &cliente);
void operator <<(ofstream &arch, class Cliente &cliente);

#endif /* CLIENTE_H */

