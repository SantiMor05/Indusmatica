/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
//#include <fstream>
#include <cstring>
#include <fstream>
#include <memory>
using namespace std;
#include "funcionesAux.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 150

void lecturaDeProductos(const char* nombreArch, char*** &productos, int* &stock, double* &precios) {
    ifstream archLee(nombreArch, ios::in);
    if (not archLee.is_open()) {
        cout << "No se ha podido abrir el archivo " << nombreArch << endl;
        exit(1);
    }
    int bufferStock[200]{}, numDat = 0, stockLec;
    double bufferPrec[200]{}, precio;
    char** bufferProd[200]{}, c;


    while (true) {
        bufferProd[numDat] = lecturaProducto(archLee);
        if (archLee.eof()) break;
        archLee >> precio >> c>>stockLec;
        //quitamos el \n
        archLee.get();
        bufferPrec[numDat] = precio;
        bufferStock[numDat] = stockLec;
        numDat++;
    }
    numDat++;
    // Inicializamos
    productos = new char**[numDat] {
    };
    stock = new int[numDat] {
    };
    precios = new double[numDat] {
    };
    //Pasamos del buffer a nuestros punteros
    for (int i = 0; i < numDat; i++) {
        productos[i] = bufferProd[i];
        stock[i] = bufferStock[i];
        precios[i] = bufferPrec[i];
    }
}

char** lecturaProducto(ifstream &archLee) {
    char* buffer[10]{}, **producto;
    int nc = 0;
    for (int i = 0; i < 2; i++) {
        buffer[nc] = lecturaExacta(archLee);
        if (archLee.eof()) break;
        nc++;
    }
    if (archLee.eof()) return nullptr;
    nc++;
    //Inicializamos 
    producto = new char*[nc] {
    };
    //Copiamos 
    for (int i = 0; i < nc; i++)
        producto[i] = buffer[i];

    return producto;
}

char* lecturaExacta(ifstream &archLee) {
    char* ptCad, buffer[150];
    int canCar;
    archLee.getline(buffer, 150, ',');
    if (archLee.eof()) return nullptr;
    canCar = strlen(buffer);
    ptCad = new char[canCar + 1];
    strcpy(ptCad, buffer);
    return ptCad;
}

void pruebaDeLecturaDeProductos(const char* nombreArch, char*** productos, int* stock, double* precios) {
    ofstream archReport(nombreArch, ios::out);
    if (not archReport.is_open()) {
        cout << "No se ha podido abrir el archivo " << nombreArch << endl;
        exit(1);
    }
    archReport << fixed;
    archReport.precision(2);
    archReport << left << setw(70) << "PRODUCTO - DESCRIPCIÓN" << right << setw(15)
            << "PRECIO" << setw(15) << "STOCK" << endl;
    for (int i = 0; precios[i]; i++) {
        impresionProducto(productos[i], archReport);
        archReport << right << setw(15) << precios[i] << setw(15) << stock[i] << endl;
    }
}

void impresionProducto(char** productos, ofstream &archReport) {
    int espacio;
    for (int i = 0; productos[i]; i++) {
        if (i == 0) espacio = 10;
        else espacio = 60;
        archReport << left << setw(espacio) << productos[i];
    }

}

void lecturaDePedidos(const char* nombreArch, int*& fechaPedidos, char***& codigosPedidos, int***& dniCantPedidos) {
    ifstream archLee(nombreArch, ios::in);
    if (not archLee.is_open()) {
        cout << "No se ha podido abrir el archivo " << nombreArch << endl;
        exit(1);
    }

    int**bufferDniCant[600]{}, bufferFec[600]{}, dni, cant, dd, aa, mm, fecha, numDat = 0
            , ndDniCant[600]{}, ndCod[600]{}, pos;
    char **bufferCodPed[600]{}, c, *producto;



    while (true) {
        producto = lecturaExacta(archLee);
        if (archLee.eof()) break;
        archLee >> dni >> c >> cant >> c >> dd >> c >> mm >> c>>aa;
        //        / quitar el \n
        archLee.get();
        fecha = aa * 10000 + mm * 100 + dd;


        //Buscamos en el arreglo
        pos = buscamosFecha(bufferFec, fecha);
        if (pos != NO_ENCONTRADO) {
            //Si encontramos fecha
            aumentamosProductos(bufferCodPed[pos], ndCod[pos], producto);
            aumentamosDniCant(bufferDniCant[pos], ndDniCant[pos], dni, cant);
        } else {
            //Si no encontramos la fecha la agregamos
            bufferFec[numDat] = fecha;
            bufferCodPed[numDat] = new char*[600] {
            };
            bufferDniCant[numDat] = new int*[600] {
            };
            aumentamosProductos(bufferCodPed[numDat], ndCod[numDat], producto);
            aumentamosDniCant(bufferDniCant[numDat], ndDniCant[numDat], dni, cant);
            //Como entro una nueva fecha el numDat aumenta
            numDat++;
        }

    }
    numDat++;
    //Inicilizamos
    fechaPedidos = new int[numDat] {
    };
    dniCantPedidos = new int**[numDat] {
    };
    codigosPedidos = new char**[numDat] {
    };


    //    //Pasamos de nuestros buffers al arreglo principal
    for (int i = 0; i < numDat; i++) {
        asignamosMemoriaExactaCodPed(codigosPedidos[i], bufferCodPed[i], ndCod[i]);
        asignamosMemoriaExactaDniCant(dniCantPedidos[i], bufferDniCant[i], ndDniCant[i]);

        fechaPedidos[i] = bufferFec[i];

        delete bufferDniCant[i];
        delete bufferCodPed[i];
        //Aprovecho en asignarle una memoria exacta
    }




}

void asignamosMemoriaExactaDniCant(int **&dniCantPedidos, int** bufferDniCant, int ndDniCant) {
    int **espacioMemoria;
    //La mera existaencia de una fecha me indica que debe haber un dni con su cant
    espacioMemoria = new int*[ndDniCant + 1] {
    };
    for (int i = 0; i < ndDniCant; i++)
        espacioMemoria[i] = bufferDniCant[i];
    delete dniCantPedidos;
    dniCantPedidos = espacioMemoria;
}

void asignamosMemoriaExactaCodPed(char**& codigosPedidos, char** bufferCodPed, int ndCod) {
    //El mera existencia de una fecha me indica que debe haber un producto al menos
    char** espacioExacto;

    espacioExacto = new char*[ndCod + 1] {
    };
    //pasamos el arreglo anterior al nuevo
    for (int i = 0; i < ndCod; i++) {
        espacioExacto[i] = bufferCodPed[i];
    }
    delete codigosPedidos;
    codigosPedidos = espacioExacto;

}

void aumentamosDniCant(int **bufferDniCant, int &ndDniCant, int dni, int cant) {
    bufferDniCant[ndDniCant] = new int[3] {
    };
    asignar(bufferDniCant[ndDniCant], dni, cant);
    ndDniCant++;
}

void asignar(int *bufferDniCant, int dni, int cant) {
    int dato;
    for (int i = 0; i < 2; i++) {
        if (i == 0) dato = dni;
        else dato = cant;
        bufferDniCant[i] = dato;
    }
}

void aumentamosProductos(char** bufferCodPed, int&ndCod, char *producto) {
    bufferCodPed[ndCod] = producto;
    ndCod++;
}

int buscamosFecha(int *bufferFec, int fecha) {
    for (int i = 0; bufferFec[i]; i++) {
        if (bufferFec[i] == fecha) return i;
    }
    return NO_ENCONTRADO;
}

void pruebaDeLecturaDePedido(const char* nombreArch, int* fechaPedidos, char*** codigosPedidos, int*** dniCantPedidos) {
    ofstream archReport(nombreArch, ios::out);
    if (not archReport.is_open()) {
        cout << "No se ha podido abrir el archivo " << nombreArch << endl;
        exit(1);
    }
    archReport << fixed;
    archReport.precision(2);
    for (int i = 0; fechaPedidos[i]; i++) {
        archReport << "FECHA" << setw(15) << fechaPedidos[i] << endl;
        archReport << right << setw(10) << "CODIGO" << setw(15) << "DNI" << setw(10) << "CANT" << endl;
        impresionProductos(codigosPedidos[i], dniCantPedidos[i], archReport);
    }



}

void impresionProductos(char**codigosPedidos, int**dniCantPedidos, ofstream &archReport) {

    for (int i = 0; codigosPedidos[i]; i++) {
        archReport << setw(3) << i + 1 << right << setw(10) << codigosPedidos[i];
        impresionDni(dniCantPedidos[i], archReport);

    }
}

void impresionDni(int* dniCantPedidos, ofstream &archReport) {
    int espacio;
    for (int i = 0; dniCantPedidos[i]; i++) {
        if (i == 0) espacio = 10;
        else espacio = 15;
        archReport << setw(espacio) << dniCantPedidos[i];
    }
    archReport << endl;
}

void reporteDeEnvioDePedidos(const char* nombreArch, char*** productos, int* stock, double* precios,
        int* fechaPedidos, char*** codigosPedidos, int*** dniCantPedidos) {
    ofstream archReport(nombreArch, ios::out);
    if (not archReport.is_open()) {
        cout << "No se ha podido abrir el archivo " << nombreArch << endl;
        exit(1);
    }


    archReport << fixed;
    archReport.precision(2);
    archReport << right << setw((MAX_LINEA + 23) / 2) << "REPORTE DE ENTREGA DE PEDIDOS" << endl;
    for (int i = 0; fechaPedidos[i]; i++) {
        impresionLinea(archReport, MAX_LINEA, '=');
        archReport << "FECHA: " << fechaPedidos[i] << endl;

        impresionLinea(archReport, MAX_LINEA, '=');
        archReport << right << setw(6) << "No." << setw(15) << "Dni" << setw(70) << "Producto" << setw(15) << "Cantidad"
                << setw(15) << "Precio" << setw(15) << "Total Ingresos" << endl;

        impresionLinea(archReport, MAX_LINEA, '-');
        impresionDatosYModiStock(codigosPedidos[i], dniCantPedidos[i],
                productos, precios, stock, archReport);

    }
}

void impresionDatosYModiStock(char** codigosPedidos, int** dniCantPedidos,
        char***productos, double *precios, int* stock, ofstream &archReport) {
    double totalIngreso = 0, totalPerdido = 0;
    int auxStock, *auxDniCant, posProd;
    bool hayStock;
    for (int i = 0; codigosPedidos[i]; i++) {
        //Primero encontramo el producto;
        posProd = buscarProd(codigosPedidos[i], productos);
        if (posProd != NO_ENCONTRADO) {
            //verifcamos el stock;
            auxStock = stock[posProd];
            auxDniCant = dniCantPedidos[i];
            auxStock -= auxDniCant[1];
            if (auxStock >= 0) {
                //hay stock
                hayStock = true;
                stock[posProd] -= auxDniCant[1];
                impresion(i + 1, precios[posProd], dniCantPedidos[i], hayStock, totalIngreso,
                        totalPerdido, productos[posProd], archReport);
            } else {
                hayStock = false;
                //No hay stock
                impresion(i + 1, precios[posProd], dniCantPedidos[i], hayStock, totalIngreso,
                        totalPerdido, productos[posProd], archReport);
            }

        }
    }
    impresionLinea(archReport, MAX_LINEA, '-');
    archReport << left << setw(70) << "Total Ingreso: " << right << setw(15) << totalIngreso << endl;
    archReport << left << setw(70) << "Total perdida por falta de stock:" << right <<
            setw(15) << totalPerdido << endl;

}

void impresion(int num, double precios, int* dniCantPedidos, bool hayStock, double& totalIngreso,
        double &totalPerdido, char**productos, ofstream &archReport) {
    double total;
    total = precios * (dniCantPedidos[1]);
    archReport << right << setw(6) << num << setw(15) << dniCantPedidos[0] << setw(10) << productos[0] << "  " << left <<
            setw(58) << productos[1] << right << setw(15) << dniCantPedidos[1]
            << setw(15) << precios;
    if (hayStock) {
        archReport << setw(15) << total << endl;
        totalIngreso += total;
    } else {
        archReport << setw(15) << "No Stock" << endl;
        totalPerdido += total;
    }

}

int buscarProd(char* codigo, char*** productos) {
    bool valido = false;
    for (int i = 0; productos[i]; i++) {
        valido = comparacion(codigo, productos[i]);
        if (valido) return i;
    }
    return NO_ENCONTRADO;


}

bool comparacion(char* codigo, char** productos) {
    int cmp;
    cmp = strcmp(codigo, productos[0]);
    if (cmp == 0) return true;
    else return false;

}

void impresionLinea(ofstream &archReport, int cant, char car) {
    for (int i = 0; i < cant; i++) {
        archReport << car;
    }
    archReport << endl;
}

