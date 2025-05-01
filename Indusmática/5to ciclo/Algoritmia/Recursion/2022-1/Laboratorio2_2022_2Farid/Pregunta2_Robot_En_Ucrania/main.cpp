/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 30 de abril de 2025, 10:53 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define N 9
#define M 5

/*
 * 
 */

char mapaaux[N][M] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

void imprimirMapaDetectado(int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << '(' << mapaaux[i][j] << ") ";
        }
        cout << endl;
    }
}

int mov[][2] = {
    {-1,-1},
    {-1, 0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1}
};

void detectarMinas(char mapa[][5], int x, int y, int n, int m) {
    int nx, ny;
    
    for (int i = 0; i < 8; i++) {
        nx= x + mov[i][0];
        ny = y +mov[i][1];
        if(nx >=0 and ny>= 0 and nx <N and ny < M and mapa[nx][ny]=='*')
            mapaaux[nx][ny] = '*';
    }
}

int robotRecorrido(char mapa[][5], int x, int y, int n, int m, int pasos) {
    int min = 999;
    if(mapa[x][y] == '*') return min;
    if (x < n and y < m and mapa[x][y] != '*')
        detectarMinas(mapa, x, y, n, m);
    if (x == n - 1 and y == m - 1) {
        //        cout << pasos << endl;
        if (min > pasos) min = pasos;
        return min;
    }
    int aux;

    if (x + 1 < n and mapa[x + 1][y] != '*') {
        aux = robotRecorrido(mapa, x + 1, y, n, m, pasos + 1);
        if (aux < min) min = aux;
    }
    if (y + 1 < m and mapa[x][y + 1] != '*') {
        aux = robotRecorrido(mapa, x, y + 1, n, m, pasos + 1);
        if (aux < min) min = aux;
    }

    if (x + 1 < n and y + 1 < m and mapa[x + 1][y + 1] != '*') {
        aux = robotRecorrido(mapa, x + 1, y + 1, n, m, pasos + 1);
        if (aux < min) min = aux;
    }

    return min;
}

int main(int argc, char** argv) {
    int n = 9, m = 5;
    char mapa[N][M] = {
        {'*', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', '*', '*', ' ', '*'},
        {' ', '*', '*', ' ', '*'},
        {'*', '*', ' ', '*', ' '},
        {'*', '*', '*', '*', ' '},
        {'*', ' ', ' ', ' ', ' '}
    };
    int x = 0, y = 0, pasos = 0, min;

    min = robotRecorrido(mapa, x, y, n, m, pasos);

    imprimirMapaDetectado(n, m);
    if (min != 999)
        cout << "El robot llega el punto final en " << min << " pasos" << endl;
    else cout << "No se puede llegar " << endl;
    return 0;
}

