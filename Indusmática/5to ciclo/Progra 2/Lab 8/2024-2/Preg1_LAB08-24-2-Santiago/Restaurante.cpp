/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 11:06
 */

#include "Restaurante.h"
#include "DetalleComanda.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Restaurante::Restaurante() {
}

//Restaurante::Restaurante(const Restaurante& orig) {
//}

Restaurante::~Restaurante() {
}

void Restaurante::carga(){
    ifstream arch("comandas2.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo comandas" << endl;
        exit(1);
    }
    DetalleComanda comanda;
    while(true){
        comanda.leerComanda(arch);
        if(arch.eof())break;
        Ccomanda.encola(comanda);
    }
    cout << "Hola" <<endl;
}


void Restaurante::atiende(){
    ofstream arch("Reporte.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    
    DetalleComanda comanda;
    int n = Ccomanda.GetLongitud();
    
    arch << setprecision(2) << fixed;
    arch <<"Detalle Comandas" << endl;
    arch <<"================================================" << endl;
    
    for(int i = 0; i < n; i++){
        Ccomanda.desencola(comanda);
        comanda.imprimirDatos(arch);
        arch << endl;
        Ccomanda.encola(comanda);
    }

}

void Restaurante::elimina(int tip_prote){
//    
//    Ccomanda.eli
    
}