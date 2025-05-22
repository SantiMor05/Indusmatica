/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 21 de mayo de 2025, 05:09 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */

void cargabin(int cromo[4], int num, int base, int n) {
    int res = 0, j = 0;
    for (int i = 0; i < n; i++)cromo[i] = 0;
    while (num > 0) {
        res = num % base;
        num /= base;
        cromo[j] = res;
        j++;
    }
}

bool verificarDiferencia(int cromo[4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j and cromo[i] == cromo[j])return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int resultado = 136948;
    int num[] = {1, 3, 6, 9, 4, 8}, n = 6;
    int cromo[n]{};
    int opciones = pow(n, n), num1, num2;

    for (int i = 0; i < opciones; i++) {
        cargabin(cromo, i, n, n);
        if (verificarDiferencia(cromo, n)) {
//                        for (int j = 0; j < n; j++) cout << cromo[j] << " ";
//                        cout << endl;
                        num1 = 0, num2 = 0;
            for (int j = 0; j < n / 2; j++) {
                num1 += round(pow(10, j)) * num[cromo[j]];
                //                cout << num1 << endl;
            }
            //            cout << num1 << " ";
            for (int j = n - 1; j >= n / 2; j--) {
                num2 += round(pow(10, n - (j + 1))) * num[cromo[j]];
                //                cout << num2 << endl;
            }
            //            cout << num2 << endl;
            if (num1 * num2 == resultado) {
                cout << "Respuesta :" << num1 << " * " << num2 << endl;
            }
        }
    }

    return 0;
}

