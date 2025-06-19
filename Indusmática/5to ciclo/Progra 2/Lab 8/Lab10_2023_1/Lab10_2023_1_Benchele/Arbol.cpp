/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 08:46 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbol.h"
#include "Boleta.h"
#include "Nodo.h"
#include "Escala.h"
#define MAX_LINEA 120
using namespace std;

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    eliminar();
}

/*
 5,666.90
 4,556.70
*/
void Arbol::cargarEscalas(ifstream &arch){
    int cod;
    double prec;
    while (true) {
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        arch>>prec;
        lEscala[cod - 1].asigna(cod, prec);
    }  
}

/*
 V,202319927,PATINO/MEZA/MANUEL,3,19.5,872193-E
 P,202221155,CORRALES/ZIMIC/JAIME-DANIEL,5,18,20
 S,202315724,VEGA/SAENZ/ALEXANDER-RICHARD,4,19.5,50
 */
void Arbol::crear(ifstream &arch){
    class Boleta boleta; //...(*)
    
    char tipo;
    while (true) {
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        boleta.asignaMemoria(tipo);
        boleta.lee(arch);
        insertar(boleta);
    }
    boleta.inicializa(); //Esto porque al salir del while, la ultima boleta apunta a ...(*)
                         //Y al terminar la funcion se destruiria y la ultima no apuntaria a la nada
                         //Por eso se apunta a null antes para no afectar ese dato
}

void Arbol::insertar(const class Boleta &bol){
    insertarRec(raiz, bol);
}
void Arbol::actualizaBoleta(){
    actualizaBoletaRec(raiz);
}
void Arbol::mostrarEnOrden(ofstream &arch){
    arch<<fixed<<setprecision(2);
    
    arch<<right<<setw((MAX_LINEA + 18)/2)<<"REPORTE DE ALUMNOS"<<endl;
    
    imprimirLinea(arch, '=');
    
    arch<<left<<setw(15)<<"Codigo"<<setw(40)<<"Nombre"<<right<<setw(3)<<"Escala"<<setw(13)<<"Creditos"
        <<right<<setw(14)<<"Licencia"<<setw(14)<<"Total"<<endl;
    
    imprimirLinea(arch,'-');
    mostrarEnOrdenRec(arch, raiz);
}
void Arbol::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}
void Arbol::eliminar(){
    eliminaRec(raiz);
}

//Recursivos
void Arbol::insertarRec(class Nodo *&arbol, const class Boleta &boleta){
    if(arbol == nullptr){
        arbol = new class Nodo;
        arbol->dBoleta = boleta;
        return;
    }
    if(arbol->dBoleta > boleta)insertarRec(arbol->izq, boleta);
    else insertarRec(arbol->der, boleta);
}
void Arbol::mostrarEnOrdenRec(ofstream &arch, class Nodo *arbol){
    if(arbol){
        mostrarEnOrdenRec(arch, arbol->izq);
        arch << arbol->dBoleta;
        mostrarEnOrdenRec(arch, arbol->der);
    }
}
void Arbol::actualizaBoletaRec(class Nodo *arbol){
    if(arbol == nullptr)return;
    int esc;
    double precio;
    esc = arbol->dBoleta.GetEscala();
    precio = lEscala[esc - 1].GetPrecio();
    
    arbol->dBoleta.actualiza(precio);
    actualizaBoletaRec(arbol->izq);
    actualizaBoletaRec(arbol->der);
}
void Arbol::eliminaRec(class Nodo *raiz){
    if(raiz){
        eliminaRec(raiz->izq);
        eliminaRec(raiz->der);
        delete raiz;
    }
}