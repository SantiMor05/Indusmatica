#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesSobrecargadas.h"
#include "FuncionesAuxiliares.h"

using namespace std;

void leerLibros(struct Libro *libros, int &n) {

    ifstream archLibros;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");

    n = 0;
    bool valor;
    while (true) {
        valor = archLibros >> libros[n];
        if (!valor)
            break;
        n++;
    }
    strcpy(libros[n].codigo, "FIN");
    n++;

}

void leerClientes(struct Cliente *clientes, int &n) {


    ifstream archClientes;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");

    n = 0;
    bool valor;
    while (true) {
        valor = archClientes >> clientes[n];
        if (!valor)
            break;
        n++;
    }


}

void leerPedidos(struct Libro *libros, int nLibros, struct Cliente *clientes,
        int nClientes) {

    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos.txt");

    struct LibroSolicitado pedido;
    int dni, pos;
    bool valor;
    while (true) {
        arch >> pedido.numeroDePedido;
        if(arch.eof())break;
        arch.get();
        arch >> dni;
        pos = buscarCliente(dni, clientes, nClientes);
        if (pos != -1) {
            while (arch.get() != '\n') {
                arch >> pedido.codigoDelLibro;
                pedido >> libros;
                valor = clientes[pos] << pedido;
                if (!valor)
                    while (arch.get() != '\n');
            }
        } else
            while (arch.get() != '\n');
    }
    for (int i = 0; i < nClientes; i++)
        ++(clientes[i]);
}

int buscarCliente(int dni, struct Cliente *clientes, int n) {

    for (int i = 0; i < n; i++)
        if (clientes[i].dni == dni)
            return i;

    return -1;

}

void imprimriLibros(struct Libro *libros, int nLibros) {

    ofstream outLibros;
    AperturaDeUnArchivoDeTextosParaEscribir(outLibros, "ReporteLibros.txt");

    outLibros << "LIBROS" << endl;
    imprimirCaracter('-', 125, outLibros);
    outLibros << "Codigo" << setw(10) << "Titulo" << setw(64) << "Autor" <<
            setw(35) << "Stock" << setw(8) << "Precio" << endl;

    imprimirCaracter('=', 125, outLibros);

    for (int i = 0; i < nLibros; i++) {
        outLibros << libros[i];
    }

}

void imprimirCaracter(char car, int n, ofstream &arch) {

    for (int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;

}

void imprimirClientes(struct Cliente *clientes, int n) {
    
    ofstream outClientes;

    AperturaDeUnArchivoDeTextosParaEscribir(outClientes, "ReporteClientes.txt");

    outClientes << "CLIENTES" << endl;
    imprimirCaracter('-', 40, outClientes);
    outClientes << "DNI" << setw(14) << "Nombre" << endl;
    imprimirCaracter('=', 40, outClientes);
    
    for (int i =0; i < n; i++)
        outClientes  << clientes[i];

    }