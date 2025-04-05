/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 1 de abril de 2025, 22:52
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

void cambiarBase(int *cromosoma, int base, int numPosi, int cantLetras);
void convertirALetras(int *cromosoma, char *letrasFabricadas, int cantLetras,
        char *auxLetras);
bool valida(char *auxPalabra, char *auxLetras, int cantLetras,
        int column);
bool buscadorConContador( char *auxLetras, int cantLetras,
        char letraBuscada);

/*
 * 
 */
int main(int argc, char** argv) {
    int cantLetras = 8, column = 4, cantPosibilidades, fila = 4;
    int cromosoma[cantLetras];
    char auxLetras[cantLetras];
    char letrasFabricadas[cantLetras] = {'G', 'A', 'L', 'A', 'O', 'G', 'L', 'M'};
    char palabras[fila][column] = {
        {'G', 'O', 'L', '$'},
        {'G', 'A', 'L', 'A'},
        {'A', 'L', 'A', '$'},
        {'L', 'O', 'M', 'A'},
    };
    int combinaciones[fila] = {};
    int base = 2;
    bool validacion;
    char auxPalabra[column];
    int contador;
    int longitudCadena, auxLongitud;

    // vamos fila por fila
    for (int i = 0; i < fila; i++) {
        //Asignamos
        for (int k = 0; k < column; k++) {
            auxPalabra[k] = palabras[i][k];
        }
        //GOL$
                
        for (int t = 0; t < column; t++) {
            cout << auxPalabra[t];
        }
        cout << endl;




        // el cantLetras representa de cunatos bits/cifras queremos nuestra base;
        cantPosibilidades = pow(base, cantLetras);

        for (int numPosi = 0; numPosi < cantPosibilidades; numPosi++) {

            //convertimos a binario nuestor numPosi
            cambiarBase(cromosoma, base, numPosi, cantLetras);
            //10010101001010101

            //convertimos a cadena de letas a la posibilidad;
            convertirALetras(cromosoma, letrasFabricadas, cantLetras, auxLetras);

            //Obtenemos el tamaño de las letras dentro del cromosoma
            longitudCadena = 0;
            for (int i = 0; i < cantLetras; i++) {
                cout << auxLetras[i];
                if (auxLetras[i] != '\0') longitudCadena++;
            }
            cout << "   " << longitudCadena << endl;

            //Obtenemos el tamñao del auxPalbras
            
            auxLongitud=0;
            for (int i = 0; i < column && auxPalabra[i] != '$'; i++) {
                auxLongitud++;
            }
            
            cout << "   " << auxLongitud << endl;
            
            if(auxLongitud==longitudCadena){
                
                //validamos q sea el cromosoma valido GOL y no GOLGO
                            validacion = valida(auxPalabra, auxLetras, cantLetras, column);
                //
                            if (validacion) {
                                combinaciones[i]++;
                            }
            }







        }
    }

    for (int i = 0; i < fila; i++) {
        cout << combinaciones[i] << endl;
    }




    return 0;
}

void cambiarBase(int *cromosoma, int base, int numPosi, int cantLetras) {
    int a = 0, residuo;

    //Inicializamos
    for (int i = 0; i < cantLetras; i++) {
        cromosoma[i] = 0;
    }
    while (numPosi > 0) {
        residuo = numPosi % base;
        numPosi = numPosi / base;
        cromosoma[a] = residuo;
        a++;
    }
}

void convertirALetras(int *cromosoma, char *letrasFabricadas, int cantLetras,
        char *auxLetras) {
    for (int i = 0; i < cantLetras; i++) {
        auxLetras[i] = cromosoma[i] * letrasFabricadas[i];
    }
}

bool valida(char *auxPalabra, char *auxLetras, int cantLetras,
        int column){
    bool estaLaLetra;
    for (int i = 0; i < column && auxPalabra[i] != '$'; i++) {
        //G
        estaLaLetra= buscadorConContador( auxLetras, cantLetras, auxPalabra[i]);
        
        if(!estaLaLetra) return false;
    }
    return true;


}

bool buscadorConContador( char *auxLetras, int cantLetras,
        char letraBuscada) {
    for (int i = 0; i < cantLetras; i++) {
        if (auxLetras[i] == letraBuscada) {
            auxLetras[i]='\0';
            return true ;
        }
    }
    return false;
}