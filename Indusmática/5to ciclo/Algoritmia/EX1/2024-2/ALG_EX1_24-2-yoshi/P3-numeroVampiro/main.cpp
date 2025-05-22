/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 22 de mayo de 2025, 11:58
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

/*
 * 
 */


void cargabin(int *cromo,int num, int cantCifras){
    int res;
    for (int i = 0; i < cantCifras; i++) {
        res = num % cantCifras;
        num /= cantCifras;
        cromo[i] = res;
    }
}

bool esVampiro(int posibleVampiro,int *numero,int cantCifras){
    int posible = pow(cantCifras,cantCifras), cromo[cantCifras]{}, cant1, cant0, n1, n2;
    for (int i = 0; i < posible; i++) {
        cargabin(cromo,i,cantCifras);
        n1 = 0; n2 = 0;
        for (int i = 0; i < cantCifras; i++) {
            if (cromo[i] % 2 == 0) n1 += numero[i] * round((double)pow(10,cromo[i]/2));
            else n2 += numero[i] * round((double)pow(10,(cromo[i]-1)/2));
        }
        if (n1*n2==posibleVampiro){
            cout<<"EXSTE LA COMBINACIÓN: "<<n1<<" * "<<n2<<endl;
            return true;
        }
    }
    return false;
}

int calcular_y_guardar(int num,int *arreglo){
    int cont = 0, cifra;
    while(num>0){
        cifra = num % 10;
        num /= 10;
        arreglo[cont] = cifra;
        cont++;
    }
    return cont;
}

int main(int argc, char** argv) {
    int posibleVampiro, numero[10], cantCifras;
    cout<<"Ingrese el número a evaluar: ";
    cin>>posibleVampiro;
    cantCifras = calcular_y_guardar(posibleVampiro,numero);
    if (cantCifras % 2 ==0){
        if (esVampiro(posibleVampiro,numero,cantCifras)){
            cout<<posibleVampiro<<" SI es vampiro"<<endl;
        }else cout<<posibleVampiro<<" NO es vampiro"<<endl;
    }else cout<<"El número tiene una cantidad de cifras impar, por tanto, no puede ser evaluado";
    
    return 0;
}

