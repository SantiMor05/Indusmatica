/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 18 de abril de 2025, 05:15 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#define N 10


void leerDatos(ifstream &arch,int ciudad[][N],int x,int y){
    
    if(y==N){
        y=0;
        x++;
    }
    if(x==N)return;
    
    arch>>ciudad[x][y];
    leerDatos(arch,ciudad,x,y+1);
}
//int a=0;
    
void resultado(int ciudad[][N],int x,int y,int i,int *tortugas,int movs[][4]){
    
    if(i==4){
        cout<<"La mision ha sido un fracado";
        return;
    }
    
    tortugas[i]-=ciudad[x][y];
    if(tortugas[i]>=0){
//        a++;
        if(ciudad[x][y]==50){
            cout<<"Las tortuninjas lograron vencer a SuperFly";
            return;
        }
        else resultado(ciudad,x+movs[i][0],y+movs[i][1],i,tortugas,movs);
    }
    else{
        x-=movs[i][0];
        y-=movs[i][1];
        i++;
        resultado(ciudad,x+movs[i ][0],y+movs[i][1],i,tortugas,movs);
    }
}


int main(int argc, char** argv) {

    ifstream arch("cuidad.txt",ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<"cuidad.txt"; exit(1);
    }
    int ciudad[N][N],tortugas[4]{75,58,65,80};
    int movs[][4]{
        {0,1},
        {1,0},
        {0,1},
        {0,1}
    };
    int x=0,y=0,i=0;
    leerDatos(arch,ciudad,0,0);
    resultado(ciudad,x,y,i,tortugas,movs);
//    cout<<endl<<a;
    
    return 0;
}

