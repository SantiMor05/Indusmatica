/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: kenyi
 * 
 * Created on 1 de mayo de 2025, 08:14 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
#define INCREMENTADO 5
#define NO_ENCONTRADO -1

void cargaproductos(void *&prod) {
    ifstream archProd("Productos2.csv", ios::in);
    if (not archProd.is_open()) {
        cout << "Error al abrir el archivo Productos2.csv";
        exit(1);
    }

    void **productos = nullptr, *reg;
    int nd = 0, cap = 0;
    while (true) {
        reg = leerRegPro(archProd);
        if (archProd.eof())break;
        if (nd == cap)incrementarEspacio(productos, nd, cap);
        productos[nd - 1] = reg;
        nd++;
    }
    prod = productos;
    imprimeproductos(prod);

}

void incrementarEspacio(void **&pt, int &nd, int &cap) {
    void **aux;
    cap += INCREMENTADO;
    if (pt == nullptr) {
        pt = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++) aux[i] = pt[i];
        delete pt;
        pt = aux;
    }
}

void *leerRegPro(ifstream &archProd) {
    void **reg;
    char *cod, c;
    cod = leerExacto(archProd, 8, ',');
    if (archProd.eof())return nullptr;
    reg = new void*[4];
    double precio;
    reg[0] = cod;
    reg[1] = leerExacto(archProd, 80, ',');
    archProd >> precio>>c;
    reg[2] = new double{precio};
    reg[3] = leerExacto(archProd, 2, '\n');
    return reg;
}

char *leerExacto(ifstream &archProd, int max, char del) {
    char buff[max], *cad;
    archProd.getline(buff, max, del);
    if (archProd.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void cargaclientes(void *&cli) {
    ifstream archCli("Clientes2.csv", ios::in);
    if (not archCli.is_open()) {
        cout << "Error al abrir el archivo Clientes2.csv";
        exit(1);
    }
    void **clientes = nullptr, *reg;
    int nd = 0, cap = 0;
    while (true) {
        reg = leerRegCli(archCli);
        if (archCli.eof())break;
        if (nd == cap)incrementarEspacio(clientes, nd, cap);
        clientes[nd - 1] = reg;
        nd++;
    }
    cli = clientes;
    imprimeclientes(cli);
}

void *leerRegCli(ifstream &archCli) {
    void **reg;
    int dni, num;
    double credito;
    char c;
    archCli>>dni;
    if (archCli.eof())return nullptr;
    archCli.get();
    reg = new void*[4];
    reg[0] = new int{dni};
    reg[1] = leerExacto(archCli, 60, ',');
    reg[2] = nullptr;
    archCli >> num >> c>>credito;
    reg[3] = new double{credito};
    return reg;
}

void cargapedidos(void *productos, void *&clientes) {
    ifstream archPed("Pedidos2.csv", ios::in);
    if (not archPed.is_open()) {
        cout << "Error al abrir el archivo Pedidos2.csv";
        exit(1);
    }
    void **regPro = (void**) productos, **regCli = (void**) clientes;
    int ndCli = 0, ndProd = 0;
    for (int i = 0; regCli[i]; i++)ndCli++;
    for (int i = 0; regPro[i]; i++)ndProd++;
    int dni, cant, numProEnCli[ndCli]{}, posC, posP;
    char *cod, c;
    while (true) {
        cod = leerExacto(archPed, 8, ',');
        if (archPed.eof())break;
        archPed >> dni >> c>>cant;
        archPed.get();
        posC = buscarCliente(dni, regCli);
        posP = buscarProducto(cod, regPro);
        if (posC != NO_ENCONTRADO and posP != NO_ENCONTRADO) {
            colocarPedido(regCli[posC], regPro[posP], numProEnCli[posC],
                    cant, ndProd);
        }
    }
    eliminarEspacios(clientes, numProEnCli);
}

void eliminarEspacios(void *clientes, int *numProEnCli) {
    void **reg = (void**) clientes;
    void **detalles;
    for (int i = 0; reg[i]; i++) {
        detalles = (void**) reg[i];
        if (detalles[2] != nullptr)disminuirPedidos(detalles[2], numProEnCli[i]);
    }
}

void disminuirPedidos(void *&ped, int numPro) {
    void **aux = new void*[numPro + 1] {
    };
    void **pedidos = (void**) ped;
    for (int i = 0; pedidos[i]; i++) {
        aux[i] = pedidos[i];
    }
    delete pedidos;
    ped = aux;
}

void colocarPedido(void *clientes, void *productos, int &numPed,
        int cant, int ndPro) {
    void **regCli = (void **) clientes, **regPro = (void**) productos;
    if (regCli[2] == nullptr)regCli[2] = new void*[ndPro] {
        };
    //    double *credito = (double *) regCli[3], *precio = (double *) regPro[2],
    //            *monto = new double{*precio * cant};
    //    if (*credito - *monto >= 0) {
    //        void**pedido = (void**) regCli[2];
    //        void**tripleta = new void*[3];
    //        int *cantidad = new int{cant};
    //        char *cod = (char *) regPro[0];
    //
    //        tripleta[0] = cod;
    //        tripleta[1] = cantidad;
    //        tripleta[2] = monto;
    //
    //        pedido[numPed] = tripleta;
    //        *credito -= *monto;
    //    }


    void **ped = (void**) regCli[2];
    char *cod = (char*) regPro[0], *tipo = (char*) regPro[3];
    double *total = new double, *precio = (double *) regPro[2],
            *credito = (double *) regCli[3];
    *total = cant* *precio;
    if (*credito - *total >= 0 and *tipo == 'S') {
        ped[numPed] = colocarProd(cod, cant, total);
        numPed++;
        *credito -= *total;
    }
    if (*tipo == 'N') {
        ped[numPed] = colocarProd(cod, cant, total);
        numPed++;
    }
}

void *colocarProd(char *cod, int cant, double *total) {
    void **reg = new void*[3];
    reg[0] = cod;
    reg[1] = new int{cant};
    reg[2] = total;
    return reg;
}

int buscarCliente(int dni, void **regCli) {
    void **detalles;
    int *dni_cli;
    for (int i = 0; regCli[i]; i++) {
        detalles = (void**) regCli[i];
        dni_cli = (int *) detalles[0];
        if (*dni_cli == dni)return i;
    }
    return NO_ENCONTRADO;
}

int buscarProducto(char *cod, void **regPro) {
    void **detalles;
    char *cod_cli;
    for (int i = 0; regPro[i]; i++) {
        detalles = (void**) regPro[i];
        cod_cli = (char *) detalles[0];
        if (strcmp(cod_cli, cod) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void imprimereporte(void *clientes) {
    imprimerepfinal(clientes);
}