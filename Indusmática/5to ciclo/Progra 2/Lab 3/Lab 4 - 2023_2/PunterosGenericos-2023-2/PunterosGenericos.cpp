
/* 
 * File:   PunterosGenericos.cpp
 * Author: Usuario
 * 
 * Created on 1 de mayo de 2025, 08:19 PM
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
#include <random>
using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

#define INCREMENTO 5
#define NO_INCREMENTO -1
//Leer Productos

void cargaproductos(void *&pro) {
    ifstream arch("Productos2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << "Productos2.csv"
                << endl;
        exit(1);
    }
    void** producto, *reg;
    int nd = 0, cap = 0;
    producto = nullptr;

    while (true) {
        reg = leerRegProd(arch);
        if (arch.eof()) break;
        if (nd == cap) incrementarCap(producto, nd, cap);
        producto[nd - 1] = reg;
        nd++;
    }
    pro = producto;

    imprimeproductos(producto);
}

void incrementarCap(void **&producto, int & nd, int &cap) {
    void **aux;
    cap += INCREMENTO;
    if (producto == nullptr) {
        producto = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++) aux[i] = producto[i];
        delete producto;
        producto = aux;
    }
}

void *leerRegProd(ifstream &arch) {
    void **registro;
    char *cod, *desc, *tipo, c;
    double *precio, prec;
    cod = leerExacto(arch, 8, ',');
    if (arch.eof()) return nullptr;
    desc = leerExacto(arch, 60, ',');
    arch >> prec >> c;
    tipo = leerExacto(arch, 2, '\n');
    precio = new double{prec};
    registro = new void*[4];
    registro[0] = cod;
    registro[1] = desc;
    registro[2] = precio;
    registro[3] = tipo;

    return registro;
}

char *leerExacto(ifstream &arch, int max, char del) {
    char *cod, buff[max];
    arch.getline(buff, max, del);
    if (arch.eof()) return nullptr;
    cod = new char[strlen(buff) + 1];
    strcpy(cod, buff);
    return cod;
}

//Leer Clientes 

void cargaclientes(void *&cli) {
    ifstream arch("Clientes2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << "Productos2.csv"
                << endl;
        exit(1);
    }
    void** clientes, *reg;
    int nd = 0, cap = 0;
    clientes = nullptr;

    while (true) {
        reg = leerRegCli(arch);
        if (arch.eof()) break;
        if (nd == cap)incrementarCap(clientes, nd, cap);
        clientes[nd - 1] = reg;
        nd++;
    }
    cli = clientes;
    aumentarEspacioCliente(cli);
    imprimeclientes(cli);
}

void aumentarEspacioCliente(void *cli) {
    void**clientes = (void**) cli;
    for (int i = 0; clientes[i]; i++)
        volverCuarteta(clientes[i]);

}

void volverCuarteta(void *&cli) {
    void **aux = new void*[4] {
    },
    **cliente = (void**) cli;
    aux[0] = cliente[0];
    aux[1] = cliente[1];
    aux[3] = cliente[2];
    delete cliente;
    cli = aux;
}

void *leerRegCli(ifstream &arch) {
    void **reg;
    char*nombre;
    int dni, *codDni;
    double linea, *credito;

    arch >> dni;
    if (arch.eof()) return nullptr;
    arch.get();
    nombre = leerExacto(arch, 60, ',');
    while (arch.get() != ',');
    arch >> linea;
    codDni = new int{dni};
    credito = new double{linea};
    reg = new void*[3] {
    };
    reg[0] = codDni;
    reg[1] = nombre;
    reg[2] = credito;
    return reg;
}

//Leer Pedidos

void cargapedidos(void *pro, void *cli) {
    ifstream arch("Pedidos2.csv", ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << "Productos2.csv"
                << endl;
        exit(1);
    }

    void **productos = (void**) pro, **clientes = (void**) cli;
    int ndP[150]{}, pos_c, pos_p, dni, cant;
    char cod[8], c;
    while (true) {
        arch.getline(cod, 8, ',');
        if (arch.eof()) break;
        arch >> dni >> c >> cant;
        arch.get();
        pos_c = buscarCli(cli, dni);
        pos_p = buscarProd(pro, cod);
        if (pos_c != NO_INCREMENTO and pos_p != NO_INCREMENTO) {

            agregarPedido(productos[pos_p], clientes[pos_c], cant, ndP[pos_c]);
        }
    }
    AcotarPedidos(cli, ndP);
    imprimerepfinal(cli);
}

void AcotarPedidos(void *cli, int *ndP) {
    void **clientes = (void**) cli;
    for (int i = 0; clientes[i]; i++) {
        cortarEspacio(clientes[i], ndP[i] + 1);
    }

}

void cortarEspacio(void *cli, int nd) {
    void **cliente = (void**) cli;
    if (cliente[2] != nullptr) {
        void **pedidos = (void**) cliente[2], **auxPed = new void*[nd];
        for (int i = 0; i < nd; i++) {
            auxPed[i] = pedidos[i];
        }
        delete pedidos;
        cliente[2] = auxPed;
    }
}

void agregarPedido(void *pro, void *cli, int cant, int &ndP) {
    void **producto = (void**) pro, **cliente = (void**) cli;
    if (cliente[2] == nullptr) cliente[2] = asignarMemoria();

    double *credito = (double*) cliente[3], *precio = (double*) producto[2]
            , *monto = new double{(*precio) * cant};
    char*tipo = (char*) producto[3];

    void **pedido = (void**) cliente[2], **tripleta = new void*[3];
    int *cantidad = new int{cant};
    char*cod = (char*) producto[0];
    tripleta[0] = cod;
    tripleta[1] = cantidad;
    tripleta[2] = monto;


    if (*tipo == 'S') {
        if (*credito - (*monto) >= 0) {
            *credito -= *monto;
            pedido[ndP] = tripleta;
            ndP++;
        } else delete tripleta;
    } else {
        pedido[ndP] = tripleta;
        ndP++;
    }
}

void* asignarMemoria() {
    void **buff = new void*[300] {
    };
    return buff;
}

int buscarCli(void*cli, int dni) {
    void ** cliente = (void**) cli, **detalleCliente;
    int *codDNI;
    for (int i = 0; cliente[i]; i++) {
        detalleCliente = (void**) cliente[i];
        codDNI = (int*) detalleCliente[0];
        if (*codDNI == dni) return i;
    }
    return NO_INCREMENTO;
}

int buscarProd(void*pro, char* cod) {
    void ** producto = (void**) pro, **detalleProducto;
    char *codPro;
    for (int i = 0; producto[i]; i++) {
        detalleProducto = (void**) producto[i];
        codPro = (char*) detalleProducto[0];
        if (strcmp(codPro, cod) == 0) return i;
    }
    return NO_INCREMENTO;
}
//Imprimir Clientes

void imprimereporte(void *clientes) {

}
