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


void leerClientes(struct Cliente*clientes,const char*nombArch){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    
    int cantCli=0;
    while(true){
        if(arch>>clientes[cantCli]){
            cantCli++;
        }
        else break;
    }
    clientes[cantCli++].dni=0;
}

void leerProductos(struct Producto*productos,const char*nombArch){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    
    int cantPro=0;
    while(true){
        if(arch>>productos[cantPro]){
            cantPro++;
        }
        else break;
    }
    strcpy(productos[cantPro++].codigo,"XXX");
}
    
void procesarPedidos(struct Cliente*clientes,struct Producto*productos,
        const char*nombArch){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,nombArch);
    
//    JXD-139,50375303
    struct Pedido pedido{};
    while(true){
        if(arch>>pedido){
           if(productos+=pedido){
               clientes+=pedido;
           }
        }
        else break;
    }
}

void hallarMontosClie(struct Cliente*clientes){
    
    for (int i = 0; clientes[i].dni; i++) {
        calcMonto(clientes[i]);
    }

}

void calcMonto(struct Cliente &cliente){
    
    for (int i = 0; i < cliente.cantidadProductosEntrgados; i++) {
        cliente.montoTotal+=cliente.productosEntregados[i].precio;
    }
}

    
void emitirClientes(struct Cliente*clientes,const char*nombArch){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
     
    for (int i = 0; clientes[i].dni; i++) {
        arch<<clientes[i];
    }
}
    
void emitirProductos(struct Producto*productos,const char*nombArch){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
     for (int i = 0; strcmp(productos[i].codigo,"XXX"); i++) {
        arch<<productos[i];
        arch<<endl;
    }
}