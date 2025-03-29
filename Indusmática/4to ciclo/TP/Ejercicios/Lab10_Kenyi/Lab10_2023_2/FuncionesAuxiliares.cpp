/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Articulo.h"
#include "Vendedor.h"
#include "FuncionesAuxiliares.h"
using namespace std;
#define NO_ENCONTRADO -1
#define MAX_LINE 130

void leerArticulosBin(const char*nombArch, const char*nombArchBin) {
    ifstream archArticulo(nombArch, ios::in);
    if (not archArticulo.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    ofstream archArticuloBin(nombArchBin, ios::out | ios::binary);
    if (not archArticuloBin.is_open()) {
        cout << "Error al abrir el archivo " << nombArchBin;
        exit(1);
    }

    struct Articulo articulo {
    };

    while (true) {
        leerArticulo(articulo, archArticulo);
        if (archArticulo.eof())break;
        archArticuloBin.write(reinterpret_cast<const char*> (&articulo),
                sizeof (struct Articulo));
    }

}

void leerArticulo(struct Articulo &articulo, ifstream &archArticulo) {
    archArticulo.getline(articulo.codigo, 10, ',');
    if (archArticulo.eof())return;
    archArticulo.getline(articulo.descripcion, 60, ',');
    archArticulo >> articulo.precio;
    archArticulo.get();
}

void leerVendedoresBin(const char*nombArch, const char*nombArchBin) {
    ifstream archVendedores(nombArch, ios::in);
    if (not archVendedores.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    ofstream archVendedoresBin(nombArchBin, ios::out | ios::binary);
    if (not archVendedoresBin.is_open()) {
        cout << "Error al abrir el archivo " << nombArchBin;
        exit(1);
    }

    struct Vendedor vendedor {
    };

    while (true) {
        leerVendedores(vendedor, archVendedores);
        if (archVendedores.eof())break;
        archVendedoresBin.write(reinterpret_cast<const char*> (&vendedor),
                sizeof (struct Vendedor));
    }
}

void leerVendedores(struct Vendedor &vendedor, ifstream &archVendedores) {
    archVendedores >> vendedor.codigo;
    if (archVendedores.eof())return;
    archVendedores.get();
    archVendedores.getline(vendedor.nombre, 60, ',');
    archVendedores >> vendedor.porcentaje;
    archVendedores.get();
    archVendedores >> vendedor.cuotaMinima;
}

void procesarVentas(const char*nombVentas, const char*nombArticuloBin,
        const char*nombVendedorBin) {
    ifstream archVenta(nombVentas, ios::in);
    if (not archVenta.is_open()) {
        cout << "Error al abrir el archivo " << nombVentas;
        exit(1);
    }
    fstream archVendedoresBin(nombVendedorBin, ios::out | ios::in | ios::binary);
    if (not archVendedoresBin.is_open()) {
        cout << "Error al abrir el archivo " << nombVendedorBin;
        exit(1);
    }
    fstream archArticuloBin(nombArticuloBin, ios::out | ios::in | ios::binary);
    if (not archArticuloBin.is_open()) {
        cout << "Error al abrir el archivo " << nombArticuloBin;
        exit(1);
    }





    struct Articulo articulo;
    struct Vendedor vendedor;

    int tamRegA, tamRegV, numRegA, numRegV, codigoVendedor, cantidad,
            posA, posV, ventas;
    char codigo[10];
    tamRegA = sizeof (struct Articulo);
    tamRegV = sizeof (struct Vendedor);
    datosArchivoFstream(tamRegA, numRegA, archArticuloBin);
    datosArchivoFstream(tamRegV, numRegV, archVendedoresBin);



    while (true) {
        archVenta.getline(codigo, 10, ' ');
        if (archVenta.eof())break;
        archVenta >> codigoVendedor>>cantidad;
        archVenta.get();
        posA = buscarArticulo(codigo, tamRegA, numRegA, archArticuloBin);
        posV = buscarVendedor(codigoVendedor, tamRegV, numRegV, archVendedoresBin);
        if (posA != NO_ENCONTRADO and posV != NO_ENCONTRADO) {
            archArticuloBin.seekg(tamRegA*posA, ios::beg);
            archArticuloBin.read(reinterpret_cast<char*> (&articulo), tamRegA);

            archVendedoresBin.seekg(tamRegV*posV, ios::beg);
            archVendedoresBin.read(reinterpret_cast<char*> (&vendedor), tamRegV);

            ventas = vendedor.cantidadArr;
            articulo.cantidadVendidos += cantidad;
            articulo.monto += articulo.precio*cantidad;
            vendedor.articulosVendidos[ventas].cantidad += cantidad;
            strcpy(vendedor.articulosVendidos[ventas].codigo, codigo);
            vendedor.articulosVendidos[ventas].monto += articulo.precio
                    *cantidad;
            vendedor.articulosVendidos[ventas].cantidad += cantidad;
            vendedor.articulosVendidos[ventas].pagoRepartidor +=
                    articulo.precio * cantidad *
                    vendedor.porcentaje / 100;
            vendedor.totalVendido +=
                    vendedor.articulosVendidos[ventas].monto;
            vendedor.cantidadArr++;
            archArticuloBin.seekg(tamRegA*posA, ios::beg);
            archArticuloBin.write(reinterpret_cast<const char*> (&articulo),
                    tamRegA);

            archVendedoresBin.seekg(tamRegV*posV, ios::beg);
            archVendedoresBin.write(reinterpret_cast<const char*> (&vendedor),
                    tamRegV);
        }
    }

    archArticuloBin.seekg(0, ios::beg);
    archVendedoresBin.seekg(0, ios::beg);
    for (int i = 0; i < numRegA; i++) {
        archArticuloBin.read(reinterpret_cast<char*> (&articulo), tamRegA);
        cout << setw(2) << setfill('0') << i + 1 << ")" << setfill(' ')
                << "  " << articulo.codigo << "  " << left << setw(40)
                << articulo.descripcion << right << setw(18)
                << articulo.precio <<
                setw(16) << articulo.cantidadVendidos << setw(35)
                << articulo.monto << endl;
    }

}

void ordenarVendedores(const char*nombVendedorBin) {
    fstream archVendedoresBin(nombVendedorBin, ios::out | ios::in | ios::binary);
    if (not archVendedoresBin.is_open()) {
        cout << "Error al abrir el archivo " << nombVendedorBin;
        exit(1);
    }

    struct Vendedor vendedorI, vendedorK;
    int tamReg, numReg;
    tamReg = sizeof (struct Vendedor);
    datosArchivoFstream(tamReg, numReg, archVendedoresBin);

    for (int i = 0; i < numReg; i++) {
        for (int k = i + 1; k < numReg; k++) {
            archVendedoresBin.seekg(tamReg*i, ios::beg);
            archVendedoresBin.read(reinterpret_cast<char*> (&vendedorI), tamReg);

            archVendedoresBin.seekg(tamReg*k, ios::beg);
            archVendedoresBin.read(reinterpret_cast<char*> (&vendedorK), tamReg);
            if (vendedorI.totalVendido > vendedorK.totalVendido) {
                archVendedoresBin.seekg(tamReg*i, ios::beg);
                archVendedoresBin.write(reinterpret_cast<char*> (&vendedorK), tamReg);

                archVendedoresBin.seekg(tamReg*k, ios::beg);
                archVendedoresBin.write(reinterpret_cast<char*> (&vendedorI), tamReg);
            }
        }
    }
}

void emitirReporte(const char*nombReporte, const char*nombArticuloBin,
        const char*nombVendedorBin) {
    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "Error al abrir el archivo " << nombReporte;
        exit(1);
    }
    fstream archVendedoresBin(nombVendedorBin, ios::in | ios::binary);
    if (not archVendedoresBin.is_open()) {
        cout << "Error al abrir el archivo " << nombVendedorBin;
        exit(1);
    }
    fstream archArticuloBin(nombArticuloBin, ios::in | ios::binary);
    if (not archArticuloBin.is_open()) {
        cout << "Error al abrir el archivo " << nombArticuloBin;
        exit(1);
    }

    struct Articulo articulo;
    struct Vendedor vendedor;

    int tamRegA, tamRegV, numRegA, numRegV, posA;
    double totalArticulosVendidos = 0, totalPagoRepartidores, ingresoFinal = 0;
    tamRegA = sizeof (struct Articulo);
    tamRegV = sizeof (struct Vendedor);
    datosArchivoFstream(tamRegA, numRegA, archArticuloBin);
    datosArchivoFstream(tamRegV, numRegV, archVendedoresBin);

    archReporte << setw(MAX_LINE / 2) << "TIENDA POR DEPARTAMENTOS TP" << endl
            << endl << "DETALLE DE PAGOS A LOS VENDEDORES" << endl;
    imprimirLinea('=', MAX_LINE, archReporte);


    archReporte << setprecision(2) << fixed;
    for (int i = 0; i < numRegV; i++) {
        archVendedoresBin.read(reinterpret_cast<char*> (&vendedor), tamRegV);
        archReporte << "No.   " << "VENDEDOR" << setw(53) << "% POR VENTAS " << " CUOTA MINI"
                "MO" << setw(16) << "OBSERVACIN" << endl;
        imprimirLinea('-', MAX_LINE, archReporte);
        archReporte << setw(2) << setfill('0') << i + 1 << ")" << setfill(' ')
                << setw(11) << vendedor.codigo << "  " << setw(40) << left <<
                vendedor.nombre << right << setw(5) << vendedor.porcentaje << "%"
                << setw(16) << vendedor.cuotaMinima;
        totalPagoRepartidores = 0;
        if (!vendedor.superoCuota) {
            archReporte << setw(8) << " " << "NO SUPERO LA CUOTA" << endl;
        } else {
            archReporte << endl << setw(5) << " " << "ARTICULOS VENDIDOS" << endl
                    << setw(5) << " " << "No  ARTICULO" << setw(48)
                    << "CANTIDAD" << setw(12) << "TOTAL" << setw(4)
                    << "  " << "PAGO POR VENTAS" << endl;

            for (int k = 0; k < vendedor.cantidadArr; k++) {
                archReporte << setw(5) << " " << setw(2) << setfill('0')
                        << k + 1 << ")" << setfill(' ') << "  "
                        << vendedor.articulosVendidos[k].codigo << "  ";
                posA = buscarArticulo(vendedor.articulosVendidos[k].codigo,
                        tamRegA, numRegA, archArticuloBin);
                if (posA != NO_ENCONTRADO) {
                    archArticuloBin.seekg(tamRegA*posA, ios::beg);
                    archArticuloBin.read(reinterpret_cast<char*> (&articulo),
                            tamRegA);
                    archReporte << setw(40) << left << articulo.descripcion
                            << right;
                    archReporte << setw(3) << vendedor.articulosVendidos[k].cantidad
                            << setw(16) << vendedor.articulosVendidos[k].monto
                            << setw(16) <<
                            vendedor.articulosVendidos[k].pagoRepartidor << endl;
                    totalPagoRepartidores +=
                            vendedor.articulosVendidos[k].pagoRepartidor;
                }
            }
        }
        imprimirLinea('=', MAX_LINE, archReporte);
        archReporte << "TOTAL DE PAGO POR VENTAS:" << setw(9)
                << totalPagoRepartidores << endl;
        imprimirLinea('=', MAX_LINE, archReporte);
        ingresoFinal += totalPagoRepartidores;
    }

    archReporte << setw(MAX_LINE / 2) << "DETALLE DE INGRESOS POR ARTICULO" << endl;
    imprimirLinea('=', MAX_LINE, archReporte);
    archReporte << "No.   " << "ARTICULO" << setw(46) << "PRECIO" << setw(22) <<
            "CANTIDAD VENDIDA" << setw(25) << "INGRESOS POR VENTAS" << endl;
    imprimirLinea('-', MAX_LINE, archReporte);
    archArticuloBin.seekg(0, ios::beg);
    for (int i = 0; i < numRegA; i++) {
        archArticuloBin.read(reinterpret_cast<char*> (&articulo), tamRegA);
        archReporte << setw(2) << setfill('0') << i + 1 << ")" << setfill(' ')
                << "  " << articulo.codigo << "  " << left << setw(40)
                << articulo.descripcion << right << setw(18)
                << articulo.precio <<
                setw(16) << articulo.cantidadVendidos << setw(35)
                << articulo.monto << endl;
        totalArticulosVendidos += articulo.monto;
    }
    imprimirLinea('=', MAX_LINE, archReporte);
    archReporte << "TOTAL DE INGRESOS POR VENTAS, DESCONTANDOS PAGO :"
            << setw(16) << +ingresoFinal + totalArticulosVendidos << endl;
    imprimirLinea('=', MAX_LINE, archReporte);
}

void imprimirLinea(char c, int n, ofstream &archReporte) {
    for (int i = 0; i < n; i++) {
        archReporte.put(c);
    }
    archReporte << endl;
}

void corregirVendedores(const char*nombVendedorBin) {
    fstream archVendedoresBin(nombVendedorBin, ios::out | ios::in | ios::binary);
    if (not archVendedoresBin.is_open()) {
        cout << "Error al abrir el archivo " << nombVendedorBin;
        exit(1);
    }

    struct Vendedor vendedor;

    int tamReg, numReg;
    tamReg = sizeof (struct Vendedor);
    datosArchivoFstream(tamReg, numReg, archVendedoresBin);

    for (int i = 0; i < numReg; i++) {
        archVendedoresBin.read(reinterpret_cast<char*> (&vendedor), tamReg);

        if (vendedor.cuotaMinima < vendedor.totalVendido) {
            vendedor.superoCuota = true;
        } else {
            vendedor.superoCuota = false;
            vendedor.totalVendido = 0;
        }
        archVendedoresBin.seekg(tamReg*i, ios::beg);
        archVendedoresBin.write(reinterpret_cast<const char*> (&vendedor),
                tamReg);
    }
}

int buscarVendedor(int codigoVendedor, int tamRegV, int numRegV,
        fstream &archVendedoresBin) {
    struct Vendedor datVendedor;
    archVendedoresBin.seekg(0, ios::beg);
    for (int i = 0; i < numRegV; i++) {
        archVendedoresBin.read(reinterpret_cast<char*> (&datVendedor), tamRegV);

        if (codigoVendedor == datVendedor.codigo)return i;
    }
    return NO_ENCONTRADO;
}

int buscarArticulo(char *codigo, int tamRegA, int numRegA,
        fstream &archArticuloBin) {
    struct Articulo datArticulo;
    archArticuloBin.seekg(0, ios::beg);
    for (int i = 0; i < numRegA; i++) {
        archArticuloBin.read(reinterpret_cast<char*> (&datArticulo), tamRegA);

        if (strcmp(codigo, datArticulo.codigo) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void datosArchivoIfstream(int tamReg, int &numReg, ifstream &archBin) {
    int tamArch;
    archBin.seekg(0, ios::end);
    tamArch = archBin.tellg();
    archBin.seekg(0, ios::beg);
    numReg = tamArch / tamReg;
}

void datosArchivoFstream(int tamReg, int &numReg, fstream &archBin) {
    int tamArch;
    archBin.seekg(0, ios::end);
    tamArch = archBin.tellg();
    archBin.seekg(0, ios::beg);
    numReg = tamArch / tamReg;
}