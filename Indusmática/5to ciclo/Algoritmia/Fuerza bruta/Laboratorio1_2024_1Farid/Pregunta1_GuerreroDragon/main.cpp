/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 30 de marzo de 2025, 04:17 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>

#define MAX_GRR 3
#define MAX_ARM 12
#define MAX_REQ 3
#define MAX_TPO 3

/*
 * 
 */
void cargaBin(int *cromo, int base, int num, int n) {
    int rest, j = 0;
    for (int i = 0; i < n; i++) cromo[i] = 0;
    while (num > 0) {
        rest = num % base;
        num /= base;
        cromo[j] = rest;
        j++;
    }
}

bool verificarRequisitos(int *cromo, char *arm_nom, char* requisitos,
        int mochila, int n) {

    for (int i = 0; i < MAX_REQ; i++) {

        if (!requisitos[i]) return true;
        for (int j = 0; j < MAX_ARM; j++) {
            if (requisitos[i] == arm_nom[j] and cromo[j] != mochila) {
                return false;
            }
        }
    }
    return true;


}

bool verificarTipo(int mochila, int tipo, int*grr_tip, int n) {
    for (int i = 0; i < n; i++) {

        if (grr_tip[i] == tipo) return true;
    }
    return false;

}

int main(int argc, char** argv) {
    //    int grr_pod[MAX_GRR]{}, grr_tip[MAX_GRR][MAX_TPO]{}, arm_tipo[MAX_ARM];
    //    char arm_pod[MAX_ARM]{}, arm_req[MAX_ARM][MAX_REQ]{};


    int grr_pod[MAX_GRR] = {120, 160, 80};
    int grr_tip[MAX_GRR][MAX_TPO] = {
        {2},
        {1, 3},
        {3}
    };
    char arm_nom[MAX_ARM] = {'Z', 'P', 'R', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L'};
    int arm_pod[MAX_ARM] = {60, 80, 38, 25, 49, 57, 68, 35, 62, 42, 36, 54};
    int arm_tip[MAX_ARM] = {3, 1, 2, 2, 2, 1, 3, 2, 2, 2, 1, 3};
    char arm_req[MAX_ARM][MAX_REQ]{
        {},
        {'Z'},
        {},
        {'R'},
        {},
        {},
        {},
        {'Z', 'E'},
        {'R'},
        {}
        ,
        {'Z'},
        {}
    };
    int base = MAX_GRR + 1, opc = (int) pow(base, MAX_ARM);
    int cromo[MAX_ARM], mejorC;
    int grr_pod_aux[MAX_GRR], contador = 0;
    bool siValeRequisito, siValeTipo, siValeCromo;


    for (int i = 0; i < opc; i++) {
        cargaBin(cromo, base, i, MAX_ARM);
        siValeCromo = true;

        for (int k = 0; k < MAX_GRR; k++) grr_pod_aux[k] = grr_pod[k];

        for (int j = 0; j < MAX_ARM; j++) {

            if (verificarTipo(cromo[j], arm_tip[j],
                    grr_tip[cromo[j] - 1], MAX_TPO)) {
                if (verificarRequisitos(cromo, arm_nom, arm_req[j], cromo[j],
                        MAX_ARM)) {
                    grr_pod_aux[cromo[j] - 1] -= arm_pod[j];
                } else siValeCromo = false;
            } else {
                if (cromo[j] != 0) siValeCromo = false;
            }
        }


        for (int l = 0; l < MAX_GRR; l++) {
            if (grr_pod_aux[l] > 0) {
                siValeCromo = false;
                break;
            }
        }

        if (siValeCromo) {
            contador++;
            cout << "Solucion " << contador << " : " << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "Cromo : " << i << endl;
            for (int p = 0; p < MAX_GRR; p++) {
                cout << "Guerrero " << p + 1 << endl << "Poder : " << grr_pod[p]
                        << endl;
                cout << "Armas en la mochila para vencerlo: ";
                for (int o = 0; o < MAX_ARM; o++) {
                    if (cromo[o] == p + 1) cout << arm_nom[o] << ' ';
                }
                cout << endl;

            }
            cout << "-----------------------------------------------------" << endl;
          
        }
    }


//        if (siValeCromo) {
//            cargaBin(cromo, base, mejorC, MAX_ARM);
//            cout << mejorC << endl;
//            for (int p = 0; p < MAX_GRR; p++) {
//                cout << "Guerrero " << p + 1 << endl << "Poder : " << grr_pod[p]
//                        << endl;
//                cout << "Armas en la mochila para vencerlo: ";
//                for (int o = 0; o < MAX_ARM; o++) {
//                    if (cromo[o] == p + 1) cout << arm_nom[o] << ' ';
//                }
//                cout << endl;
//    
//            }
//        }
    return 0;
}

