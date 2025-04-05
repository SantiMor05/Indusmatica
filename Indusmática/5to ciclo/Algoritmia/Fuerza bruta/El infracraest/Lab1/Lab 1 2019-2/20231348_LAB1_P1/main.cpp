/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 4 de abril de 2025, 19:33
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void cargaBin(int numPosi,int cantProyec,int base,int *cromosoma);
bool buscamos(int proyecto,int *cromosoma,int cantProyec);
/*
 * 
 */
int main(int argc, char** argv) {
    int cantProyec=8;
    int cromosoma[cantProyec]{};
    int costos[cantProyec]={80,20,100,100,50,10,50,50};
    int ganancias[cantProyec]={150,80,300,150,80,50,120,150};
    int predecesores[cantProyec][3]={
        {0,0,0},       
        {0,0,0},       
        {1,2,0},       
        {0,0,0},       
        {0,0,0},       
        {2,0,0},       
        {6,0,0},       
        {6,0,0},       
    };
    int auxPredecesores[3]{};
    int base=2;
    int cantPosi;
    int presupuesto=250,costoTotal,gananciaTotal,gananciaMax=0,combiOpti;
    bool sePuede;
    bool siEstan;
    
    //calculamos la cantidad de pisibilidades;
    cantPosi=pow(base,cantProyec);
    
    //vamos posibilidad por posibilidad
    for (int numPosi = 0; numPosi < cantPosi; numPosi++) {
        //Variables incializadas en cada posibilidad
        sePuede=true;
        costoTotal=0;
        gananciaTotal=0;
//        for (int g = 0; g < 3; g++) {
//            auxPredecesores[g]=0;
//        }

        
        
        //convertimos a binariio
        cargaBin(numPosi,cantProyec,base,cromosoma);
        // 1 1 0 1 0 1
        
        //recoremos el cromosoma
        for (int i = 0; i < cantProyec; i++) {
            //1
            if(cromosoma[i]>0){
                //verificamos si cromo[i] necesita predecesores
                for (int j = 0; j < 3; j++) {
                    auxPredecesores[j]= predecesores[i][j];

                }

                for (int s = 0; auxPredecesores[s] ; s++) {
                    // 1 2 0
                    //Buscamos si los proyectoes estan en el proyecto
                    siEstan=buscamos(auxPredecesores[s],cromosoma,cantProyec);
                    if(!siEstan){
                        sePuede=false;
                        break;
                    }
                }
                
                // aca hace lo demas
                if(sePuede){
                    //sumamos el coste total
                    costoTotal+=costos[i];
                    
                    if(costoTotal>presupuesto){
                        sePuede=false;
                        break;
                    }else{
                        //guardamos el maximo
                        gananciaTotal+=ganancias[i];
                        if(gananciaTotal>gananciaMax){
                            gananciaMax=gananciaTotal;
                            combiOpti=numPosi;
                        }
                    }
                    
                }else break;
                
            }
        }
        

    }
        //Imprimimos
        
        cargaBin(combiOpti,cantProyec,base,cromosoma);
        cout<<"Ganancia Total Maxima: "<<gananciaMax<<endl;
        cout<<"Proyectos:"<<endl;
//        for (int i = 0; i < cantProyec; i++) {
//            cout<<cromosoma[i]<<" "<<endl;
//    }

        
        for (int i = 0; i < cantProyec; i++) {
            
            if(cromosoma[i]>0){
                cout<<i+1<<endl;
            }
        }

    
    
    
    return 0;
}

void cargaBin(int numPosi,int cantProyec,int base,int *cromosoma){
    int indice=0,residuo;
    
    //incializamos
    for (int i = 0; i < cantProyec; i++) {
        cromosoma[i]=0;
    }
    
    while (numPosi>0) {
        residuo=numPosi%base;
        numPosi=numPosi/base;
        cromosoma[indice]=residuo;
        indice++;
    }
}

bool buscamos(int proyecto,int *cromosoma,int cantProyec){
    for (int i = 0; i < cantProyec; i++) {
        if(cromosoma[i]>0){
            if(i+1==proyecto) return true;
        }
    }
    return false;   
}