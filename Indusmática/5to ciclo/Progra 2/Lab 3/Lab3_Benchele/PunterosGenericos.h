/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Lenovo
 *
 * Created on 29 de abril de 2025, 09:55 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

//Comunes
char *leerCadenaExacta(ifstream &arch, char delimitador = '\n');
//Cargar cliente
void cargaClientes(const char*nombArch, void *&cli);
void *leerRegistro(ifstream &arch);
//Crear reserva
void crearReserva(const char*nombArch, void *&res);
void *leerLibros(ifstream &arch);
void *crearMemoriaExactaStock(int cantPed);
void mostrarRservas(const char*nombArch, void *res);
void imprimirUnaReserva(ofstream &arch, void *res);

//Cargar Reserva
void cargarReserva(const char*nombArch, void *cli, void *res);
int buscarCliente(int dniCli, void **clientes);
int buscarLibro(char *codLib, void **reservas);
bool sonIguales(int dniCli, void *cli);
bool sonIguales(char *codLib, void *res);
void calcularStockActual(int *&stockActual, void **reservas);
void pasarStock(int &stockActual, void *res);
void agregarPedido(void *cli, void *res, int &stockActual);
void actualizarPed(int *dniCli, char *nombCLi, void *&pedido);

#endif /* PUNTEROSGENERICOS_H */
