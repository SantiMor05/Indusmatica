/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAux.cpp
 * Author: kenyi
 * 
 * Created on 1 de mayo de 2025, 11:27 AM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;
#include "enums.h"
#include "pruebas.h"
#include "FuncionesAux.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void cargarInventario(const char*nombArch, void *&inv) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }

    void**inventario, *reg;
    int nd = 0, cap = 0;
    inventario = nullptr;
    while (true) {
        reg = leerRegistro(arch);
        if (arch.eof())break;
        if (nd == cap)incrementarEspacios(inventario, nd, cap);
        inventario[nd - 1] = reg;
        nd++;
    }
    inv = inventario;
}

void incrementarEspacios(void **&pt, int &nd, int &cap) {
    void **aux;
    cap += INCREMENTO;
    if (pt == nullptr) {
        pt = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++)
            aux[i] = pt[i];
        delete pt;
        pt = aux;
    }
}

void *leerRegistro(ifstream &arch) {
    void **registro;
    char *cod, c;
    double *cant;
    cod = leerExacto(arch, 5, ',');
    if (arch.eof())return nullptr;
    registro = new void*[invNumCampos] {
    };

    registro[invCodigo] = cod;
    registro[invNombre] = leerExacto(arch, 20, ',');

    cant = new double;
    arch >> *cant >> c;

    registro[invCantDisponible] = cant;
    registro[invCantRequerida] = new double{0.0};
    registro[invUnidadMedida] = leerExacto(arch, 3, '\n');

    return registro;
}

char *leerExacto(ifstream &arch, int max, char del) {
    char buff[max], *cad;
    arch.getline(buff, max, del);
    if (arch.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void cargarMenu(const char*nombArch, void *&men) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    void **menu, *reg;
    menu = nullptr;
    int nd = 0, cap = 0;
    while (true) {
        reg = leerRegMenu(arch);
        if (arch.eof())break;
        if (nd == cap)incrementarEspacios(menu, nd, cap);
        menu[nd - 1] = reg;
        nd++;
    }
    men = menu;

}

void reporte(const char *nombArch, void *men) {
    void **menu = (void **) men;

    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    arch << "============================= Menú del día ==============="
            "=======================" << endl;
    void **aux;
    arch.precision(2);
    arch << fixed;
    for (int i = 0; menu[i]; i++) {
        imprimirReg(menu[i], arch);
    }
}

void imprimirReg(void *menu, ofstream &arch) {
    void **beb = (void **) menu;

    char*cod, *nom, *des, *tipo;
    bool *disp;
    double *precio;
    int *cant;

    cod = (char *) beb[bebCodigo];
    nom = (char *) beb[bebNombre];
    des = (char *) beb[bebDescripcion];
    tipo = (char *) beb[bebTipo];
    disp = (bool *)beb[bebDisponible];
    precio = (double *) beb[bebPrecio];
    cant = (int *) beb[bebCantVent];
    if (*disp) {
        if (*tipo == 'C') arch << "Cafe: ";
        else if (*tipo == 'T') arch << "Te: ";
        else if (*tipo == 'I') arch << "Infusion: ";
        else arch << "Chocolate: ";
        arch << nom << endl << des << endl << "Precio: S/ " << *precio << endl;
//        arch << "Cantidad esperada: " << *cant << endl;
        if (*disp)arch << "Disponible: Si" << endl;
        else arch << "Disponible: No" << endl;
        arch << "================================================================"
                "================" << endl;
    }
}

void *leerRegMenu(ifstream & arch) {
    void **reg;
    char *cod, c;
    double *precio;
    int *cant;
    cod = leerExacto(arch, 5, ',');
    if (arch.eof())return nullptr;
    reg = new void*[bebNumCampos];

    reg[bebCodigo] = cod;
    reg[bebNombre] = leerExacto(arch, 40, ',');
    reg[bebDescripcion] = leerExacto(arch, 200, ',');
    reg[bebTipo] = leerExacto(arch, 2, ',');
    reg[bebDisponible] = new bool{true};
    precio = new double;
    cant = new int;
    arch>>*precio >> c>>*cant;
    arch.get();
    reg[bebPrecio] = precio;
    reg[bebCantVent] = cant;
    reg[bebInsumoInv] = nullptr;

    return reg;
}

void actualizarMenu(const char*nombArch, void *inventario, void *&menu) {

    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error el abrir el archivo " << nombArch;
        exit(1);
    }
    void **regInv = (void**) inventario, **regMen = (void **) menu;
    char*codBeb, *codInv, *uni, c;
    int ndIns[25]{}, cpIns[25]{}, posI, posM;
    double *cantidad = new double;
    while (true) {
        codBeb = leerExacto(arch, 5, ',');
        if (arch.eof())break;
        codInv = leerExacto(arch, 5, ',');
        arch>>*cantidad>>c;
        uni = leerExacto(arch, 2, '\n');
        posI = buscar(regInv, codInv);
        posM = buscar(regMen, codBeb);

        if (posI != NO_ENCONTRADO and posM != NO_ENCONTRADO) {
            verificarDisponible(regInv[posI], regMen[posM],
                    cantidad, uni, ndIns[posM], cpIns[posM]);
        }
    }
}

void verificarDisponible(void *inv, void *men, double*cantidad,
        char *uni, int& ndIns, int &cpIns) {
    void **menu = (void **) men;
    void **inventario = (void **) inv;
    void **insumo = (void **) menu[bebInsumoInv], **pedido = new void*[3] {
    };
    double *cantidadReq = new double;
    int *cantVenta = (int*) menu[bebCantVent];
    * cantidadReq = *cantidad * *cantVenta;
    if (*uni == 'g') *cantidadReq = *cantidadReq * (double) 1 / 1000;

    if (ndIns == cpIns) {
        incrementarEspacios(insumo, ndIns, cpIns);
        menu[bebInsumoInv] = insumo;
    }
    pedido[0] = inv;
    pedido[1] = cantidad;
    pedido[2] = uni;
    insumo[ndIns - 1] = pedido;
    ndIns++;
    bool *disponible = (bool *)menu[bebDisponible];
    double *reqInv = (double *) inventario[invCantRequerida]
            , *disInv = (double *) inventario[invCantDisponible];
    *reqInv += *cantidadReq;
    if (*reqInv >= *disInv) *disponible = false;
}

int buscar(void **reg, char *cod) {
    void **detalles;
    char *codigo;
    for (int i = 0; reg[i]; i++) {
        detalles = (void**) reg[i];
        codigo = (char *) detalles[0];
        if (strcmp(cod, codigo) == 0)return i;
    }
    return NO_ENCONTRADO;
}

