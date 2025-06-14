/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comanda.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 19:54
 */

#ifndef COMANDA_H
#define COMANDA_H


#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

#include <fstream>
using namespace std;

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
        
        
        void imprimirHora(ofstream &arch, int hora);
public:
    Comanda();
//    Comanda(const Comanda& orig);
    virtual ~Comanda();
    void SetEstado(char* estado);
    void GetEstado(char *buffer) const;
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
    void inicializa();
    void leerDatos(ifstream &arch);
    void agregarDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
    void actualizarComanda();
};

#endif /* COMANDA_H */

