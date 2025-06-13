/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.cpp
 * Author: kenyi
 * 
 * Created on 12 de junio de 2025, 04:46 PM
 */

#include <iomanip>
using namespace std;
#include "Restaurante.h"
#define NO_ENCONTRADO -1

Restaurante::Restaurante() {
    cantidad_comandas = 0;
}

void Restaurante::SetCantidad_comandas(int cantidad_comandas) {
    this->cantidad_comandas = cantidad_comandas;
}

int Restaurante::GetCantidad_comandas() const {
    return cantidad_comandas;
}

void Restaurante::cargar_comandas() {
    leerAten("atenciones.csv");
    leerCom("comandas.csv");
}

void Restaurante::leerAten(const char* nombArch) {
    ifstream arch("atenciones.csv", ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    int id, hh, ss, horaAten, horaServ;
    char c;
    while (true) {
        arch>>id;
        if (arch.eof())break;
        arch >> c >> hh >> c >> ss;
        horaAten = hh * 100 + ss;
        arch >> c >> hh >> c >> ss;
        horaServ = hh * 100 + ss;
        comandas[cantidad_comandas].llenarAten(id, horaAten, horaServ);
        cantidad_comandas++;
    }
}

void Restaurante::leerCom(const char* nombArch) {
    ifstream arch("comandas.csv", ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    int id, pos;
    while (true) {
        arch>>id;
        if (arch.eof())break;
        arch.get();
        pos = buscarPro(id);
        if (pos != NO_ENCONTRADO)
            comandas[pos].agregarComanda(arch);
        else while (arch.get() != '\n');
    }
}

int Restaurante::buscarPro(int ident) {
    for (int i = 0; i < cantidad_comandas; i++) {
        if (comandas[i].GetId() == ident)return i;
    }
    return NO_ENCONTRADO - 1;
}

void Restaurante::imprimir_comandas() {
    ofstream arch("Reporte.txt", ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo Reporte.txt";
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch << setw(100/2)<<"REPORTE DE COMANDAS"<<endl;
    for(int i=0;i<cantidad_comandas;i++){
        comandas[i].imprimir(arch);
    }
}



