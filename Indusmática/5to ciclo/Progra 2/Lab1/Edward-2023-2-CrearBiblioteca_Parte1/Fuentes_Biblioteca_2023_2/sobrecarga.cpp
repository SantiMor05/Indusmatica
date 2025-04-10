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


bool operator >>(ifstream &arch,struct Cliente &cliente){
    
    arch>>cliente.dni;
    if(arch.eof())return false;
    arch.get();
    arch.getline(cliente.nombre,60,',');
    arch>>cliente.telefono;
    cliente.cantidadProductosEntrgados=0;
    cliente.montoTotal=0;
    return true;
}

bool operator >>(ifstream &arch,struct Producto &producto){
    
    arch.getline(producto.codigo,8,',');
    if(arch.eof())return false;
    arch.getline(producto.descripcion,60,',');
    arch>>producto.precio;
    arch.get();
    arch>>producto.stock;
    arch.get();
    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;
    return true;
}

bool operator >>(ifstream &arch,struct Pedido &pedido){
    
    arch.getline(pedido.CodigoProducto,8,',');
    if(arch.eof())return false;
    arch>>pedido.dniCliente;
    arch.get();
    pedido.precioProducto=0;
    return true;
}

void operator +=(struct Cliente *clientes,const struct Pedido &pedido){
    
    for (int i = 0; clientes[i].dni; i++) {
        if(clientes[i].dni==pedido.dniCliente){
            agregarPedido(clientes[i],pedido);
            return;
        }
    }
    cout<<"No cliente"<<endl;
}

void agregarPedido(struct Cliente &cliente,const struct Pedido &pedido){
    
    int cant=cliente.cantidadProductosEntrgados;
    strcpy(cliente.productosEntregados[cant].codigo,pedido.CodigoProducto);
    cliente.productosEntregados[cant].precio=pedido.precioProducto;
    cliente.cantidadProductosEntrgados++;
}

bool operator +=(struct Producto *productos,struct Pedido &pedido){

    for (int i = 0; strcmp(productos[i].codigo,"XXX"); i++) {
        if(not strcmp(productos[i].codigo,pedido.CodigoProducto)){
            return actualizarProduc(productos[i],pedido);
        }
    }
    cout<<"No producto"<<endl;
    return false;
}

bool actualizarProduc(struct Producto &producto,struct Pedido &pedido){
    
    pedido.precioProducto=producto.precio;
    int cant;
    if(producto.stock>0){
        cant=producto.cantidadClientesServidos;
        producto.clientesServidos[cant]=pedido.dniCliente;
        producto.cantidadClientesServidos++;
        producto.stock--;
        return true;
    }
    else{
        cant=producto.cantidadClientesNoServidos;
        producto.clientesNoServidos[cant]=pedido.dniCliente;
        producto.cantidadClientesNoServidos++;
        return false;
    }
}

void operator <<(ofstream &arch,const struct Cliente &cliente){
    
    arch.precision(2);
    arch<<fixed;
    arch<<setw(8)<<cliente.dni<<"  "<<left<<setw(60)<<cliente.nombre<<"  "<<
            cliente.telefono<<"  "<<right<<setw(9)<<cliente.montoTotal<<"  "<<
            "Productos entregados: ";
    if(cliente.cantidadProductosEntrgados>0){
        for (int i = 0; i < cliente.cantidadProductosEntrgados; i++) {
            arch<<cliente.productosEntregados[i].codigo<<"  ";
        }
        arch<<endl;
    }
    else arch<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
}

void operator <<(ofstream &arch,const struct Producto &producto){
    
    arch<<producto.codigo<<"  "<<left<<setw(60)<<producto.descripcion<<"  "<<
            right<<setw(9)<<producto.precio<<"  "<<setw(3)<<producto.stock<<endl;
    arch<<"Clientes atendidos: ";
    if(producto.cantidadClientesServidos){
        imprimirArr(arch,producto.clientesServidos,
                producto.cantidadClientesServidos);
    }
    else arch<<"NO SE ATENDIERON PEDIDOS"<<endl;
    
    arch<<"Clientes no atendidos: ";
    if(producto.cantidadClientesNoServidos){
        imprimirArr(arch,producto.clientesNoServidos,
                producto.cantidadClientesNoServidos);
    }
    else arch<<"NO HAY CLIENTES SIN ATENDER"<<endl;  
}

void imprimirArr(ofstream &arch,const int*dnis,int cant){
    
    for (int i = 0; i < cant; i++) {
        arch<<right<<setw(8)<<dnis[i]<<"  ";
    }
    arch<<endl;
}
