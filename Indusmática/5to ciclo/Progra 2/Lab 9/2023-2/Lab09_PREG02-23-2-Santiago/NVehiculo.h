/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NVehiculo.h
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:42
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include "Vehiculo.h"
#include <fstream>
using namespace std;

class NVehiculo {
private:
    Vehiculo *unidad;
    
public:
    NVehiculo();
//    NVehiculo(const NVehiculo& orig);
//    virtual ~NVehiculo();
    void inicializa();
    void asignaTipo(char car);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    int retornaCliente()const;
    void cargadeposito(ifstream &arch);
    bool operator <(const NVehiculo &veh);
};

#endif /* NVEHICULO_H */

