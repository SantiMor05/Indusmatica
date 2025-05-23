/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include <fstream>
#include "Elemento.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-1
 */
void ordernarColRec(struct Cola &cola,int n){
   struct Elemento  max,aux;
   
   if(esColaVacia(cola)) return;
   
   max= desencolar(cola);
   for (int i = 1; i < n; i++) {
       aux= desencolar(cola);
       if(aux.horaIni>max.horaIni){
           encolar(cola,max);
           max= aux;
       }else encolar(cola,aux);
       
   }
   
   ordernarColRec(cola,n-1);
   encolar(cola,max);
    
    
    
}

void ordenRecHoraFin(struct Cola &cola,int n){
   struct Elemento  max,aux;
   
   if(esColaVacia(cola)) return;
   
   max= desencolar(cola);
   for (int i = 1; i < n; i++) {
       aux= desencolar(cola);
       if(aux.horaFin>max.horaFin){
           encolar(cola,max);
           max= aux;
       }else encolar(cola,aux);
       
   }
   
   ordenRecHoraFin(cola,n-1);
   encolar(cola,max);
    
    
    
}



void modificarLlegada(struct Cola &cola,int avion,int newHh,int newMm){
    struct Elemento vehiculo;
    int n= longitud(cola.lista);
    while (n>0) {
        vehiculo= desencolar(cola);
        if(vehiculo.numero==avion){
            vehiculo.horaFin= newHh*3600+newMm*60;
            encolar(cola,vehiculo);
            break;
        }else encolar(cola,vehiculo);     
        n--;
    }

    
}

int main(int argc, char** argv) {

    struct Cola cola;
    struct Elemento elemento;
    construir(cola);

    ifstream archLee("Datos.txt",ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<endl;
        exit(1);
    }
    int hh,mm;
    char c;
    while (true) {
        archLee>>elemento.numero;
        if(archLee.eof()) break;
        archLee>>hh>>c>>mm;
        elemento.horaIni= hh*3600+ mm*60;
        archLee>>hh>>c>>mm;
        elemento.horaFin= hh*3600+ mm*60;
        
        encolar(cola,elemento);
    }
    

    imprimir(cola);

    ordernarColRec(cola,longitud(cola.lista));
    cout<<"HORA DE LLEGADA"<<endl;
    imprimir(cola);
    
    modificarLlegada(cola,2101,0,15);
    modificarLlegada(cola,2105,2,10);
    
    ordenRecHoraFin(cola,longitud(cola.lista));
    cout<<"NUEVA HORA DE LLEGADA"<<endl;
    imprimir(cola);
    
    return 0;
}

