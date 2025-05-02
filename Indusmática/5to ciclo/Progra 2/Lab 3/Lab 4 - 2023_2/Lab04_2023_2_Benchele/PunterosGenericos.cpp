/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones_Auxiliares.cpp
 * Author: Lenovo
 * 
 * Created on 1 de mayo de 2025, 07:19 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#include "PunterosVoid.h"
#define MAX_LINEA 96
#define MAX_LETRAS 60
#define NO_ENCONTRADO -1
#define INCREMENTO 5
using namespace std;

enum PRODUCTOS{COD, DESC, PREC, TIP};
enum CLIENTES{DNI, NOMB, LIS, LIN};

enum PEDIDOS{CODPRO, CANT, TOT};

//Comunes

void verificar_Apertura_I(ifstream &arch, const char*nombArch){
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}
void verificar_Apertura_O(ofstream &arch, const char*nombArch){
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

char *leerCadenaExacta(ifstream &arch, char delimitador){
    char buffer[200], *cad;
    arch.getline(buffer, 200, delimitador);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void incrementarEspacios(void **&puntGen, int &numDat, int &cap){
    void **aux;
    cap += INCREMENTO;
    if(puntGen == nullptr){
        puntGen = new void*[cap]{};
        numDat = 1;
    }
    else{
        aux = new void*[cap]{};
        for (int i = 0; i < numDat; i++)aux[i] = puntGen[i];
        delete puntGen;
        puntGen = aux;
    }
}

void imprimir_Linea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}

//Cargar productos

void cargarProductos(const char*nombArch, void *&pro){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    void **productos = nullptr;
    void *registro;
    int nd = 0, cap = 0;
    while (true) {
        registro = leerRegistroProd(arch);
        if(arch.eof())break;
        if(nd == cap)incrementarEspacios(productos, nd, cap);
        productos[nd - 1] = registro;
        nd++;
    }
    imprimeproductos(productos);
    pro = productos;
    //imprimeproductos(pro);
}


/*
 BIT-434,Campana Extractora modelo Glass,375.09,S
 SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
 //codigo, descripcion, precio, tipo de linea
 */
void *leerRegistroProd(ifstream &arch){
    void **reg;
    char *cod, *desc, *tipLinea, c;
    double *precio;
    cod = leerCadenaExacta(arch, ',');
    if(arch.eof())return nullptr;
    desc = leerCadenaExacta(arch, ',');
    precio = new double;
    tipLinea = new char;
    arch>>*precio>>c>>*tipLinea;
    arch.get();
    
    //COD, DESC, PREC, TIP}
    reg = new void*[4]{};
    reg[COD] = cod;
    reg[DESC] = desc;
    reg[PREC] = precio;
    reg[TIP] = tipLinea;
    return reg;
}

//Cargar clientes

void cargaCliente(const char*nombArch, void *&cli){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);

    void **clientes = nullptr;
    void *registro;
    int nd = 0, cap = 0;
    while (true) {
        registro = leerRegistroCli(arch);
        if(arch.eof())break;
        if(nd == cap)incrementarEspacios(clientes, nd, cap);
        clientes[nd - 1] = registro;
        nd++;
    }
    imprimeclientes(clientes);
    cli = clientes;
    //imprimeclientes(cli);
}
/*
 79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
 16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
 dni, nombre, telefono, y linea de credito
 */
void *leerRegistroCli(ifstream &arch){
    void **reg;
    int *dni, *tel; 
    double *cred;
    char *nomb, c;
    dni = new int;
    arch>>*dni;
    if(arch.eof())return nullptr;
    arch.get();
    nomb = leerCadenaExacta(arch, ',');
    tel = new int;
    cred = new double;
    arch>>*tel>>c>>*cred;
    
    //DNI, NOMB, LIS, LIN
    reg = new void*[4]{};
    reg[DNI] = dni;
    reg[NOMB] = nomb;
    //reg[LIS] = nullptr;
    reg[LIN] = cred;
    return reg;
}

//Cargar pedidos
/*
 JXD-139,50375303,6
 CRU-009,50375303,5
 //Cod producto, dni cliente, cantidad
 */
void cargaPedidos(const char*nombArch, void *pro, void *cli){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);

    void **productos = (void **)pro, **clientes = (void **)cli;
    
    char codPro[8], c;
    int posPro, posCli, dniCLi, cantidad;
    int numDat = 0;
    while (clientes[numDat])numDat++;

    int nd[numDat]{}, cap[numDat]{};
    
    while (true) {
        arch.getline(codPro, 8, ',');
        if(arch.eof())break;
        arch>>dniCLi>>c>>cantidad;
        arch.get();
        posPro = buscarPosProd(codPro, productos);
        posCli = buscarPosCLiente(dniCLi, clientes);
        if(posPro != NO_ENCONTRADO and posCli != NO_ENCONTRADO){
            actualizarPedido(productos[posPro], clientes[posCli], nd[posCli], 
                             cap[posCli], cantidad);
        }
    }

}
int buscarPosProd(char *codPro, void **productos){
    for (int i = 0; productos[i]; i++) {
        if(sonIguales(codPro, productos[i]))return i;
    }
    return NO_ENCONTRADO;
}
int buscarPosCLiente(int dniCLi, void **clientes){
    for (int i = 0; clientes[i]; i++) {
        if(sonIguales(dniCLi, clientes[i]))return i;
    }
    return NO_ENCONTRADO;
}
bool sonIguales(char *codPro, void *pro){
    void **producto = (void **)pro;
    char *cod = (char *)producto[COD];
    return strcmp(codPro, cod) == 0;
}
bool sonIguales(int dniCLi, void *cli){
    void **cliente = (void **)cli;
    int *dni = (int *)cliente[DNI];
    return *dni == dniCLi;
}

void actualizarPedido(void *pro, void *cli, int &nd, int &cap, int cantidad){
    void **producto = (void **)pro, **cliente = (void **)cli;
    void **pedidos = (void **)cliente[LIS];
    void *regPedidos;
    double *precio = (double *)producto[PREC];
    char *reqCred = (char *)producto[TIP];
    double *credCli = (double *)cliente[LIN];
    double totalPed = (*precio)*cantidad;
    
    if(totalPed < *(double*)cliente[LIN] or *reqCred != 'S'){
        if(*reqCred == 'S')*(double *)cliente[LIN] -=totalPed;
        regPedidos = ponerPedido(producto[COD], cantidad, *precio*cantidad);
        if(nd == cap)incrementarEspacios(pedidos, nd, cap);
        pedidos[nd - 1] = regPedidos;
        cliente[LIS] = pedidos;
        nd++;
    }
}

void *ponerPedido(void *codProducto, int cantidad, double totalPed){
    void **ped;    
    char *codPro = (char *)codProducto;
    int *cant = new int;
    *cant = cantidad;
    double *totPed = new double;
    *totPed = totalPed;
    
    ped = new void*[3]{};
    //CODPRO, CANT, TOT
    ped[CODPRO] = codPro;
    ped[CANT] = cant;
    ped[TOT] = totPed;
    return ped;
}


//Imprimir reporte
void imprimirReporte(const char*nombArch, void *cli){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    
    void **clientes = (void **)cli;
    arch<<fixed<<setprecision(2);
    imprimir_Encabezado(arch, 1);
    
    for (int i = 0; clientes[i]; i++) {
        imprimir_Encabezado(arch,2);
        imprimirCliente(arch, clientes[i]);
        imprimir_Linea(arch,'=');
    }
}

void imprimirCliente(ofstream &arch, void *cli){
    void **cliente = (void **)cli;
    //COD, DESC, PREC, TIP //Productos
    //DNI, NOMB, LIS, LIN //Clientes
    //CODPRO, CANT, TOT //Pedidos
    char *nombCli = (char *)cliente[NOMB];
    int *dniCLi = (int *)cliente[DNI]; 
    double *credCLi = (double *)cliente[LIN];
    void **regPed = (void **)cliente[LIS];
    
    arch<<setw(12)<<*dniCLi<<setw(8)<<' '<<left<<setw(MAX_LETRAS)<<nombCli;
    arch<<right<<setw(12)<<*credCLi<<endl;
    
    imprimir_Encabezado(arch,3);
    if(regPed and regPed[DNI]){
        for(int i = 0;regPed[i];i++){
            imprimirPedidos(arch,regPed[i]);
        }   
    } 
    else{
        arch<<endl<<setw((MAX_LINEA+9)/2)<<"> [NO SE CONCRETARON";
        arch<<" PEDIDOS] <"<<endl<<endl;
    }
}
void imprimirPedidos(ofstream &arch, void *ped){
    void **pedido = (void **)ped;
    char *codPro = (char *)pedido[CODPRO];
    int *cantPro = (int *)pedido[CANT];
    double *totalPed = (double *)pedido[TOT];
    
    arch<<setw(11)<<codPro<<setw(10)<<*cantPro<<setw(15)<<*totalPed;
    arch<<endl;
}

void imprimir_Encabezado(ofstream &arch,int tipo){
    if(tipo == 1){
        arch<<setw((MAX_LINEA+14)/2)<<"REPORTE DE PEDIDOS ATENDIDOS";
        arch<<" POR CLIENTE"<<endl;
        imprimir_Linea(arch, '=');
    } 
    else{
        if(tipo == 2){
            arch<<setw(7)<<"DNI"<<setw(13)<<' '<<left<<setw(MAX_LETRAS)<<"Nombre";
            arch<<right<<setw(12)<<"Credito"<<endl;
        }   
        else{
            imprimir_Linea(arch, '-');
            arch<<setw(22)<<"Pedidos atendidos:"<<endl;
            imprimir_Linea(arch, '-');
            arch<<setw(10)<<"Codigo"<<setw(14)<<"Cantidad"<<setw(12)<<"Total";
            arch<<endl;
            imprimir_Linea(arch, '-');
        }
    } 
}