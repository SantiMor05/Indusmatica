/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 19 de abril de 2025, 05:01 PM
 */

#include <iostream>

using namespace std;
#define F 5
#define C 5
//#define F 6
//#define C 6

int anaquel[][C]{
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,1,0,0,0},
    {0,0,0,0,0},
};
//int anaquel[][C]{
//    {0,0,0,0,0,0},
//    {0,0,0,0,0,0},
//    {0,0,0,1,0,0},
//    {0,1,0,0,0,0},
//    {0,0,0,0,1,0},
//    {0,0,0,0,0,0},
//};

void completar(int x,int y,int &cant){
    
    if(x<0 or y<0 or x>=F or y>=C)return;
    
    if(anaquel[x][y]!=1 and anaquel[x][y]!=5){
        anaquel[x][y]=5;
        cant--;
    }
    else return;
    if(cant==0){
        cout<<"Si es posible ordenar los productos en el anaquel"<<endl;
        return;
    }
    else{
        
        completar(x+1,y-1,cant);
        if(cant!=0){
            completar(x+1,y,cant);
        }
        if(cant!=0){
            completar(x+1,y+1,cant);
        }
    }
}


int main(int argc, char** argv) {

    int y=C/2,x=0;
    int cant=16;
//    int cant=27;
    
    if(C%2==0){
        completar(x,y,cant);
        completar(x,y-1,cant);
    }
    else{
        completar(x,y,cant);
    }
    if(cant>0)cout<<"“No es posible utilizar este anaquel para la "
            "cantidad de productos solicitados"<<endl;
    cout<<"Queda "<<cant<<" productos"<<endl;
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            cout<<anaquel[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}

