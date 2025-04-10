/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 9 de abril de 2025, 02:31 PM
 */

#include <iostream>
#include <fstream>

using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecarga.h"


/*
 * 
 */
int main(int argc, char** argv) {

//    54393647,Reyes Tang Edward 

    struct Libro libros[2]{};
    struct Cliente clientes[2]{};
    ifstream archLibIn,archClieIn;
    ofstream archLibOut,archClieOut;
    AperturaDeUnArchivoDeTextosParaLeer(archLibIn,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClieIn,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archLibOut,"pruebaLib.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archClieOut,"pruebaClie.txt");
    
    archLibIn>>libros[0];
    archLibIn>>libros[1];
    archLibOut<<libros[0];
    archLibOut<<libros[1];
        
    archClieIn>>clientes[0];
    archClieIn>>clientes[1];
    archClieOut<<clientes[0];
    archClieOut<<clientes[1];
    
//    000004,46582367,  IIM5175    MBQ9495

    struct LibroSolicitado pedido{4,"IIM5175"};
    
    if(pedido>>libros){
        cout<<"Acerca del pedido:"<<endl;
        cout<<pedido.precio<<"  "<<pedido.atendido<<endl;
        archLibOut<<endl<<"DESPUES"<<endl;
        archLibOut<<libros[0];
        archLibOut<<endl;
    }
    else cout<<"no se encontro el libro"<<endl;
    
    if(clientes[0]<<pedido){
        archClieOut<<endl<<"DESPUES"<<endl;
        ++clientes[0];
        archClieOut<<clientes[0];
        archClieOut<<endl;
    }
    else cout<<"No se pudo colocar el pedido al cliente"<<endl;
    
    
    
//    IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23

    return 0;
}

