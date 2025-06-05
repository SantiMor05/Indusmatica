/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Lenovo
 *
 * Created on 3 de junio de 2025, 08:11 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "Cliente.h"
#include "Producto.h"

class Almacen {
    
private:
    class Cliente arreglo_clientes[150];
    int cantidad_clientes;
    class Producto arreglo_productos[200];
    int cantidad_productos;
public:
    Almacen();
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    
    
    void cargar_clientes(const char*nombArch);
    void cargar_productos(const char*nombArch);
    void cargar_pedidos(const char*nombArch);
    void mostrar_datos(const char*nombArch);
    
    //Funciones buscar
    int buscarCliente(int dni);
    int buscarPlato(char *cod);
    
    void imprimirLinea(ofstream &arch, char linea);
};

#endif /* ALMACEN_H */

