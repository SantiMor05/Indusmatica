/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: santi
 * 
 * Created on 1 de mayo de 2025, 11:45
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"
using namespace std;
#define NO_ENCONTRADO -1

void cargaproductos(void *&productos){
    
    ifstream arch("Productos2.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Productos" << endl;
        exit(1);
    }
    
    void *buffer[200], *registro, **aux;
    int numDat = 0;
    while(true){
        registro = leerProducto(arch);
        if(registro == nullptr)break;
        buffer[numDat] = registro;
        numDat++;
    }
    
    aux = new void *[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    productos = aux;
}

void *leerProducto(ifstream &arch){
    
    char *cod, *descripcion, *tipo;
    double *precio;
    
    cod = leerCadenaExacta(arch, ',');
    if(cod == nullptr)return nullptr;
    descripcion = leerCadenaExacta(arch, ',');
    precio = new double;
    arch >> *precio;
    arch.get();
    tipo = leerCadenaExacta(arch, '\n');
    
    void **registros = new void*[4];
    registros[0] = cod;
    registros[1] = descripcion;
    registros[2] = precio;
    registros[3] = tipo;
    return registros;
}

char *leerCadenaExacta(ifstream &arch, char deli){
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;    
}


void cargaclientes(void *&clientes){
    
    ifstream arch("Clientes2.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Productos" << endl;
        exit(1);
    }
    
    void *buffer[200], *registro, **aux;
    int numDat = 0;
    while(true){
        registro = leerCliente(arch);
        if(registro == nullptr)break;
        buffer[numDat] = registro;
        numDat++;
    }
    
    aux = new void *[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    clientes = aux;
    
}

void* leerCliente(ifstream &arch){
    
    int *dni, doc, telefono;
    double *credito;
    char *nombre, car;
    
    arch >> doc;
    if(arch.eof())return nullptr;
    dni = new int {doc};
    credito = new double;
    arch.get();
    nombre = leerCadenaExacta(arch, ',');
    arch >> telefono >> car >> *credito;
    
    void **registros = new void*[4];
    registros[0] = dni;
    registros[1] = nombre;
    registros[2] = nullptr;
    registros[3] = credito;
    
    return registros;
    
}


void cargapedidos(void *productos,void *clientes){
    
    ifstream arch("Pedidos2.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Productos" << endl;
        exit(1);
    }
    
    char cod[8], car;
    int dni, cant, posCli, posProd, nd[200]{};
    void **regCli, **regProd;
    
    while(true){
        arch.getline(cod, 8, ',');
        if(arch.eof())break;
        arch >> dni >> car >> cant;
        arch.get();//Leemos el cambio de linea
        posCli = buscarCliente(dni, clientes);
        posProd = buscarProducto(cod, productos);
        if(posCli != NO_ENCONTRADO and posProd !=NO_ENCONTRADO){
            regCli = (void **)clientes;
            regProd = (void **) productos;
            agregarPedido(regCli[posCli], regProd[posProd], cant, nd[posCli],
                    cod);
        }
    }
    disminuirEspacios(clientes, nd);
}



void disminuirEspacios(void *clientes, int *nd){
    
    void **registros = (void **)clientes;
    void **cliente, **pedidos;
    for(int i = 0; registros[i];i++){
        cliente = (void **)registros[i];
        if(cliente[2] != nullptr){
            ajustarEspacios(cliente[2],nd[i]);
        }
    }
}


void ajustarEspacios(void *&pedidos,int nd){
    
    void **regPedidos = (void **)pedidos;
    void **aux = new void *[nd + 1]{};
    for(int i = 0; i < nd; i++)
        aux[i] = regPedidos[i];
    
    delete regPedidos;
    pedidos = aux;
}

int agregarPedido(void *cliente, void *producto,int cant, int &nd, char *cod){
    
    void **detalleCli = (void **)cliente;
    bool agregar = true;
    void **detalleProd = (void **)producto;
    double *precio = (double *)detalleProd[2],
            *linea = (double *)detalleCli[3], total;
    char *tipoProd = (char *)detalleProd[3];
    
    total = *precio * cant;
    if(*tipoProd == 'S'){
        if(*linea < total)
            agregar = false;
        else{
            *linea -= total;
        }
    }
    
    if(detalleCli[2] == nullptr and agregar) //Si la lista de pedidos apunta a null, le asignamos espacio
        asignarEspacio(detalleCli[2]);  //uno bien grande (Memoria exacta, luego lo acortamos)
    
    if(agregar){
        void **detallePedido = (void **)detalleCli[2];
        void **regPedido = new void*[3];
        double *totalPedido = new double{total};
        int *cantPedido = new int{cant};
        char *codPedido = asignarCadena(cod);
        
        regPedido[0] = codPedido;
        regPedido[1] = cantPedido;
        regPedido[2] = totalPedido;
        detallePedido[nd] = regPedido;
        nd++;
    }        
}

char *asignarCadena(char *cadena){
    
    char *cad = new char[strlen(cadena) + 1];
    strcpy(cad,cadena);
    return cad;
    
}

void asignarEspacio(void *&Listapedidos){
    
    void **pedidos = new void*[20]{};
    
    Listapedidos = pedidos;    
}

int buscarProducto(char *cod, void *productos){
    
    void **registro = (void **)productos, **detalleProd;
    char *codigo;
    for(int i = 0; registro[i]; i++){
        detalleProd = (void **)registro[i];
        codigo = (char *)detalleProd[0];
        if(strcmp(codigo, cod) == 0)
            return i;
    }
    return NO_ENCONTRADO;
    
}

int buscarCliente(int dni, void *clientes){
    
    void **registro = (void **)clientes, **detalleCliente;
    int *doc;
    for(int i = 0; registro[i]; i++){
        detalleCliente = (void **)registro[i];
        doc = (int *)detalleCliente[0];
        if(*doc == dni)
            return i;
    }
    return NO_ENCONTRADO;
}