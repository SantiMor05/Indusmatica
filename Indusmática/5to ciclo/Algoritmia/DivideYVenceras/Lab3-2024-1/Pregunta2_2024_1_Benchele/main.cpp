/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 20 de junio de 2025, 04:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */

int hallarInicio(int *arr, int ini, int fin){
    if(ini == fin)return ini;
    
    int med = (ini + fin)/2;
    
    if(0 < arr[med]){
        return hallarInicio(arr, ini, med);
    }
    else{
        return hallarInicio(arr, med + 1, fin);
    }
}


int hallarPotMax(int *arr, int ini, int fin){
    if(ini == fin)return arr[ini];
    
    int med = (ini + fin)/2;
    
    if(arr[med - 1] < arr[med] and arr[med] > arr[med + 1]){
        return arr[med];
    }
    if(arr[med - 1] < arr[med]){
        return hallarPotMax(arr, med + 1, fin);
    }
    else{
        return hallarPotMax(arr, ini, med - 1);
    }
}
int main(int argc, char** argv) {
    //int arr[] = {-1, 0, -1, 0, -1, -1, 0, 0, 1, 2, 4, 5, 8, 10, 3, 1, 1};
    int arr[] = {0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    //int arr[] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "PREG 2 2024_1: " << endl;
    cout << "La radiacion empieza en " << hallarInicio(arr, 0, n - 1) << " km" << endl;

    cout<<"Potencia maxima es "<< hallarPotMax(arr, hallarInicio(arr, 0, n - 1), n - 1) <<" megatones"<<endl;
    return 0;
}

