/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comanda.h
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 04:36 PM
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
    Bebida bebidas[10];
    Entrada entradas[10];
    PlatoFondo platos_fondo[10];
    int cantidad_bebidas;
    int cantidad_entradas;
    int cantidad_platos_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    char *estado;
public:
    Comanda();
    virtual ~Comanda();
    void SetEstado(const char* estado);
    void GetEstado(char*) const;
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
    void llenarAten(int id, int horaAten, int horaServ);
    void agregarComanda(ifstream &arch);
    void imprimir(ofstream &arch);
    void imprimirLinea(ofstream &arch, char c,int tam);
};

#endif /* COMANDA_H */

