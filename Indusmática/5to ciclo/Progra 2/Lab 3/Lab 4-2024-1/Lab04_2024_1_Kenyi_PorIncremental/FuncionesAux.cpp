/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAux.cpp
 * Author: kenyi
 * 
 * Created on 1 de mayo de 2025, 04:42 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
#include "FuncionesAux.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void cargaclientes(void *&cli) {
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli, "Clientes.csv");

    void **clientes = nullptr, *reg;
    int nd = 0, cap = 0;
    while (true) {
        reg = leerReg(archCli);
        if (archCli.eof())break;
        if (nd == cap)incrementarEspacio(clientes, nd, cap);
        clientes[nd - 1] = reg;
        nd++;
    }
    cli = clientes;

    muestraclientes(cli);
}

void incrementarEspacio(void **&clientes, int &nd, int &cap) {
    void **aux;
    cap += INCREMENTO;
    if (clientes == nullptr) {
        clientes = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++) aux[i] = clientes[i];
        delete clientes;
        clientes = aux;
    }
}

void *leerReg(ifstream &archCli) {
    void **reg;
    int dni;
    archCli>>dni;
    if (archCli.eof())return nullptr;
    archCli.get();
    reg = new void*[2] {
    };

    reg[0] = new int{dni};
    reg[1] = leerExato(archCli, 40, '\n');

    return reg;
}

char *leerExato(ifstream &arch, int max, char del) {
    char buff[max], *cad;
    arch.getline(buff, max, del);
    if (arch.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void creareserva(void *&res) {
    ifstream archLib;
    AperturaDeUnArchivoDeTextosParaLeer(archLib, "Libros.csv");

    void **reserva = nullptr, *reg;
    int nd = 0, cap = 0;

    while (true) {
        reg = leerRegReserva(archLib);
        if (archLib.eof())break;
        if (nd == cap)incrementarEspacio(reserva, nd, cap);
        reserva[nd - 1] = reg;
        nd++;
    }
    res = reserva;

    muestrareservas(res);

}
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23

void *leerRegReserva(ifstream &archLib) {
    void **reg;
    char *cod, c;
    int stock;
    double precio;
    cod = leerExato(archLib, 8, ',');
    if (archLib.eof())return nullptr;

    reg = new void*[5] {
    };

    reg[0] = cod;
    reg[1] = leerExato(archLib, 80, ',');
    reg[2] = leerExato(archLib, 60, ',');

    archLib >> stock >> c>>precio;
    archLib.get();
    reg[3] = new void*[stock] {
    };
    reg[4] = new int{stock};


    return reg;
}

void cargareservar(void *clientes, void *&reserva) {
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed, "Pedidos2.csv");
    int nd = 0;
    void **regRes = (void**) reserva, **regCli = (void**) clientes;
    for (int i = 0; regRes[i]; i++)nd++;
    int dni, cantCliEnRes[nd]{}, posC, posR;
    char *cod;
    while (true) {
        archPed>>dni;
        if (archPed.eof())break;
        archPed.get();
        cod = leerExato(archPed, 8, '\n');
        posC = buscarClientes(dni, regCli);
        posR = buscarReserva(cod, regRes);
        if(posC!=NO_ENCONTRADO,posR!=NO_ENCONTRADO){
            colocarCliente(regRes[posR],regCli[posC],cantCliEnRes[posR]);
        }
    }
}

void colocarCliente(void *res,void *cli,int &cantCli){
    void **regRes=(void**)res,**regCli=(void**)cli;
    void **pedClientes=(void**)regRes[3];
    int *stock=(int*)regRes[4];
    
    if(*stock>cantCli){
        pedClientes[cantCli]=colocarSolicitante(regCli);
        cantCli++;
    }
}

void *colocarSolicitante(void **regCli){
    void **reg=new void*[2];
    
    reg[0]=regCli[0];
    reg[1]=regCli[1];
    return reg;
}

int buscarClientes(int dni, void **regCli) {
    void **detalle;
    int *dniCli;
    for (int i = 0; regCli[i]; i++) {
        detalle = (void**) regCli[i];
        dniCli = (int*) detalle[0];
        if (dni == *dniCli)return i;
    }
    return NO_ENCONTRADO;
}

int buscarReserva(char *cod, void **regRes) {
    void **detalle;
    char *codLib;
    for (int i = 0; regRes[i]; i++) {
        detalle = (void**) regRes[i];
        codLib = (char*) detalle[0];
        if (strcmp(cod, codLib) == 0)return i;
    }
    return NO_ENCONTRADO;
}