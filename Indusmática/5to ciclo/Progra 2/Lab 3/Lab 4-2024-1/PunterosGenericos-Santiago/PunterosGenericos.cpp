/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: santi
 * 
 * Created on 1 de mayo de 2025, 10:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "PunterosGenericos.h"
using namespace std;

#define NO_ENCONTRADO -1

void cargaclientes(void *&clientes){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes.csv");
    
    void *buffer[100], *registro, **aux;
    int numDat = 0;
    while(true){
        registro = leerCliente(arch);
        if(registro == nullptr)break;
        buffer[numDat] = registro;
        numDat++;
    }
    aux = new void *[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    clientes = aux;
}


void *leerCliente(ifstream &arch){
    
    int *dni, documento;
    char *nombre;
    
    arch >> documento;
    if(arch.eof())return nullptr;
    dni = new int{documento};
    arch.get();
    nombre = leerCadenaExacta(arch, '\n');
    
    void **registro = new void*[2];
    registro[0] = dni;
    registro[1] = nombre;
    
    return registro;
}

char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char [strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}

void creareserva(void *&reserva){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Libros.csv");
    
    void *buffer[300], *registro, **aux;
    int numDat = 0;
    while(true){
        registro = leerLibro(arch);
        if(registro == nullptr)break;
        buffer[numDat] = registro;
        numDat++;
    }
    aux = new void *[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    reserva = aux;
}


void * leerLibro(ifstream &arch){
    
    char *cod, *nombre, *autor, car;
    int *stock;
    double precio;
    
    cod = leerCadenaExacta(arch, ',');
    if(cod == nullptr) return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, ',');
    stock = new int;
    arch >> *stock >> car >> precio;
    arch.get(); //Leemos el salto de linea
    
    void **registro = new void*[5];
    void **pedidos = new void*[*stock]{};
    registro[0] = cod;
    registro[1] = nombre;
    registro[2] = autor;
    registro[3] = pedidos;
    registro[4] = stock;
    
    return registro;
}


void cargareservar(void *clientes, void *reserva){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
    
    int dni, posCli, posLibro;
    char codigo[8], car;
    void **regLibro, **regCliente;
    while(true){
        arch >> dni;
        if(arch.eof())break;
        arch >> car >> codigo;
        posLibro = buscarLibro(codigo, reserva);
        posCli = buscarCliente(dni, clientes);
        if(posCli !=NO_ENCONTRADO and posLibro != NO_ENCONTRADO){
            regLibro = (void **)reserva;
            regCliente = (void **)clientes;
            agregarReserva(regCliente[posCli], regLibro[posLibro]);
        }
    }
    
}

void agregarReserva(void *cliente, void *libro){
    
    void **detalleCli = (void **)cliente;
    void **detalleLibro = (void **)libro;
    int *stock = (int *)detalleLibro[4];
    void **pedidos = (void **)detalleLibro[3];
    int n = 0;
    for(n; n < *stock and pedidos[n]; n++); //Contamos la posicion a insertar
    
    if(n == *stock){ //No insertamos porque no hay stock
        return;
    }
    else{
        void **detallePedido = new void *[2];
        int *dniCli, *dniPed;
        char *nombreCli, *cad;
        
        dniCli = (int *)detalleCli[0];
        nombreCli = (char *)detalleCli[1];
        dniPed = new int{*dniCli};
        cad = asignarCadena(nombreCli);
        detallePedido[0] = dniPed;
        detallePedido[1] = cad;
        
        pedidos[n] = detallePedido;
               
    }
}

char *asignarCadena(char *nombre){
    
    char *cad = new char [strlen(nombre) + 1];
    strcpy(cad,nombre);
    return cad;
    
}

int buscarCliente(int dni, void *clientes){
    
    void **registro = (void **)clientes;
    void **detalleCliente;
    int *documento;
    for(int i = 0; registro[i]; i++){
        detalleCliente = (void **)registro[i];
        documento = (int *)detalleCliente[0];
        if(dni == *documento)
            return i;
    }
    return NO_ENCONTRADO;
}

int buscarLibro(char *codigo, void *reserva){
    
    void **registro = (void **)reserva;
    void **detalleLibro;
    char *cod;
    for(int i = 0; registro[i]; i++){
        detalleLibro = (void **)registro[i];
        cod = (char *)detalleLibro[0];
        if(strcmp(codigo, cod) == 0)
            return i;
    }
    return NO_ENCONTRADO;
}