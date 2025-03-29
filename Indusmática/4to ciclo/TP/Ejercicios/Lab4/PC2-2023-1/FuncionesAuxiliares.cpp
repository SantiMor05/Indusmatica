#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 60

using namespace std;

void leerLibros(int *cod_libro, double *precio_libro, int &cant_libros,
        const char *nombLibros) {

    ifstream archLibros(nombLibros, ios::in);
    if (not archLibros.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombLibros << endl;
        exit(1);
    }

    cant_libros = 0;

    while (true) {

        archLibros >> cod_libro[cant_libros];
        if (archLibros.eof())break;

        //Saltamos el nombre del libro
        archLibros >> ws;
        while (archLibros.get() != ' ');
        archLibros >> precio_libro[cant_libros];
        cant_libros++;
    }

}

void leerAutores(int *cod_autor, int *libro, double *porcentaje,
        int &cant_autores, const char *nombAutores) {

    ifstream archAutores(nombAutores, ios::in);
    if (not archAutores.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombAutores << endl;
        exit(1);
    }
    cant_autores = 0;

    while (true) {

        archAutores >> cod_autor[cant_autores];
        if (archAutores.eof())break;
        archAutores >> libro[cant_autores] >> porcentaje[cant_autores];

        cant_autores++;
    }


}

void pedirFechas(int &fecha_ini, int &fecha_fin) {

    int dd, mm, aa;
    char car;

    while (true) {
        cout << "Ingrese el rango de fechas que desea visualizar" << endl;
        cout << "Ingresa la fecha inicial (dd/mm/aa): ";
        cin >> dd >> car >> mm >> car >> aa;

        fecha_ini = calcularFecha(dd, mm, aa);

        cout << "Ingresa la fecha final (dd/mm/aa): ";
        cin >> dd >> car >> mm >> car >> aa;

        fecha_fin = calcularFecha(dd, mm, aa);
        if (fecha_ini > fecha_fin) {
            cout << "La fecha inicial debe ser anterior a la final" << endl;
        } else break;
    }



}

void emitirReporte(int *cod_libro, int *cod_autor, int *libro,
        double *precio_libro, double *porcentaje, int cant_libros,
        int cant_autores, int fecha_ini, int fecha_fin,
        const char *nombReporte, const char *nombVentas) {

    int dd, mm, aa, fecha, cant, codigo, pos;
    int contador = 0;
    double monto;
    char car;

    ifstream archVentas(nombVentas, ios::in);
    if (not archVentas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombVentas << endl;
        exit(1);
    }

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirEncabezado(fecha_ini, fecha_fin, archReporte);

    archReporte << setprecision(2) << fixed;
    while (true) {

        archVentas >> dd;
        if (archVentas.eof())break;
        archVentas >> car >> mm >> car >> aa;

        fecha = calcularFecha(dd, mm, aa);
        if (fecha >= fecha_ini and fecha <= fecha_fin) {
            while (archVentas.get() != '\n') {
                archVentas >> codigo >> cant;
                pos = buscarLibro(codigo, cod_libro, cant_libros);
                imprimirEncabezadoLibro(contador, codigo, archReporte);
                if (pos >= 0) {
                    monto = cant * precio_libro[pos];
                    archReporte << setw(12) << cant << setw(10) <<
                            precio_libro[pos] << setw(15) << monto << endl;
                    imprimiRegalias(codigo, monto, cant_autores, cod_autor,
                            libro, porcentaje, archReporte);
                } else {
                    archReporte << setw(15) << "NO ENCONTRADO";
                }

                contador++;
            }
        } else while (archVentas.get() != '\n');

    }

}


void imprimiRegalias(int codigo, double monto, int cant_autores, int *cod_autor,
        int *libro, double *porcentaje, ofstream &archReporte){
    
    double recibe;
    
    archReporte <<  endl << setw(5)<< " " <<"REGALIAS PARA LOS AUTORES" << endl;
    archReporte << setw(5) << " " << "AUTOR" << setw(25) << "PORCENTAJE A "
            "RECIBIR" << setw(20) << "MONTO A RECIBIR"  << endl;
    
    for(int i = 0; i < cant_autores; i++){
        if(codigo == libro[i]){
            recibe = monto * porcentaje[i] / 100;
            archReporte << setw(5) << " " << cod_autor[i] << setw(12) << 
                    porcentaje[i] << "%" << setw(20) << recibe << endl;
        }
    }
    imprimirCaracter('=', archReporte);
}

void imprimirEncabezadoLibro(int contador, int codigo, ofstream &archReporte) {

    archReporte << setfill('0') << setw(2) << contador + 1 << ") " <<
            setfill(' ');
    
    if(contador + 1 < 100){
        archReporte<< " LIBRO";
    }
    else archReporte<< "LIBRO";
    
    archReporte << setw(20) << "CANTIDAD" << setw(12) <<
            "PRECIO" << setw(20) << "MONTO RECAUDADO" << endl;
    archReporte << setw(12) << codigo;

}

int buscarLibro(int codigo, int *cod_libro, int cant_libros) {

    for (int i = 0; i < cant_libros; i++) {
        if (codigo == cod_libro[i]) return i;
    }
    return -1;

}

void imprimirEncabezado(int fecha_ini, int fecha_fin, ofstream &archReporte) {

    int dd, mm, aa;

    archReporte << setw(MAX_CAR / 2 + 11) << "LIBRERIA LOS LIBROS_TP" << endl
            << endl;
    archReporte << setw(MAX_CAR / 4) << "VENTA DE LIBROS EN EL RANGO ";

    formatoFecha(dd, mm, aa, fecha_ini);

    archReporte << setfill('0') << setw(2) << dd << "/" << setw(2) << mm <<
            "/" << aa << " AL ";

    formatoFecha(dd, mm, aa, fecha_fin);

    archReporte << setw(2) << dd << "/" << setw(2) << mm <<
            "/" << aa << endl << endl << setfill(' ');

    imprimirCaracter('=', archReporte);
}

void imprimirCaracter(char car, ofstream &archSalida) {

    for (int i = 0; i < MAX_CAR; i++) {
        archSalida.put(car);
    }

    archSalida << endl;

}

void formatoFecha(int &dd, int &mm, int &aa, int fecha) {

    dd = fecha % 100;
    fecha /= 100;
    mm = fecha % 100;
    aa = fecha / 100;

}

int calcularFecha(int dd, int mm, int aa) {

    return dd + mm * 100 + aa * 10000;

}