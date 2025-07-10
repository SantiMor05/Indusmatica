/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kalef Mandujano
 *
 * Descripción del código
 * 
 * Created on 7 de julio de 2025, 07:45 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int buscarInicio(int *arr1,int *arr2,int cod,int ini, int fin){
    if(ini == fin) return ini;
    int med = (ini+fin)/2;
    
    if(arr2[med]==cod and arr2[med] == arr2[med+1] and arr2[med] != arr2[med-1])
        return med;
    
    //Realizamos la separacion
    if(arr2[med] < cod){
        //Vamos a la derecha
        return buscarInicio(arr1,arr2,cod,med+1,fin);
    }else{
        //Vamos a la izquierda
        return buscarInicio(arr1,arr2,cod,ini,med-1);
    }
    
    
}

int buscarFin(int *arr1,int *arr2,int cod, int ini, int fin){
    if(ini == fin) return ini;
    int med = (ini+fin)/2;
    
    if(arr2[med]==cod and arr2[med] == arr2[med-1] and arr2[med] != arr2[med+1])
        return med;
    
    //Realizamos la separacion
    if(arr2[med] <= cod){
        //Vamos a la derecha
        return buscarFin(arr1,arr2,cod,med+1,fin);
    }else{
        //Vamos a la izquierda
        return buscarFin(arr1,arr2,cod,ini,med-1);
    }
}

int main(int argc, char** argv) {

    int arr1[]={15872,15865,15866,14357,14365,14368,14370,19258,19260};
    int arr2[]={3,4,4,6,6,6,6,8,8};
    
    int n = sizeof(arr1)/sizeof(arr1[0]);
    
//    cout<<n<<endl;
    
    int ini;
    int fin;
    
    ini = buscarInicio(arr1,arr2,3,0,n-1);
    fin = buscarFin(arr1,arr2,3,0,n-1);
    
    cout<<"Para encontrar los lotes de 3 productos:"<<endl;
    cout<<"Lote inicial: "<<arr1[ini]<<endl;
    cout<<"Lote Final: "<<arr1[fin]<<endl;
    
    ini = buscarInicio(arr1,arr2,6,0,n-1);
    fin = buscarFin(arr1,arr2,6,0,n-1);
    
    cout<<"Para encontrar los lotes de 6 productos:"<<endl;
    cout<<"Lote inicial: "<<arr1[ini]<<endl;
    cout<<"Lote Final: "<<arr1[fin]<<endl;
    
    ini = buscarInicio(arr1,arr2,8,0,n-1);
    fin = buscarFin(arr1,arr2,8,0,n-1);
    
    cout<<"Para encontrar los lotes de 8 productos:"<<endl;
    cout<<"Lote inicial: "<<arr1[ini]<<endl;
    cout<<"Lote Final: "<<arr1[fin]<<endl; 
    
    

    return 0;
}

