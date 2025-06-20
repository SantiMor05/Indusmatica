/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 1 de junio de 2025, 01:34 PM
 */

#include <iostream>
#include <ratio>

using namespace std;

/*
 * 
 */

int distinto(int arr[], int ini, int fin) {
    if (ini == fin)return arr[ini];
    
    int medio = (ini + fin) / 2;
    
    if(arr[ini]<arr[fin])return arr[ini];
    
    if (arr[medio] >= arr[ini]) {
        return distinto(arr, medio + 1, fin);
    } else return distinto(arr, ini, medio);
}

int main(int argc, char** argv) {
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    cout << distinto(arr, 0, n - 1);
    return 0;
}

