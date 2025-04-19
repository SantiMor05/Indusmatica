/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.cpp
 * Author: kenyi
 * 
 * Created on 19 de abril de 2025, 01:12 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#define NO_ENCONTRADO -1
#define MAX_LINE 120

enum indices {
    COD, DES, AUT
};
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
//YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02

void lecturaDeLibros(const char*nombArch, char ***&libros, int **&stock) {
    char **buffLib[300]{}, c;
    int *buffStock[300]{};

    ifstream archLib(nombArch, ios::in);
    if (not archLib.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    double precio;
    int nd = 0;

    while (true) {
        buffLib[nd] = leerLibro(archLib);
        if (archLib.eof())break;
        buffStock[nd] = leerStock(archLib);
        archLib>>precio;
        archLib.get();
        nd++;
    }
    nd++;
    libros = new char**[nd];
    stock = new int*[nd];
    for (int i = 0; i < nd; i++) {
        libros[i] = buffLib[i];
        stock[i] = buffStock[i];
    }
}

int *leerStock(ifstream &archLib) {
    int *stock, *dupla = new int[2] {
    }, stock_ini;
    archLib>>stock_ini;
    archLib.get();
    dupla[0] = stock_ini;
    stock = dupla;
    return stock;
}

char **leerLibro(ifstream &archLib) {
    char **lib, *cod, *desc, *autor;
    cod = leerExacto(archLib, 8, ',');
    if (archLib.eof())return nullptr;
    desc = leerExacto(archLib, 60, ',');
    autor = leerExacto(archLib, 40, ',');
    lib = new char*[3];
    lib[COD] = cod;
    lib[DES] = desc;
    lib[AUT] = autor;
    return lib;
}

char *leerExacto(ifstream &archLib, int max, char del) {
    char buff[max]{}, *cad;
    archLib.getline(buff, max, del);
    if (archLib.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros, int **stock) {
    ofstream archRep(nombArch, ios::out);
    if (not archRep.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    int *dupla;
    for (int i = 0; libros[i]; i++) {
        imprimirLibroPrueba(archRep, libros[i]);
        dupla = stock[i];
        archRep << setw(8) << dupla[0] << setw(8) << dupla[1] << endl;
    }

}

void imprimirLibroPrueba(ofstream &arch, char**lib) {
    arch << left << setw(12) << lib[COD] << setw(60) << lib[DES]
            << setw(40) << lib[AUT] << right;
}
//000059,34460612   CRY6839    VYG3594
//000140,42302422   WPU8819    CTW5846

void atencionDePedidos(const char*nombArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros,
        bool **&pedidosAtendidos) {
    int *buffPedCli[200]{};
    char **buffPedLib[200]{};
    bool *buffPedAten[200]{};
    ifstream archPed(nombArch, ios::in);
    if (not archPed.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    int numPed, dni, posC, cantCli = 0, cantPorPedido[200]{}, cantPed = 0;
    char cod[8], c;
    while (true) {
        archPed>>numPed;
        if (archPed.eof())break;
        archPed >> c>>dni;
        posC = buscarCliente(buffPedCli, dni);
        if (posC == NO_ENCONTRADO) {
            agregarCliente(buffPedCli[cantCli], dni, cantCli, posC);
        }
        insertarPedido(buffPedCli[posC], numPed);
        leerPedido(archPed, libros, stock, buffPedLib[numPed],
                buffPedAten[numPed], cantPorPedido[numPed]);
        cantPed++;
    }
    cargarArreglos(pedidosClientes, pedidosLibros, pedidosAtendidos,
            buffPedCli, buffPedLib, buffPedAten, cantPed, cantCli,
            cantPorPedido);
}

void cargarArreglos(int **&pedidosClientes, char ***&pedidosLibros,
        bool **&pedidosAtendidos, int **buffPedCli, char ***buffPedLib,
        bool **buffPedAten, int cantPed, int cantCli, int *cantPorPedido) {

    pedidosClientes = new int*[cantCli + 1];
    pedidosLibros = new char**[cantPed + 2];
    pedidosAtendidos = new bool*[cantPed + 1];

    int *auxBuffCli;
    for (int i = 0; i < cantCli; i++) {
        auxBuffCli = buffPedCli[i];
        pedidosClientes[i] = new int[auxBuffCli[1] + 2];
        cargaClienteInterno(pedidosClientes[i], buffPedCli[i]);
    }

    pedidosClientes[cantCli] = nullptr;

    for (int i = 1; i < cantPed + 1; i++) {
        pedidosLibros[i] = new char*[cantPorPedido[i] + 1];
        pedidosAtendidos[i] = new bool[cantPorPedido[i]];
        cargaPedidoInterno(pedidosLibros[i], pedidosAtendidos[i],
                buffPedLib[i], buffPedAten[i], cantPorPedido[i]);
    }
}

void cargaPedidoInterno(char **pedidosLibros, bool *pedidosAtendidos,
        char **buffPedLib, bool *buffPedAten, int cant) {
    for (int i = 0; i < cant; i++) {
        pedidosAtendidos[i] = buffPedAten[i];
        pedidosLibros[i] = buffPedLib[i];
    }
    pedidosLibros[cant] = nullptr;
}

void cargaClienteInterno(int *pedidosClientes, int *buffPedCli) {
    for (int i = 0; i < buffPedCli[1] + 2; i++) {
        pedidosClientes[i] = buffPedCli[i];
    }
}

void leerPedido(ifstream &archPed, char ***libros, int **stock, char **&buffPedLib,
        bool *&buffPedAten, int &cant) {
    char codLib[8];
    int posLib;
    buffPedLib = new char*[20];
    buffPedAten = new bool[20];
    while (archPed.get() != '\n') {
        archPed>>codLib;
        buffPedLib[cant] = new char[8];
        strcpy(buffPedLib[cant], codLib);
        posLib = buscarLibro(libros, codLib);
        modificarAtendido(stock[posLib], buffPedAten[cant]);
        cant++;
    }
}

void modificarAtendido(int *stock, bool &buffPedAten) {
    if (stock[0] > 0) {
        buffPedAten = true;
        stock[0]--;
    } else {
        buffPedAten = false;
        stock[1]++;
    }
}

int buscarLibro(char ***libros, char *codLib) {
    char **tripleta;
    for (int i = 0; libros[i]; i++) {
        tripleta = libros[i];
        if (strcmp(tripleta[COD], codLib) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void insertarPedido(int *buffPedCli, int numPed) {
    buffPedCli[2 + buffPedCli[1]] = numPed;
    buffPedCli[1]++;
}

void agregarCliente(int *&buffPedCli, int dni, int &cantCli, int &posC) {
    buffPedCli = new int[20] {
    };
    buffPedCli[0] = dni;
    posC = cantCli;
    cantCli++;
}

int buscarCliente(int **buffPedCli, int dni) {
    int *dupla;
    for (int i = 0; buffPedCli[i]; i++) {
        dupla = buffPedCli[i];
        if (dupla[0] == dni)return i;
    }
    return NO_ENCONTRADO;
}

void reporteDeEntregaDePedidos(const char*nombArch, int **pedidosClientes,
        char ***pedidosLibros, bool **pedidosAtendidos) {
    ofstream archRep(nombArch, ios::out);
    if (not archRep.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    archRep << fixed << setprecision(2);
    imprimirTitulo(archRep);

    int *auxCli;
    for (int i = 0; pedidosClientes[i]; i++) {
        auxCli = pedidosClientes[i];
        archRep << "CLIENTE: " << auxCli[0] << endl;
        imprimirLinea(archRep, MAX_LINE, '=');
        for (int j = 2; j < auxCli[1] + 2; j++) {
            imprimirEncabezado(archRep);
            archRep << setw(32) << " " << setw(6) << setfill('0')
                    << auxCli[j] << setfill(' ') << setw(29) << " ";
            imprimirPed(archRep, pedidosLibros[auxCli[j]],
                    pedidosAtendidos[auxCli[j]]);
            imprimirLinea(archRep, MAX_LINE, '-');
        }
        imprimirLinea(archRep, MAX_LINE, '=');
    }

}

void imprimirPed(ofstream &arch, char **pedidosLibros, bool *pedidosAtendidos) {
    for (int i = 0; pedidosLibros[i]; i++) {
        if (i != 0)arch << setw(67) << " ";
        arch << pedidosLibros[i];
        if (pedidosAtendidos[i]) {
            arch << setw(20) << " " << "ATENDIDO" << endl;
        } else arch << setw(20) << " " << "NO ATENDIDO" << endl;
    }
}

void imprimirEncabezado(ofstream &archRep) {
    archRep << setw(40) << "Pedido No." << setw(40) << "Codigo del Libro"
            << setw(24) << "Observacion" << endl;
    imprimirLinea(archRep, MAX_LINE, '-');
}

void imprimirTitulo(ofstream &archRep) {
    archRep << setw(MAX_LINE / 2) << "REPORTE DE ATENCION DE PEDIDOS" << endl;
    imprimirLinea(archRep, MAX_LINE, '=');
}

void imprimirLinea(ofstream &archRep, int n, char c) {
    for (int i = 0; i < n; i++)archRep.put(c);
    archRep << endl;
}