/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 28 de marzo de 2025, 09:53 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

/*
 * 
 */

void cargarBin(int num, int *cromo, int n) {
    int res, i = 0;
    for (int j = 0; j < n; j++) cromo[j] = 0;
    while (num > 0) {
        res = num % 2;
        num = num / 2;
        cromo[i] = res;
        i++;
    }
}

int main(int argc, char** argv) {
    char letras[10] = {'G', 'A', 'L', 'A', 'O', 'G', 'L', 'M'};
    int cromosoma[8]{};
    char palabras[4][8] = {
        {'G', 'O', 'L'},
        {'G', 'A', 'L', 'A'},
        {'A', 'L', 'A'},
        {'L', 'O', 'M', 'A'}
    };
    int tamnhoPalabra[4] = {3, 4, 3, 4};
    int opciones = pow(2, 8);
    int cantidadPalabras = 4;


    for (int k = 0; k < cantidadPalabras; k++) { //Utilizamos una palabra a la vez
        int cantidadSoluciones = 0;
        for (int i = 0; i < opciones; i++) {
            cargarBin(i, cromosoma, 8);
            int cantLetras = 0;
            for (int j = 0; j < 8; j++) {
                if (cromosoma[j] == 1) cantLetras++; //verficamos que tenga la misma cantidad de letras que la palabra
            }
            bool seEncontro = true;
            for (int y = 0; y < tamnhoPalabra[k]; y++) {
                int letrasCoincididas = 0;
                for (int h = 0; h < 8; h++) { //verificamos la palabra y cambiamos el cromosoma por 0 cuando encuentra la palabra
                    if (cromosoma[h] and (letras[h] == palabras[k][y])) {
                        letrasCoincididas++;
                        if (letrasCoincididas == 1)cromosoma[h] = 0;
                    }
                }
                if (letrasCoincididas == 0)seEncontro = false;
            }
            if (cantLetras == tamnhoPalabra[k] and seEncontro) {
                cantidadSoluciones++;
            }
        }

        cout << "La palabra " << palabras[k] << " tiene " << cantidadSoluciones
                << " combinaciones." << endl;
    }

    return 0;
}

