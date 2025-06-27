/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.h
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:43
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <vector>
#include "NVehiculo.h"
#include <fstream>
using namespace std;

class Flota {
private:
    vector <NVehiculo> vflota;
    void imprimirLinea(ofstream &arch, char car);
    NVehiculo*buscarCliente(int cliente);
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void muestracarga();
    void cargapedidos();
    void ordena();
};

#endif /* FLOTA_H */

