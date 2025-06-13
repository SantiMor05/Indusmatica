/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Restaurante.h
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 06:37 PM
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <fstream>
#include "Comanda.h"
using namespace std;

class Restaurante {
    
private:
    class Comanda comandas[100];
    int cantidad_comandas;
public:
    Restaurante();

    void cargar_comandas(const char*nombArchAten, const char*nombArchComa);
    
    //Funciones de lectura
    void leerAtenciones(ifstream &arch);
    void leerComandas(ifstream &arch);
    
    //Busqueda
    int buscarComanda(int id);
    
    //Actualizar
    void actualizar_comandas();
    
    //Para verificar
    void imprimirVericiar();
    
    //Impresion
    void imprimir_comandas(const char*nombArch);
    void imprimirLinea(ofstream &arch, char linea);
};

#endif /* RESTAURANTE_H */

