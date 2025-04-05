/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Kenyi Chavez Ramos 20231466
 *
 * Created on 5 de abril de 2025, 10:17 a. m.
 */

#include <iostream>
#include <cmath>
#define N 10
using namespace std;

/*
 * 
 */

void cargarBin(int *cromo, int n, int num, int base) {
    int res, j = 0;
    for (int i = 0; i < n; i++)cromo[i] = 0;
    while (num > 0) {
        res = num % base;
        num /= base;
        cromo[j] = res;
        j++;
    }
}

bool validarImplementacion(int IDrecurso, char *rescursos,
        int *cromo, char *implementados) {
    for (int i = 0; i < 3; i++) {
        bool encontro = false; // bandera que cambia para saber si encontro en los implementos
        // en caso no encuentre ninguno retorna false porque no cumple
        if (!implementados[i])return true; // para cuando llege al fin del arreglo, cumple para cuando no tiene implementos
        for (int j = 0; j < N; j++)
            if (rescursos[j] == implementados[i] and cromo[j] == IDrecurso) encontro = true;
        // si cambi la bandera no retorna falso, solo retornara true cuando llegue al final del arreglo '0'
        if (encontro == false)return false;
    }
    return false;
}

int main(int argc, char** argv) {
    int base = 2,  presupuesto = 200;;
    char rescursos[N] = {'F', 'D', 'M', 'S', 'P', 'A', 'H', 'I', 'C', 'G'};
    //F: Firewall |  IDS:D   |Monitoreo de Red:M   | Sistema de Autenticacion:S
    //IPS: P  |  IDS Avanzado:A   |   Honeypot:H   | Deteccion de Intrusos:I
    //Segurridad de Correo: C   |   Gestion Centralizada: G
    int cromo[N];
    int costo[N] = {50, 40, 80, 70, 85, 140, 55, 130, 30, 150};
    int nivel[N] = {120, 110, 140, 130, 160, 250, 100, 240, 90, 300};
    char implementados[N][3] = {
        {},
        {},
        {},
        {'F'},
        {'F'},
        {'F', 'D'},
        {'D'},
        {'D', 'M'},
        {},
        {'F', 'D', 'P'}
    };
    int opciones = (int) pow(base, N);
    int combinacion, costoObtenido, min = (int) presupuesto * 0.8;
    int contador = 0;
    //Ingrese Nivel Minimo;
    int nivelMin = 400;
    cout << "Combinaciones validas(Costo entre " << presupuesto * 0.8
            << " y " << presupuesto << " miles y Nivel Minimo " << nivelMin << " ):" << endl;
    for (int i = 0; i < opciones; i++) {
        //        i = 4;
        cargarBin(cromo, N, i, base);
        //        for (int j = 0; j < N; j++)cout << cromo[j];
        //        cout << endl;
        int gasto = 0;
        int nivelObtenido = 0;
        bool valido = true;
        for (int j = 0; j < N; j++) {//entro al cromo
            if (cromo[j] != 0) {
                if (validarImplementacion(cromo[j], rescursos,
                        cromo, implementados[j])) {
                    gasto += costo[j];
                    nivelObtenido += nivel[j];
                } else valido = false;
            }
        }
        if (valido and gasto >= min and gasto <= presupuesto and
                nivelObtenido >= nivelMin) {
            contador++;
            combinacion = i;
            costoObtenido = gasto;
            cout << "Combinacion " << i << ": Recursos ";
            for (int j = 0; j < N; j++)if (cromo[j] != 0)cout << "R" << cromo[j]*(j + 1) << " ";
            cout << " | Costo: " << costoObtenido <<
                    " miles | Nivel: " << nivelObtenido << endl;
        }
    }

    if (!contador) {
        cout << "No encontro solucion";
    }

    return 0;
}


