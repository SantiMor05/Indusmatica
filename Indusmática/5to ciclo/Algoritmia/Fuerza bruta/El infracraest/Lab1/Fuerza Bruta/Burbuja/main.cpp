/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 28 de marzo de 2025, 23:45
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int aux;
    int randomArray[10] = {2, 32, 45, 12, 19, 34, 20, 25, 1, 34};

    for (int i = 0; i < 10 - 1; i++) {
        for (int k = 0; k < 10 - 1; k++) {
            if (randomArray[k] > randomArray[k + 1]) {
                aux = randomArray[k];
                randomArray[k] = randomArray[k + 1];
                randomArray[k + 1] = aux;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << randomArray[i] << endl;
    }

    return 0;
}

