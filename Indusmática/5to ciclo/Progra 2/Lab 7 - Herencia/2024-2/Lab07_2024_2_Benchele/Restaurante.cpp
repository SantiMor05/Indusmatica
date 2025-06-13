/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Restaurante.cpp
 * Author: Lenovo
 * 
 * Created on 12 de junio de 2025, 06:37 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <random>
#include "Restaurante.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 120
using namespace std;

Restaurante::Restaurante() {
    cantidad_comandas = 0;
}

void Restaurante::cargar_comandas(const char*nombArchAten, const char*nombArchComa){
    ifstream archAten(nombArchAten, ios::in);
    if(not archAten.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchAten<<endl;
        exit(1);
    }
    ifstream archComa(nombArchComa, ios::in);
    if(not archComa.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchComa<<endl;
        exit(1);
    }
    leerAtenciones(archAten);
    leerComandas(archComa);
    //imprimirVericiar();
}

//Funciones de lectura

/*
 738,11:40,12:43
 936,08:32,09:13
 ID HORAATEN HORASERV
 */
void Restaurante::leerAtenciones(ifstream &arch){
    int id, hh, mm, horaAten, horaServ;
    char c;
    while (true) {
        arch>>id;
        if(arch.eof())break;
        arch.get();
        arch>>hh>>c>>mm>>c;
        horaAten = hh*60+mm;
        arch>>hh>>c>>mm;
        horaServ = hh*60+mm;
        comandas[cantidad_comandas].asignarDatos(id, horaAten, horaServ);
        cantidad_comandas++;
    }   
}

/*
 142,P,Pollo a la Brasa,15,1,1,1,1
 142,E,Bruschetta,4,picante
 161,B,Agua Mineral,2.5,mediano
 */
void Restaurante::leerComandas(ifstream &arch){
    int id, posCom;
    char tipo;
    while (true) {
        arch>>id;
        if(arch.eof())break;
        arch.get();
        posCom = buscarComanda(id);
        if(posCom != NO_ENCONTRADO){
            comandas[posCom].actualizar(arch);
        }       
        else{
            while(arch.get() != '\n');
        }
    }
}

//Busqueda
int Restaurante::buscarComanda(int id){
    for (int i = 0; i < cantidad_comandas; i++) {
        if(id == comandas[i].GetId())return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::actualizar_comandas(){
    for (int i = 0; i < cantidad_comandas; i++) {
        comandas[i].actualizarDatos();
    }
}

//Para verificar
void Restaurante::imprimirVericiar(){
    for (int i = 0; i < cantidad_comandas; i++) {
        cout<<comandas[i].GetId()<<endl;
    }
}


void Restaurante::imprimir_comandas(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    arch<<right<<setw((MAX_LINEA + 23)/2)<<"REPORTE DEL RESTAURANTE"<<endl;
    imprimirLinea(arch, '=');
    for (int i = 0; i < cantidad_comandas; i++) {
        comandas[i].mostrarResultados(arch);

    }

}

void Restaurante::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++) arch.put(linea);
    arch<<endl;
}