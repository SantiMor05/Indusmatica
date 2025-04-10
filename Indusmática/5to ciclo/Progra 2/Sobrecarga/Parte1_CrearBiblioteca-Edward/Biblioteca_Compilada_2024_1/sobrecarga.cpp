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

bool operator >>(ifstream &arch,struct Libro &libro){
    
    arch.getline(libro.codigo,8,',');
    if(arch.eof())return false;
    arch.getline(libro.tiltulo,80,',');
    arch.getline(libro.autor,60,',');
    arch>>libro.stock;
    arch.get();
    arch>>libro.precio;
    arch.get();
    return true;
}

bool operator >>(ifstream &arch,struct Cliente &cliente){
    
    arch>>cliente.dni;
    if(arch.eof())return false;
    arch.get();
    arch.getline(cliente.nombre,60);
    cliente.cantDeLibros=0;
    cliente.pagoTotal=0;
    return true;
}

bool operator >>(struct LibroSolicitado &libroSoli,struct Libro*libros){
    
    for (int i = 0; strcmp(libros[i].codigo,"FIN"); i++) {
        if(not strcmp(libros[i].codigo,libroSoli.codigoDelLibro)){
            actualizar(libroSoli,libros[i]);
            return true;
        }
    }
    return false;
}

void actualizar(struct LibroSolicitado &libroSoli,struct Libro &libro){
    
    if(libro.stock>0){
        libroSoli.precio=libro.precio;
        libroSoli.atendido=true;
        libro.stock-=1;
    }
    else libroSoli.atendido=false;
}

bool operator <<(struct Cliente &cliente,struct LibroSolicitado &libroSoli){
    
    int cant=cliente.cantDeLibros;
    if(cant<30){
        agregarLibro(cliente.librosSolicitados[cant],libroSoli);
        cliente.cantDeLibros++;
        return true;
    }
    else return false;
}
void agregarLibro(struct LibroSolicitado &libroModi,
        struct LibroSolicitado &libroSoli){
    
    libroModi.numeroDePedido=libroSoli.numeroDePedido;
    libroModi.precio=libroSoli.precio;
    libroModi.atendido=libroSoli.atendido;
    strcpy(libroModi.codigoDelLibro,libroSoli.codigoDelLibro);
}

void operator ++(struct Cliente &cliente){

    double pagoTot=0;
    for (int i = 0; i < cliente.cantDeLibros; i++) {
        pagoTot+=cliente.librosSolicitados[i].precio;
    }
    cliente.pagoTotal=pagoTot;
}

void operator <<(ofstream &arch,const struct Libro &libro){
    
    arch.precision(2);
    arch<<fixed;
    arch<<libro.codigo<<"  "<<left<<setw(80)<<libro.tiltulo<<"  "<<setw(60)<<
            libro.autor<<"  "<<right<<setw(3)<<libro.stock<<"  "<<setw(8)<<
            libro.precio<<endl;
}

void operator <<(ofstream &arch,const struct Cliente &cliente){
    
    arch<<endl<<right<<setw(8)<<cliente.dni<<"  "<<cliente.nombre<<endl;
    arch<<"Libros entregados:"<<endl;
    arch<<"       Pedido No.  "<<left<<setw(8)<<"Codigo"<<"  Precio"<<endl;
    for (int i = 0; i < cliente.cantDeLibros; i++) {
        imprimirLibEntre(arch,cliente.librosSolicitados[i]);
    }
    arch<<"Total a pagar: "<<cliente.pagoTotal<<endl;
    arch<<"Libros no entregados por falta de stock:"<<endl;
    arch<<"       Pedido No.  "<<left<<setw(8)<<"Codigo"<<endl;
    for (int i = 0; i < cliente.cantDeLibros; i++) {
        imprimirLibNOEntre(arch,cliente.librosSolicitados[i]);
    }
}
        
void imprimirLibEntre(ofstream &arch,const struct LibroSolicitado &libroSoli){
    
    if(libroSoli.atendido){
        arch<<"         "<<right<<setfill('0')<<setw(6)<<libroSoli.codigoDelLibro<<
                "     "<<setfill(' ')<<libroSoli.codigoDelLibro<<"  "<<right<<
                setw(8)<<libroSoli.precio<<endl;
    }
}
        
void imprimirLibNOEntre(ofstream &arch,const struct LibroSolicitado &libroSoli){
    
    if(not libroSoli.atendido){
        arch<<"         "<<right<<setfill('0')<<setw(6)<<
                libroSoli.numeroDePedido<<"  "<<setfill(' ')<<
                libroSoli.codigoDelLibro<<endl;
    }
}