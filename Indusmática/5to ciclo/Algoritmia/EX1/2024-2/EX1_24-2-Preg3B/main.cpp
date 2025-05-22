/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 17:49
 */

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int obteneDigitos(int numero){
    return log10(numero) + 1;
}

void cargabin(int num, int *cromo, int base, int n){
    
    for(int i = 0; i < n; i++)
        cromo[i] = 0;
    int resto, cont = 0;
    
    while(num > 0){
        resto = num % base;
        num /= base;
        cromo[cont] = resto;
        cont++;
    }
    
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int numero = 1396, aux, digito, cont, numero1, numero2, potencia;
    int digitos = obteneDigitos(numero),divisor;
    int cromo[digitos], arrNumero[digitos];
    bool vampiro = false;
    int opciones = pow(digitos, digitos); 
    
    //Pasamos el número a un arreglo;
    aux = numero;
    for(int i = 0; i < digitos; i++){
        digito = aux % 10;
        arrNumero[i] = digito;
        aux /= 10;
    }
    
    for(int i = 1; i < opciones; i++){
       
        cargabin(i, cromo, digitos, digitos);
        aux = cont = 0;
        //Buscamos que estan todos los numeros y lo vamos ordenando
        for(int c = 0; c < digitos; c++){
            for(int j = 0; j < digitos; j++){
                if(cromo[j] == c){
                    aux =  aux * 10 + arrNumero[j];
                    cont++;
                    break;
                }
            }
        }
        if(cont == digitos){//Están todos los numeros de 0 hasta cant_digitos
            potencia = digitos / 2;
            divisor = round(pow(10,potencia));
            numero1 = aux / divisor;
            numero2 = aux % divisor;
            if(numero1 * numero2 == numero){
                cout << "Es numero vampiro" << endl;
                vampiro = true;
                break;
            }
                
        }        
    }

    if(vampiro == false)
        cout << "No es vampiro" << endl;
    
    return 0;
}

