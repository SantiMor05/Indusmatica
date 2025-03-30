/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 30 de marzo de 2025, 11:44
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

/*
 * 
 */


void cargabin(int num,int *cromo,int n, int base){
    
    for(int i = 0; i < n; i++)
        cromo[i] = 0;
    int resto, i = 0;
    while(num > 0){
        resto = num % base;
        num /= base;
        cromo[i] = resto;
        i++;
    }
    
}

int contarLetras(char *palabra, int nmax){
    
    int i;
    for(i = 0; i < nmax and palabra[i]; i++);
    return i;    
}

int contarUnos(int *cromo, int nmax){
    int cont = 0;
    for(int i = 0; i < nmax; i++){
        if(cromo[i] == 1)
            cont++;
    }
    return cont;  
}

bool verificarPalabras(char *letras, int *cromo, char *palabra, 
        int letrasPalabra, int nletras){
    
    for(int i = 0; i < letrasPalabra; i++){
        
        for(int j = 0; j < nletras; j++){
            if(palabra[i] == (cromo[j] * letras[j])){
                cromo[j] = 0;
                break;
            }    
        }
    }
    
    int nceros = 0;
    for(int i = 0; i < nletras; i++){
        if(cromo[i] == 0)
            nceros++;
    }
    if(nceros == nletras)
        return true;
    return false;
    
}


int main(int argc, char** argv) {
    
    char letras[10] {'G', 'A', 'L', 'A', 'O', 'G', 'L',  'M'};
    
    char palabras[8][8]{
        {'G','O','L'},
        {'G','A','L','A'},
        {'A','L','A'},
        {'L','O','M','A'}
    };
    
    int nletras = 10, npalabras = 4;
    int combinaciones;
    int opciones = pow(2,nletras);
    int cromo[10], letrasPalabra, letrasCromo;
    
    for(int i = 0; i < npalabras; i++){
        combinaciones = 0;
        letrasPalabra = contarLetras(palabras[i], 8);
        
        for(int j = 0; j < opciones; j++){
            cargabin(j,cromo,nletras, 2);
            letrasCromo =  contarUnos(cromo, nletras);
            if(letrasCromo == letrasPalabra){
                if(verificarPalabras(letras, cromo, palabras[i], letrasPalabra,
                        nletras)) 
                    combinaciones++;
            }
        }
        cout << "La palabra " << palabras[i] << " tiene " << combinaciones << 
                " combinaciones de letras" << endl;
    }
    

    return 0;
}

