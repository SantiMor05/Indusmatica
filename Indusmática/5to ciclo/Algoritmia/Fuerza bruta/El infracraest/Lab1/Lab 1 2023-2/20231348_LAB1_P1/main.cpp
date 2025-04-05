/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 4 de abril de 2025, 18:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void cargabin(int base, int numPosi, int bits, int *cromosoma);

/*
 * 
 */
int main(int argc, char** argv) {

    int cantPosi, pesoMax=100, n = 4, base = 2, bits = n*n;
    int cromosoma[bits]{};
    int pesos[bits] = {20, 20, 20, 20, 10, 30, 10, 30, 10, 10, 10, 10, 15, 15, 15, 15};
    int valores[bits] = {10, 10, 10, 50, 80, 10, 10, 20, 20, 20, 20, 20, 50, 50, 50, 50};
    int combiOptima, valorMaximo = 0, pesoTotal, peso, valorTotal;
    bool sePuede;


    cantPosi = pow(base, bits);

    // vamos posiblidad por posibilidad
    for (int numPosi = 0; numPosi < cantPosi; numPosi++) {
        //se vuelve a inciarlizar para otra posibliadad
        pesoTotal = 0;
        valorTotal=0;
        sePuede = true;


        //convetimos a la base;
        cargabin(base, numPosi, bits, cromosoma);

        //recorremos el cromosoma para sumarle a peso
        for (int a = 0; a < bits; a++) {
            // 1 0 0 1 0 1 0 
            if (cromosoma[a] > 0) {

                peso = pesos[a];
                pesoTotal += peso;

                //si el peso supera el peso maximo lo mandamos a la mrd
                if (pesoTotal > pesoMax) {
                    sePuede = false;
                    break;
                }

                if (sePuede) {
                    valorTotal += valores[a];
                    if (valorTotal > valorMaximo) {
                        // guardamos aqui lo necesarip para imprimir el resultado optimo
                        combiOptima = numPosi;
                        valorMaximo = valorTotal;

                    }
                }

            }

        }

    }
    // impresionv
    cargabin(base, combiOptima, bits, cromosoma);
    cout << "Valor maximo de la optimizacion: "<<valorMaximo << endl;
    for (int i = 0; i < bits; i++) {
        if(i>0 and i%4==0){
            cout<<endl;
        }
        cout<<cromosoma[i]<<" ";
    }






    return 0;
}

void cargabin(int base, int numPosi, int bits, int *cromosoma) {
    int indice = 0, resi;

    //INicializamos
    for (int i = 0; i < bits; i++) {
        cromosoma[i] = 0;
    }

    //convetimos a base
    while (numPosi > 0) {
        resi = numPosi % base;
        numPosi = numPosi / base;
        cromosoma[indice] = resi;
        indice++;
    }

}

