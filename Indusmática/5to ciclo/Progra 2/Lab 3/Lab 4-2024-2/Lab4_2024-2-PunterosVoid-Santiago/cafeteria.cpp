/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cafeteria.cpp
 * Author: santi
 * 
 * Created on 29 de abril de 2025, 21:53
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "cafeteria.h"

using namespace std;

#define NO_ENCONTRADO -1
#define INCREMENTOS 5
#define MAX_CAR 80

void cargarInventario(const char *nombArch, void *&inventario){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    void *buffer[50], *aux, **registros;
    int numDat = 0;
    while(true){
        aux = leerInsumo(arch);
        if(aux == nullptr)break;
        buffer[numDat] = aux;
        numDat++;
    }
    
    registros = new void *[numDat + 1]{};
    for(int i = 0; i < numDat;i++)
        registros[i] = buffer[i];
    
    inventario = registros;
    
}

void *leerInsumo(ifstream &arch){
    
    void *registro, **detalleInsumo;
    detalleInsumo = new void*[5];
    char *cod, *nombre, *unidad;
    double *cantidad, *requerido;
    
    cod = leerCadenaExacta(arch, ',');
    if(cod ==  nullptr)return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    cantidad = new double;
    requerido = new double{0};
    
    arch >> *cantidad;
    arch.get();
    unidad = leerCadenaExacta(arch, '\n');
    
    detalleInsumo[0] = cod;
    detalleInsumo[1] = nombre;
    detalleInsumo[2] = cantidad;
    detalleInsumo[3] = requerido;
    detalleInsumo[4] = unidad;
    
    registro = detalleInsumo;
    return registro;    
}

char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char [strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}


void cargarMenu(const char *nombArch, void *&menu){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    void *buffer[50], *aux, **registros;
    int numDat = 0;
    
    while(true){
        aux = leerMenu(arch);
        if(aux == nullptr)break;
        buffer[numDat] = aux;
        numDat++;
    }
    
    registros = new void *[numDat + 1]{};
    for(int i = 0; i < numDat;i++)
        registros[i] = buffer[i];
    
    menu = registros;
    
}

void *leerMenu(ifstream &arch){
    
    void *menu, **registros;
    char *cod, *nombre, *descripcion, *tipo, car;
    bool *disponible = new bool{true};
    double *precio;
    int *ventasEstimadas;
    
    cod = leerCadenaExacta(arch, ',');
    if(cod == nullptr)return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    descripcion = leerCadenaExacta(arch, ',');
    tipo = leerCadenaExacta(arch, ',');
    precio = new double;
    ventasEstimadas = new int;
    arch >> *precio >> car >> *ventasEstimadas;
    arch.get(); //Leemos el salto de linea
    
    registros = new void*[8]{};
    registros[0] = cod;
    registros[1] = nombre;
    registros[2] = descripcion;
    registros[3] = tipo;
    registros[4] = disponible;
    registros[5] = precio;
    registros[6] = ventasEstimadas;
    
    menu = registros;
    return menu;    
}


void actualizarMenu(const char *nombArch,void *inventario, void *menu){

    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }    
    
    void**regInventario = (void **)inventario, **regMenu = (void**)menu;
    char codBebida[5], codInsumo[5], unidad[3];
    int cantidad, nd[30]{}, cap[30]{}, posMenu, posInventario;
    
    while(true){
        arch.getline(codBebida, 5,',');
        if(arch.eof())break;
        arch.getline(codInsumo, 5, ',');
        arch >> cantidad;
        arch.get();
        arch.getline(unidad, 3,'\n');
        posMenu = buscar(codBebida, menu);
        posInventario = buscar(codInsumo, inventario);
        
        if(posMenu != NO_ENCONTRADO and posInventario != NO_ENCONTRADO){
            verificarDisponibilidad(regMenu[posMenu], regInventario[posInventario],
                    cantidad, unidad, nd[posMenu], cap[posMenu]);
        }
        
    }
    
}

void verificarDisponibilidad(void *bebida, void*insumo,
                    int cantidad, char *unidad, int &numDat, int &cap){
    
    //Crear Estructura
    void **regBebidas = (void **)bebida;
    if(numDat == cap)
        incrementarEspacios(regBebidas[7], numDat, cap); 
    void **regInsumos = (void **)regBebidas[7];
    void **pedido = new void*[3]{};

    
    int *ventasEstimadas = (int *) regBebidas[6];
    double *requerido = new double{(double)cantidad * (*ventasEstimadas)};
    if(strcmp(unidad,"g") == 0) (*requerido)/=1000;
    
    pedido[0] = insumo;
    pedido[1] = requerido;
    pedido[2] = asignarCadena(unidad);
    regInsumos[numDat - 1] = pedido;
    numDat++;
    //Verificas disponibilidad
    void **detalleInsumo = (void **)insumo;
    double *cantDisponible = (double *)detalleInsumo[2];
    double *cantRequerida = (double *)detalleInsumo[3];
    (*cantRequerida) += (*requerido);
    if(*cantDisponible < *cantRequerida){
        bool *disponibilidad = (bool *)regBebidas[4];
        *disponibilidad = false;
    }
}


char *asignarCadena(char *unidad){
    
    char *cad = new char[strlen(unidad) + 1];
    strcpy(cad, unidad);
    return cad;
    
}
void incrementarEspacios(void *&insumos, int &numDat, int &cap){
    
    cap += INCREMENTOS;
    if(insumos == nullptr){
        void **aux = new void*[cap]{};
        numDat = 1;
        insumos = aux;
    }
    else{
        void **aux = new void*[cap]{}, **registros = (void**)insumos;
        for(int i = 0; i < numDat; i++)
            aux[i] = registros[i];
        
        delete registros;//Solo queremos borrar el arreglo de void, no lo datos que  contienen;
        insumos = aux;
    }
    
}

int buscar(char *codBebida, void *menu){
    
    void **registros = (void **)menu;
    void **detalleRegistro;
    char *cod;
    for(int i = 0; registros[i]; i++){
        detalleRegistro = (void **)registros[i];
        cod = (char *)detalleRegistro[0];
        if(strcmp(codBebida, cod) == 0)
            return i;
    }
    return NO_ENCONTRADO;
}


void reporteMenu(const char *nombArch, void *menu){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    } 
    
    void **regMenu = (void **)menu;
    void **detalleMenu;
    bool *disponible;
    arch << setprecision(2) << fixed;
    arch << "=============================Menu del dia======================="
            << endl;
    
    
    for(int i = 0; regMenu[i]; i++){
        detalleMenu = (void **) regMenu[i];
        disponible = (bool *)detalleMenu[4];
        if(*disponible){
            imprimirRegistro(regMenu[i],arch);
            imprimirLinea(arch, MAX_CAR, '-');
        }
    }
}

void imprimirLinea(ofstream &arch, int n, char car){
    for(int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
}

void imprimirRegistro(void *menu,ofstream &arch){
    
    void **registros = (void**)menu;
    char *cod, *nombre, *descripcion, *tipo;
    double *precio;
    
    cod = (char *)registros[0];
    nombre = (char *)registros[1];
    descripcion = (char *)registros[2];
    tipo = (char *)registros[3];
    precio = (double *)registros[5];
    
    if(strcmp(tipo, "C") == 0) arch << "Cafe: ";
    else if(strcmp(tipo, "T") == 0) arch << "Te: ";
    else if(strcmp(tipo, "I") == 0) arch << "Infusion: ";
    else arch << "Chocolate: ";
    arch << nombre << endl  << descripcion << endl;
    arch << "Precio: S/"  << *precio << endl <<"Disponible: Si" << endl;
    
}