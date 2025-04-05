/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 29 de marzo de 2025, 23:07
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void convertirABinario(int numPosibilidad, int *cromosoma, int n);

/*
 * 
 */
int main(int argc, char** argv) {
    int n = 5, maxPeso=15, peso=0;
    int cromosoma[n];
    int paquetes[n] = {1, 2, 4, 12, 1};
    int posibilidadesTotales = (int) pow(2, n);

    for (int numPosibilidad = 0; numPosibilidad < posibilidadesTotales;
            numPosibilidad++) {
        //Obtenemos el numero en binario
        convertirABinario(numPosibilidad, cromosoma, n);
        
        
        peso=0;
        //Obtenemos cuanto equivales en peso
        for (int k = 0; k < n; k++) {
            peso += cromosoma[k]*paquetes[k];
        }

        
        //verificamos si cumple con el peso maximo+
        if (peso==maxPeso) {
            cout<<"El numero del cromosoma es: "<<numPosibilidad<<endl;
            cout<<"El cromosoma es: "<<endl;
            for (int a = 0; a < n; a++) {
                cout<<cromosoma[a]<<" ";
            }
            cout<<endl;
        }

        
    }
    
    


    return 0;
}

void convertirABinario(int numPosibilidad, int *cromosoma, int n) {

    int residuo;
    //Inicializamos nuestro cromosoma cada vez q venga un nuevo numero
    for (int i = 0; i < n; i++) {
        cromosoma[i] = 0;
    }

    int k = 0;
    //Volvemos a base 2 y lo guardamos en un cromosoma
    while (numPosibilidad > 0) {
        residuo = numPosibilidad % 2;
        numPosibilidad = numPosibilidad / 2;
        cromosoma[k] = residuo;
        k++;
    }

}

