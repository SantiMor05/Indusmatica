/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 23 de setiembre de 2024, 11:21
 */

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    Cola colaPrioridad;
    construirPrioridad(colaPrioridad);
    /*Esta funcion se encuentra implementada en FuncionesCola.cpp*/
    //    encolarPrioridad(colaPrioridad,0,'N');//NO VIP
    //    encolarPrioridad(colaPrioridad,30,'V');//VIP
    int cantCli = 50, cont = 0, atenVip = 0, noAtenVip = 0, tiempoSalida;
    char tipo;
    Nodo rec, ant;
    for (int i = 1; i <= cantCli * 15; i++) {

        if (i % 15 == 0 and (i % 2) != 0) {
            cout << "Entra NoVip en segundo: " << i << endl;
            encolarPrioridad(colaPrioridad, 0, 'N');
        } else if (i % 15 == 0 and i % 2 == 0) {
            if (tiempoSalida - i <= 10) {
                cout << "Entra Vip en segundo: " << i << endl;
                encolarPrioridad(colaPrioridad, 0, 'V');
                atenVip++;
            } else {
                noAtenVip++;
            }
        }
        if (cont == 0) {
            if (!esColaVacia(colaPrioridad)) {
//                cout<<i<<endl;
                tipo = desencolar(colaPrioridad);
                cont = 20;
                tiempoSalida = cont + i;
            }
        }

        if (cont > 0)cont--;
    }
    cout << " Clientes VIP Atendidos: " << atenVip;
    cout << " Clientes VIP no atendidos: " << noAtenVip;
    return 0;
}

