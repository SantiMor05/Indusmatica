/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Comanda.h
 * Author: Usuario
 *
 * Created on 12 de junio de 2025, 08:20
 */

#ifndef COMANDA_H
#define COMANDA_H

#include <fstream>
using namespace std;
#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"


class Comanda {
private:
    int id;
    Bebida bebudas[50];
    Entrada entradas[50];
    PlatoFondo platos_fondo[50];
    int cantidad_bebidas;
    int cantidad_entradas;
    int cantidad_platos_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    char* estado;
public:
    Comanda();
    virtual ~Comanda();
    void SetEstado(const char* estado);
    void GetEstado(char* cad) const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetTiempo_preparacion(int tiempo_preparacion);
    int GetTiempo_preparacion() const;
    void SetHora_servicio(int hora_servicio);
    int GetHora_servicio() const;
    void SetHora_atencion(int hora_atencion);
    int GetHora_atencion() const;
    void SetCantidad_platos_fondo(int cantidad_platos_fondo);
    int GetCantidad_platos_fondo() const;
    void SetCantidad_entradas(int cantidad_entradas);
    int GetCantidad_entradas() const;
    void SetCantidad_bebidas(int cantidad_bebidas);
    int GetCantidad_bebidas() const;
    void SetId(int id);
    int GetId() const;
    void llenarDatos1(int id,int tempI,int tempF);
    void LeerProducto(ifstream &arch, char tipo);
    void imprimirComanda(ofstream &arch);
    void imprimirLinea(ofstream &arch,char c,int n);
    void actualiza();
};

#endif /* COMANDA_H */

