/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 15 de junio de 2025, 07:28 PM
 */

#include <iostream>

using namespace std;

int buscar(int*arr,int ini,int fin){
    
    if(ini>=fin)return arr[ini];
    
    int med=(ini+fin)/2;
    if(not(arr[med]==arr[med-1] or arr[med]==arr[med+1]))return arr[med];
    
    if(med%2!=0){
        if(arr[med-1]!=arr[med])return buscar(arr,ini,med-1);
        return buscar(arr,med+1,fin);
    }
    else{
        if(arr[med+1]!=arr[med])return buscar(arr,ini,med-1);
        return buscar(arr,med+2,fin);
    }
}

int main(int argc, char** argv) {

    int arr[]{1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"El ignorado es "<<buscar(arr,0,n-1);
    
    return 0;
}

