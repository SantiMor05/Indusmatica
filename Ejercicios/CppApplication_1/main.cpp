/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de septiembre de 2024, 14:46
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

inline void suma(int &sum, int n, vector <int> d) {

    sum = 0;

    for (int i = 0; i < n; ++i)
        sum += d[i];

}

int main() {

    int sum = 0;
    vector <int> datos(N);

    for (int i = 0; i < datos.size(); i++) {
        datos[i] = i;
    }


    suma(sum, N, datos);

    cout << "La suma es " << sum << endl;

    return 0;

}