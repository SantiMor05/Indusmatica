#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
#include "FuncionesSobrecargadas.h"

using namespace std;


bool operator  >> (ifstream &arch, struct Cliente &cliente){
    
    arch >> cliente.dni;
    if(arch.eof())
        return false;
    arch.get();
    
    arch.getline(cliente.nombre, 60,',');
    arch >> cliente.telefono;
    
    cliente.montoTotal = cliente.cantidadProductosEntrgados = 0;
    return true;
}


bool operator >> (ifstream &arch, struct Producto &producto){
    
    arch.getline(producto.codigo, 8, ',');
    if(arch.eof())
        return false;
    
    arch.getline(producto.descripcion, 60, ',');
    arch >> producto.precio;
    arch.get();
    arch >> producto.stock;
    
    //Leemos el salto de linea
    arch.get();
    
    producto.cantidadClientesNoServidos = producto.cantidadClientesServidos = 0;
    
    return true;
    
}

bool operator >> (ifstream &arch, struct Pedido &pedido){
    
    arch.getline(pedido.CodigoProducto, 8, ',');
    if(arch.eof())
        return false;
    
    arch >> pedido.dniCliente;
    arch.get();
    pedido.precioProducto = 0;
    
    return true;
    
}

void operator += (struct Cliente *clientes, const struct Pedido &pedido){
    
    int n;
    
    for(int i = 0; clientes[i].dni != 0; i++){
        if(clientes[i].dni == pedido.dniCliente){
            n = clientes[i].cantidadProductosEntrgados;
            clientes[i].productosEntregados[n].precio = pedido.precioProducto;
            strcpy(clientes[i].productosEntregados[n].codigo, 
                    pedido.CodigoProducto);
            clientes[i].cantidadProductosEntrgados++;
            clientes[i].montoTotal += pedido.precioProducto;
        }
    }
    
}

bool operator += (struct Producto *productos, struct Pedido &pedido){
    
    int n;
    
    for(int i = 0; strcmp(productos[i].codigo, "XXXXXXX") != 0; i++){
        
        if(strcmp(productos[i].codigo, pedido.CodigoProducto) == 0){
            
            pedido.precioProducto = productos[i].precio;
            
            if(productos[i].stock > 0){
                n = productos[i].cantidadClientesServidos;
                productos[i].clientesServidos[n] = pedido.dniCliente;
                productos[i].stock--;
                productos[i].cantidadClientesServidos++;
                return true;
            }
            else{
                n = productos[i].cantidadClientesNoServidos;
                productos[i].clientesNoServidos[n] = pedido.dniCliente;
                productos[i].cantidadClientesNoServidos++;
                return false;
            }
        }
        
    }
    
    return false;
}

void operator << (ofstream &arch, const struct Cliente &cliente){
    
    int n = cliente.cantidadProductosEntrgados;
    arch << setprecision(2) << fixed; 
    
    arch << cliente.dni << setw(3) << " " << left << setw(40) << cliente.nombre
            << right << setw(10) << cliente.telefono << setw(10) <<
            cliente.montoTotal << setw(25) << "Productos entregados: ";
    
    if(n == 0)
        arch << "NO SE LE ENTREGARON PRODUCTOS" << endl;
    else{
        for(int i = 0; i < n; i++){
            arch << setw(9) << cliente.productosEntregados[i].codigo;
        }
        arch << endl;
    }
    
}

void operator << (ofstream &arch, const struct Producto &producto){
    
    int n;
    
    arch << setprecision(2) << fixed; 
    arch << producto.codigo << setw(3) << " " << left << setw(60) <<
            producto.descripcion << right << setw(8) << producto.precio <<
            setw(8) << producto.stock << endl;
    
    n = producto.cantidadClientesServidos;
    arch << "Cliente atendidos:     ";
    if(n == 0)
        arch << "NO SE ATENDIERON PEDIDO" << endl;
    else{
        for(int i = 0; i < n; i++){
            arch << setw(10) << producto.clientesServidos[i];
        }
        arch << endl;
    }
    
    n = producto.cantidadClientesNoServidos;
    arch << "Cliente no atendidos:  ";
    if(n == 0)
        arch << "NO HAY CLIENTES SIN ATENDER" << endl;
    else{
        for(int i = 0; i < n; i++){
            arch << setw(10) << producto.clientesNoServidos[i];
        }
        arch << endl;
    }
    
}