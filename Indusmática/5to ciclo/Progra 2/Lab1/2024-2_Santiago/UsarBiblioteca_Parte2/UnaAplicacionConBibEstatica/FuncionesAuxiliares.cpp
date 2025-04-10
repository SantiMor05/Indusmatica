#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "FuncionesAuxiliares.h"
#include "FuncionesSobrecargadas.h"
#include "Estructuras.h"
using namespace std;

#define MAX_CAR_PLAT 90
#define MAX_CAR_REP 100

void leerPlatos(struct Plato *platos, int &nPlatos) {
    nPlatos = 0;
    ifstream archPlatos;

    AperturaDeUnArchivoDeTextosParaLeer(archPlatos, "PlatosOfrecidos.csv");

    while (true) {
        archPlatos >> platos[nPlatos];
        if (archPlatos.eof())break;
        nPlatos++;
    }
    strcpy(platos[nPlatos].codigo, "FIN");
    nPlatos++;

}

void leerPedidos(struct Pedido *pedidos, int &nPedidos) {

    ifstream archOrdenes;
    AperturaDeUnArchivoDeTextosParaLeer(archOrdenes, "OrdenesDeCompra.txt");

    nPedidos = 0;

    while (true) {
        archOrdenes >> pedidos[nPedidos];
        if (archOrdenes.eof())break;
        nPedidos++;
    }
}

void leerRepartidores(struct Repartidor *repartidores, int &nRepar) {

    ifstream archRepar;
    AperturaDeUnArchivoDeTextosParaLeer(archRepar, "RepartidoresContratados.csv");

    nRepar = 0;

    while (true) {
        archRepar >> repartidores[nRepar];
        if (archRepar.eof())break;
        nRepar++;
    }
    strcpy(repartidores[nRepar].codigo, "FIN");
    nRepar++;

}

void imprimirReportePlatos(struct Plato *platos, int nPlatos) {

    ofstream outPlatos;
    AperturaDeUnArchivoDeTextosParaEscribir(outPlatos,
            "ReportePlatos.txt");

    outPlatos << setprecision(2) << fixed;
    outPlatos << "PLATOS OFRECIDOS" << endl;
    imprimirCaracter('-', MAX_CAR_PLAT, outPlatos);

    outPlatos << "Codigo" << setw(12) << "Nombre" << setw(56) << "Precio" <<
            setw(10) << "Pedidos" << setw(10) << "Recaudado" << endl;
    imprimirCaracter('=', MAX_CAR_PLAT, outPlatos);

    for (int i = 0; i < nPlatos; i++)
        outPlatos << platos[i];
}

void imprimirReporteRepartidores(struct Repartidor *repartidores, int nRepar) {

    ofstream outRepar;

    AperturaDeUnArchivoDeTextosParaEscribir(outRepar,
            "ReporteRepartidores.txt");
    
    outRepar << setprecision(2) << fixed;
    outRepar << "REPARTIDORES" << endl;
    imprimirCaracter('-', MAX_CAR_REP, outRepar);
    
    outRepar << "Codigo" << setw(12) << "Nombre" << setw(46) << "Vehiculo" <<
            setw(16) <<"Pago envios" << endl;
    imprimirCaracter('=', MAX_CAR_REP, outRepar);

    for (int i = 0; i < nRepar; i++) {
        outRepar << repartidores[i];
    }
    
}

void imprimirCaracter(char car, int n, ofstream &outPlatos) {
    for (int i = 0; i < n; i++)
        outPlatos.put(car);
    outPlatos << endl;

}
