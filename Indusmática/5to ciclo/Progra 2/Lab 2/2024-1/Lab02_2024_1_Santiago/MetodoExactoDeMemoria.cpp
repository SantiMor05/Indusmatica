#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "MetodoExactoDeMemoria.h"

using namespace std;

#define MAX_CAR_LIBR_PRUEBA 105
#define NO_ENCONTRADO -1
#define MAX_CAR 105

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock) {

    ifstream arch(nomArch, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    char **bufferLibros[300], **auxLibro;
    int *buffStock[300], *auxStock;
    int numDat = 0;

    while (true) {
        auxLibro = leerLibro(arch);
        if (auxLibro == nullptr)break;
        auxStock = leerStock(arch);
        bufferLibros[numDat] = auxLibro;
        buffStock[numDat] = auxStock;
        numDat++;
    }

    libros = new char **[numDat + 1]{};
    stock = new int *[numDat + 1]{};

    for (int i = 0; i < numDat; i++) {
        libros[i] = bufferLibros[i];
        stock[i] = buffStock[i];
    }

}

int *leerStock(ifstream &arch) {

    int stock, *aux;
    double precio;
    arch >> stock;
    arch.get(); //Leemos la coma
    arch >> precio;
    arch.get(); //Leemos el cambio de linea

    aux = new int[2];
    aux[0] = stock;
    aux[1] = 0;

    return aux;
}

char **leerLibro(ifstream &arch) {

    char **aux, *cod, *nomb, *autor;

    cod = leerCadenaExacta(arch, ',');
    if (cod == nullptr) return nullptr;
    nomb = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, ',');

    aux = new char*[3];

    aux[0] = cod;
    aux[1] = nomb;
    aux[2] = autor;
    return aux;
}

char *leerCadenaExacta(ifstream &arch, char deli) {

    char buffer[500], *cad;
    arch.getline(buffer, 500, deli);
    if (arch.eof())return nullptr;
    cad = new char [strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;

}

void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock) {

    ofstream arch(nomArch, ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    arch << "Codigo" << setw(12) << "Nombre" << setw(60) << "Autor" << setw(30)
            << "Stock" << endl;

    imprimirCaracter(arch, MAX_CAR_LIBR_PRUEBA, '=');
    for (int i = 0; libros[i]; i++) {
        imprimirRegistroLibro(arch, libros[i], stock[i]);
    }

}

void imprimirRegistroLibro(ofstream &arch, char **libro, int *stock) {

    arch << left << setw(12) << libro[0] << setw(60) << libro[1] << setw(30)
            << libro[2] << right << setw(6) << stock[0] << endl;

}

void imprimirCaracter(ofstream &arch, int n, char car) {

    for (int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;

}

void atencionDePedidos(const char *nomArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos) {

    ifstream arch(nomArch, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    int *buffClientes[200], pedido, dni, pos;
    char **buffLibros[200], car, cod[80];
    bool *buffAtendidos[200];
    int numDat = 0, atendible;
    while (true) {
        arch >> pedido;
        if (arch.eof())break;
        arch >> car >> dni;
        pos = buscarCliente(buffClientes, numDat, dni);
        if (pos == NO_ENCONTRADO) {
            pos = numDat;
            buffClientes[numDat] = new int[50]{};
            buffLibros[numDat] = new char*[50]{};
            buffAtendidos[numDat] = new bool[50]{};
            inicializarCliente(dni, buffClientes[numDat]);
            numDat++;
        }
        while (arch.get() != '\n') {
            arch >> cod;
            agregarPedido(pedido, cod, libros, stock, buffClientes[pos], buffLibros[pos],
                    buffAtendidos[pos]);
        }
    }

    crearEspaciosExactos(buffClientes, buffLibros, buffAtendidos, numDat, 
            pedidosClientes, pedidosLibros, pedidosAtendidos);
}


void crearEspaciosExactos(int **buffClientes, char ***buffLibros, 
        bool **buffAtendidos, int numDat, int ** &pedidosClientes, 
        char ***&pedidosLibros, bool **&pedidosAtendidos){
    
    pedidosClientes = new int*[numDat + 1]{};
    pedidosLibros = new char**[numDat + 1]{};
    pedidosAtendidos = new bool*[numDat + 1]{};
    
    int *auxClientes;
    char **auxLibros;
    bool *auxAtendidos;
    
    for(int i = 0; i < numDat; i++){
        recolocarEspacios(auxClientes, auxLibros, auxAtendidos, buffClientes[i],
                buffLibros[i], buffAtendidos[i]);
        pedidosClientes[i] = auxClientes;
        pedidosLibros[i] = auxLibros;
        pedidosAtendidos[i] = auxAtendidos;
    }
    
    
    
//    delete buffLibros;
//    delete buffClientes;
//    delete buffAtendidos;
    
}

void recolocarEspacios(int *&auxClientes, char **&auxLibros, bool *&auxAtendidos, 
        int *buffClientes, char **buffLibros, bool *buffAtendidos){
    
    int cantidad = buffClientes[1] + 2;
    auxClientes = new int[cantidad]{};
    auxAtendidos = new bool[cantidad - 2]{};
    auxLibros = new char*[cantidad - 2]{};
    
    for(int i = 0; i < cantidad; i++){
        auxClientes[i] = buffClientes[i];
    }
    for(int i = 0; i < cantidad - 2; i++){
        auxAtendidos[i] = buffAtendidos[i];
        auxLibros[i] = buffLibros[i];
    }   
    delete buffLibros;
    delete buffClientes;
    delete buffAtendidos;
}

void agregarPedido(int pedido, char *cod, char ***libros, int **stock,
        int *buffClientes, char **buffLibros, bool *buffAtendidos) {

    char **libro;
    int pos, *stockLibro;
    buffClientes[1]++;
    pos = buffClientes[1] + 1;
    for (int i = 0; libros[i]; i++) {
        libro = libros[i];
        stockLibro = stock[i];
        
        if (strcmp(libro[0], cod) == 0) {
            buffClientes[pos] = pedido;
            buffLibros[pos - 2] = asignarCadena(cod);
            if (stockLibro[0] > 0) {
                stockLibro[0]--; //Restamos el stock
                buffAtendidos[pos - 2] = true;
            } else{
                buffAtendidos[pos - 2] = false;
                stockLibro[1]++; //Aumentamos el contador de no atendidos
            }
                
        }
    }
}

char *asignarCadena(char *cod){
    
    char *aux = new char[strlen(cod) + 1];
    strcpy(aux, cod);
    return aux;
    
}


void inicializarCliente(int dni, int *cliente) {

    cliente[0] = dni;
    cliente[1] = 0;

}

int buscarCliente(int **clientes, int numDat, int dni) {

    int *cliente;

    for (int i = 0; i < numDat; i++) {
        cliente = clientes[i];
        if (dni == cliente[0])
            return i;
    }
    return NO_ENCONTRADO;
}


void reporteDeEntregaDePedidos(const char *nomArch,int **pedidosClientes,
            char *** pedidosLibros, bool **pedidosAtendidos){
    
    ofstream arch(nomArch, ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << setw(MAX_CAR / 2 + 15) << "REGISTRO DE ATENCION DE PEDIDOS" << endl;
        int *pedido;
    for(int i = 0; pedidosClientes[i]; i++){
        pedido = pedidosClientes[i];
        imprimirCaracter(arch, MAX_CAR, '=');
        arch << "CLIENTE: " << setw(10) << pedido[0] << endl;
        imprimirCaracter(arch, MAX_CAR, '=');
        arch << setw(20) << "Pedido No. " << setw(25) << "Codigo del libro"
                << setw(20) << "Observacion" << endl;
        imprimirCaracter(arch, MAX_CAR, '-');
        imprimirEstado(arch, pedido, pedidosLibros[i], pedidosAtendidos[i]);

        //imprimirCaracter(arch, MAX_CAR, '-');
    }
}

void imprimirEstado(ofstream &arch, int *pedido, char **pedidosLibros, 
        bool *pedidosAtendidos){
    int pedidoAnt = pedido[2];
    for(int j =0; j < pedido[1]; j++){
        if(pedidoAnt != pedido[j + 2]){
            imprimirCaracter(arch, MAX_CAR, '-');
            arch << setw(20) << "Pedido No. " << setw(25) << "Codigo del libro"
                << setw(20) << "Observacion" << endl;
            imprimirCaracter(arch, MAX_CAR, '-');
            pedidoAnt = pedido[j+2];
        }
        arch << setw(10) << " " << setfill('0') << setw(6) << pedido[j + 2]
                << setfill(' ');
        arch << setw(25) << pedidosLibros[j] << setw(15) << " ";
        if(pedidosAtendidos[j])
            arch << "ATENDIDO" << endl;
        else
            arch << "NO ATENDIDO" << endl;
    }
}