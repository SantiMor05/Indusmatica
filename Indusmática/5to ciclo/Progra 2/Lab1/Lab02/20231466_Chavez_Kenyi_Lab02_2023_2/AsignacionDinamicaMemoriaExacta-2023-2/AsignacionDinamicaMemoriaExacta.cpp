/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: kenyi
 * 
 * Created on 18 de abril de 2025, 08:02 PM
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
#define NO_ENCONTRADO -1
#define MAX_LINE 160
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

//BIT-434,Campana Extractora modelo Glass,375.09,10
//SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23

void lecturaDeProductos(const char*nombArch, char ***&productos, int *&stock,
        double *&precios) {
    char **buffProd[200]{};
    int buffStock[200]{};
    double buffPrecio[200]{};

    ifstream archProd(nombArch, ios::in);
    if (not archProd.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }

    int nd = 0;

    while (true) {
        buffProd[nd] = leerProd(archProd);
        if (archProd.eof())break;
        archProd >> buffPrecio[nd];
        archProd.get();
        archProd >> buffStock[nd];
        archProd.get();
        nd++;
    }
    nd++;
    productos = new char**[nd];
    stock = new int[nd];
    precios = new double[nd];
    for (int i = 0; i < nd; i++) {
        productos[i] = buffProd[i];
        stock[i] = buffStock[i];
        precios[i] = buffPrecio[i];
    }

}

char **leerProd(ifstream &archProd) {
    char **prod, *cod, *desc;
    cod = leerCadenaExacto(archProd, 8, ',');
    if (archProd.eof())return nullptr;
    desc = leerCadenaExacto(archProd, 60, ',');

    prod = new char*[2];

    prod[0] = cod;
    prod[1] = desc;
    return prod;
}

char *leerCadenaExacto(ifstream &archProd, int max, char del) {
    char buff[max], *cad;
    archProd.getline(buff, max, del);
    if (archProd.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void pruebaDeLecturaDeProductos(const char*nombArch, char ***productos,
        int *stock, double *precios) {
    ofstream archRep(nombArch, ios::out);
    if (not archRep.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    archRep.precision(2);
    archRep << fixed;

    for (int i = 0; productos[i]; i++) {
        imprimirProd(archRep, productos[i]);
        archRep << setw(12) << stock[i] << setw(12) << precios[i] << endl;
    }

}

void imprimirProd(ofstream &archRep, char **prod) {
    archRep << left << setw(12) << prod[0] << setw(40) << prod[1] << right;
}

//JXD-139,50375303,6,24/08/2023
//CRU-009,50375303,5,3/09/2023

void lecturaDePedidos(const char*nombArch, int *&fechaPedidos,
        char ***&codigoPedidos, int ***&dniCantPedidos) {
    char **buffCodPed[600]{};
    int **buffDni[600]{}, buffFecha[600]{};

    ifstream archPed(nombArch, ios::in);
    if (not archPed.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    char *codProd, c;
    int dni, cant, dd, mm, aa, fecha, posF, cantF = 0, cantPorPed[600]{};
    while (true) {
        codProd = leerCadenaExacto(archPed, 8, ',');
        if (archPed.eof())break;
        archPed >> dni >> c >> cant >> c >> dd >> c >> mm >> c >> aa;
        archPed.get();
        fecha = juntarFecha(dd, mm, aa);
        posF = buscarFecha(buffFecha, fecha, cantF);
        if (posF == NO_ENCONTRADO) {
            agregarDato(buffFecha[cantF], buffCodPed[cantF], buffDni[cantF], fecha,
                    cantF, posF);
        }
        insertarPedido(buffCodPed[posF], buffDni[posF], dni
                , cant, codProd, cantPorPed[posF]);
    }
    cargarArreglos(fechaPedidos, codigoPedidos, dniCantPedidos, buffFecha,
            buffCodPed, buffDni, cantF, cantPorPed);
}

void cargarArreglos(int *&fechaPedidos, char ***&codigoPedidos,
        int ***&dniCantPedidos, int *buffFecha, char ***buffCodPed,
        int ***buffDni, int &cantF, int *cantPorPed) {
    cantF++;
    fechaPedidos = new int[cantF];
    codigoPedidos = new char**[cantF];
    dniCantPedidos = new int**[cantF];

    for (int i = 0; i < cantF; i++) {
        fechaPedidos[i] = buffFecha[i];
        if (fechaPedidos[i]) {
            codigoPedidos[i] = new char*[cantPorPed[i] + 1];
            dniCantPedidos[i] = new int*[cantPorPed[i] + 1];
            cargarCodYDni(codigoPedidos[i], dniCantPedidos[i], buffCodPed[i],
                    buffDni[i], cantPorPed[i] + 1);
        }
        else{
             codigoPedidos[i] = nullptr;
             dniCantPedidos[i] = nullptr;
        }
        delete buffCodPed[i];
        delete buffDni[i];
    }
}

void cargarCodYDni(char **codigoPedidos, int **dniCantPedidos, char **buffCodPed,
        int **buffDni, int cant) {
    for (int i = 0; i < cant; i++) {
        codigoPedidos[i] = buffCodPed[i];
        dniCantPedidos[i] = buffDni[i];
    }
}

void insertarPedido(char **buffCodPed, int **buffDni, int dni, int cant,
        char *codProd, int &cantPorPed) {
    buffCodPed[cantPorPed] = codProd;
    int *dupla = new int[2];
    dupla[0] = dni;
    dupla[1] = cant;
    buffDni[cantPorPed] = dupla;
    cantPorPed++;
}

void agregarDato(int &buffFecha, char **&buffCodPed, int **&buffDni, int fecha,
        int &cantF, int &posF) {
    buffFecha = fecha;
    buffCodPed = new char*[600] {
    };
    buffDni = new int*[600] {
    };
    posF = cantF;
    cantF++;
}

int buscarFecha(int *buffFecha, int fecha, int cantF) {
    for (int i = 0; i < cantF; i++) {
        if (buffFecha[i] == fecha)return i;
    }
    return NO_ENCONTRADO;
}

int juntarFecha(int dd, int mm, int aa) {
    return aa * 10000 + mm * 100 + dd;
}

void pruebaDeLecturaDePedidos(const char*nombArch, int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream archRep(nombArch, ios::out);
    if (not archRep.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }

    for (int i = 0; fechaPedidos[i]; i++) {
        archRep << "FECHA: ";
        imprimirFecha(archRep, fechaPedidos[i]);
        imprimirPruebaPorFecha(archRep, codigoPedidos[i], dniCantPedidos[i]);
    }
}

void imprimirPruebaPorFecha(ofstream &archRep,
        char **codigoPedidos, int **dniCantPedidos) {
    for (int i = 0; codigoPedidos[i]; i++) {
        int *aux = dniCantPedidos[i];
        archRep << i + 1 << ").  " << codigoPedidos[i]
                << " " << aux[0] << " " << aux[1] << endl;
    }
}

void reporteDeEnvioDePedidos(const char*nombArch, char ***productos,
        int *stock, double *precios, int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos) {
    ofstream archRep(nombArch, ios::out);
    if (not archRep.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    
    double totalIng,totalPer;
    archRep.precision(2);
    archRep<<fixed;
    imprimirTitulo(archRep);
    for (int i = 0; fechaPedidos[i]; i++) {
        totalIng=0.0;
        totalPer=0.0;
        archRep << "FECHA:  ";
        imprimirFecha(archRep, fechaPedidos[i]);
        imprimirLinea(archRep, MAX_LINE, '=');
        archRep << "No. DNI" << setw(30) << "Producto" << setw(70)
                << "Cantidad" << setw(15) << "Precio" << setw(20)
                << "Total de ingresos" << endl;
        imprimirLinea(archRep, MAX_LINE, '-');
        imprimirDetalles(archRep, codigoPedidos[i], dniCantPedidos[i],
                productos, precios, stock,totalIng,totalPer);
        imprimirLinea(archRep, MAX_LINE, '=');
        archRep<<"Total ingresado:"<<setw(121)<<totalIng<<endl;
        archRep<<"Total perdido por falta de stock:"<<setw(104)<<totalPer<<endl;
        imprimirLinea(archRep, MAX_LINE, '=');
    }
}

void imprimirDetalles(ofstream &archRep, char **codigoPedidos,
        int **dniCantPedidos, char ***productos, double *precios,
        int *stock,double &totalIng,double &totalPer) {
    int posP;
    char **dupla;
    for (int i = 0; dniCantPedidos[i]; i++) {
        int *aux = dniCantPedidos[i];
        posP = buscarProducto(codigoPedidos[i], productos);
        if (posP) {
            dupla = productos[posP];
            archRep << setw(2) << i + 1 << ")" << setw(10) << aux[0] 
                    << setw(16) << dupla[0] << "  "
                    << left << setw(60) << dupla[1] << right << setw(13)
                    << aux[1] << setw(18) << precios[posP];
            if(aux[1]<=stock[posP]){
                archRep<<setw(16)<<precios[posP]*aux[1]<<endl;
                stock[posP]-=aux[1];
                totalIng+=precios[posP]*aux[1];
            }
            else{
                archRep<<setw(20)<<"SIN STOCK"<<endl;
                totalPer+=precios[posP]*aux[1];
            }
        }
    }
}

int buscarProducto(char *codigoPedidos, char ***productos) {
    char **dupla;
    for (int i = 0; productos[i]; i++) {
        dupla = productos[i];
        if (strcmp(dupla[0], codigoPedidos) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void imprimirTitulo(ofstream &archRep) {
    archRep << setw(MAX_LINE / 2) << "REPORTE DE ENTREGA DE PEDIDOS" << endl;
    imprimirLinea(archRep, MAX_LINE, '=');
}

void imprimirFecha(ofstream &archRep, int fecha) {
    int dd, mm, aa;
    aa = fecha / 10000;
    dd = fecha % 100;
    mm = (fecha % 10000) / 100;
    archRep << setw(2) << setfill('0') << dd << "/"
            << setw(2) << mm << "/" << setw(4) << aa
            << setfill(' ') << endl;
}

void imprimirLinea(ofstream &archRep, int n, char c) {
    for (int i = 0; i < n; i++)archRep.put(c);
    archRep << endl;
}