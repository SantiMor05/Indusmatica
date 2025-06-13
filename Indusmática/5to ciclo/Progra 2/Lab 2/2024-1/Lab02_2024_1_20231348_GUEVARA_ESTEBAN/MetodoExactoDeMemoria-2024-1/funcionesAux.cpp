/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.cpp
 * Author: esteban
 * 
 * Created on 20 de abril de 2025, 18:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "funcionesAux.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 150


//Lectura De Libros
//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
void lecturaDeLibros(const char *nombreArch, char***&libros, int**&stock){
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    
    //1. Creacion de Buffers
    char **bufferLib[300]{},**ptLibro;
    int*bufferStock[300]{},numDat=0;
    int* ptStock;
    //2. Lectura de variables
    while (true) {
        ptLibro= lecturaLibro(archLee);
        if(archLee.eof()) break;
        ptStock= lecturaStock(archLee);
        
        //asignación
        bufferLib[numDat]= ptLibro;
        bufferStock[numDat]= ptStock;
        numDat++;
    }
    //para tener un nullptr al final;
    numDat++;
    
    //3: Asignamcion memoria Exacta
    libros= new char**[numDat]{};
    stock= new int*[numDat]{};
    for (int i = 0; i<numDat; i++) {
        libros[i]= bufferLib[i];
        stock[i]= bufferStock[i];
    }

}

int* lecturaStock(ifstream &archLee){
    int stock,*dupla;
    char c;
    double precio;
    archLee>>stock>>c>>precio;
    archLee.get();
    //Inicializamos dupla;
    dupla= new int[2]{};
    dupla[0]=stock;
    return dupla;
}

//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
char** lecturaLibro(ifstream &archLee){
    char** triplete,*ptCod,*ptNomb,*ptAut;
    
    ptCod= lecturaExacta(archLee,',');
    if(archLee.eof()) return nullptr;
    //Ya verificado que se pueda leer empezamos con las demas lecturas inicializando el triplet
    triplete= new char*[3]{};
    triplete[0]= ptCod;
    triplete[1]= lecturaExacta(archLee,',');
    triplete[2]= lecturaExacta(archLee,',');
    
    return triplete;
    
}

char* lecturaExacta(ifstream &archLee,char delim){
    char* ptCad,buffer[200];
    int cantCad;
    archLee.getline(buffer,200,delim);
    if(archLee.eof()) return nullptr;
    cantCad= strlen(buffer);
    ptCad = new char[cantCad+1];
    strcpy(ptCad,buffer);
    return ptCad;
}

//Prueba de Lectura
void pruebaDeLecturaDeLibros(const char *nombreArch, char***libros, int**stock){
    ofstream archReport(nombreArch,ios::out);
    if (not archReport.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    //variables
    char**libro;
    int* stockPorLib;
    archReport<<fixed<<setprecision(2);
    
    archReport<<left<<setw(10)<<"Codigo"<<left<<setw(60)<<"Nombre"<<
            setw(40)<<"Autor"<<right<<setw(10)<<"Stock. I"<<setw(10)<<"Cant.I"<<endl;
    for (int i = 0; libros[i]; i++) {
        libro= libros[i];
        stockPorLib= stock[i];
        archReport<<left<<setw(10)<<libro[0]<<left<<setw(60)<<libro[1]<<
            setw(40)<<libro[2]<<right<<setw(10)<<stockPorLib[0]<<setw(10)<<
                stockPorLib[1]<<endl;
    }

}

//Lectua de Pedidos
void atencionDePedidos(const char *nombreArch, char***libros, int**stock,
        int**& pedidosClientes, char***&pedidosLibros, bool**&pedidosAtendidos){
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    //1. Declarar buffers
    int *bufferClien[200]{},ndPed[200]{},ndLib[200]{},numPed,dniClien,
            numDat=0,posClie;
    char** bufferLib[200]{},c;
    bool* bufferAtend[200]{};
    
    //2. lectura
    while (true) {
        archLee>>numPed;
        if(archLee.eof()) break;
        archLee>>c>>dniClien;
        // buscamos dni;
        posClie= buscamosCliente(dniClien,bufferClien);
        if(posClie!=NO_ENCONTRADO){
            //Existe un cliente al cual podemos modificar;
            modificamosCliente(bufferClien[posClie],ndPed[posClie],numPed);
            
        }else{
            //Tenemos q agregar al cliente
            agregamosCliente(bufferClien[numDat],dniClien,ndPed[numDat],numPed,numDat);
        }
        
        //Espcamos a agregar los libros por pedido
        agregamosLibrosYAtendidos(archLee,bufferLib[numPed-1],
                bufferAtend[numPed-1],ndLib[numPed-1],libros,stock);

    }

    //3. Asignacion Memoria Exacta
    asignacionExacta(pedidosAtendidos,pedidosClientes,pedidosLibros,
            bufferAtend,bufferClien,bufferLib,ndLib,ndPed,numDat);
    
    
}

void asignacionExacta(bool**& pedidosAtendidos,int**&pedidosClientes,
        char***&pedidosLibros,bool** bufferAtend,int** bufferClien,char*** bufferLib,
        int*ndLib,int*ndPed,int numDat){
    int canPed=0;
    //para el nullptr
    numDat++;
    //INicializamos
    pedidosClientes= new int*[numDat];
    while (bufferLib[canPed]) canPed++;

    cout<<canPed;;
    
    
    
}

void agregamosLibrosYAtendidos(ifstream &archLee,char** bufferLibros,
        bool*bufferAtendibles,int &ndLib,char*** libros,int **stock){
    char c,codLibro[8],*ptCodLibro;
    int posLibro,*auxStock,stockActual;
    
    // inicializamos
    bufferLibros= new char*[10]{};
    bufferAtendibles= new bool[10]{};
    
    while (true) {
        c= archLee.get();
        if(c=='\n') break;
        archLee>>codLibro;
        ptCodLibro= new char[8]{};
        strcpy(ptCodLibro,codLibro);
        // buscamos libro
        posLibro= buscamosLibro(ptCodLibro,libros);
        if(posLibro!=NO_ENCONTRADO){
            //agregamos libros
            bufferLibros[ndLib]= ptCodLibro;
            //verificamos si puede ser atendido
            auxStock=stock[posLibro]; 
            if(auxStock[0]>=0){
                bufferAtendibles[ndLib]=true;
                auxStock[0]--;
            }else{
                bufferAtendibles[ndLib]=false;
                auxStock[1]++;
            }
            ndLib++;
        }
        
    }

}

int buscamosLibro(char*ptCodLibro,char***libros){
    char** libro;
    int cmp;
    for (int i = 0; libros[i]; i++) {
        libro= libros[i];
        cmp= strcmp(ptCodLibro,libro[0]);
        if(cmp==0) return i;
    }
    return NO_ENCONTRADO;
}

void agregamosCliente(int* cliente,int dniClien,int& ndPed,int numPed,int &numDat){
    //Que impiece en 2
    ndPed=2;
    //Inicializamos Cliente
    cliente = new int[200]{};
    
    cliente[0]=dniClien;
    cliente[1]++;
    cliente[ndPed]= numPed;
    ndPed++;
    //como un nuevo cliente fue registrado mi numDat Aumenta
    numDat++;
}

void modificamosCliente(int* cliente,int &ndPed,int numPed){
    cliente[ndPed]= numPed;
    numPed++;
}
int buscamosCliente(int dniClien,int** bufferClientes){
    int *cliente;
    for (int i = 0; bufferClientes[i] ; i++) {
        cliente= bufferClientes[i];
        if(dniClien==cliente[0]) return i;
    }
    return NO_ENCONTRADO;
    
    
}
//Prueba Lectura Pedidos
void reporteDeEntregaPedidos(const char *nombreArch, int** pedidosClientes,
        char*** pedidosLibros, bool** pedidosAtendidos){
    
}