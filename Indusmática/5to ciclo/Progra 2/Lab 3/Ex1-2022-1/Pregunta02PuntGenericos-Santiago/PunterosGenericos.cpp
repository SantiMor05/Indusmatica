/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: santi
 * 
 * Created on 1 de mayo de 2025, 21:52
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"

using namespace std;
#define NO_ENCONTRADO -1
#define INCREMENTOS 5
#define MAX_CAR 85

void cargaproductos(void *&productos){
    
    ifstream arch("productos2.csv", ios::in);
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
    
    aux = new void*[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    productos = aux;
    
}


void *leerProducto(ifstream &arch){
    
    int cod, *codigo,*cant;
    char *descripcion,car;
    double *precio;
    void **registro;
    
    arch >> cod;
    if(arch.eof())return nullptr;
    codigo = new int{cod};
    cant = new int;
    precio = new double;
    arch.get();
    descripcion = leerCadenaExacta(arch, ',');
    arch >> *precio >> car >> *cant;
    
    
    registro = new void*[4];
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = precio;
    registro[3] = cant;
    
    return registro;
}

char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}


void cargapedidos(void *&pedidos){
    
    ifstream arch("pedidos2.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Pedidos" << endl;
        exit(1);
    }
    
    void *buffer[200], *registro, **aux;
    int numDat = 0;
    while(true){
        registro = leerPedido(arch);
        if(registro == nullptr)break;
        buffer[numDat] = registro;
        numDat++;
    }
    
    aux = new void*[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    pedidos = aux;
    
}

void *leerPedido(ifstream &arch){
    
    int cod, *codigo, *cant, *dni, *fecha, dd,mm,aa;
    char *descripcion, *estado, car;
    void **registro;
    arch >> cod;
    if(arch.eof())return nullptr;
    codigo = new int{cod};
    cant = new int;
    dni = new int;
    fecha = new int;
    estado = new char{'N'};
    arch.get();
    descripcion = leerCadenaExacta(arch, ',');
    arch >> *cant >> car >> *dni >> car >> dd >>car >> mm >> car >> aa;
    *fecha = aa * 10000 + mm * 100 + dd;
    
    registro = new void *[6];
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = cant;
    registro[3] = dni;
    registro[4] = fecha;
    registro[5] = estado;
    
    return registro;
}


void procesaclientes(void *productos, void *pedidos, void *&clientes){
    
    ifstream arch("clientes2.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Clientes" << endl;
        exit(1);
    }
    
    actualizarEstadosProductos(productos, pedidos);
    
    void *buffer[30], *cliente, **aux;
    int numDat = 0;
    while(true){
        cliente = leerCliente(arch, pedidos);
        if(cliente == nullptr)break;
        buffer[numDat] = cliente;
        numDat++;
    }
    
    aux = new void*[numDat + 1]{};
    for(int i = 0; i < numDat; i++)
        aux[i] = buffer[i];
    
    clientes = aux;
}



void *leerCliente(ifstream &arch, void *pedidos){
    
    int *dni, doc;
    char *nombre;
    
    arch >> doc;
    if(arch.eof()) return nullptr;
    dni = new int {doc};
    arch.get();
    nombre = leerCadenaExacta(arch, '\n');
 
    void **registro = new void*[3]{};
    registro[0] = dni;
    registro[1] = nombre;
    
    agregarPedidos(doc, registro[2], pedidos);
    
    return registro;
}


void agregarPedidos(int dni, void *&listaPedidos, void *pedidos){
    
    int numDat = 0, cap = 0, *cliente;
    char *estado;
    void **regListaPedidos = nullptr;
    void **regPedidos = (void **)pedidos;
    void **detallePedido;
    for(int i = 0; regPedidos[i]; i++){
        detallePedido = (void **)regPedidos[i];
        cliente = (int *)detallePedido[3];
        if(dni == *cliente){
            estado = (char *)detallePedido[5];
            if(*estado == 'A'){
                if(numDat == cap)
                    incrementarEspacios(listaPedidos, numDat, cap);
                regListaPedidos = (void **)listaPedidos;
                agregarPedidos(regListaPedidos[numDat - 1], regPedidos[i]);
                numDat++;
            }
            
        }
    }
    //listaPedidos = regListaPedidos;
}

void agregarPedidos(void *&pedCliente, void *pedido){
    
    void **registro = new void*[4];
    void **detallePedido = (void **)pedido;
    
    int *fechaPed, *fechaCli, *codPed, *codCli,*cantPed, *cantCli;
    char *descPed, *descCli;
    
    fechaPed = (int *)detallePedido[4];
    codPed = (int *)detallePedido[0];
    cantPed = (int *)detallePedido[2];
    descPed = (char *)detallePedido[1];
    
    fechaCli = new int {*fechaPed};
    codCli = new int {*codPed};
    cantCli = new int{*cantPed};
    descCli = asignarCadena(descPed);
    
    registro[0] = fechaCli;
    registro[1] = codCli;
    registro[2] = descCli;
    registro[3] = cantCli;
    
    pedCliente = registro;
}

char *asignarCadena(char *cadena){
    
    char *cad = new char[strlen(cadena) + 1];
    strcpy(cad, cadena);
    return cad;
    
}

void incrementarEspacios(void *&pedidos, int &numDat, int &cap){
    
    
    cap += INCREMENTOS;
    if(pedidos == nullptr){
        void **aux = new void*[cap]{};
        numDat = 1;
        pedidos = aux;
    }
    else{
        void **regPedidos = (void **)pedidos;
        void **aux = new void*[cap]{};
        for(int i = 0; i < numDat; i++){
            aux[i] = regPedidos[i];
        }
        delete regPedidos;
        pedidos = aux;
    }
        
    
}


void actualizarEstadosProductos(void *productos, void *pedidos){
    
    void **regPedidos = (void **)pedidos;
    void **regProd = (void **)productos;
    void **detallePedido;
    
    int *codigo, *cant;
    int posProd;
    
    for(int i = 0; regPedidos[i]; i++){
        detallePedido = (void **)regPedidos[i];
        codigo = (int *)detallePedido[0];
        cant = (int *)detallePedido[2];
        
        posProd = buscarProducto(*codigo, productos);
        if(posProd != NO_ENCONTRADO){
            verificarEstado(regPedidos[i], regProd[posProd], *cant);
        }
    }
    
}

void verificarEstado(void *pedido, void *producto, int cant){
    
    void ** detallePedido = (void**)pedido;
    void **detalleProd = (void **)producto;
    char *estado = (char *) detallePedido[5];
    int *stock = (int *)detalleProd[3];
    
    if(cant <= *stock){
        (*stock) -= cant;
        *estado = 'A';
    }
    
    
}


int buscarProducto(int codigo, void *productos){
    
    void **regProd = (void **)productos;
    void **detalleProd;
    int *cod;
    for(int i = 0; regProd[i]; i++){
        detalleProd = (void **)regProd[i];
        cod = (int *)detalleProd[0];
        if(*cod == codigo)
            return i;
    }
    return NO_ENCONTRADO;
}

void imprimeReporte(void *clientes){
    
    ofstream arch("ReporteDePedidos.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Clientes" << endl;
        exit(1);
    }
    
    void **registros = (void **)clientes;
    void **detalleCliente;
    
    int *dni;
    char *nombre;
    imprimirCaracter(arch, MAX_CAR, '=');
    arch << "PEDIDOS ATENDIDOS POR CLIENTE:" << endl;
    imprimirCaracter(arch, MAX_CAR, '=');
    for(int i = 0; registros[i]; i++){
        detalleCliente = (void **)registros[i];
        arch <<"DNI" << setw(20) << "NOMBRE" << endl;
        dni = (int *)detalleCliente[0];
        nombre = (char *)detalleCliente[1];
        arch << left << setw(18) << *dni << nombre << right << endl;
        imprimirCaracter(arch, MAX_CAR, '-');
        arch << "Pedidos atendidos:" << endl;
        imprimirCaracter(arch, MAX_CAR, '-');
        arch <<"Fecha" << setw(12) << "Codigo" << setw(25) << "Descripcion del "
                "producto" << setw(45) << "Cantidad" << endl;
        imprimirCaracter(arch, MAX_CAR, '-');
        imprimirPedidos(detalleCliente[2], arch);
    }
    
}


void imprimirPedidos(void *pedidos, ofstream &arch){
    
    if(pedidos == nullptr)
        return;
    
    void **regPedidos = (void **)pedidos;
    void **detallePedidos;
    int dd, mm, aa, *fecha, *cod, *cant;
    char *nombre;
    for(int i = 0; regPedidos[i]; i++){
        detallePedidos = (void **)regPedidos[i];
        fecha = (int *)detallePedidos[0];
        cod = (int *)detallePedidos[1];
        cant = (int *)detallePedidos[3];
        nombre = (char *)detallePedidos[2];
        
        dd = *fecha % 100;
        (*fecha)/= 100;
        mm = (*fecha) % 100;
        aa =(*fecha) / 100;
        arch << setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" << 
                setw(4) << aa << setfill(' ') << setw(10) << *cod << setw(4) 
                << " " << left << setw(45) << nombre << right << setw(4) <<
                *cant << endl;
    }
    imprimirCaracter(arch, MAX_CAR, '=');
}

void imprimirCaracter(ofstream &arch, int n, char car){
    for(int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
}