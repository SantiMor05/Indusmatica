/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de julio de 2025, 21:49
 */

#include <iostream>

using namespace std;

#define N 9

/*
 * Divide y vencerás
 */


int encontrarLoteInicial(int *lotes, int *cantidades, int cantidad, int ini, int fin){
    
    if(ini > fin) return -1;
    
    int medio = (ini + fin) / 2;
    
    if(cantidades[medio] == cantidad){
        if(medio - 1 >= ini and cantidades[medio - 1] == cantidad)
            return encontrarLoteInicial(lotes,cantidades,cantidad, ini, medio - 1);
        else
            return lotes[medio];
    }
    
    if(cantidades[medio] > cantidad){
        return encontrarLoteInicial(lotes,cantidades,cantidad, ini, medio - 1);
    }
    else
        return encontrarLoteInicial(lotes,cantidades,cantidad, medio + 1, fin);
}


int encontrarLoteFinal(int *lotes, int *cantidades, int cantidad, int ini, int fin){
    
    if(ini > fin) return -1;
    
    int medio = (ini + fin) / 2;
    
    if(cantidades[medio] == cantidad){
        if(medio + 1 <= fin and cantidades[medio + 1] == cantidad)
            return encontrarLoteFinal(lotes,cantidades,cantidad, medio + 1, fin);
        else
            return lotes[medio];
    }
    
    if(cantidades[medio] > cantidad){
        return encontrarLoteFinal(lotes,cantidades,cantidad, ini, medio - 1);
    }
    else
        return encontrarLoteFinal(lotes,cantidades,cantidad, medio + 1, fin);
}


int main(int argc, char** argv) {
    
    int lotes[N] = {15872, 15865, 15866,14357,14365,14368,14370, 19258,19260};
    int cantidades[N] = {3,4,4,6,6,6,6,8,8};
    int cantidadBusca = 4;
    int loteInicial = encontrarLoteInicial(lotes, cantidades, cantidadBusca, 0, N - 1);
    int loteFinal = encontrarLoteFinal(lotes,cantidades, cantidadBusca, 0, N - 1);
    cout << "Lote inicial: " << loteInicial << endl;
    cout << "Lote final: " << loteFinal << endl;

    return 0;
}

