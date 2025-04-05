/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 2 de abril de 2025, 10:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
#include "Arma.h"
#include "Guerrero.h"
#include "Mochila.h"
using namespace std;
#define NO_ENCONTRADO -1

void cambioBase(int numPosi, int base, int *cromosoma, int cantArmas);
bool buscamos(int tipoArma, int *tipoDebilidad);
int buscamosRequisito(char tipoArma, struct Arma *armas, int cantArmas);
bool vericamosPoder(struct Guerrero *guerrero, int cantGuerreros,
        int poderMochilas);

/*
 * 
 */
int main(int argc, char** argv) {
    int cantArmas = 12;
    int cantGuerreros = 3;
    struct Guerrero guerrero[cantGuerreros]{};
    struct Arma armas[cantArmas]{};
//    struct Mochila mochilas[cantGuerreros]{};
    int cantPosi;
    int base = cantGuerreros + 1;
    int cromosoma[cantArmas];
    //    int poderMochilas[cantGuerreros];
    int index;
    int poderMochilas[cantGuerreros]{};
    char mochilasCumplen[cantGuerreros][cantArmas]{};

    //definimos
    //Primer G
    guerrero[0].poder = 120;
    guerrero[0].tipoDebilidad[0] = 2;
    //Segundo G
    guerrero[1].poder = 160;
    guerrero[1].tipoDebilidad[0] = 1;
    guerrero[1].tipoDebilidad[1] = 3;
    //Tercer G
    guerrero[2].poder = 120;
    guerrero[2].tipoDebilidad[0] = 3;

    //definimos las armas
    //Primera
    armas[0].arma = 'Z';
    armas[0].poder = 60;
    armas[0].tipo = 3;
    armas[0].tieneRequi = false;
    //Primera
    armas[1].arma = 'P';
    armas[1].poder = 80;
    armas[1].tipo = 1;
    armas[1].tieneRequi = true;
    armas[1].requisi[0] = 'Z';
    //Primera
    armas[2].arma = 'R';
    armas[2].poder = 38;
    armas[2].tipo = 2;
    armas[2].tieneRequi = false;

    //Primera
    armas[3].arma = 'D';
    armas[3].poder = 25;
    armas[3].tipo = 2;
    armas[3].tieneRequi = true;
    armas[3].requisi[0] = 'R';
    //Primera
    armas[4].arma = 'E';
    armas[4].poder = 49;
    armas[4].tipo = 2;
    armas[4].tieneRequi = false;

    //Primera
    armas[5].arma = 'F';
    armas[5].poder = 57;
    armas[5].tipo = 1;
    armas[5].tieneRequi = false;

    //Primera
    armas[6].arma = 'G';
    armas[6].poder = 68;
    armas[6].tipo = 3;
    armas[6].tieneRequi = false;

    //Primera
    armas[7].arma = 'H';
    armas[7].poder = 35;
    armas[7].tipo = 2;
    armas[7].tieneRequi = true;
    armas[7].requisi[0] = 'Z';
    armas[7].requisi[1] = 'E';
    //Primera
    armas[8].arma = 'I';
    armas[8].poder = 62;
    armas[8].tipo = 2;
    armas[8].tieneRequi = true;
    armas[8].requisi[0] = 'R';

    //Primera
    armas[9].arma = 'J';
    armas[9].poder = 42;
    armas[9].tipo = 2;
    armas[9].tieneRequi = false;
    //Primera
    armas[10].arma = 'K';
    armas[10].poder = 36;
    armas[10].tipo = 1;
    armas[10].tieneRequi = true;
    armas[10].requisi[0] = 'Z';
    //Primera
    armas[11].arma = 'L';
    armas[11].poder = 54;
    armas[11].tipo = 3;
    armas[11].tieneRequi = false;

    int flag;
    bool armaValida;
    int posicionCromo;
    bool poderValido;
    int indexMochila;
    int cantDato;


    //Definimos las cantPosibili
    cantPosi = pow(base, cantArmas);

    //recorremos cada posibilidad en q puede ser puestas las armas
    for (int numPosi = 0; numPosi < cantPosi; numPosi++) {
        flag = 0;
                //limpio mi poder mochilas
                for (int w = 0; w < cantGuerreros; w++) {
                    poderMochilas[w]=0;
                }
        //limpio mochilas q cumplen;
        for (int i = 0; i < cantGuerreros; i++) {
                for (int j = 0; j < cantArmas; j++) {
                    mochilasCumplen[i][j]=0;
                }
        }
        
        
        //convertimos a la base
        cambioBase(numPosi, base, cromosoma, cantArmas);
        //1010011010101010


        //Recorremos el cromosoma
        for (int i = 0; i < cantArmas; i++) {

            if (cromosoma[i] > 0) {
                //el incez del poder de mochila se comparte con el de guerreros;
                index = cromosoma[i] - 1;
                
                //Primero verifcamos si sirve el arma contra el enemigo
                armaValida = buscamos(armas[i].tipo, guerrero[index].tipoDebilidad);

                if (armaValida) {

                    //Si el arma tiene reuqisitos aqui lo verificamos
                    if (armas[i].tieneRequi) {
                        for (int j = 0; armas[i].requisi[j]; j++) {
                            //Z
                            posicionCromo = buscamosRequisito(armas[i].requisi[j],
                                    armas, cantArmas);
                            if (posicionCromo != NO_ENCONTRADO) {
                                if (cromosoma[posicionCromo] != cromosoma[i]) {
                                    flag = 1;
                                    break;
                                }
                            } else {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1) break;
                    }
                    
                    //Si llega aca mi cromo es pq solo falta verificar que sumarle el poder
                    if (flag == 0) {
                        poderMochilas[index] += armas[i].poder;
                    }

                } else {
                    flag = 1;
                    break;
                }





            }

        }

        
        if(flag==0){
            
            //Verificamos q cumpla con superar el poder sino brako waa
            for (int d = 0; d < cantGuerreros; d++) {
                poderValido = guerrero[d].poder < poderMochilas[d];
                if (!poderValido) {
                    flag = 1;
                    break;
                }
            }
            
        }



        if (flag == 0) {
            //guardamos con el cromosoma las armas en la matriz
            cantDato = 0;
            for (int s = 0; s < cantArmas; s++) {
                if (cromosoma[s] > 0) {
                    indexMochila = cromosoma[s] - 1;
                    mochilasCumplen[indexMochila][cantDato] = armas[s].arma;
                    cantDato++;
                }
            }
            
            //IMprimos el arreglo

            for (int i = 0; i < cantGuerreros; i++) {
                for (int j = 0; j < cantArmas; j++) {
                    cout << mochilasCumplen[i][j] << "-";
                }
                cout << endl;
            }
            

        }

    }










    return 0;
}

void cambioBase(int numPosi, int base, int *cromosoma, int cantArmas) {
    int i = 0, resi;

    //Inicializamos
    for (int k = 0; k < cantArmas; k++) {
        cromosoma[k] = 0;
    }

    while (numPosi > 0) {
        resi = numPosi % base;
        numPosi = numPosi / base;
        cromosoma[i] = resi;
        i++;
    }
}

bool buscamos(int tipoArma, int *tipoDebilidad) {
    for (int i = 0; i < 3; i++) {
        if (tipoArma == tipoDebilidad[i]) return true;
    }

    return false;
}

int buscamosRequisito(char tipoArma, struct Arma *armas, int cantArmas) {
    for (int i = 0; i < cantArmas; i++) {
        if (tipoArma == armas[i].arma) return i;
    }
    return NO_ENCONTRADO;

}

bool vericamosPoder(struct Guerrero *guerrero, int cantGuerreros,
        int poderMochila) {
    for (int i = 0; i < cantGuerreros; i++) {
        if (poderMochila < guerrero[i].poder) return false;
    }
    return true;

}