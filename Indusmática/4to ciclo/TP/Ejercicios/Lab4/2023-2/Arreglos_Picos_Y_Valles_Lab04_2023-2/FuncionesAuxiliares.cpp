/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_PRUEBA 30
#define MAX_CAR 40

using namespace std;


void leerDatos(int *anhos, int *ganancias, int &numDat, const char *nombDatos){
    
    
    ifstream archDatos(nombDatos, ios::in);
    
    if(not archDatos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombDatos;
        exit(1);
    }
    numDat = 0;
    while(true){
        
        archDatos >> anhos[numDat];
        if(archDatos.eof())break;
        archDatos >> ganancias[numDat];
        numDat++;
    }
    
}

void reporteDePrueba(int *anhos, int *ganancias, int numDat, 
        const char *nombPrueba){
    
    ofstream archPrueba(nombPrueba, ios::out);
    if(not archPrueba.is_open()){
        cout << "No se pudo abrir el archivo " << nombPrueba << endl;
        exit(1);
    }
    
    archPrueba << setw(10) << "Anho" << setw(13) << "Ganancia" << endl;
    imprimirCaracter('=', MAX_CAR_PRUEBA, archPrueba);
    
    for (int i = 0; i < numDat; i++) {
        
        archPrueba << setw(10) << anhos[i] << setw(10) << ganancias[i] << endl;

    }

    
}

void imprimirCaracter(char car, int n, ofstream &archSalida){
    
    for(int i = 0; i < n; i++)
        archSalida.put(car);
    
    archSalida << endl;
    
}

void emitirReporte(int *anhos, int *ganancias, int numDat, 
        const char *nombReporte){
    
    int picos[50], valles[50], a_picos[50] , a_valles[50];
    int cant_picos, cant_valles;
    int pos;
    
   
    ofstream archReporte(nombReporte, ios::out); 
    if(not archReporte.is_open()){
        cout << "No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    encontrarPicosYValles(anhos, ganancias, picos, valles, a_picos, a_valles,
            cant_picos, cant_valles, numDat);
    
    imprimirEncabezado(archReporte);
    
    for (int i = 0; i < cant_picos; i++) {
        archReporte << setw(15) << a_picos[i] << setw(10) << picos[i] << endl;
    }
    
    imprimirCaracter('=', MAX_CAR, archReporte);
    pos = encontrarPicoMayor(picos, cant_picos);
    
    archReporte << "PICO MAYOR: " << a_picos[pos] << " con " << picos[pos] <<
            " millones" << endl;
    
    imprimirEncabezadoValles(archReporte);
    
    for (int i = 0; i < cant_valles; i++) {
        archReporte << setw(15) << a_valles[i] << setw(10) << valles[i] << endl;
    }
    
    imprimirCaracter('=', MAX_CAR, archReporte);
    pos = encontrarValleMenor(valles, cant_valles);
    archReporte << "VALLE MENOR: " << a_valles[pos] << " con " << valles[pos] <<
            " millones" << endl;
    
}

int encontrarValleMenor(int *valles, int cant_valles){
    
    int pos, menor;
    
    for(int i = 0; i < cant_valles; i++){
        if(i == 0 or valles[i] < menor){
            pos = i;
            menor = valles[i];
        }
    }
    return pos;
}

void imprimirEncabezadoValles(ofstream &archReporte){
    
    imprimirCaracter('=', MAX_CAR, archReporte);
    archReporte << "RELACION DE VALLES :" << endl;
    archReporte << setw(15) << "Periodo" << setw(13) << "Ganancia" << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
    
}


int encontrarPicoMayor(int *picos, int cant_picos){
    
    int pos, mayor;
    
    for(int i = 0; i < cant_picos; i++){
        if(i == 0 or picos[i] > mayor){
            mayor = picos[i];
            pos = i;
        }
    }
    return pos;
}

void imprimirEncabezado(ofstream &archReporte){
    
    archReporte << setw(MAX_CAR / 2 + 12) << "EMPRESA MULTINACIONAL TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 14) << "GANANCIAS A TRAVES DEL TIEMPO" <<
            endl;
    
    imprimirCaracter('=', MAX_CAR, archReporte);
    archReporte << "RELACION DE PICOS :" << endl;
    archReporte << setw(15) << "Periodo" << setw(13) << "Ganancia" << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
    
}

void encontrarPicosYValles(int *anhos, int *ganancias, int *picos, int *valles, 
        int *a_picos, int *a_valles, int &cant_picos, int &cant_valles, 
        int numDat){
    
    int ganancia_anterior, anho_anterior;
    bool sube, baja;
    
    cant_picos = cant_valles = 0;
    sube = baja = false;
    ganancia_anterior = ganancias[0];
    anho_anterior = anhos[0];
    
    for (int i = 0; i < numDat; i++) {
        
        if(ganancias[i] > ganancia_anterior) {
            if(baja ){ //Es valle (esta bajando y comienza a subir)
                valles[cant_valles] = ganancia_anterior;
                a_valles[cant_valles] = anho_anterior;
                baja = false;
                cant_valles++;
            }
            sube = true;
        }
        
        if(ganancias[i] < ganancia_anterior){
            
            if(sube){//Es pico, esta subiendo y comienza a bajar
                picos[cant_picos] = ganancia_anterior;
                a_picos [cant_picos] = anho_anterior;
                sube =false;
                cant_picos++;
            }
            
            baja = true;
        }
            
        ganancia_anterior = ganancias[i];
        anho_anterior = anhos[i];
    }
    
}