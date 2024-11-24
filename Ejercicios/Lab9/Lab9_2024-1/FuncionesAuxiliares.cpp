#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define NO_ENCONTRADO -1
#define MAX_CAR 150

using namespace std;

void leerDatosClientes(struct Cliente *arrClientes, int &num_cientes,
        const char *nombClientes) {

    ifstream archClientes(nombClientes, ios::in);
    if (not archClientes.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombClientes << endl;
        exit(1);
    }
    num_cientes = 0;

    while (true) {
        leerCliente(arrClientes[num_cientes], archClientes);
        if (archClientes.eof())break;
        num_cientes++;
    }

}

void leerCliente(struct Cliente &cliente, ifstream &archClientes) {
    archClientes >> cliente.dni;
    if (archClientes.eof())return;
    archClientes.get();
    cliente.nombre = leerCadenaExacta(archClientes, '\n');
}

char *leerCadenaExacta(ifstream &archEntrada, const char delimitador) {

    char aux[200];
    archEntrada.getline(aux, 200, delimitador);

    int longitud = strlen(aux);

    char *ptr = new char[longitud + 1];
    strcpy(ptr, aux);
    return ptr;

}

void leerDatosLibros(struct Libro *arrLibros, int &num_libros,
        const char *nombLibros) {

    ifstream archLibros(nombLibros, ios::in);
    if (not archLibros.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombLibros << endl;
        exit(1);
    }

    num_libros = 0;
    while (true) {
        leerLibro(arrLibros[num_libros], archLibros);
        if (archLibros.eof())break;
        num_libros++;
    }
}

void leerLibro(struct Libro &libro, ifstream &archLibros) {

    libro.codigo = leerCadenaExacta(archLibros, ',');
    libro.titulo = leerCadenaExacta(archLibros, ',');
    libro.autor = leerCadenaExacta(archLibros, ',');
    archLibros >> libro.precio;
    archLibros.get();

    libro.ventas = new struct Venta[10]{};
}

void leerVentas(struct Libro *arrLibros, int num_libros,
        const char *nombVentas) {

    ifstream archVentas(nombVentas, ios::in);
    if (not archVentas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombVentas << endl;
        exit(1);
    }
    char libro[8], car;
    int dni, dd, mm, aa, pos, pos_venta, calificacion;
    while (true) {
        archVentas.getline(libro, 8, ',');
        if(archVentas.eof())break;
        pos = buscarLibro(libro, num_libros, arrLibros);
        if (pos != NO_ENCONTRADO) {
            pos_venta = arrLibros[pos].librosVendidos;
            archVentas >> arrLibros[pos].ventas[pos_venta].dni >> car >> dd >>
                    car >> mm >> car >> aa >> car >>calificacion;
            archVentas.get();
            arrLibros[pos].ventas[pos_venta].fecha.dd = dd;
            arrLibros[pos].ventas[pos_venta].fecha.mm = mm;
            arrLibros[pos].ventas[pos_venta].fecha.aa = aa;
            arrLibros[pos].ventas[pos_venta].fecha.fecha = dd + mm * 100
                    + aa * 10000;
            arrLibros[pos].ventas[pos_venta].calificacion = calificacion;
            arrLibros[pos].sumaDeCalificaciones += calificacion;
            arrLibros[pos].librosVendidos++;
        } else {
            while (archVentas.get() != '\n');
        }
    }
}

int buscarLibro(char *libro, int num_libros, struct Libro *arrLibros) {

    for (int i = 0; i < num_libros; i++) {
        if (strcmp(libro, arrLibros[i].codigo) == 0) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}

void determinarRankings(struct Libro *arrLibros, int num_libros) {

    int suma, cant_ventas;
    double promedio;
    for (int i = 0; i < num_libros; i++) {
        suma = arrLibros[i].sumaDeCalificaciones;
        cant_ventas = arrLibros[i].librosVendidos;
        if (suma != 0) {
            promedio = (double) suma / cant_ventas;
        } else
            promedio = 0;

        arrLibros[i].ranking = calcularRanking(promedio);
    }
}

int calcularRanking(double promedio) {
    if (promedio == 0) return 0;
    else if (promedio < 25) return 1;
    else if (promedio < 50) return 2;
    else if (promedio < 75) return 3;
    else return 4;
}

void ordenarLibros(struct Libro *arrLibros, int num_libros) {

    for (int i = 0; i < num_libros - 1; i++) {
        for (int j = i + 1; j < num_libros; j++) {

            if (arrLibros[i].ranking < arrLibros[j].ranking or (
                    arrLibros[i].ranking == arrLibros[j].ranking and
                    strcmp(arrLibros[i].titulo, arrLibros[j].titulo) < 0)) {
                intercambiar(arrLibros[i], arrLibros[j]);
            }
        }
    }
}

void intercambiar(struct Libro &libro1, struct Libro &libro2) {

    struct Libro aux;
    aux = libro1;
    libro1 = libro2;
    libro2 = aux;
}

void emitirReporte(struct Cliente *arrClientes, int num_clientes,
        struct Libro *arrLibros, int num_libros, const char *nombReporte) {

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirEncabezado(archReporte);

    for (int i = 0; i < num_libros; i++) {

        archReporte << "LIBRO NO. " << setfill('0') << setw(3) << i + 1 <<
                setfill(' ') << endl;
        archReporte << setw(10) << "CODIGO" << setw(10) << "TITULO" << setw(59)
                << "AUTOR" << setw(31) << "PRECIO" << setw(25) << "LIBROS "
                "VENDIDOS" << setw(12) << "RANKINGS" << endl;

        archReporte << setw(4) << " " << left << setw(10) << arrLibros[i].codigo
                << setw(60) << arrLibros[i].titulo << setw(30) <<
                arrLibros[i].autor << right << setw(6) << arrLibros[i].precio <<
                setw(18) << arrLibros[i].librosVendidos << setw(16) <<
                arrLibros[i].ranking << endl;

        imprimirCaracter(archReporte, '-');
        imprimirVentas(archReporte, arrLibros[i].ventas,
                arrLibros[i].librosVendidos, arrClientes, num_clientes);
    }

}

void imprimirVentas(ofstream &archReporte, struct Venta *ventas,
        int cant_ventas, struct Cliente *arrClientes, int num_clientes) {

    int pos;
    archReporte << setw(4) << " " << "VENTAS REALIZADAS :" << endl;
    archReporte << setw(7) << "No." << setw(6) << "DNI" << setw(14) <<
                "NOMBRE" << setw(42) << "CALIFICACION" << endl;
    
    for (int i = 0; i < cant_ventas; i++) {
        pos = buscarCliente(ventas[i].dni, num_clientes, arrClientes);
        if (pos != NO_ENCONTRADO) {

            archReporte << setw(4) << " " << setfill('0') << setw(2) << i + 1
                    << setfill(' ') << setw(12) << ventas[i].dni << setw(3) <<
                    " " << left << setw(35) << arrClientes[pos].nombre << right
                    << setw(8) << ventas[i].calificacion << endl;
        }
    }
    imprimirCaracter(archReporte, '=');
}

int buscarCliente(int dni, int num_clientes, struct Cliente *arrClientes) {

    for (int i = 0; i < num_clientes; i++) {
        if (dni == arrClientes[i].dni)

            return i;
    }
    return NO_ENCONTRADO;
}

void imprimirEncabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 8) << "LIBRERIA PUCP-TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 17) << "RESULTADO DE LAS VENTAS "
            "REALIZADAS" << endl;
    imprimirCaracter(archReporte, '=');
    archReporte << setprecision(2) << fixed;
}

void imprimirCaracter(ofstream &archReporte, char car) {
    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
       
    }
    archReporte << endl;
}