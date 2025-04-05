/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 4 de abril de 2025, 21:05
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;


void cargaBin(int numPosi, int base, int cantControles, int *cromosoma);
bool buscamosControl(int control, int *cromosoma, int cantControles);

/*
 * 
 */
int main(int argc, char** argv) {

    int cantControles = 8;
    int inversiones[cantControles] = {32000, 8000, 40000, 40000, 20000, 4000, 16000, 16000};
    int beneficios[cantControles] = {60000, 32000, 120000, 60000, 32000, 20000, 48000, 60000};
    int requisitos[cantControles][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {1, 2, 0},
        {0, 0, 0},
        {0, 0, 0},
        {2, 0, 0},
        {6, 0, 0},
        {6, 0, 0},
    };
    int auxRequisitos[3]{};
    int cromosoma[cantControles]{};
    int presupuesto = 100000;
    int inversionTotal, base = 2, beneficioTotal, beneficioMaximo = 0, combiOp;
    bool siPuede, siTiene;
    int cantPosi;
    //Obtenemos cuantas son las posibilidades
    cantPosi = pow(base, cantControles);

    // Recoremos cada una de las posibilidades
    for (int numPosi = 0; numPosi < cantPosi; numPosi++) {
        //Inicializamos variables en cada n¿posibilidad
        beneficioTotal = 0;
        inversionTotal = 0;
        siPuede = true;


        //Convertimos a bianrio
        cargaBin(numPosi, base, cantControles, cromosoma);
        // 1 0 1 1 1 0 1

        //Recorremos el cromosoma
        for (int i = 0; i < cantControles; i++) {
            if (cromosoma[i] > 0) {

                //varificamos que no tenga requisitos
                for (int k = 0; k < 3; k++) {
                    auxRequisitos[k] = requisitos[i][k];
                }
                for (int j = 0; auxRequisitos[j]; j++) {

                    siTiene = buscamosControl(auxRequisitos[j], cromosoma, cantControles);
                    if (!siTiene) {
                        siPuede = false;
                        break;
                    }
                }

                //continuamos con los demas waaa
                // verificamos que no pase el presupuesto
                if (siPuede) {
                    inversionTotal += inversiones[i];
                    if (inversionTotal > presupuesto) {
                        siPuede = false;
                        break;

                    } else {
                        beneficioTotal += beneficios[i];

                        //guardamos al mayor resultado de beneficio
                        if (beneficioTotal > beneficioMaximo) {
                            beneficioMaximo = beneficioTotal;
                            combiOp = numPosi;

                        }
                    }

                } else break;

            }

            //Imprimmos en la ultima iteracion para comprobar que 
            //presumpuesto == inversion con todos los casos posibles

            //aqui puede q haya un 0 al final y q nunca haya entrado
            if (inversionTotal == presupuesto and i == cantControles - 1 and siPuede) {

                cout << "Beneficio Total: " << beneficioTotal << endl;
                for (int f = 0; f < cantControles; f++) {
                    if (cromosoma[f] > 0) {
                        cout << f + 1 << " ";
                    }
                }
                cout << endl;
            }
        }



    }

    //Imprimimos la mejor combinacion con mayor beneficio
    cout << "OPCION MAS OPTIMA: "<<endl;
    cout << "Beneficio Total: " << beneficioMaximo << endl;
    cargaBin(combiOp, base, cantControles, cromosoma);



    for (int h = 0; h < cantControles; h++) {
        if (cromosoma[h] > 0) {
            cout << h + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}

void cargaBin(int numPosi, int base, int cantControles, int *cromosoma) {
    int indice = 0, residuo;

    //Inicializamos
    for (int i = 0; i < cantControles; i++) {
        cromosoma[i] = 0;
    }

    while (numPosi > 0) {
        residuo = numPosi % base;
        numPosi = numPosi / base;
        cromosoma[indice] = residuo;
        indice++;
    }

}

bool buscamosControl(int control, int *cromosoma, int cantControles) {

    for (int i = 0; i < cantControles; i++) {
        if (cromosoma[i] > 0) {
            if (i + 1 == control) return true;
        }
    }
    return false;

}