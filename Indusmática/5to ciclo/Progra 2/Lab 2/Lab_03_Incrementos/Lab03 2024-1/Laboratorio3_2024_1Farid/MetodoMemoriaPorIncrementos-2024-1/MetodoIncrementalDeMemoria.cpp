
/* 
 * File:   MetodoIncrementalDeMemoria.cpp
 * Author: Usuario
 * 
 * Created on 24 de abril de 2025, 03:17 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MetodoIncrementalDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define MAX_LINE 140
// LeerLibros

void lecturaDeLibros(const char* nomArch, char***&libros, int **&stock) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);

    int nd = 0, cap = 0;

    libros = nullptr;
    stock = nullptr;

    char **registroLibros, c;
    int cantstock, *registroStock;
    double precio;
    while (true) {
        registroLibros = leerRegistroLibro(arch);
        if (arch.eof()) break;
        arch >> cantstock >> c >> precio;
        arch.get();
        registroStock = new int[2] {
        };
        if (nd == cap)
            incrementarCap(libros, stock, nd, cap);
        libros[nd - 1] = registroLibros;
        registroStock[0] = cantstock;
        stock[nd - 1] = registroStock;
        nd++;
    }

}

void incrementarCap(char ***&libro, int **&stock, int &nd, int&cap) {

    cap += INCREMENTO;

    if (libro == nullptr) {
        libro = new char**[cap] {
        };
        stock = new int*[cap] {
        };
        nd++;
    } else {
        char ***auxLibro = new char**[cap] {
        };
        int **auxStock = new int *[cap] {
        };

        for (int i = 0; libro[i]; i++) {
            auxLibro[i] = libro[i];
            auxStock[i] = stock[i];
        }

        delete libro;
        delete stock;
        libro = auxLibro;
        stock = auxStock;

    }

}

char **leerRegistroLibro(ifstream &arch) {
    char *cod, **tripleta;
    cod = leerExacto(arch, 8, ',');
    if (arch.eof()) nullptr;
    tripleta = new char*[3] {
    };
    tripleta[0] = cod;
    tripleta[1] = leerExacto(arch, 60, ',');
    tripleta[2] = leerExacto(arch, 30, ',');
    return tripleta;
}

char* leerExacto(ifstream &arch, int max, char deli) {
    char buff[max], *cod;
    arch.getline(buff, max, deli);
    if (arch.eof()) return nullptr;
    cod = new char[strlen(buff) + 1];
    strcpy(cod, buff);
    return cod;
}


//Mostrar Libros

void pruebaDeLecturaDeLibros(const char* nomArch, char ***libros, int **stock) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nomArch);

    char** tripleta;
    int* dupla;
    arch << setw(8) << left << "CODIGO" << setw(60) << "TITULO" << setw(30)
            << "AUTOR" << setw(15) << "STOCK INCIAL" << "NO ATENDIDOS" << endl;
    for (int i = 0; libros[i]; i++) {
        tripleta = libros[i];
        dupla = stock[i];
        arch << setw(8) << left << tripleta[0] << setw(60) << tripleta[1] << setw(30)
                << tripleta[2] << right << setw(7) << dupla[0] << setw(12)
                << dupla[1] << endl;
    }
}

//Leer Pedidos

void atencionDePedidos(const char* nomArch, char*** libros, int**stock, int**&pedidosClientes,
        char ***&pedidosLibros, bool**&pedidosAtendidos) {
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nomArch);

    int ndCli = 0, capCli = 0, ndPedCli[200]{}, capPedCli[200]{}, capLib = 0;

    int numPed, dni, pos_cli;
    char c;
    pedidosClientes = nullptr, pedidosLibros = nullptr;
    int i = 0;
    while (true) {
        arch >> numPed;
        i++;
        if (arch.eof()) break;
        arch >> c >> dni;
        pos_cli = buscarCliente(pedidosClientes, dni);
        if (pos_cli == NO_ENCONTRADO) {
            if (ndCli == capCli)
                incrementarCapClientes(pedidosClientes, ndCli, capCli);
            agregarCliente(pedidosClientes, ndCli, dni, pos_cli, ndPedCli, capPedCli);
        }
        agregarPedido(pedidosClientes[pos_cli], numPed, ndPedCli[pos_cli],
                capPedCli[pos_cli]);

        if (capLib <= numPed)
            incrementarCapLib(pedidosLibros, pedidosAtendidos, numPed, capLib);
        leerLibros(arch, pedidosAtendidos, pedidosLibros, numPed, libros, stock);
    }
}

void leerLibros(ifstream &arch, bool **pedidosAtendidos, char ***pedidosLibros,
        int numPed, char ***libros, int ** stock) {
    int nd = 0, cap = 0, pos_L;
    char cod[8], **auxLib;
    bool *auxAten;

    while (arch.get() != '\n') {
        arch >> cod;
        if (nd == cap)
            incrementarCapPedidos(pedidosAtendidos[numPed],
                pedidosLibros[numPed], nd, cap);
        auxAten = pedidosAtendidos[numPed];
        auxLib = pedidosLibros[numPed];
        auxLib[nd - 1] = new char[8];
        strcpy(auxLib[nd - 1], cod);
        pos_L = buscarLibro(libros, cod);
        auxAten[nd - 1] = verificarStock(stock[pos_L]);

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

int buscarLibro(char***libros, char* cod) {
    char ** auxLib;
    for (int i = 0; libros[i]; i++) {
        auxLib = libros[i];
        if (strcmp(auxLib[0], cod) == 0) return i;
    }
    return NO_ENCONTRADO;
}

void incrementarCapPedidos(bool *&pedidosAtendidos, char **&pedidosLibros,
        int &nd, int &cap) {
    char **auxLib;
    bool* auxAten;

    cap += INCREMENTO;
    if (pedidosLibros == nullptr) {
        pedidosLibros = new char*[cap] {
        };
        pedidosAtendidos = new bool[cap] {
        };
        nd++;
    } else {
        auxAten = new bool[cap] {
        };
        auxLib = new char *[cap] {
        };
        for (int i = 0; i < nd; i++) {
            auxAten[i] = pedidosAtendidos[i];
            auxLib[i] = pedidosLibros[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        pedidosAtendidos = auxAten;
        pedidosLibros = auxLib;
    }

}

void incrementarCapLib(char ***&pedidosLibros, bool **&pedidosAtendidos,
        int numPed, int &capPedLib) {
    char ***auxLibro;
    bool **auxAtendido;

    if (pedidosLibros == nullptr) {
        pedidosAtendidos = new bool*[numPed + INCREMENTO] {
        };
        pedidosLibros = new char **[numPed + INCREMENTO] {
        };
    } else {
        auxLibro = new char**[numPed + INCREMENTO] {
        };
        auxAtendido = new bool*[numPed + INCREMENTO] {
        };
        for (int i = 0; i < capPedLib; i++) {
            auxAtendido[i] = pedidosAtendidos[i];
            auxLibro[i] = pedidosLibros[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        pedidosAtendidos = auxAtendido;
        pedidosLibros = auxLibro;
    }
    capPedLib = numPed + INCREMENTO;
}

void agregarPedido(int *&pedidosClientes, int numPed, int &ndPedCli, int &capPedCli) {
    if (ndPedCli == capPedCli)
        incrementarPedCli(pedidosClientes, ndPedCli, capPedCli);
    pedidosClientes[ndPedCli] = numPed;
    pedidosClientes[1]++;
    ndPedCli++;

}

void agregarCliente(int **pedidosClientes, int &ndCli, int dni, int &pos_cli,
        int *ndPedCli, int *capPedCli) {
    incrementarPedCli(pedidosClientes[ndCli - 1], ndPedCli[ndCli - 1],
            capPedCli[ndCli - 1]);
    int *auxcli = pedidosClientes[ndCli - 1];
    auxcli[0] = dni;
    pos_cli = ndCli - 1;
    ndCli++;
}

void incrementarPedCli(int *&pedidosClientes, int &ndPedCli,
        int &capPedCli) {
    capPedCli += INCREMENTO;
    int *auxCli;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int[capPedCli] {
        };
        ndPedCli += 2;
    } else {
        auxCli = new int[capPedCli] {
        };
        for (int i = 0; i < ndPedCli; i++) auxCli[i] = pedidosClientes[i];
        delete pedidosClientes;
        pedidosClientes = auxCli;
    }
}

void incrementarCapClientes(int **&pedidosClientes, int &ndCli, int &capCli) {
    int ** auxCli;
    capCli += INCREMENTO;
    if (pedidosClientes == nullptr) {
        pedidosClientes = new int*[capCli] {
        };
        ndCli++;
    } else {
        auxCli = new int*[capCli] {
        };
        for (int i = 0; pedidosClientes[i]; i++) auxCli[i] = pedidosClientes[i];
        delete pedidosClientes;
        pedidosClientes = auxCli;
    }
}

int buscarCliente(int **pedidosClientes, int dni) {
    if (pedidosClientes != nullptr) {
        int *auxCli;
        for (int i = 0; pedidosClientes[i]; i++) {
            auxCli = pedidosClientes[i];
            if (auxCli[0] == dni) return i;
        }
    }
    return NO_ENCONTRADO;
}

//OrdenarPedidos

void ordenarPedidosClientes(int **pedidosClientes) {

    int contar = contarClientes(pedidosClientes);
    qSort(pedidosClientes, 0, contar-1);
}

void qSort(int **datos, int izq, int der) {
    int lim, pos;
    if (izq >= der) return;
    pos = (izq + der) / 2;
    cambiar(datos[izq], datos[pos]);
    lim = izq;
    int *auxIzq = datos[izq], * auxI;
    for (int i = izq + 1; i < der + 1; i++) {
        auxI = datos[i];
        if (auxI[1] > auxIzq[1] or
                (auxI[1] == auxIzq[1] and auxI[0] < auxIzq[0])) {
            lim ++;
            cambiar(datos[lim], datos[i]);
        }
    }
    cambiar(datos[lim], datos[izq]);
    qSort(datos, izq, lim-1);
    qSort(datos, lim+1, der);
    

}

void cambiar(int *&datoI, int*&datoJ) {
    int *aux;

    aux = datoI;
    datoI = datoJ;
    datoJ = aux;
}

int contarClientes(int **pedidosClientes) {
    int i;
    for (i = 0; pedidosClientes[i]; i++);
        return i;
}


//ReporteDePedidos

void reporteDeEntregaDePedidos(const char* nomArch, int** pedidosClientes,
        char ***pedidosLibros, bool** pedidosAtendidos) {
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nomArch);

    int * auxCli;

    arch << setw(60) << "REPORTE TOP 5" << endl << setw(65) << "ATENCION DE PEDIDOS"
            << endl;
    int numPed;
    for (int i = 0; pedidosClientes[i]; i++) {
        auxCli = pedidosClientes[i];

        mostrarLinea(arch, '=');
        arch << setw(10) << left << "CLIENTE:" << setw(40) << auxCli[0]
                << setw(20) << "CANTIDAD PEDIDOS:" << auxCli[1] << endl;
        mostrarLinea(arch, '=');

        for (int j = 2; j < auxCli[1] + 2; j++) {
            numPed = auxCli[j];
            imprimirPedidos(arch, numPed, pedidosAtendidos[numPed],
                    pedidosLibros[numPed]);

        }


    }

}

void imprimirPedidos(ofstream &arch, int numPed, bool *pedidosAtendidos,
        char **pedidosLibros) {

    arch << setw(7) << ' ' << setw(15) << "Pedido No." << setw(25) << "Codigo del libro"
            << "Observacion" << endl;
    mostrarLinea(arch, '-');
    arch << setw(7) << ' ' << setw(6) << right << setfill('0') << numPed
            << setw(10) << setfill(' ') << ' ';
    if (pedidosLibros != nullptr) {
        for (int i = 0; pedidosLibros[i]; i++) {
            if (i != 0) arch << setw(23) << ' ';
            arch << setw(24) << left << pedidosLibros[i];
            if (pedidosAtendidos[i]) {
                arch << "ATENDIDO" << endl;
            } else arch << "NO ATENDIDO" << endl;
        }
    } else arch << "NO TIENE PEDIDOS" << endl;
    mostrarLinea(arch, '-');

}

void mostrarLinea(ofstream &arch, char c) {
    for (int i = 0; i < MAX_LINE; i++) {
        arch << c;
    }
    arch << endl;
}



