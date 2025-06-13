/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.h
 * Author: kenyi
 *
 * Created on 3 de junio de 2025, 05:19 PM
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Cliente.h"
#include "Plato.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Restaurante {
private:
    class Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    class Plato *platos;
    int cantidadDePlatos;
    int capacidadDePlatos;

public:
    Restaurante();
    virtual ~Restaurante();
    inicializa();
    elimina();
    void SetCapacidadDePlatos(int capacidadDePlatos);
    int GetCapacidadDePlatos() const;
    void SetCantidadDePlatos(int cantidadDePlatos);
    int GetCantidadDePlatos() const;
    void SetCapacidadDeClientes(int capacidadDeClientes);
    int GetCapacidadDeClientes() const;
    void SetCantidadDeClientes(int cantidadDeClientes);
    int GetCantidadDeClientes() const;
    void operator<(const char *nombArch);
    void aumentarEspaciosCli();
    void operator<=(const char*nombArch);
    void aumentarEspaciosPla();
    void operator<<=(const char*nombArch);
    int buscarCliente(int dniCli) const;
    void agregarAtributos(ifstream &arch, Cliente &cliente, int posCli);
    int buscarPlato(const char *cod) const;
    void operator>>(const char*nombArch) const;
};

#endif /* RESTAURANTE_H */

