/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Kenyi
 *
 * Created on 20 de agosto de 2025, 14:45
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int empaca(int *paq,int peso,int pos, int cant){
    if(peso<0 or cant==pos)return 0;
    if(paq[pos]==peso)return 1;
    if (empaca(paq,peso-paq[pos],pos+1,cant))
        return 1;
    else 
        return empaca(paq,peso,pos+1,cant);
}

    int paq[] = {1, 1, 12, 2, 1};int main(int argc, char** argv) {

    int n = sizeof (paq) / sizeof (paq[0]);
    int peso = 15;

    if (empaca(paq,peso,0, n))
        cout << "Si hay solucion";
    else
        cout << "Pipipi no salio";
    return 0;
}

