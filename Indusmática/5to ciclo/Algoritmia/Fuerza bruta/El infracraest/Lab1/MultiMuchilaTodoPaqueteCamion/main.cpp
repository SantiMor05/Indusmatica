/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 30 de marzo de 2025, 23:42
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void inicializaCromo(int *cromosoma, int cantPaquetes);
void cambioDeBase(int numPosi, int cantPaquetes, int base, int *cromosoma);
void busqueda(int &capMax, int &capMin, int *capAux, int cantCamion);
bool validacion(int *cromosoma,int *camiones,int cantCamion,int cantPaquetes);
bool busqueda(int camion,int* cromosoma,int cantPaquetes);
/*
 * 
 */
int main(int argc, char** argv) {
    int base = 5, cantCamion = 4, cantPaquetes = 5;
    int paquetes[cantPaquetes] = {50, 20, 30, 50, 20};
    int capacidad[] = {25, 50, 100, 100};
    int capAux[cantCamion];
    int cromosoma[cantPaquetes];
    int index, capMin, capMax,menorDiferencia=999999;
    int numPosiOptima;
    int camiones[cantCamion]={1,2,3,4};
    bool siTodosCamiones;
    int flag;

    int cantPosibles = pow(base, cantPaquetes);

    for (int numPosi = 0; numPosi < cantPosibles; numPosi++) {
        //convertimos a la base pedida
        flag=0;
        
        cambioDeBase(numPosi, cantPaquetes, base, cromosoma);

        //creamos un array para guardar los sobrande de las nuevas capacidades
        for (int a = 0; a < cantCamion; a++) {
            capAux[a] = capacidad[a];
        }

        // barrimos el cromosoma para saber si los paquetes estan en los 4 camion
        
        siTodosCamiones= validacion(cromosoma,camiones,cantCamion,cantPaquetes);
        
        if (siTodosCamiones) {
            for (int k = 0; k < cantPaquetes; k++) {
//                if (cromosoma[k] > 0) {
                    index = cromosoma[k] - 1;
                    capAux[index] -= paquetes[k];
                    if(capAux[index]<0 || cromosoma[k]==0){
                        flag=1;
                        break;
                    }
//                }
                cout<<cromosoma[k]<<" ";
            }
        }

        cout<<endl;

        //encontramos a la cap Max y a la Min
        busqueda(capMax, capMin, capAux, cantCamion);
        
        //Obtenemos la diferencia si cumple las condiciones
        if(capMin>=0 and capMax-capMin<menorDiferencia and flag==0){
            menorDiferencia=capMax-capMin;
            numPosiOptima=numPosi;
        }

    }
    
    //Imprimimos el resultado mas optimo
    cambioDeBase(numPosiOptima, cantPaquetes, base, cromosoma);
    for (int i = 0; i < cantPaquetes; i++) {
        cout<<cromosoma[i]<<" ";
    }
    cout<<"Diferencia mas minima: "<<menorDiferencia<<endl;
    

    
    
    


    return 0;
}

void cambioDeBase(int numPosi, int cantPaquetes, int base, int *cromosoma) {
    int residuo,i=0;

    inicializaCromo(cromosoma, cantPaquetes);
    while (numPosi > 0) {
        residuo = numPosi % base;
        numPosi = numPosi / base;
        cromosoma[i]= residuo;
        i++;
//                cromosoma[cantPaquetes - 1] = residuo;
//        cantPaquetes--;
    }
}

void inicializaCromo(int *cromosoma, int cantPaquetes) {
    for (int i = 0; i < cantPaquetes; i++) {
        cromosoma[i] = 0;
    }
}

void busqueda(int &capMax, int &capMin, int *capAux, int cantCamion) {
    for (int i = 0; i < cantCamion; i++) {
        if (i == 0) {
            capMax = capAux[0];
            capMin = capAux[0];
        }
        else{
            if (capAux[i] > capMax) capMax = capAux[i];
            if (capAux[i] < capMin) capMin = capAux[i];
        }
    }
}

bool validacion(int *cromosoma,int *camiones,int cantCamion,int cantPaquetes){
    bool validacion;
    for (int i = 0; i < cantCamion; i++) {
       
        validacion= busqueda(camiones[i],cromosoma,cantPaquetes);
        if(!validacion) return false;
    }
    return true;
    


   
}

bool busqueda(int camion,int* cromosoma,int cantPaquetes){
    for (int i = 0; i < cantPaquetes; i++) {
        if (camion==cromosoma[i]) {
            return true; 
        }
    }
    return false;

}