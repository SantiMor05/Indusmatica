/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 21 de mayo de 2025, 20:51
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void cargaBin(int numPosi,int* cromosoma,int base,int cantCifras){
    int residuo,indice=0;
    
    for (int i = 0; i < cantCifras; i++) {
        cromosoma[i]= 0;
    }
    
    while (numPosi>0) {
        residuo= numPosi% base;
        numPosi= numPosi/base;
        cromosoma[indice]= residuo;
        indice++;
    }

    
    
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int base=6;
    int cantCifras= 6;
    int numeroIni= 136948;
    int numero[cantCifras]={1,3,6,9,4,8};
    int cromosoma[cantCifras]{};
    int cantPosi;
    bool esValido;
    bool esVampiro=false;
    cantPosi= pow(base,cantCifras);
    int primerNum,segundoNum,cont;
    for (int numPosi = 1; numPosi < cantPosi; numPosi++) {
        primerNum=0;
        segundoNum=0;
        // creamos el crmosoa
        cargaBin(numPosi,cromosoma,base,cantCifras);
        
        esValido=true;
        // rocoremos arreglo por secciones
        cont=0;
        for (int i = 0; i < cantCifras; i++) {
            
            //buscamos q no se repita
            for (int k = 0; k < cantCifras; k++) {
                if(i==cromosoma[k]){
                    cont++;
                    break;
                }    

            }
//            
//            for (int k = i+1; k < cantCifras; k++) {
//                if(cromosoma[i]==cromosoma[k]){
//                    esValido=false;
//                    break;
//                }
//            }


        }
        
        //hay ya valitar que en cada cromosoma hay digto del numero unico
        
        if(cont==cantCifras){
            int mitad=cantCifras/2;
            int auxExponente= mitad;
            for (int i = 0; i < mitad; i++) {
                primerNum+= numero[cromosoma[i]] * round(pow(10,auxExponente-1));
                auxExponente--;
            }
            auxExponente= mitad;
            for (int i = mitad; i < cantCifras; i++) {
                segundoNum+= numero[cromosoma[i]] * round(pow(10,auxExponente-1));
                auxExponente--;
            }
            
            if(numeroIni== primerNum*segundoNum){
                //Imprimimos
                esVampiro=true;
                cout<<primerNum<<" * "<<segundoNum<<endl;
                
            }
            
        }   
        
    }

    if(esVampiro) cout<<"El numero es vampiro";
    
    return 0;
}

