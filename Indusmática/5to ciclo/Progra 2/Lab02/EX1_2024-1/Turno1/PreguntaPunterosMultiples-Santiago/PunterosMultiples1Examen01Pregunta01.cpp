#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "PunterosMultiples1Examen01Pregunta01.h"

using namespace std;

#define INCREMENTOS 5
#define MAX_CAR_PRUEBA_VENTAS 60
#define MAX_CAR_PRUEBA_LIBROS 100

void cargarVentas(char **&ventasLibroCodigo, int **&ventasDniFechaPuntaje, 
        const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    int numDat = 0, cap = 0; 
    char *cod;
    ventasLibroCodigo = nullptr;
    ventasDniFechaPuntaje = nullptr;
    while(true){
        cod = leerCadenaExacta(arch, ',');
        if(cod == nullptr)
            break;
        if(numDat == cap)
            incrementarEspacios(ventasLibroCodigo, ventasDniFechaPuntaje, numDat,
                    cap);
        
        ventasLibroCodigo[numDat - 1] = cod;
        ventasDniFechaPuntaje[numDat - 1] = leerCalifacion(arch);
        numDat++;
    }
    
}

int *leerCalifacion(ifstream &arch){
    
    int dni, aa,mm,dd,fecha,calificacion;
    char car;
    
    arch >> dni >> car >> dd >> car >> mm >> car >>aa >> car >> calificacion;
    arch.get(); //Leemos el salto de linea
    fecha = aa * 10000 + mm * 100 + dd;
    int *aux = new int[3];
    aux[0] = dni;
    aux[1] = fecha;
    aux[2] = calificacion;
    
    return aux;
}

void incrementarEspacios(char **&codLibro, int **&ventasDniFechaPuntaje, 
        int &numDat, int &cap){
    
    cap += INCREMENTOS;
    if(codLibro == nullptr){
        codLibro = new char *[cap]{};
        ventasDniFechaPuntaje = new int *[cap]{};
        numDat = 1;
    }
    else{
        char **auxLibro;
        int **auxPuntaje;
        auxLibro = new char *[cap]{};
        auxPuntaje = new int *[cap]{};
        
        for(int i = 0; i < numDat; i++){
            auxLibro[i] = codLibro[i];
            auxPuntaje[i] = ventasDniFechaPuntaje[i];
        }
        
        delete codLibro;
        delete ventasDniFechaPuntaje;
        ventasDniFechaPuntaje = auxPuntaje;
        codLibro = auxLibro;
    }
}

char *leerCadenaExacta(ifstream &arch, char deli){
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void pruebaDeCargaDeVentas(char **ventasLibroCodigo, int **ventasDniFechaPuntaje, 
        const char *nombArch){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int *datos;
    arch << "PRUEBA DE CARGA DE VENTAS" << endl;
    imprimirCaracter(arch, MAX_CAR_PRUEBA_VENTAS, '=');
    arch << "Codigo" << setw(6) << "DNI" << setw(14) << "Fecha"  << setw(13) <<
            "Puntaje" << endl;
    imprimirCaracter(arch, MAX_CAR_PRUEBA_VENTAS, '=');
    for(int i = 0; ventasLibroCodigo[i]; i++){
        datos = ventasDniFechaPuntaje[i];
        arch << ventasLibroCodigo[i] << setw(10) << datos[0] << setw(12) <<
                datos[1] << setw(8) << datos[2] << endl;
    }
}

void imprimirCaracter(ofstream &arch, int n, char car){
    for(int i = 0; i < n;i++)
        arch.put(car);
    arch << endl;
}


void cargaLibros(char ***&libro, const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    libro = nullptr;
    int numDat = 0, cap = 0;
    char **aux;
    while(true){
        aux = leerInfoLibro(arch);
        if(aux == nullptr)
            break;
        if(numDat == cap)
            incrementarEspacios(libro, numDat, cap);
        libro[numDat - 1] = aux;
        numDat++;
    }
    qsort(libro,numDat - 1,sizeof(char ***), comparar);
}

int comparar(const void *a, const void *b){
    char ***libroI = (char ***)a;
    char ***libroK = (char ***)b;
    
    char **infoI = (char **)libroI[0];
    char **infoK = (char **)libroK[0];
    
    return strcmp(infoI[1], infoK[1]);
    
//    char **libroI = (char **)a;
//    char **libroK = (char **)b;
//    
//    return strcmp(libroI[1], libroK[1]);
}

char **leerInfoLibro(ifstream &arch){
    
    char *cod, *nombre, *autor;
    char **aux;
    cod = leerCadenaExacta(arch, ',');
    if(cod == nullptr)
        return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, '\n');
    
    aux = new char*[3];
    aux[0] = cod;
    aux[1] = nombre;
    aux[2] = autor;
    
    return aux;
}

void incrementarEspacios(char ***&libro,int &numDat, int &cap){
    
    cap += INCREMENTOS;
    if(libro == nullptr){
        libro = new char **[cap]{};
        numDat = 1;
    }
    else{
        char ***auxLibro;
        auxLibro = new char **[cap]{};
        
        for(int i = 0; i < numDat; i++)
            auxLibro[i] = libro[i];
        
        delete libro;
        libro = auxLibro;
    }
    
}


void pruebaDeCargaDeLibros(char ***libro, const char *nombArch){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    arch <<"PRUEBA DE LIBROS" << endl;
    imprimirCaracter(arch, MAX_CAR_PRUEBA_LIBROS, '=');
    arch << "Codigo" << setw(12) << "Nombre" << setw(59) << "Autor" << endl;
    imprimirCaracter(arch, MAX_CAR_PRUEBA_LIBROS, '-');
    char **datos;
    for(int i = 0; libro[i]; i++){
        datos = libro[i];
        arch << left << setw(12) << datos[0] << setw(60) << datos[1] << datos[2]
                << endl;
    }
}