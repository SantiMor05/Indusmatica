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

    int cantPosibles = pow(base, cantPaquetes);

    for (int numPosi = 0; numPosi < cantPosibles; numPosi++) {
        //convertimos a la base pedida
        cambioDeBase(numPosi, cantPaquetes, base, cromosoma);

        //creamos un array para guardar los sobrande de las nuevas capacidades
        for (int a = 0; a < cantCamion; a++) {
            capAux[a] = capacidad[a];
        }

        // barrido de cromosoma para actualizar aux capacidad

        for (int k = 0; k < cantPaquetes; k++) {
            if (cromosoma[k] > 0) {
                index = cromosoma[k] - 1;
                capAux[index] -= paquetes[k];
                if(capAux[index]<0){
                    break;
                }
            }
            

        }

        //encontramos a la cap Max y a la Min
        busqueda(capMax, capMin, capAux, cantCamion);
        
        //Obtenemos la diferencia si cumple las condiciones
        if(capMin>=0 and capMax-capMin<menorDiferencia){
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
//        cromosoma[i]= residuo;
//        i++;
                cromosoma[cantPaquetes - 1] = residuo;
        cantPaquetes--;
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