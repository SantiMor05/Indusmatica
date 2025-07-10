/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 7 de julio de 2025, 18:20
 */

#include <iostream>

using namespace std;

struct Lote{
    int numero;
    int cantidad;
};

int hallarIni(Lote*lotes,int ini,int fin,int cantidad){
    
    if(ini>=fin)
        return lotes[ini].numero;
    
    int med=(ini+fin)/2;
    
    if(lotes[med].cantidad==cantidad){
        if(lotes[med-1].cantidad!=cantidad)
            return lotes[med].numero;
        return hallarIni(lotes,ini,med-1,cantidad);
    }
    
    if(lotes[med].cantidad>cantidad)
        return hallarIni(lotes,ini,med-1,cantidad);
    else
        return hallarIni(lotes,med+1,fin,cantidad);
    
}

int hallarFin(Lote*lotes,int ini,int fin,int cantidad){
    
    if(ini>=fin)
        return lotes[ini].numero;
    
    int med=(ini+fin)/2;
    
    if(lotes[med].cantidad==cantidad){
        if(lotes[med+1].cantidad!=cantidad)
            return lotes[med].numero;
        return hallarFin(lotes,med+1,fin,cantidad);
    }
    
    if(lotes[med].cantidad>cantidad)
        return hallarFin(lotes,ini,med-1,cantidad);
    else
        return hallarFin(lotes,med+1,fin,cantidad);
    
}

int main(int argc, char** argv) {

    Lote lotes[]{
        {15872,3},{15865,4},{15866,4},{14357,6},{14365,6},
        {14368,6},{14370,6},{19258,8},{19260,8}
    };
    
    int n=9;
    int numIni,numFin;
    int cantidad=8;
    numIni=hallarIni(lotes,0,n-1,cantidad);
    numFin=hallarFin(lotes,0,n-1,cantidad);
    
    cout<<"Para encontrar los lotes de "<<cantidad<<" productos:"<<
            endl;
    cout<<"Lote inicial: "<<numIni<<endl;
    cout<<"Lote Final: "<<numFin<<endl;
    
    return 0;
}

