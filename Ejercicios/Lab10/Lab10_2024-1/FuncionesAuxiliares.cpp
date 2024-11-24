#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define NO_ENCONTRADO -1
#define MAX_CAR 140

using namespace std;

void crearBinarioClientes(const char *nombClientes, const char *nombBinario) {

    ifstream archClientes(nombClientes, ios::in);
    if (not archClientes.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombClientes << endl;
        exit(1);
    }

    ofstream archBin(nombBinario, ios::out | ios::binary);
    if (not archBin.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombBinario << endl;
        exit(1);
    }

    int dni, tamReg;
    char nombre[50];
    struct Cliente cliente;
    tamReg = sizeof (struct Cliente);
    while (true) {
        archClientes >> cliente.dni;
        if (archClientes.eof())break;
        archClientes.get();

        archClientes.getline(nombre, 50);
        strcpy(cliente.nombre, nombre);

        archBin.write(reinterpret_cast<const char*> (&cliente), tamReg);
    }
}

void crearBinarioLibros(const char *nombLibros, const char *nombBinario) {

    ifstream archLibros(nombLibros, ios::in);
    if (not archLibros.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombLibros << endl;
        exit(1);
    }

    ofstream archBin(nombBinario, ios::out | ios::binary);
    if (not archBin.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombBinario << endl;
        exit(1);
    }

    struct Libro libros{};

    int tamReg = sizeof (struct Libro);

    while (true) {
        archLibros.getline(libros.codigo, 8, ',');
        if (archLibros.eof())break;
        archLibros.getline(libros.titulo, 65, ',');
        archLibros.getline(libros.autor, 40, ',');
        archLibros >> libros.precio;
        archLibros.get();

        archBin.write(reinterpret_cast<const char*> (&libros), tamReg);

    }
}

void completarDatos(const char *nombVentas, const char *nombCli,
        const char *nombLibros) {

    ifstream archVentas(nombVentas, ios::in);
    if (not archVentas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombVentas << endl;
        exit(1);
    }

    ifstream archClientes(nombCli, ios::in | ios::binary);
    if (not archClientes.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCli << endl;
        exit(1);
    }

    fstream archLibros(nombLibros, ios::in | ios::out | ios::binary);
    if (not archLibros.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombLibros << endl;
        exit(1);
    }

    struct Libro libros;
    struct Cliente cliente;

    int tamRegL, numRegL, dni, pos_cliente, pos_libro, tamRegC, numRegC;
    int dd, mm, aa, calificacion, n;
    char codigo[8], car;
    tamRegL = sizeof (struct Libro);
    tamRegC = sizeof (struct Cliente);
    datosArchivoLibros(tamRegL, numRegL, archLibros);
    datosArchivoCliente(tamRegC, numRegC, archClientes);

    while (true) {
        archVentas.getline(codigo, 8, ',');
        if (archVentas.eof())break;
        archVentas >> dni;
        pos_cliente = buscarDni(dni, tamRegC, numRegC, archClientes);
        pos_libro = buscarLibro(codigo, tamRegL, numRegL, archLibros);
        if (pos_cliente != NO_ENCONTRADO and pos_libro != NO_ENCONTRADO) {
            archClientes.seekg(tamRegC*pos_cliente, ios::beg);
            archClientes.read(reinterpret_cast<char*> (&cliente), tamRegC);

            archLibros.seekg(tamRegL * pos_libro, ios::beg);
            archLibros.read(reinterpret_cast<char*> (&libros), tamRegL);

            archVentas >> car >> dd >> car >> mm >> car >> aa >> car >>
                    calificacion;
            archVentas.get();

            n = libros.librosVendidos;
            libros.sumaCalificaciones += calificacion;
            libros.ventas[n].calificacion = calificacion;
            libros.ventas[n].fecha.dd = dd;
            libros.ventas[n].fecha.mm = mm;
            libros.ventas[n].fecha.aa = aa;
            libros.ventas[n].fecha.fecha = dd + mm * 100 + aa * 10000;
            libros.ventas[n].dni = dni;
            strcpy(libros.ventas[n].nombre, cliente.nombre);
            libros.librosVendidos++;
            archLibros.seekg(tamRegL * pos_libro, ios::beg);
            archLibros.write(reinterpret_cast<const char*> (&libros), tamRegL);
        }
    }

}

int buscarLibro(char *codigo, int tamRegL, int numRegL, fstream &archLibros) {

    struct Libro libro;
    archLibros.seekg(0, ios::beg);

    for (int i = 0; i < numRegL; i++) {
        archLibros.read(reinterpret_cast<char*> (&libro), tamRegL);
        if (strcmp(codigo, libro.codigo) == 0)
            return i;
    }
    return NO_ENCONTRADO;
}

int buscarDni(int dni, int tamRegC, int numRegC, ifstream &archClientes) {

    struct Cliente cliente;
    archClientes.seekg(0, ios::beg);
    for (int i = 0; i < numRegC; i++) {
        archClientes.read(reinterpret_cast<char*> (&cliente), tamRegC);
        if (cliente.dni == dni)
            return i;
    }
    return NO_ENCONTRADO;
}

void datosArchivoLibros(int tamReg, int &numReg, fstream &archLibros) {
    int tamArch;
    archLibros.seekg(0, ios::end);
    tamArch = archLibros.tellg();
    numReg = tamArch / tamReg;
    archLibros.seekg(0, ios::beg);
}

void datosArchivoLibrosLectura(int tamReg, int &numReg, ifstream &archLibros) {
    int tamArch;
    archLibros.seekg(0, ios::end);
    tamArch = archLibros.tellg();
    numReg = tamArch / tamReg;
    archLibros.seekg(0, ios::beg);
}

void datosArchivoCliente(int tamReg, int &numReg, ifstream &archClientes) {

    int tamArch;
    archClientes.seekg(0, ios::end);
    tamArch = archClientes.tellg();
    numReg = tamArch / tamReg;
    archClientes.seekg(0, ios::beg);

}

void determinarRankig(const char *nombBin) {

    fstream archBin(nombBin, ios::in | ios::out | ios::binary);
    if (not archBin.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombBin << endl;
        exit(1);
    }

    archBin.seekg(0,ios::beg);
    struct Libro libro;
    
    struct Fecha fecha_mayor {};
    int tamReg, numReg, promedio;
    tamReg = sizeof (struct Libro);
    datosArchivoLibros(tamReg, numReg, archBin);
    for (int i = 0; i < numReg; i++) {
        archBin.read(reinterpret_cast<char*> (&libro), tamReg);

        if (libro.librosVendidos > 0) {
            promedio = libro.sumaCalificaciones / libro.librosVendidos;
        } else {
            promedio = 0;
        }
        libro.ranking = calcularRanking(promedio);
        fecha_mayor.fecha = 0;

        for (int i = 0; i < libro.librosVendidos; i++) {
            if (libro.ventas[i].fecha.fecha > fecha_mayor.fecha)
                fecha_mayor = libro.ventas[i].fecha;
        }
        libro.fechaMasReciente = fecha_mayor;
        archBin.seekg(tamReg*i,ios::beg);
        archBin.write(reinterpret_cast<const char*> (&libro), tamReg);
    }
}

int calcularRanking(int promedio) {
    if (promedio == 0)
        return 0;
    else if (promedio < 25)
        return 1;
    else if (promedio < 50)
        return 2;
    else if (promedio < 75)
        return 3;
    else
        return 4;
}

void ordernar(const char *nombBin) {

    fstream archBin(nombBin, ios::in | ios::out | ios::binary);
    if (not archBin.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombBin << endl;
        exit(1);
    }

    struct Libro libroI, libroJ;
    int tamReg, numReg;
    tamReg = sizeof (struct Libro);
    datosArchivoLibros(tamReg, numReg, archBin);

    for (int i = 0; i < numReg - 1; i++) {
        for (int j = i + 1; j < numReg; j++) {
            archBin.seekg(tamReg*i, ios::beg);
            archBin.read(reinterpret_cast<char*> (&libroI), tamReg);
        
            archBin.seekg(tamReg*j, ios::beg);
            archBin.read(reinterpret_cast<char*> (&libroJ), tamReg);
            if (libroI.ranking < libroJ.ranking or
                    (libroI.ranking == libroJ.ranking and
                    libroI.fechaMasReciente.fecha > libroJ.fechaMasReciente.fecha)){
                //Intercambiamos
                archBin.seekg(tamReg*i, ios::beg);
                archBin.write(reinterpret_cast<const char*> (&libroJ), tamReg);
                archBin.seekg(tamReg*j, ios::beg);
                archBin.write(reinterpret_cast<const char*> (&libroI), tamReg);
            }
        }
    }
}

void emitirReporte(const char *nombBin, const char *nombReporte){
    
    
   ifstream archBin(nombBin, ios::in | ios::binary);
    if (not archBin.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombBin << endl;
        exit(1);
    } 
   
    ofstream archReporte(nombReporte, ios::out );
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    imprimirEncabezado(archReporte);
    
    struct Libro libro;
    int tamReg, numReg, dd, mm ,aa;
    tamReg = sizeof (struct Libro);
    datosArchivoLibrosLectura(tamReg, numReg, archBin);
    for(int i = 0; i < numReg; i++){
        archBin.read(reinterpret_cast<char*>(&libro), tamReg);
        
        archReporte << "LIBRO No. " << setfill('0') << setw(3) << i + 1 << 
                setfill(' ') << endl; 
        archReporte << setw(5) << " " << "CODIGO" << setw(10) << "TITULO" <<
                setw(59) << "AUTOR" << setw(31) << "PRECIO" << setw(20) <<
                "LIBROS VENDIDOS" << setw(12) << "RANKINGS" << endl;
        archReporte << setw(5) << " " << left << setw(10) << libro.codigo <<
                setw(60) << libro.titulo << setw(30) << libro.autor << right <<
                setw(6) << libro.precio << setw(13) << libro.librosVendidos <<
                setw(15) << libro.ranking << endl;
        imprimirCaracter('-', archReporte);
        archReporte << setw(5) << " " << "VENTAS REALIZADAS" << endl;
        archReporte << setw(5) << " " << "No." << setw(6) << "DNI" << setw(12) 
                << "NOMBRE" << setw(55) << "CALIFICACION" << setw(15) <<
                "FECHA" << endl;
        for(int j = 0; j < libro.librosVendidos;j++){
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
        imprimirCaracter('-', archReporte);
        archReporte << setw(5) << " " << "FECHA MAS RECIENTE DE COMPRA: " <<
                setfill('0') << setw(2) << libro.fechaMasReciente.dd << "/" <<
                setw(2) << libro.fechaMasReciente.mm << "/" << setw(4) <<
                libro.fechaMasReciente.aa << setfill(' ') << endl;
        imprimirCaracter('=', archReporte);
    }
    
}

void imprimirEncabezado(ofstream &archReporte){
    
    archReporte << setw(MAX_CAR / 2 + 8) << "LIBRERIA PUCP-TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 17) << "RESULTADO DE LAS VENTAS "
            "REALIZADAS" << endl;
    
    imprimirCaracter('=', archReporte);
    archReporte << setprecision(2) << fixed;
}

void imprimirCaracter(char car, ofstream &archReporte){
    
    for(int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
    
}