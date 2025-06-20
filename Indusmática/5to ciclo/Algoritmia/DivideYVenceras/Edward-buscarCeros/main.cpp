/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 15 de junio de 2025, 12:18 PM
 */

#include <iostream>

using namespace std;

void buscaCeros(int*arr,int ini,int fin,int &cant){
    
    if(ini>fin)return;
    int med=(ini+fin)/2;
    if(arr[med]==0){
        cant+=fin-med+1;
        buscaCeros(arr,ini,med-1,cant);
    }
    else buscaCeros(arr,med+1,fin,cant);
}


int main(int argc, char** argv) {

    int cant=0;
    int arr[]{1,1,1,1,0,0};
    int n=(sizeof(arr)/sizeof(arr[0]));
    buscaCeros(arr,0,n-1,cant);
    cout<<"Cantidad de ceros: "<<cant<<endl;    
    return 0;
}

