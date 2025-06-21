/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de junio de 2025, 18:51
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Oppenheimer
 */


int calcularDistancia(int *arr, int ini, int fin){
    if(ini > fin)return -1;
    int medio = (ini + fin) / 2;
    int dist = 0;
    if(arr[medio] <= 0){ //Todavia no llega la radiación
        dist = calcularDistancia(arr, medio + 1, fin);
        if(dist <= 0)
            dist = medio;
    }
    else{//Ya llego la radiacion, buscamos a la izquierda
        dist = calcularDistancia(arr, 0, medio - 1);
    }
    return dist;
}

int calcularPotencia(int *arr,int ini, int fin){
    
    if(ini > fin)return -1;
    int medio =(ini + fin) / 2;
    int cont = 1;
    
    if(arr[medio] <= 0)
        calcularPotencia(arr, medio + 1, fin);
    
    if(medio - 1 >= ini and arr[medio - 1] == arr[medio])
        cont++;
    if(medio + 1 <=fin and arr[medio + 1] == arr[medio])
        cont++;
    
    if(cont == 1)
        return arr[medio];
    else if((medio + 1 <=fin and arr[medio + 1] > arr[medio]) or
            (medio - 1 >= ini and arr[medio - 1] < arr[medio]))
        calcularPotencia(arr, medio, fin);
    else if((medio - 1 >= ini and arr[medio - 1] > arr[medio]) or
            (medio + 1 <=fin and arr[medio + 1] < arr[medio]) )
        calcularPotencia(arr, ini, medio);
    
}


int main(int argc, char** argv) {

//    int arr[] ={0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
//    int n = 14;
    
//    int arr[] = {-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1};
//    int n =17;
    
    int arr[] = {-1,0,-1,0,0,0,-1,-5,1,1,2,2,3,3,4,4,5,5,6,5,5,4,4,3,3,2,2,1,1,0,0};
    int n =31;
    
    int distancia = calcularDistancia(arr, 0, n - 1);
    int potencia = calcularPotencia(arr, 0 , n - 1);
    
    cout << "La radiacion empieza a: " << distancia + 1<< " km" << endl;
    cout << "Potencia maxima de " << potencia << " megatones" << endl; 
    
    return 0;
}

