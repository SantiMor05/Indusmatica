/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MetodoExactoDeMemoria.h"

using namespace std;

enum indices{COD,TIT,AUT};
#define LINEA 70

void lecturaDeLibros(const char*nombArch,char***&libros,int**&stock){
    
    ifstream arch(nombArch,ios::in);
    apertura(arch.is_open(),nombArch);
    
    int nd=0,*buffStock[300]{};
    char**buffLibros[300]{};
//    double precio;
    while(true){
        buffLibros[nd]=leerLibro(arch);
        if(arch.eof())break;
        buffStock[nd]=leerStock(arch);
//        arch.get();
//        arch>>precio;
//        arch.get();
        while(arch.get()!='\n');
        nd++;
    }
    nd++;
    pasarInfo(libros,stock,buffLibros,buffStock,nd);
}

void apertura(bool abierto,const char*nombArch){

    if(not abierto){
        cout<<"Error en "<<nombArch;exit(1);
    }
}

char**leerLibro(ifstream &arch){
        
    char **libro,*codigo,*titulo,*autor;
    codigo=leerCadena(arch,',');
    if(arch.eof())return nullptr;
    titulo=leerCadena(arch,',');
    autor=leerCadena(arch,',');
    libro=new char*[3]{};
    libro[0]=codigo;
    libro[1]=titulo;
    libro[2]=autor;
    return libro;
}

char*leerCadena(ifstream &arch,char deli){
    
    char aux[100],*p;
    arch.getline(aux,100,deli);
    if(arch.eof())return nullptr;
    p=new char[strlen(aux)+1];
    strcpy(p,aux);
    return p;
}

//    IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23

int*leerStock(ifstream &arch){
    
    int*stock=new int[2]{};
    arch>>stock[0];
    return stock;
}

void pasarInfo(char***&libros,int**&stock,char***buffLibros,int**buffStock,
        int nd){
    
    libros=new char**[nd]{};
    stock=new int*[nd]{};
    
    for (int i = 0; i < nd; i++) {
        libros[i]=buffLibros[i];
        stock[i]=buffStock[i];
    }
}

void pruebaDeLecturaDeLibros(const char*nombArch,char***libros,int**stock){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);
    
    arch<<"Codigo   "<<left<<setw(60)<<"Titulo libro"<<"  "<<setw(60)<<
            "Autor"<<"  "<<"Stock inicial  "<<"Cantidad no atendida"<<endl;
    for (int i = 0; libros[i]; i++) {
        imprimirLibro(arch,libros[i]);
        imprimirStock(arch,stock[i]);
    }
}

void imprimirLibro(ofstream &arch,char**libro){
    
    arch<<libro[COD]<<"  "<<left<<setw(60)<<libro[TIT]<<"  "<<setw(60)<<
            libro[AUT]<<"  ";
}

void imprimirStock(ofstream &arch,int*stock){
    
    arch<<right<<setw(13)<<stock[0]<<"  "<<setw(20)<<stock[1]<<endl;
}


    
void atencionDePedidos(const char*nombArch,char***libros,int**stock,
        int**&pedidosClientes,char***&pedidosLibros,bool**&pedidosAtendidos){
    
    ifstream arch(nombArch,ios::in);
    apertura(arch.is_open(),nombArch);
    
    int*buffCli[200]{},numPed,cantCli=0,dni,posCli;
    char**buffPedi[200]{},c;
    bool*buffAten[200]{};
    
//    000001,34460612,  CRY6839    VYG3594
    while(true){
        arch>>numPed;
        if(arch.eof())break;
        arch>>c>>dni;
        buffPedi[numPed]=leerPedido(arch);
        buffAten[numPed]=contrastarPedido(buffPedi[numPed],libros,stock);
        
        posCli=buscarCli(buffCli,dni);
        if(posCli!=-1){
            modificarCliente(buffCli[posCli],numPed);
        }
        else crearCliente(buffCli[cantCli++],dni,numPed);
    }
    cantCli++;numPed+=2;
    for (int i = 0; buffCli[i]; i++) {
        acortarEspacioCliente(buffCli[i]);
    }
    pasarInfo(pedidosClientes,pedidosLibros,pedidosAtendidos,
            buffCli,buffPedi,buffAten,cantCli,numPed);
}

void pasarInfo(int**&pedidosClientes,char***&pedidosLibros,bool**&pedidosAtendidos,
        int**buffCli,char***buffPedi,bool**buffAten,int cantCli,int cantPed){
    
    pedidosClientes=new int*[cantCli]{};
    pedidosLibros=new char**[cantPed]{};
    pedidosAtendidos=new bool*[cantPed]{};
    
    for (int i = 0; i < cantCli; i++) {
        pedidosClientes[i]=buffCli[i];
    }
    for (int i = 0; i < cantPed; i++) {
        pedidosLibros[i]=buffPedi[i];
        pedidosAtendidos[i]=buffAten[i];
    }

}

void acortarEspacioCliente(int*&cliente){
    
    int *nuevoCli,nd=0;
    while(cliente[nd++]);
    nuevoCli=new int[nd]{};
    for (int i = 0; i < nd; i++) {
        nuevoCli[i]=cliente[i];
    }
    delete cliente;
    cliente=nuevoCli;
}


bool*contrastarPedido(char**pedido,char***libros,int**stock){
    
    int pos,nd=0;
    while(pedido[nd])nd++;
    bool *atendidos=new bool[nd]{};
    
    for (int i = 0; pedido[i]; i++) {
        pos=buscarLibro(libros,pedido[i]);
        if(pos!=-1){
            atendidos[i]=verificarStock(stock[pos]);
        }
    }
    return atendidos;
}

int buscarLibro(char***libros,char*codigo){
    
    for (int i = 0; libros[i]; i++) {
        if(cumple(codigo,libros[i]))return i;
    }
    return -1;
}

bool cumple(char*codigo,char**libro){
    
    return strcmp(codigo,libro[0])==0;
}

bool verificarStock(int*stock){
    
    if(stock[0]>0){
        stock[0]--;
        return true;
    }
    stock[1]++;
    return false;
}
    
char** leerPedido(ifstream &arch){
    
    //    000001,34460612,  CRY6839    VYG3594
    char*buffLibros[10]{},**libros;
    int nd=0;
    while(arch.get()!='\n'){
        arch>>ws;
        buffLibros[nd]=new char[8];
        arch.get(buffLibros[nd],8);        
        nd++;
    }
    nd++;
    libros=new char*[nd]{};
    for (int i = 0; i < nd; i++) {
        libros[i]=buffLibros[i];
    }
    return libros;
}
        
int buscarCli(int**buffCli,int dni){
    
    for (int i = 0; buffCli[i]; i++) {
        if(iguales(dni,buffCli[i]))return i;
    }
    return -1;
}

bool iguales(int dni,int*cliente){
    return dni==cliente[0];
}
      
void crearCliente(int*&cliente,int dni,int numPed){
    
    cliente=new int[20]{};
    cliente[0]=dni;
    cliente[2]=numPed;
    cliente[1]=1;
}


void modificarCliente(int*cliente,int numPed){
    
    int nd=cliente[1],pos;
    pos=2+nd;
    cliente[pos]=numPed;
    cliente[1]++;
}


void reporteDeEntregaDePedidos(const char*nombArch,int**pedidosClientes,
        char***pedidosLibros,bool**pedidosAtendidos){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);
    
    arch<<setw(LINEA/2)<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    for (int i = 0; pedidosClientes[i]; i++) {
            imprimirCliente(arch,pedidosClientes[i],pedidosLibros,
                    pedidosAtendidos);
    }
}

void imprimirCliente(ofstream &arch,int*cliente,char***pedidosLibros,
        bool**pedidosAtendidos){
 
    int pos,numPedi,cant,dni;
    dni=cliente[0];
    cant=cliente[1];
    
    imprimeLinea(arch,LINEA,'=');
    arch<<"CLIENTE: "<<dni<<endl;
    imprimeLinea(arch,LINEA,'=');
    for (int i = 0; i < cant; i++) {
        numPedi=cliente[i+2];
        arch<<"    "<<"Pedido No.  "<<"Codigo del libro  "<<"Observacion"<<endl;
        pos=numPedi;
        if(pos!=-1){
            imprimeLinea(arch,LINEA,'-');
            imprimirPedido(arch,numPedi,pedidosLibros[pos],pedidosAtendidos[pos]);
        }
        imprimeLinea(arch,LINEA,'-');
    }
}

void imprimeLinea(ofstream &arch,int n,char c){
    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}
     
void imprimirPedido(ofstream &arch,int numPedi,char**pedido, bool*atendidos){
    
    for (int i = 0; pedido[i]; i++) {
        if(not i){
            arch<<"     "<<right<<setfill('0')<<setw(6)<<numPedi<<"       "<<
                    setfill(' ');
        }
        else arch<<setw(18)<<" ";
        imprimirLibroPedido(arch,pedido[i],atendidos[i]);
    }

}

void imprimirLibroPedido(ofstream &arch,char*libro,bool atendido){
    
    arch<<libro<<"        ";
    if(atendido)arch<<"ATENDIDO";
    else arch<<"NO ATENDIDO";
    arch<<endl;
}

