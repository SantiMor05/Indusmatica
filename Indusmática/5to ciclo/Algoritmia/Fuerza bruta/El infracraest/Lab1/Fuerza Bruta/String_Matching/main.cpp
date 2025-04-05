/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 29 de marzo de 2025, 19:13
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char arrayStringText[9] = {'M', 'I', 'L', 'F', 'L', 'O', 'V', 'E', 'R'};
    char arrayStringPatron[5] = {'L','O','V','E','R'};
    int k;
    int positionPatron=0 ;
    
    for (int i = 0; i <= 9-5 ; i++) {
        k=0;
        while (k<5 and arrayStringText[i+k]==arrayStringPatron[k]) {
            k++;
        }
        if(k==5){
            positionPatron=i;
            break;
        }
    }
    
    cout<<positionPatron;

    return 0;
}

