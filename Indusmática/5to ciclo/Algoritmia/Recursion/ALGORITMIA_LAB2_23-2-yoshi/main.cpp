/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 1 de mayo de 2025, 18:52
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "TORTUNINJAS.h"
#define N 10
#define M 10
struct TortuNinja robots[4];

void llenar_tortuninjas(TortuNinja *robots){

    robots[0].poder = 75;
    robots[0].x = 0;
    robots[0].y = 1;
    
    robots[1].poder = 58;
    robots[1].x = 1;
    robots[1].y = 0;
    
    robots[2].poder = 65;
    robots[2].x = 0;
    robots[2].y = 1;
    
    robots[3].poder = 80;
    robots[3].x = 0;
    robots[3].y = 1;
}


bool tortuMision(TortuNinja &robot,int x,int y,int tablero[][M],int i){
    if (i==4) return false; //todas las tortuninjas han muerto
    if (x<0 or y<0 or x+robot.x>=N or y+robot.y>=M) return false;
    if (tablero[x+robot.x][y+robot.y]!=0){
        if (robot.poder - tablero[x+robot.x][y+robot.y] >= 0){
            robot.poder -= tablero[x+robot.x][y+robot.y];
            if (tablero[x+robot.x][y+robot.y] == 50) return true;
            return tortuMision(robot,x+robot.x,y+robot.y,tablero,i);
        }else{
            return tortuMision(robots[i+1],x+robots[i+1].x,y+robots[i+1].y,tablero,i+1);
        }
    }else{
        return tortuMision(robot,x+robot.x, y+robot.y, tablero,i);
    }
}



int main(int argc, char** argv) {
    int tablero[][M] = {    {0,0,42,0,35,0,0,10,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,27,0,0,0,0,50,0,0,0},
                            {0,0,30,0,0,0,0,0,0,0},
                            {0,0,0,0,38,0,0,42,0,0},
                            {15,0,0,50,0,0,0,50,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,50,0,37,0,0,0},
                            {0,18,0,17,0,0,0,0,50,0},
                            {0,0,0,0,0,0,0,0,0,0}};
    llenar_tortuninjas(robots);
    bool vivos = true;
    int i=0;
    if (tortuMision(robots[0],0,0,tablero,i)) 
        cout<<"Las tortuninjas lograron vencer a Superfly"<<endl;
    else cout<<"Las tortuninjas NO lograron vencer a Superfly"<<endl;
    return 0;
}

