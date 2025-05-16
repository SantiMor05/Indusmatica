/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Pila.h"
#include "Elemento.h"
#include "funcionesPila.h"
using namespace std;
#define N 14
//#define N 7

void hallar(int*numeros,int n,int &posMax,int &cantMax){
    
    Elemento max{-1},ele;
    Pila pila;
    construir(pila);
    for (int i = N-1; i>=0; i--) {
        ele.numero=numeros[i];
        apilar(pila,ele);
        if(max.numero==-1 or ele.numero>max.numero)
            max.numero=ele.numero;
    }
    imprimir(pila);
    bool condi=true,bandera=true,esPrimerMax=true;
    int arri=0,aba=0,cant,pos,i=0;
    while(!esPilaVacia(pila)){
        ele=desapilar(pila);
        if(ele.numero==max.numero){
            if(esPrimerMax){
                esPrimerMax=false;
                condi=false;
                pos=i;
            }
            else{
                cant=arri+aba;
                if(bandera or cant>cantMax){
                    bandera=false;
                    cantMax=cant;
                    posMax=pos;
                }
                pos=i;
                arri=aba;
                aba=0;
            }
        }
        else{
            if(condi)arri++;
            else aba++;
            
        }
        i++;
    }
    cant=arri+aba;
    if(bandera or cant>cantMax){
        bandera=false;
        cantMax=cant;
        posMax=pos;
    }
}



int main(int argc, char** argv) {

    int numeros[N]{ 1,7, 2 ,7 ,3 ,4, 3, 2, 1, 7, 2, 1, 7, 3};
//    int numeros[N]{ 6,2,5,4,5,1,6};
    int pos=-1,cant=-1;
    hallar(numeros,N,pos,cant);
    cout<<"Posicion: "<<pos<<"  Cantidad: "<<cant<<endl;
    return 0;
}

