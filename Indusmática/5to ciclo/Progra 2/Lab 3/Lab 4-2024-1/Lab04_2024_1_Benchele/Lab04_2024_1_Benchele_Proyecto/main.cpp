/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 29 de abril de 2025, 09:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *clientes, *reserva;
    //Cargar cliente
    cargaClientes("Clientes.csv",clientes); //Se debe llamar el archivo dentro de la funcion
    //Crear reserva
    crearReserva("Libros.csv",reserva);
    //Cargar Reserva
    cargarReserva("Pedidos2.csv", clientes, reserva);
    //Reporte final
    reportefinal(reserva);
    return 0;
}

