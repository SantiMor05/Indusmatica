#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "FuncionesLaboratorio05.h"

using namespace std;

#define INCREMENTOS 5
#define MAX_CAR_REP 95

void leerPalets(char *** &almacenes) {

    ifstream arch("Stock.txt", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Stock" << endl;
        exit(1);
    }
    char **buffer[500]{}, **aux;
    int numDat = 0;

    while (true) {
        aux = leerRegistroPalet(arch);
        if (aux == nullptr) break;
        buffer[numDat] = aux;
        numDat++;
    }
    
    almacenes = new char**[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        almacenes[i] = buffer[i];
    almacenes[numDat] = nullptr;
}

char **leerRegistroPalet(ifstream &arch) {

    int almacen, almacen_ant, numDat = 0, cap = 0;
    char *cadena, palet[10], **aux = nullptr;
    static bool cambio = false;
    while (1) {
        if (!cambio) {
            arch >> almacen;
            if(arch.eof()) break;;
            if (almacen != almacen_ant and numDat != 0) {
                cambio = true;
                break;
            }
        }
        almacen_ant = almacen;
        cambio = false;

        if (numDat == cap) incrementarEspacios(aux, numDat, cap);
        arch >> ws;
        if(arch.eof())break;
        cadena = leerCadenaExacta(arch, ' ');
        arch >> palet;

        aux[numDat - 1] = cadena;
        aux[numDat] = nullptr;
        numDat++;
    }

    return aux;
}

void incrementarEspacios(char ** &productos, int &numDat, int &cap) {

    char **aux;
    cap += INCREMENTOS;

    if (productos == nullptr) {
        productos = new char *[cap]{};
        numDat = 1;
    } 
    else {
        aux = new char *[cap]{};
        for (int i = 0; i < numDat; i++) {
            aux[i] = productos[i];
        }
        delete productos;
        productos = aux;
    }

}

char *leerCadenaExacta(ifstream &arch, char delimitador) {

    char buff[500], *cad;

    arch.getline(buff, 500, delimitador);
    if(arch.eof()) return nullptr;
    cad = new char [strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

void imprimirPalets(char ***almacenes) {

    ofstream archReporte("PruebaPalets.txt", ios::out);
    if (!archReporte) {
        cout << "ERROR: No se pudo abrir el archivo PruebaPalets" << endl;
        exit(1);
    }
    
    for(int i = 0; almacenes[i]; i++){
        archReporte << "ALMACEN " << i + 1 << endl;
        imprimirProductosEnAlmacen(almacenes[i],archReporte);
    }

}

void imprimirProductosEnAlmacen(char **almacen,ofstream &archReporte){
    
    for(int i = 0; almacen[i]; i++)
        archReporte << setw(12) << almacen[i] << endl;
    
}


void leerProductos(char **&codigoProd, char **&nombreProd){
    
    ifstream arch("Productos.txt", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Productos" << endl;
        exit(1);
    }
    
    char *buffNombre[100]{}, *buffCod[100]{};
    char *cod, *nombre, **auxNombre, **auxCod;
    int numDat = 0;
    while(true){
        cod = leerCadenaExacta(arch, ',');
        if(cod == nullptr) break;
        nombre = leerCadenaExacta(arch,'\n');
        buffNombre[numDat] = nombre;
        buffCod[numDat] = cod;
        numDat++;
    }
    
    codigoProd = new char*[numDat + 1]{};
    nombreProd = new char*[numDat + 1]{};
    
    for(int i = 0; i < numDat; i++){
        codigoProd[i] =  buffCod[i];
        nombreProd[i] = buffNombre[i];
    }
}
void imprimirProductos(char **codigoProd, char **nombreProd){
    static bool primera = true;
    ofstream archReporte;
    if(primera){
        archReporte.open("PruebaProductos.txt", ios::out);
        primera = false;
    }
    else
        archReporte.open("PruebaProductosOrdenado.txt", ios::out);
    
    if (!archReporte) {
        cout << "ERROR: No se pudo abrir el archivo PruebaProductos" << endl;
        exit(1);
    }
 
    for(int i = 0; codigoProd[i]; i++){
        archReporte << setw(10) << codigoProd[i] << setw(3) << " " << 
                nombreProd[i] << endl;
    }
    
}

void ordenarProductos(char **codigoProd, char **nombreProd){
    
    int numDat = 0;
    for(; codigoProd[numDat]; numDat++);
    
    qsort(codigoProd, nombreProd, 0, numDat - 1);
    
}

void qsort(char **codigoProd, char **nombreProd, int izq, int der){
    
    if(izq >= der)
        return;
    int limite = izq;
    cambiar(codigoProd, nombreProd, izq, (izq + der)/2);
    
    for(int i = izq + 1; i <= der; i++){
        if(strcmp(nombreProd[i], nombreProd[izq]) < 0)
            cambiar(codigoProd, nombreProd, ++limite, i);
    }
    
    cambiar(codigoProd, nombreProd, limite, izq);
    
    qsort(codigoProd, nombreProd, izq, limite - 1);
    qsort(codigoProd, nombreProd, limite + 1, der);
    
}


void cambiar(char **codigoProd, char **nombreProd, int i, int k){
    
    char *cod, *nomb;
    cod = codigoProd[i];
    nomb = nombreProd[i];
    codigoProd[i] = codigoProd[k];
    nombreProd[i] = nombreProd[k];
    
    codigoProd[k] = cod;
    nombreProd[k] = nomb;
}

void cuentaProductos(char ***almacenes,char **codigoProd, char **nombreProd){
    
    ofstream archReporte("Reporte.txt", ios::out);
    if (!archReporte) {
        cout << "ERROR: No se pudo abrir el archivo PruebaPalets" << endl;
        exit(1);
    }
    
    archReporte << "Nombre del Producto" << setw(55) << "Codigo del Producto"
            << setw(20) << "Cantidad de Palets" << endl;
    int palets;
    imprimirCaracter(archReporte, MAX_CAR_REP, '=');
    
    for(int i = 0; codigoProd[i]; i++){
        archReporte << left << setw(55) << nombreProd[i] <<
                setw(6) << " "<< setw(15) << codigoProd[i] << right;
        palets = contarPalets(codigoProd[i], almacenes);
        archReporte << setw(13) << palets << endl;
    }
}

int contarPalets(char *codigoProd, char ***almacenes){
    int suma = 0;
    for(int i = 0; almacenes[i]; i++)
        suma += contarPaletsEnAlmacen(codigoProd,almacenes[i]);
    
    return suma;
}

int contarPaletsEnAlmacen(char *codigoProd,char **almacen){
    int suma = 0;
    for(int i = 0; almacen[i]; i++)
        if(strcmp(codigoProd, almacen[i]) == 0)
            suma++;
    return suma;
}

void imprimirCaracter(ofstream &archReporte, int n, char car){
    
    for(int i = 0; i < n; i++)
        archReporte.put(car);
    archReporte << endl;
    
}