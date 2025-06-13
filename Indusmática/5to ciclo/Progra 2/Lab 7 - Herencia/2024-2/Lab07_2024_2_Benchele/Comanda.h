/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Comanda.h
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 05:22 PM
 */

#ifndef COMANDA_H
#define COMANDA_H

#include <fstream>
#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"
using namespace std;

class Comanda {
    
private:
    int id;
    class Bebida bebidas[200];
    class Entrada entreadas[200];
    class PlatoFondo platos_fondo[200];
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
    
    void inicializar();
    
    void asignarDatos(int id, int horaAten, int horaServ);
    
    void actualizar(ifstream &arch);
    void actualizarDatos();
    
    void mostrarResultados(ofstream &arch);
    
    void imprimirHora(ofstream &arch, int tipo);
    void imprimirLinea(ofstream &arch, char linea);
};

#endif /* COMANDA_H */

