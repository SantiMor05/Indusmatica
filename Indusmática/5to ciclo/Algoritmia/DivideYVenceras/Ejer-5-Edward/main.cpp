/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 15 de junio de 2025, 10:06 PM
 */

#include <iostream>

using namespace std;

int buscar(int*arr,int ini,int fin){
    
    if(ini>=fin)return arr[ini];
    int med=(ini+fin)/2;
    if()
}

int main(int argc, char** argv) {

    int arr[]{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"El mayor es "<<buscar(arr,0,n-1);
    
    return 0;
}

