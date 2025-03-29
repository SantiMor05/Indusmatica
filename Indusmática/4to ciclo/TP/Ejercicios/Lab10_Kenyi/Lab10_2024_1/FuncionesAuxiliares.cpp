/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */



#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#include "Cliente.h"
#include "Libro.h"

using namespace std;
#define NO_ENCONTRADO -1
#define MAX_LINE 140

void leerClienteBin(const char*nombCliente, const char*nombClienteBin) {
    ifstream archCliente(nombCliente, ios::in);
    if (not archCliente.is_open()) {
        cout << "Error al abrir el archivo " << nombCliente;
        exit(1);
    }
    ofstream archBinCliente(nombClienteBin, ios::out | ios::binary);
    if (not archBinCliente.is_open()) {
        cout << "Error al abrir el archivo " << nombClienteBin;
        exit(1);
    }

    struct Cliente cliente {
    };

    while (true) {
        leerClientes(cliente, archCliente);
        if (archCliente.eof())break;
        archBinCliente.write(reinterpret_cast<const char*> (&cliente),
                sizeof (struct Cliente));
    }


}

void leerClientes(struct Cliente &cliente, ifstream &archCliente) {
    //54393647,Reyes Tang Edward
    archCliente >> cliente.dni;
    if (archCliente.eof())return;
    archCliente.get();
    archCliente.getline(cliente.nombre, 60, '\n');
}

void leerLibrosBin(const char*nombLibro, const char*nombLibroBin) {
    ifstream archLibro(nombLibro, ios::in);
    if (not archLibro.is_open()) {
        cout << "Error al abrir el archivo " << nombLibro;
        exit(1);
    }
    ofstream archBinLibro(nombLibroBin, ios::out | ios::binary);
    if (not archBinLibro.is_open()) {
        cout << "Error al abrir el archivo " << nombLibroBin;
        exit(1);
    }

    struct Libro libro {
    };

    while (true) {
        leerLibros(libro, archLibro);
        if (archLibro.eof())break;
        archBinLibro.write(reinterpret_cast<const char*> (&libro),
                sizeof (struct Libro));
    }
}

void leerLibros(struct Libro &libro, ifstream &archLibro) {
    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,69.02
    archLibro.getline(libro.codigo, 10, ',');
    if (archLibro.eof())return;
    archLibro.getline(libro.titulo, 60, ',');
    archLibro.getline(libro.autor, 60, ',');
    archLibro >> libro.precio;
    archLibro.get();
}

void leerVentas(const char*nombVentas, const char*nombClienteBin,
        const char*nombLibroBin) {
    ifstream archVentas(nombVentas, ios::in);
    if (not archVentas.is_open()) {
        cout << "Error al abrir el archivo " << nombVentas;
        exit(1);
    }
    fstream archBinLibro(nombLibroBin, ios::out | ios::in | ios::binary);
    if (not archBinLibro.is_open()) {
        cout << "Error al abrir el archivo " << nombLibroBin;
        exit(1);
    }
    ifstream archBinCliente(nombClienteBin, ios::in | ios::binary);
    if (not archBinCliente.is_open()) {
        cout << "Error al abrir el archivo " << nombClienteBin;
        exit(1);
    }
    int tamRegL, tamRegC, numRegC, numRegL, posC, posL;
    int dd, mm, aa, fecha, dni, calificacion, posLibro, ventas;
    char codigo[10], c;

    struct Libro datLibro;
    struct Cliente datCliente;

    tamRegL = sizeof (struct Libro);
    tamRegC = sizeof (struct Cliente);
    datosArchivoFstream(tamRegL, numRegL, archBinLibro);
    datosArchivoIstream(tamRegC, numRegC, archBinCliente);

    while (true) {
        //CRY6839, 34460612, 15 / 10 / 2023, 93
        archVentas.getline(codigo, 10, ',');
        if (archVentas.eof())break;
        archVentas>>dni;
        posC = buscarCliente(dni, tamRegC, numRegC, archBinCliente);
        posL = buscarLibro(codigo, tamRegL, numRegL, archBinLibro);
        if (posL != NO_ENCONTRADO and posC != NO_ENCONTRADO) {
            archBinLibro.seekg(tamRegL*posL, ios::beg);
            archBinLibro.read(reinterpret_cast<char*> (&datLibro), tamRegL);

            archBinCliente.seekg(tamRegC*posC, ios::beg);
            archBinCliente.read(reinterpret_cast<char*> (&datCliente), tamRegC);

            archVentas >> c >> dd >> c >> mm >> c >> aa >> c>>calificacion;
            c = archVentas.get();

            ventas = datLibro.librosVendidos;
            datLibro.sumaDeCalificaciones += calificacion;
            datLibro.ventas[ventas].calificacion = calificacion;
            datLibro.ventas[ventas].dni = dni;
            datLibro.ventas[ventas].fecha.dd = dd;
            datLibro.ventas[ventas].fecha.mm = mm;
            datLibro.ventas[ventas].fecha.aa = aa;
            datLibro.ventas[ventas].fecha.fecha = aa * 10000 + mm * 100 + dd;
            strcpy(datLibro.ventas[ventas].nombre, datCliente.nombre);
            datLibro.librosVendidos++;
            archBinLibro.seekg(tamRegL*posL, ios::beg);
            archBinLibro.write(reinterpret_cast<const char*> (&datLibro),
                    tamRegL);
        }
    }
}

void determinarRanking(const char*nombLibroBin) {
    fstream archBinLibro(nombLibroBin, ios::out | ios::in | ios::binary);
    if (not archBinLibro.is_open()) {
        cout << "Error al abrir el archivo " << nombLibroBin;
        exit(1);
    }

    //    archBinLibro.seekg(0, ios::beg);
    struct Libro libro;

    struct Fecha fechaMayor {
    };
    int tamReg, numReg, promedio;
    tamReg = sizeof (struct Libro);
    datosArchivoFstream(tamReg, numReg, archBinLibro);
    for (int i = 0; i < numReg; i++) {
        archBinLibro.read(reinterpret_cast<char*> (&libro), tamReg);

        if (libro.librosVendidos > 0) {
            promedio = libro.sumaDeCalificaciones / libro.librosVendidos;
        } else promedio = 0;

        libro.ranking = calcularRanking(promedio);
        fechaMayor.fecha = 0;

        for (int i = 0; i < libro.librosVendidos; i++) {
            if (libro.ventas[i].fecha.fecha > fechaMayor.fecha)
                fechaMayor = libro.ventas[i].fecha;
        }
        libro.fechaMasReciente = fechaMayor;
        archBinLibro.seekg(tamReg*i, ios::beg);
        archBinLibro.write(reinterpret_cast<const char*> (&libro), tamReg);
    }
}

void ordenarBin(const char*nombLibroBin) {
    fstream archBinLibro(nombLibroBin, ios::out | ios::in | ios::binary);
    if (not archBinLibro.is_open()) {
        cout << "Error al abrir el archivo " << nombLibroBin;
        exit(1);
    }

    struct Libro libroI, libroJ;
    int tamReg, numReg;
    tamReg = sizeof (struct Libro);
    datosArchivoFstream(tamReg, numReg, archBinLibro);

    for (int i = 0; i < numReg; i++) {
        for (int k = i + 1; k < numReg; k++) {
            archBinLibro.seekg(tamReg*i, ios::beg);
            archBinLibro.read(reinterpret_cast<char*> (&libroI), tamReg);

            archBinLibro.seekg(tamReg*k, ios::beg);
            archBinLibro.read(reinterpret_cast<char*> (&libroJ), tamReg);
            if (libroI.ranking < libroJ.ranking or
                    (libroI.ranking == libroJ.ranking and
                    libroI.fechaMasReciente.fecha >
                    libroJ.fechaMasReciente.fecha)) {
                archBinLibro.seekg(tamReg*i, ios::beg);
                archBinLibro.write(reinterpret_cast<const char*> (&libroJ), tamReg);

                archBinLibro.seekg(tamReg*k, ios::beg);
                archBinLibro.write(reinterpret_cast<const char*> (&libroI), tamReg);
            }
        }
    }
}

void emitirReporte(const char*nombLibroBin, const char*nombReporte) {
    ifstream archBinLibro(nombLibroBin, ios::in | ios::binary);
    if (not archBinLibro.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombLibroBin << endl;
        exit(1);
    }
    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirEncabezado(archReporte);

    struct Libro libro;
    int tamReg, numReg, dd, mm, aa;
    tamReg = sizeof (struct Libro);
    datosArchivoIstream(tamReg, numReg, archBinLibro);

    for (int i = 0; i < numReg; i++) {
        archBinLibro.read(reinterpret_cast<char*> (&libro), tamReg);

        archReporte << "LIBRO No. " << setfill('0') << setw(3) << i + 1 <<
                setfill(' ') << endl;
        archReporte << setw(5) << " " << "CODIGO" << setw(10) << "TITULO" <<
                setw(59) << "AUTOR" << setw(31) << "PRECIO" << setw(20) <<
                "LIBROS VENDIDOS" << setw(12) << "RANKINGS" << endl;
        archReporte << setw(5) << " " << left << setw(10) << libro.codigo <<
                setw(60) << libro.titulo << setw(30) << libro.autor << right <<
                setw(6) << libro.precio << setw(13) << libro.librosVendidos <<
                setw(15) << libro.ranking << endl;
        imprimirLinea('-', MAX_LINE, archReporte);
        archReporte << setw(5) << " " << "VENTAS REALIZADAS" << endl;
        archReporte << setw(5) << " " << "No." << setw(6) << "DNI" << setw(12)
                << "NOMBRE" << setw(55) << "CALIFICACION" << setw(15) <<
                "FECHA" << endl;
        for (int j = 0; j < libro.librosVendidos; j++) {
            dd = libro.ventas[j].fecha.dd;
            mm = libro.ventas[j].fecha.mm;
            aa = libro.ventas[j].fecha.aa;
            archReporte << setw(5) << " " << setfill('0') << setw(2) << j + 1 <<
                    setfill(' ') << setw(10) << libro.ventas[j].dni << setw(3) <<
                    " " << left << setw(50) << libro.ventas[j].nombre <<
                    right << setw(6) << libro.ventas[j].calificacion << setw(13)
                    << " " << setfill('0') << setw(2) << dd << "/" << setw(2) <<
                    mm << "/" << setw(4) << aa << setfill(' ') << endl;
        }
        imprimirLinea('-', MAX_LINE, archReporte);
        archReporte << setw(5) << " " << "FECHA MAS RECIENTE DE COMPRA: " <<
                setfill('0') << setw(2) << libro.fechaMasReciente.dd << "/" <<
                setw(2) << libro.fechaMasReciente.mm << "/" << setw(4) <<
                libro.fechaMasReciente.aa << setfill(' ') << endl;
        imprimirLinea('=', MAX_LINE, archReporte);
    }
}

void imprimirEncabezado(ofstream &archReporte) {
    archReporte << setw(MAX_LINE / 2 + 8) << "LIBRERIA PUCP-TP" << endl;
    archReporte << setw(MAX_LINE / 2 + 17) << "RESULTADO DE LAS VENTAS "
            "REALIZADAS" << endl;

    imprimirLinea('=', MAX_LINE, archReporte);
    archReporte << setprecision(2) << fixed;
}

void imprimirLinea(char c, int n, ofstream &archReporte) {
    for (int i = 0; i < n; i++) archReporte.put(c);
    archReporte << endl;
}

int calcularRanking(double promedio) {
    if (promedio == 0)return 0;
    else if (promedio < 25) return 1;
    else if (promedio < 50) return 2;
    else if (promedio < 75) return 3;
    else return 4;
}

int buscarCliente(int dni, int tamRegC, int numRegC, ifstream &archBinCliente) {
    struct Cliente datCliente;
    archBinCliente.seekg(0, ios::beg);
    for (int i = 0; i < numRegC; i++) {
        archBinCliente.read(reinterpret_cast<char*> (&datCliente), tamRegC);
        if (dni == datCliente.dni)return i;
    }
    return NO_ENCONTRADO;
}

int buscarLibro(char *codigo, int tamRegL, int numRegL, fstream &archBinLibro) {
    struct Libro datLibro;
    archBinLibro.seekg(0, ios::beg);
    for (int i = 0; i < numRegL; i++) {
        archBinLibro.read(reinterpret_cast<char*> (&datLibro), tamRegL);
        if (strcmp(codigo, datLibro.codigo) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void datosArchivoIstream(int tamReg, int &numReg, ifstream &archBin) {
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