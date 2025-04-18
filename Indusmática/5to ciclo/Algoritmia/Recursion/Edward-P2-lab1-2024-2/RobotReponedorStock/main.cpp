/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 18 de abril de 2025, 10:16 AM
 */

#include <iostream>
#include <climits>

using namespace std;
#define N 5
#define M 5

int stock[N][M]{
    {4 ,3 ,6 ,8, 7}, 
    {6 ,3 ,8 ,4 ,10 },
    {2, 15, 1, 2, 13},
    {5 ,1 ,10, 11 ,2 },
    {10, 4 ,7 ,9 ,4 }
};

int mayor(int x,int y){
     
    if(y>=M){
        y=0;
        x++;
    }
    if(x>=N)return INT_MIN;
    int a=stock[x][y],b=mayor(x,y+1);
    if(a>=b)return a;
    return b;
}

int main(int argc, char** argv) {

    int max=mayor(0,0);
    cout<<"El mayor es "<<max<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<<max-stock[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}

