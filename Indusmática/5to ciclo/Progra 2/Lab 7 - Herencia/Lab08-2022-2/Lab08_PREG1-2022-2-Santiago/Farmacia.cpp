/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Farmacia.cpp
 * Author: santi
 * 
 * Created on 12 de junio de 2025, 22:24
 */

#include "Farmacia.h"
#include "Sinreceta.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


#define NO_ENCONTRADO -1
#define MAX_CAR 120

Farmacia::Farmacia() {
}

//Farmacia::Farmacia(const Farmacia& orig) {
//}

Farmacia::~Farmacia() {
}

void Farmacia::cargamedico() {

    ifstream arch("medicos.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo medicos" << endl;
        exit(1);
    }

    int cont = 0;
    while (true) {
        lmedicos[cont].leerDatos(arch);
        if (arch.eof())break;
        cont++;
    }
}

void Farmacia::leerecetas() {
    ifstream archRecetas("recetas.csv", ios::in);
    if (!archRecetas) {
        cout << "ERROR: No se pudo abrir el archivo recetas" << endl;
        exit(1);
    }
    ifstream archMedicamento("medicamentos.csv", ios::in);
    if (!archMedicamento) {
        cout << "ERROR: No se pudo abrir el archivo medicamentos" << endl;
        exit(1);
    }
    int fecha, dd, mm, aa, dni, contConReceta = 0, contSinReceta = 0, medicamento,
            cantidad, posMed, medico;
    char nomb[60], car;
    while (true) {
        archRecetas >> dd;
        if (archRecetas.eof())break;
        archRecetas >> car >> mm >> car >> aa >> car >> dni >> car;
        fecha = aa * 10000 + mm * 100 + dd;
        archRecetas.getline(nomb, 60, ',');
        archRecetas >> medico;
        posMed = buscarMed(medico);
        if (posMed != NO_ENCONTRADO) {
            while (archRecetas.get() != '\n') {
                archRecetas >> medicamento >> car >> cantidad;
                if ((medicamento / 10000) % 2 == 0) {
                    lconreceta[contConReceta].asigna(archMedicamento, medicamento,
                            cantidad, lmedicos[posMed], fecha);
                    contConReceta++;
                }
                else {
                    lsinreceta[contSinReceta].asigna(archMedicamento, medicamento,
                            cantidad, dni, nomb, fecha);
                    contSinReceta++;
                }
            }
        }
    }
}

int Farmacia::buscarMed(int medico) {
    for (int i = 0; lmedicos[i].GetCodigo(); i++) {
        if (medico == lmedicos[i].GetCodigo())
            return i;
    }
    return NO_ENCONTRADO;
}

void Farmacia::imprimirrecetas() {
    ofstream arch("Reporte.txt", ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }

    arch << "Codigo" << setw(25) << "Descripcion del Med." << setw(45) <<
            "Cant." << setw(20) << "DNI" << setw(15) << "Nombre" << endl;
    imprimirLinea(arch, '=', MAX_CAR);
    for (int i = 0; lsinreceta[i].GetCodigo(); i++) {
        lsinreceta[i].imprimir(arch);
    }
    
    arch << endl <<"Codigo" << setw(25) << "Descripcion del Med." << setw(45) <<
            "Cant." << setw(20) << "Cod. Medico" << setw(15) << "Especialidad"
            << endl;
    imprimirLinea(arch, '=', MAX_CAR);
    for(int i = 0; lconreceta[i].GetCodigo(); i++){
        lconreceta[i].imprimir(arch);
    }
    
}

void Farmacia::imprimirLinea(ofstream &arch, char car, int n) {

    for (int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;

}
