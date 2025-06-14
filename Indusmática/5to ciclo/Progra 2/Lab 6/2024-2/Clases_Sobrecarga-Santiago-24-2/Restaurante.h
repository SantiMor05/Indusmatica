/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.h
 * Author: santi
 *
 * Created on 1 de junio de 2025, 13:49
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Cliente.h"
#include "Plato.h"

class Restaurante {
    
private:
    Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    Plato *platos;
    int cantidadDePlatos;
    int capacidadDePlatos;
    
    void imprimirCaracter(ofstream &arch,char car);
    void incrementarEspaciosClientes();
    void incrementarEspaciosPlatos();
public:
    Restaurante();
    //Restaurante(const Restaurante& orig);
    virtual ~Restaurante();
    void inicializa();
    void operator < (const char *nombArch);
    void operator <=(const char *nombArch);
    void operator <<=(const char *nombArch);
    int buscarCliente(int dni);
    int buscarPlato(const char *codigo);
    void actualizaDatos(int posDni, int posPlato, int cant);
    void operator >> (const char *nombArch);
    
};




#endif /* RESTAURANTE_H */

