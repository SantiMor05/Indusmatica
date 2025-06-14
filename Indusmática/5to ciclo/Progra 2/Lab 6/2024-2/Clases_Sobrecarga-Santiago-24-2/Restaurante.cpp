/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.cpp
 * Author: santi
 * 
 * Created on 1 de junio de 2025, 13:49
 */

#include "Restaurante.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define MAX_CAR 130


Restaurante::Restaurante() {
    inicializa();
}

//Restaurante::Restaurante(const Restaurante& orig) {
//}

Restaurante::~Restaurante() {
    delete []clientes;
    delete []platos;
}

void Restaurante::inicializa(){
    clientes = nullptr;
    platos = nullptr;
    cantidadDeClientes = 0;
    cantidadDePlatos = 0;
    capacidadDeClientes = 0;
    capacidadDePlatos = 0;
}

void Restaurante::operator < (const char *nombArch){
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << nombArch << endl;
        exit(1);
    }
    Cliente aux;
    while(true){
        arch >> aux;
        if(arch.eof())break;
        if(cantidadDeClientes == capacidadDeClientes)
            incrementarEspaciosClientes();
        clientes[cantidadDeClientes] = aux;
        cantidadDeClientes++;
    }     
}

void Restaurante::operator <=(const char *nombArch){
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << nombArch << endl;
        exit(1);
    }
    while(true){
        if(cantidadDePlatos == capacidadDePlatos)
            incrementarEspaciosPlatos();
        arch >> platos[cantidadDePlatos];
        if(arch.eof())break;
        cantidadDePlatos++;
    }
}


void Restaurante::incrementarEspaciosClientes(){
    
    capacidadDeClientes += INCREMENTO;
    if(clientes == nullptr){
        clientes = new Cliente[capacidadDeClientes]{};
    }
    else{
        Cliente *aux = new Cliente[capacidadDeClientes]{};
        for(int i = 0; i < cantidadDeClientes; i++)
            aux[i] = clientes[i];
        
        delete []clientes;
        clientes = aux;
    }
    
}

void Restaurante::incrementarEspaciosPlatos(){
    
    capacidadDePlatos += INCREMENTO;
    if(platos == nullptr){
        platos = new Plato[capacidadDePlatos]{};
    }
    else{
        Plato *aux = new Plato[capacidadDePlatos]{};
        for(int i = 0; i < cantidadDePlatos; i++)
            aux[i] = platos[i];
        
        delete []platos;
        platos = aux;
    }
    
}

int Restaurante::buscarCliente(int dni){
    
    for(int i = 0; i < cantidadDeClientes; i++){
        if(dni == clientes[i].GetDni())
            return i;
    }
    return NO_ENCONTRADO;
}

int Restaurante::buscarPlato(const char *codigo){
    
    char buffer[500];
    
    for(int i = 0; i < cantidadDePlatos; i++){
        platos[i].GetCodigo(buffer);
        if(strcmp(codigo, buffer) == 0)
            return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::operator <<=(const char *nombArch){
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << nombArch << endl;
        exit(1);
    }
    
    int pedido, dni, cant, posDni,posPlato;
    char codigo[10], car;
    
    while(true){
        arch >> pedido;
        if(arch.eof())break;
        arch >> car >> dni;
        posDni = buscarCliente(dni);
        if(posDni != NO_ENCONTRADO){
            while(arch.get() != '\n'){
                arch.getline(codigo, 10, ',');
                arch >> cant;
                posPlato = buscarPlato(codigo);
                if(posPlato != NO_ENCONTRADO){
                    actualizaDatos(posDni, posPlato, cant);
                }
            }
        }
        else while(arch.get() != '\n');
    }
}


void Restaurante::actualizaDatos(int posDni, int posPlato, int cant){
    
    double precio = platos[posPlato].GetPrecio(), 
            descuentoPlato = platos[posPlato].GetDescuento(),
            descuentoCli = clientes[posDni].GetDescuento();
    
    int preparados = platos[posPlato].GetPreparados(),
            atendidos = platos[posPlato].GetAtendidos(), nuevoCant;
    
    double monto = cant * precio;
    platos[posPlato].SetTotalEsparado(platos[posPlato].GetTotalEsparado()+ monto);
    
    if(cant + atendidos > preparados){
        nuevoCant = preparados - atendidos;
        platos[posPlato].SetAtendidos(platos[posPlato].GetAtendidos() + nuevoCant);
        platos[posPlato].SetNoAtendidos(platos[posPlato].GetNoAtendidos() + cant 
            - nuevoCant);
        monto = nuevoCant * precio;
        
    }
    platos[posPlato].SetTotalBruto(platos[posPlato].GetTotalBruto() + monto);
    monto *= (100 - descuentoPlato) / 100 * (100 - descuentoCli) / 100;
    clientes[posDni].SetTotalPagado(clientes[posDni].GetTotalPagado() + monto);
    platos[posPlato].SetTotalNeto(platos[posPlato].GetTotalNeto() + monto);
}

void Restaurante::operator >> (const char *nombArch){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << nombArch << endl;
        exit(1);
    }
    
    arch << setprecision(2) << fixed;
    arch << setw(MAX_CAR / 2 + 9) << "RESTAURANTE 1INF25" << endl;
    arch << setw(MAX_CAR / 2 + 7) << "VENTAS DEL DIA" << endl;
    imprimirCaracter(arch, '=');
    arch << setw(MAX_CAR / 2 + 13) << "RELACION DE PLATOS VENDIDOS" << endl;
    imprimirCaracter(arch, '-');
    
    for(int i = 0; i < cantidadDePlatos; i++){
        arch << setw(2) << i + 1 << ")";
        arch << platos[i];
    }
        
    
    imprimirCaracter(arch, '=');    
    arch << setw(MAX_CAR / 2 + 13) << "RELACION DE CLIENTES VENDIDOS" << endl;
    imprimirCaracter(arch, '-');
    for(int i = 0; i < cantidadDeClientes; i++){
        arch << setw(2) << i + 1 << ")";
        arch << clientes[i];
    }
    
    
}

void Restaurante::imprimirCaracter(ofstream &arch, char car){
    
    for(int i = 0; i < MAX_CAR; i++)
        arch.put(car);
    arch << endl;    
    
}