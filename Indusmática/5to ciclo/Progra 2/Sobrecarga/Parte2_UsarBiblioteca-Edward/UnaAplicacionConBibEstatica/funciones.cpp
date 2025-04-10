/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>

using namespace std;
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecarga.h"
#include "funciones.h"

void leerLibros(struct Libro*libros,const char*nombDoc){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombDoc);
    int cant=0;
    while(true){
        if(arch>>libros[cant]){
            cant++;
        }
        else break;
    }
    strcpy(libros[cant++].codigo,"FIN");
}

void leerClientes(struct Cliente*clientes,const char*nombDoc){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombDoc);
    int cant=0;
    while(true){
        if(arch>>clientes[cant]){
            cant++;
        }
        else break;
    }
    clientes[cant++].dni=0;
}
    
void procesarPedidos(struct Libro*libros,struct Cliente*clientes,const char*nombDoc){
    
    int numPedido,dni,pos;
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombDoc);
    while(true){
        arch>>numPedido;
        if(arch.eof())break;
        arch.get();
        arch>>dni;
        arch.get();
        pos=buscarClie(clientes,dni);
        if(pos!=-1){
            procesarLibros(arch,libros,clientes,numPedido,dni,pos);
        }
        else while(arch.get()!='\n');
    }
    calcPagosClien(clientes);
}

void calcPagosClien(struct Cliente*clientes){
    
    for (int i = 0;clientes[i].dni; i++) {
        ++clientes[i];
    }

}


int buscarClie(struct Cliente*clientes,int dni){
    for (int i = 0; clientes[i].dni; i++) {
        if(clientes[i].dni==dni)return i;
    }
    return -1;
}

void procesarLibros(ifstream &arch,struct Libro*libros,struct Cliente*clientes,
        int numPedido,int dni,int posClie){
    
    //    000001,34460612,  CRY6839    VYG3594

    struct LibroSolicitado pedido{};
    pedido.numeroDePedido=numPedido;
    while(arch.get()!='\n'){
        arch>>pedido.codigoDelLibro;
        if(pedido>>libros){
            clientes[posClie]<<pedido;
        }
        else cout<<"No se encontro el pedido"<<endl;
    }
}


void emitirLibros(struct Libro*libros,const char*nombDoc){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombDoc);
    for (int i = 0; strcmp(libros[i].codigo,"FIN"); i++) {
        arch<<libros[i];
//        arch<<endl;
    }

}
    
void emitirClientes(struct Cliente*clientes,const char*nombDoc){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombDoc);
    for (int i = 0; clientes[i].dni; i++) {
        arch<<clientes[i];
//        arch<<endl;
    }
}