/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoIncremetalDeMemoria.cpp
 * Author: kenyi
 * 
 * Created on 24 de abril de 2025, 04:18 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
#include "MetodoIncremetalDeMemoria.h"
#include "AperturaDeArchivos.h"
#define MAX_LINE 120
#define INCREMENTO 5
#define NO_ENCONTRADO -1
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
//YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02

void lecturaDeLibros(const char*nombArch, char ***&libros, int **&stock) {
    ifstream archLibros;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, nombArch);

    libros = nullptr;
    stock = nullptr;

    int *regStock, nd = 0, cap = 0;
    double precio;
    char **regLib, c;
    while (true) {
        regLib = leerLibro(archLibros);
        if (archLibros.eof())break;
        regStock = leerStock(archLibros);
        if (nd == cap) {
            aumentarEspacioLibro(libros, stock, nd, cap);
        }
        libros[nd - 1] = regLib;
        stock[nd - 1] = regStock;
        nd++;
    }
}

void aumentarEspacioLibro(char ***&libros, int **&stock, int &nd, int &cap) {
    char ***auxLib;
    int **auxStock;
    cap += INCREMENTO;
    if (libros == nullptr) {
        libros = new char **[cap] {
        };
        stock = new int *[cap] {
        };
        nd = 1;
    } else {
        auxLib = new char **[cap] {
        };
        auxStock = new int *[cap] {
        };
        for (int i = 0; i < nd; i++) {
            auxLib[i] = libros[i];
            auxStock[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxLib;
        stock = auxStock;
    }
}

int *leerStock(ifstream &archLibros) {
    int *stock, cant;
    char c;
    double precio;
    archLibros >> cant >> c>>precio;
    archLibros.get();
    stock = new int[2] {
    };
    stock[0] = cant;
    return stock;
}

char **leerLibro(ifstream &archLibros) {
    char **tripleta, *cod, *desc, *aut;
    cod = leeExacto(archLibros, 8, ',');
    if (archLibros.eof())return nullptr;
    desc = leeExacto(archLibros, 80, ',');
    aut = leeExacto(archLibros, 40, ',');
    tripleta = new char*[3];
    tripleta[0] = cod;
    tripleta[1] = desc;
    tripleta[2] = aut;

    return tripleta;
}

char *leeExacto(ifstream &archLibros, int max, char del) {
    char buff[max], *cad;
    archLibros.getline(buff, max, del);
    if (archLibros.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros, int **stock) {
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep, nombArch);

    char **auxLib;
    int *auxStock;
    for (int i = 0; libros[i]; i++) {
        auxLib = libros[i];
        auxStock = stock[i];
        archRep << left << setw(20) << auxLib[0] << setw(60)
                << auxLib[1] << setw(40) << auxLib[2] << right <<
                setw(16) << auxStock[0] << setw(16) << auxStock[1] << endl;
    }
}
//000059,34460612   CRY6839    VYG3594

void atencionDePedidos(const char*nombArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool**&pedidosAtendidos) {

    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed, nombArch);
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;
    int numCli = 0, capCli = 0, numPedCli[200]{}, capPedCli[200]{},
    numPedLibro, capPedLibro, numLibro = 0, capLib = 0;
    int numPed, dni, posC;
    while (true) {
        archPed>>numPed;
        if (archPed.eof())break;
        archPed.get();
        archPed>>dni;
        posC = buscarDni(pedidosClientes, dni);
        if (posC == NO_ENCONTRADO) {
            if (numCli == capCli) {
                aumentarEspacioCliente(pedidosClientes, numCli, capCli);
            }
            agregarCliente(pedidosClientes, numCli, posC, dni, numPedCli, capPedCli);
        }
        agregarPedido(pedidosClientes[posC], numPed, numPedCli[posC], capPedCli[posC]);
        leerPedidos(pedidosLibros, pedidosAtendidos, numLibro, archPed, numPed,
                capLib, stock, libros);
    }


}

void leerPedidos(char ***&pedidosLibros, bool **&pedidosAtendidos,
        int &numLibro, ifstream &archPed, int numPed, int &capLib,
        int **stock, char ***libros) {
    char cod[8]{};
    int posL;
    if (capLib < numPed) {
        aumentarEspacioPedidos(pedidosLibros, pedidosAtendidos, capLib, numPed);
    }
    int cap = 0, nd = 0;
    char **auxLib;
    bool *auxAten;
    while (archPed.get() != '\n') {
        archPed>>cod;
        if (nd == cap) {
            aumentarEspacioPedidosInterno(pedidosLibros[numPed],
                    pedidosAtendidos[numPed], nd, cap);
        }
        auxLib = pedidosLibros[numPed];
        auxAten = pedidosAtendidos[numPed];
        posL = buscarLibro(libros, cod);
        auxAten[nd - 1] = verificarStock(stock[posL]);

        auxLib[nd - 1] = new char[8];
        strcpy(auxLib[nd - 1], cod);
        nd++;
    }
}

bool verificarStock(int *stock) {
    if (stock[0] > 0) {
        stock[0]--;
        return true;
    } else {
        stock[1]++;
        return false;
    }
}

int buscarLibro(char ***libro, char *cod) {
    char **auxLib;
    for (int i = 0; libro[i]; i++) {
        auxLib = libro[i];
        if (strcmp(auxLib[0], cod) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void aumentarEspacioPedidosInterno(char **&pedidosLibros,
        bool *&pedidosAtendidos, int &nd, int &cap) {
    char **auxLib;
    bool *auxAten;
    cap += INCREMENTO;
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char *[cap] {
        };
        pedidosAtendidos = new bool [cap] {
        };
        nd = 1;
    } else {
        auxLib = new char *[cap] {
        };
        auxAten = new bool [cap] {
        };

        for (int i = 0; i < nd; i++) {
            auxLib[i] = pedidosLibros[i];
            auxAten[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxLib;
        pedidosAtendidos = auxAten;
    }
}

void aumentarEspacioPedidos(char ***&pedidosLibros, bool **&pedidosAtendidos,
        int &capLib, int numLibro) {
    char ***auxLib;
    bool **auxAten;
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char **[numLibro + INCREMENTO] {
        };
        pedidosAtendidos = new bool *[numLibro + INCREMENTO] {
        };
    } else {
        auxLib = new char **[numLibro + INCREMENTO] {
        };
        auxAten = new bool *[numLibro + INCREMENTO] {
        };

        for (int i = 0; i < capLib; i++) {
            auxLib[i] = pedidosLibros[i];
            auxAten[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxLib;
        pedidosAtendidos = auxAten;
    }
    capLib = numLibro + INCREMENTO;
}

void agregarPedido(int *&pedidosClientes, int numPed, int &numPedCli, int &capPedCli) {
    if (numPedCli == capPedCli) {
        incrementarEspacioClienteInterno(pedidosClientes, capPedCli, numPedCli);
    }
    pedidosClientes[pedidosClientes[1] + 2] = numPed;
    pedidosClientes[1]++;
    numPedCli++;
}

void agregarCliente(int **pedidosClientes, int &numCli, int &posC, int dni,
        int *numPedCli, int *capPedCli) {
    incrementarEspacioClienteInterno(pedidosClientes[numCli - 1],
            capPedCli[numCli - 1], numPedCli[numCli - 1]);
    int *auxCli = pedidosClientes[numCli - 1];
    auxCli[0] = dni;
    posC = numCli - 1;
    numCli++;
}

void incrementarEspacioClienteInterno(int *&pedidosClientes,
        int &capPedCli, int &numPedCli) {
    int *auxPed;
    capPedCli += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int[capPedCli] {
        };
        numPedCli = 2;
    } else {
        auxPed = new int[capPedCli] {
        };
        for (int i = 0; i < numPedCli; i++) {
            auxPed[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPed;
    }
}

void aumentarEspacioCliente(int **&pedidosClientes, int &numCli, int &capPedCli) {
    int **auxCli;
    capPedCli += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int*[capPedCli] {
        };
        numCli = 1;
    } else {
        auxCli = new int*[capPedCli] {
        };
        for (int i = 0; i < numCli; i++) {
            auxCli[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxCli;
    }
}

int buscarDni(int **pedidosClientes, int dni) {
    int *auxCli;
    if (pedidosClientes != nullptr) {
        for (int i = 0; pedidosClientes[i]; i++) {
            auxCli = pedidosClientes[i];
            if (auxCli[0] == dni)return i;
        }
    }
    return NO_ENCONTRADO;
}

void ordenarPedidosClientes(int **&pedidosClientes) {

}

void reporteDeEntregaDePedidos(const char*nombArch, int **pedidosClientes,
        char ***pedidosLibros, bool**pedidosAtendidos) {
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep, nombArch);
    int cantPed;
    archRep << setw(MAX_LINE / 2) << "Reporte de mis huevos" << endl;
    imprimirLinea(MAX_LINE, '=', archRep);
    int *auxCli;
    for (int i = 0; pedidosClientes[i]; i++) {
        auxCli = pedidosClientes[i];
        cantPed = auxCli[1];
        archRep << "CLIENTE: " << auxCli[0] << setw(40)
                << "CANTIDAD DE PEDIDOS: " << cantPed << endl;
        imprimirLinea(MAX_LINE, '=', archRep);
        for (int j = 2; j < cantPed + 2; j++) {
            archRep << auxCli[j] << setw(12) << " " ;
            imprimirPedidos(pedidosAtendidos[auxCli[j]],
                    pedidosLibros[auxCli[j]], archRep);
        }
        imprimirLinea(MAX_LINE, '=', archRep);
    }
}

void imprimirPedidos(bool *pedidosAtendidos, char **pedidosLibros,
        ofstream &archRep) {
    if (pedidosAtendidos == nullptr) {
        archRep << "NO TIENE PEDIDOS" << endl;
        return;
    }
    for (int i = 0; pedidosLibros[i]; i++) {
        if (i != 0) archRep << setw(14) << " ";
        archRep << pedidosLibros[i] << setw(12) << " ";
        if (pedidosAtendidos[i]) {
            archRep << "SE ATENDIO" << endl;
        } else archRep << "NO SE ATENDIO" << endl;
    }
}

void imprimirLinea(int n, char c, ofstream &archRep) {
    for (int i = 0; i < n; i++)archRep.put(c);
    archRep << endl;
}
