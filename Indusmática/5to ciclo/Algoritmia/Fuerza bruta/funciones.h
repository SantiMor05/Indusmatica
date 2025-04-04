/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 3 de abril de 2025, 10:53 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void inizializar(struct Guerrero*guerreros,
        const char*nombArch,struct Arma*armas,int &cantArmas);

bool evaluarGuerrero(const struct Guerrero *guerreros,int cantGuerre,
        const struct Arma*armas,int cantArmas,struct Mochila *mochilas);

void cargaBin(int *cromo,int n, int base, int num);

bool comparar(int *cromo,int n,const struct Arma*armas,int cantArmas,
        const struct Guerrero *guerreros,int cantGuerre);

void pasarAMochila(int *cromo,int n,struct Mochila *mochilas,
        const struct Arma*armas,int cantArmas);

bool verificarTiposArmas(const struct Arma*armas,int cantArmas,
        int *cromo,int n,const struct Guerrero &guerrero);

bool verificarPoder(const struct Arma*armas,int cantArmas,
        int *cromo,int n,const struct Guerrero &guerrero);

bool verificarPreRequi(int *cromo,int n,int numMochi,
        const struct Arma*armas,int cantArmas);

bool cumpleRequi(int *cromo,int n,int numMochi,
        const struct Arma*armas,int cantArmas,int posiArma);

bool pertenece(const struct Arma &armaI,const struct Arma &armaRefe);


#endif /* FUNCIONES_H */

