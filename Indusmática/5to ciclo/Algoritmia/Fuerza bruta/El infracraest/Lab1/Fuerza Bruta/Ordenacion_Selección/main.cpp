/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 28 de marzo de 2025, 22:58
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int minNumberIndex, aux;
    int randomArray[10] = {2, 32, 45, 12, 19, 34, 20, 25, 1, 34};

    //Ordernar ascendente
    for (int i = 0; i < 10 - 1; i++) {
        minNumberIndex = i;
        for (int k = i + 1; k < 10; k++) {
            //Comparamos con el del costado para encontrar el menor
            if (randomArray[k] < randomArray[minNumberIndex]) {
                minNumberIndex = k;
            }
        }
        aux= randomArray[i];
        randomArray[i]=randomArray[minNumberIndex];
        randomArray[minNumberIndex]=aux;
    }
    
    for (int i = 0; i <10 ; i++) {
        cout<<randomArray[i]<<endl;
    }
    
    return 0;
}

