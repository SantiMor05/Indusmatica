#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
#include "FuncionesSobrecargadas.h"

using namespace std;


bool operator >> (ifstream &arch, struct Libro &libro){
    
    arch.getline(libro.codigo, 8, ',');
    if(arch.eof())return false;
    
    arch.getline(libro.tiltulo, 80, ',');
    arch.getline(libro.autor, 60, ',');
    
    arch >> libro.stock;
    arch.get();
    arch >> libro.precio;
//Sacamos el salto de linea
    arch.get();
    
    return true;
}

bool operator >> (ifstream &arch, struct Cliente &cliente){
    
    arch >> cliente.dni;
    if(arch.eof())return false;
    arch.get();
    
    arch.getline(cliente.nombre, 60);
    
    cliente.cantDeLibros = cliente.pagoTotal = 0;
    
    return true;
    
}

bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *libros){
 
    for(int i = 0; strcmp(libros[i].codigo, "FIN") != 0; i++){
        if(strcmp(libros[i].codigo, libroPedido.codigoDelLibro) == 0){
            if(libros[i].stock > 0){
                libros[i].stock--;
                libroPedido.atendido = true;
                libroPedido.precio = libros[i].precio;
                return true;
            }
            else{
                libroPedido.atendido = false;
                return false;
            }
        }
    }
    return false;   
}

bool operator << (struct Cliente &cliente, const struct LibroSolicitado &pedido){
    
    int n = cliente.cantDeLibros;
    
    if(n >= 30)
        return false;
    else{
        cliente.librosSolicitados[n].atendido = pedido.atendido;
        strcpy(cliente.librosSolicitados[n].codigoDelLibro, 
                pedido.codigoDelLibro);
        cliente.librosSolicitados[n].numeroDePedido = pedido.numeroDePedido;
        cliente.librosSolicitados[n].precio = pedido.precio;
        cliente.cantDeLibros++;
        return true;
    }
}

void operator ++ (struct Cliente &cliente){
    
    int n = cliente.cantDeLibros;
    cliente.pagoTotal = 0;
    for(int i = 0; i < n; i++){
        if(cliente.librosSolicitados[i].atendido)
            cliente.pagoTotal += cliente.librosSolicitados[i].precio;
    }
    
}

void operator << (ofstream &arch, const struct Libro &libro){
    
    arch << setprecision(2) << fixed;
    arch << libro.codigo << setw(3) << " " << left << setw(65) << libro.tiltulo
            << setw(35) << libro.autor << right << setw(4) << libro.stock <<
            setw(8) << libro.precio << endl;
}

void operator << (ofstream &arch, const struct Cliente &cliente){
    int n;
    arch << setprecision(2) << fixed;
    
    arch << cliente.dni << setw(3) << " " << cliente.nombre << endl;
    arch << "Libros entregados: " << endl;
    
    arch << setw(5) << " " << "Pedido No." << setw(12) << "Codigo" << setw(12)
            << "Precio" << endl;
    
    n = cliente.cantDeLibros;
    
    for(int i = 0; i < n; i++){
        if(cliente.librosSolicitados[i].atendido){
            arch << setw(6) << " " << setfill('0') << setw(5) << 
                    cliente.librosSolicitados[i].numeroDePedido << setfill(' ')
                    << setw(17) << cliente.librosSolicitados[i].codigoDelLibro
                    << setw(10) << cliente.librosSolicitados[i].precio << endl;
        }
    }
    
    arch << "Total a pagar: " << cliente.pagoTotal << endl;
    arch << "Libros no entregados por falta de stock" << endl;
    arch << setw(5) << " " << "Pedido No." << setw(12) << "Codigo" << endl;
    for(int i = 0; i < n; i++){
        if(!cliente.librosSolicitados[i].atendido){
            arch << setw(6) << " " << setfill('0') << setw(5) << 
                    cliente.librosSolicitados[i].numeroDePedido << setfill(' ')
                    << setw(17) << cliente.librosSolicitados[i].codigoDelLibro 
                    << endl;
        }
    }
    arch << endl;
}