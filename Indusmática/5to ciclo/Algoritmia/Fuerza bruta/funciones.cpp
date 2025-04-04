/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Guerrero.h"
#include "Mochila.h"
#include "Arma.h"
#include "funciones.h"
#define N 12

using namespace std;

void inizializar(struct Guerrero*guerreros,
        const char*nombArch, struct Arma*armas, int &cantArmas) {

    guerreros[0].numero= 1;
    guerreros[0].poder = 120;
    guerreros[0].tipos[0] = 2;
    guerreros[0].cantTipos++;

    guerreros[1].numero = 2;
    guerreros[1].poder = 160;
    guerreros[1].tipos[0] = 1;
    guerreros[1].tipos[1] = 3;
    guerreros[1].cantTipos=2;

    guerreros[2].numero = 3;
    guerreros[2].poder = 80;
    guerreros[2].tipos[0] = 3;
    guerreros[2].cantTipos++;

    ifstream arch(nombArch, ios::in);
    int i;
    if (not arch.is_open()) {
        cout << "Error en " << nombArch;
        exit(1);
    }
    while (true) {
        arch >> armas[cantArmas].letra;
        if (arch.eof())break;
        arch >> armas[cantArmas].poder;
        arch >> armas[cantArmas].tipo;
        i = 0;
        while (arch.get() != '\n') {
            arch >> armas[cantArmas].preRequi[i++];
        }
        armas[cantArmas].cantPreRqui=i;
        cantArmas++;
    }
}

bool evaluarGuerrero(const struct Guerrero *guerreros, int cantGuerre,
        const struct Arma*armas, int cantArmas, struct Mochila *mochilas) {

    int cromo[N], combinaciones, base = 4;
    combinaciones = (int) pow(base, N);

    for (int i = 0; i < combinaciones; i++) {
        cargaBin(cromo, N, base, i);
        if (comparar(cromo, N, armas, cantArmas, guerreros,cantGuerre)) {
            pasarAMochila(cromo, N, mochilas, armas, cantArmas);
            return true;
        }
    }
    return false;
}

void cargaBin(int *cromo,int n, int base, int num){
    int i=0,resto;
    for (int j = 0; j < n; j++) {
        cromo[j]=0;
    }
    while(num>0){
        resto=num%base;
        num/=base;
        cromo[i++]=resto;
    }    
}

bool comparar(int *cromo,int n,const struct Arma*armas,int cantArmas,
        const struct Guerrero *guerreros,int cantGuerre){
    
    for (int i = 0; i < 3; i++) {
        if(not verificarTiposArmas(armas,cantArmas,cromo,n,guerreros[i]))
            return false;
        
    }
    for (int i = 0; i < 3; i++) {
        if(not verificarPreRequi(cromo,n,i+1,armas,cantArmas))
            return false;
    }
    for (int i = 0; i < 3; i++) {
        if(not verificarPoder(armas,cantArmas,cromo,n,guerreros[i]))
            return false;
    }
    return true;
}

bool verificarTiposArmas(const struct Arma*armas,int cantArmas,
        int *cromo,int n,const struct Guerrero &guerrero){
    int j,tipo;
    for (int i = 0; i < n; i++) {
        if(cromo[i]==guerrero.numero){
            tipo=armas[i].tipo;
            for (j = 0; j < guerrero.cantTipos; j++){
                if(tipo==guerrero.tipos[j])break;
            }
            if(j==guerrero.cantTipos)return false;
        }
    }
    return true;
}

bool verificarPoder(const struct Arma*armas,int cantArmas,
        int *cromo,int n,const struct Guerrero &guerrero){
    int poderTotal=0;
    for (int i = 0; i < n; i++) {
        if(cromo[i]==guerrero.numero){
            poderTotal+=armas[i].poder;
        }
    }
    if(poderTotal>=guerrero.poder)return true;
    return false;

}

bool verificarPreRequi(int *cromo,int n,int numMochi,
        const struct Arma*armas,int cantArmas){
    for (int i = 0; i < n; i++) {
        if(cromo[i]==numMochi){
            if(armas[i].cantPreRqui>0)
                if(not cumpleRequi(cromo,n,numMochi,armas,cantArmas,i))
                    return false;
        }
    }
    return true;
}

bool cumpleRequi(int *cromo,int n,int numMochi,
        const struct Arma*armas,int cantArmas,int posiArma){
    int contadorPreArmas=0;
    for (int i = 0; i < n; i++) {
        if(cromo[i]==numMochi){
            if(pertenece(armas[i],armas[posiArma]))contadorPreArmas++;
        }
    }
    if(contadorPreArmas==armas[posiArma].cantPreRqui)return true;
    return false;

}

bool pertenece(const struct Arma &armaI,const struct Arma &armaRefe){
    int i;
    for (i = 0; i < armaRefe.cantPreRqui; i++) {
        if(armaI.letra==armaRefe.preRequi[i])break;
    }
    if(i==armaRefe.cantPreRqui)return false;
    return true;
}


void pasarAMochila(int *cromo,int n,struct Mochila *mochilas,
        const struct Arma*armas,int cantArmas){
    
    int posiMochi,nArmasEnMochi;
    for (int i = 0; i < n; i++) {
        if(cromo[i]){
            posiMochi=cromo[i]-1;
            nArmasEnMochi=mochilas[posiMochi].cantArmas;
            mochilas[posiMochi].poderTotal+=armas[i].poder;
            mochilas[posiMochi].armas[nArmasEnMochi]=armas[i].letra;
            mochilas[posiMochi].cantArmas++;
        }
    }
}
