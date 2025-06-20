/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 20 de junio de 2025, 06:26 PM
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */


int hallarSoli(int *arr, int ini, int fin){
    if(ini == fin)return arr[ini];
    int med = (ini + fin)/2;
    
    if(med % 2 == 0){//Par
        if(arr[med] != arr[med + 1]){
            return hallarSoli(arr, ini, med); 
        }
        else{
            return  hallarSoli(arr, med + 2, fin); 
        }
    }
    else{//Impar
        if(arr[med] != arr[med + 1]){
            return hallarSoli(arr, med + 1, fin); //Si son diferentes, a la derecha
        }
        else{
            return hallarSoli(arr, ini, med - 1); //Si son iguales, a la izquierda
        } 
        
    }
}

int main(int argc, char** argv) {
    //int arr[] =  {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    //int arr[] =  {1, 1, 2, 3, 3};
    //int arr[] =  {1, 1, 2, 2, 4, 5, 5, 6, 6};
    //int arr[] =  {10, 10, 12, 12, 13, 15, 15, 17, 17, 19, 19};
    //int arr[] =  {1, 1, 3, 3, 5, 5, 4, 6, 6};
    //int arr[] =  {1, 1, 2, 3, 3, 5, 5, 7, 7};
    //int arr[] =  {1, 2, 2, 3, 3, 5, 5, 7, 7};
    //int arr[] =  {1, 1, 2, 2, 3, 3, 5, 5, 7};
    //int arr[] =  {1, 1, 2, 2, 3, 3, 5, 5, 7, 7, 9};
    //int arr[] =  {1, 2, 2, 3, 3, 5, 5, 7, 7, 9, 9};
    int arr[] =  {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "El numero solitario es: " << hallarSoli(arr, 0, n - 1);
    cout << endl;
    
    return 0;
}

