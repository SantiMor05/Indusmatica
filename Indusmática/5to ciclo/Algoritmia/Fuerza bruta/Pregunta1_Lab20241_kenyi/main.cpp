/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 30 de marzo de 2025, 03:16 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

/*
 * 
 */

void cargarBin(int num, int base, int *cromo, int n) {
    int res, i = 0;
    for (int i = 0; i < n; i++)cromo[n] = 0;
    while (num > 0) {
        res = num % base;
        num /= base;
        cromo[i] = res;
        i++;
    }
}

bool validarTipoA(int tipoA, int *tipoNecesario) {
    for (int i = 0; i < 3; i++) {
        if (tipoNecesario[i] == tipoA) return true;
    }
    return false;
}

bool validarPreReq(char *armas, char *preRequiA, int *cromo, int mochila) {
    for (int i = 0; i < 3; i++) {
        bool encontro = false;
        if (!preRequiA[i])return true;
        for (int k = 0; k < 12; k++) {
            if (preRequiA[i] == armas[k] and cromo[k] == mochila)encontro = true;
        }
        if (encontro == false)return false;
    }
    return false;
}

int main(int argc, char** argv) {
    char armas[12] = {'Z', 'P', 'R', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L'};
    int estadosA[12]{}, cromo[12]{}; //0:no usado   1:usado
    int poderA[12] = {60, 80, 38, 25, 49, 57, 68,
        35, 62, 42, 36, 54};
    int tipoA[12] = {3, 1, 2, 2, 2, 1, 3, 2, 2, 2, 1, 3};
    char preRequiA[12][3] = {
        {},
        {'Z'},
        {},
        {'R'},
        {},
        {},
        {},
        {'Z', 'E'},
        {'R'},
        {},
        {'Z'},
        {}
    };
    int poderG[3] = {120, 160, 80};
    int armasNecesarias[3][3] = {
        {2},
        {1, 3},
        {3}
    };
    int opciones = (int) pow(4, 12);
    int mejorC = 0;
    //    for (int i = 0; i < 12; i++) {
    //        cout << i << "). " << preRequiA[i] << endl;
    //    }
    for (int i = 0; i < opciones; i++) {
        //                i = 16644954;
        //                i = 12662874;
        cargarBin(i, 4, cromo, 12);
        //         for(int j=0;j<12;j++)cout<<cromo[j];
        //        cout<<endl; //demora 2min para mostrar todas la posibilidades 💀
        //            int tipo[3]{};//copiamos los tipos de armas
        bool valida = true;
        int poderauxG[3]{};
        for (int k = 0; k < 3; k++)poderauxG[k] = poderG[k];
        for (int j = 0; j < 12; j++) {
            // 2 2 1 1 0 2 3 0 1 0 0 3 ||  3 2 1 0 1 2 3 1 0 0 2 0
            if (validarTipoA(tipoA[j], armasNecesarias[cromo[j] - 1])) {
                if (validarPreReq(armas, preRequiA[j], cromo, cromo[j])) {
                    poderauxG[cromo[j] - 1] -= poderA[j];
                } else valida = false;
            } else if (cromo[j] != 0)valida = false;
        }
        for (int u = 0; u < 3; u++) {
            if (poderauxG[u] > 0)valida = false;
        }
        if (valida) {
            mejorC++;
            cout << "Solucion " << mejorC << endl;
            cout << "-----------------------" << endl;
            cout << "Numero deciaml: " << i << endl;
            cout << "Cromosoma: ";
            for (int k = 0; k < 12; k++)cout << cromo[k] << " ";
            cout << endl << "-----------------------" << endl;
            for (int o = 0; o < 3; o++) {
                cout << "Guerrero " << o + 1 << endl;
                cout << "Poder: " << poderG[o] << endl;
                for (int j = 0; j < 12; j++) {
                    if (cromo[j] == o + 1)cout << armas[j] << " ";
                }
                cout << endl;
            }
            cout << "=======================" << endl;
            //            break;
        }
    }

    cargarBin(mejorC, 4, cromo, 12);



    return 0;
}

