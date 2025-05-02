/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 13:59
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * 
 */

void leerDatos(int &n, int &m, int **&tablero){
    
    ifstream arch("Datos.txt", ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo " << endl;
        exit(1);
    }
    
    arch >> n >> m;
    tablero = new int*[n];
    for(int i = 0; i < n; i++){
        tablero[i] = new int[m];
        for(int j = 0; j < m; j++)
            arch >> tablero[i][j];
    }
    
}


int menor(int derecha, int abajo){
    if(derecha < abajo)
        return derecha;
    else return abajo;
}

int menor(int derecha, int abajo, int diagonal){
    
    int datoMenor = menor(derecha, abajo);
    datoMenor = menor(datoMenor, diagonal);
    return datoMenor;
}

int encontrarCamino(int fil, int col, int filaFin, int colFin, int **tablero,
        bool &llego){
    
    if(fil == filaFin and col == colFin){
        llego = true;
        return 1;
    }
        
    if(fil > filaFin or col > colFin or fil < 0 or col < 0)
        return 99999999;
    
    if(tablero[fil][col] == 1)
        return 999999999;
    int pasos; //Contamos la casilla actual
    if(fil == 0  and col == 0)
        pasos = 0; //No contamos como paso al inicio
    else 
        pasos = 1;//Contamos la casilla actual como si hubieramos dado un paso
    //Si no estamos en el inicio, se supone que tomamos un paso para llegar a la casilla actual
    int derecha = 0, abajo = 0, diagonal = 0;
    derecha = encontrarCamino(fil, col + 1, filaFin, colFin, tablero, llego);
    abajo = encontrarCamino(fil + 1, col, filaFin, colFin, tablero, llego);
    diagonal = encontrarCamino(fil + 1, col + 1, filaFin, colFin, tablero, llego);
    
    pasos += menor(derecha, abajo, diagonal);
    return pasos;
    
}

void detectaMinas(int fil,int col, int filaFin, int colFin, 
        int **tablero,int **minas){
    
    if(fil - 1 >= 0){
        if(col - 1 >= 0)
            minas[fil - 1][col - 1] = tablero[fil - 1][col - 1];
        minas[fil - 1][col] = tablero[fil - 1][col];
        if(col + 1 <=colFin)
            minas[fil - 1][col + 1] = tablero[fil - 1][col + 1];
    }
    if(col - 1 >= 0)
        minas[fil][col - 1] = tablero[fil][col - 1];
    if(col + 1 <=colFin)
        minas[fil][col + 1] = tablero[fil][col + 1];
    if(fil + 1 <= filaFin){
        if(col - 1 >= 0)
            minas[fil + 1][col - 1] = tablero[fil + 1][col - 1];
        minas[fil + 1][col] = tablero[fil + 1][col];
        if(col + 1 <=colFin)
            minas[fil + 1][col + 1] = tablero[fil + 1][col + 1];
    }
    
}


int encontrarMinas(int fil, int col, int filaFin, int colFin, int **tablero,
        bool &llego, int **minas){
    if(fil == filaFin and col == colFin){
        llego = true;
        return 1;
    }
        
    if(fil > filaFin or col > colFin or fil < 0 or col < 0)
        return 99999999;
    
    if(tablero[fil][col] == 1)
        return 999999999;
    int pasos; //Contamos la casilla actual
    if(fil == 0  and col == 0)
        pasos = 0; //No contamos como paso al inicio
    else 
        pasos = 1;//Contamos la casilla actual como si hubieramos dado un paso
    //Si no estamos en el inicio, se supone que tomamos un paso para llegar a la casilla actual
    
    
    int derecha = 0, abajo = 0, diagonal = 0;
    derecha = encontrarMinas(fil, col + 1, filaFin, colFin, tablero, llego,minas);
    abajo = encontrarMinas(fil + 1, col, filaFin, colFin, tablero, llego,minas);
    diagonal = encontrarMinas(fil + 1, col + 1, filaFin, colFin, tablero, llego,minas);
    detectaMinas(fil,col,  filaFin,  colFin, tablero,minas);
    pasos += menor(derecha, abajo, diagonal);
    return pasos;
}

int main(int argc, char** argv) {

    int n, m;
    int **tablero;
    
    leerDatos(n, m , tablero);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
    bool llego = false;
    int pasos = encontrarCamino(0, 0, n -1, m-1,tablero, llego);
    
    if(llego)
        cout << "Llego al final en " << pasos << " pasos" << endl;
    else
        cout << "No es posible llegar al punto final" << endl;
    
    //Parte b
    int **minas = new int *[n];
    
    for(int i = 0; i < n; i++){
        minas[i] = new int[m];
        for(int j = 0; j < m; j++)
            minas[i][j] = 0;
    }
    
    encontrarMinas(0, 0, n -1, m-1,tablero, llego, minas);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << minas[i][j] << " ";
        cout << endl;
    }
    return 0;
}

