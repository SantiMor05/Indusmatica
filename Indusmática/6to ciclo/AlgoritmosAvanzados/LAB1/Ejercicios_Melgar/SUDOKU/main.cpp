#include <iostream>
using namespace std;
#define MAX 9

int tablero[MAX][MAX] {
    {0,2,0,0,0,0,0,9,0},
    {3,0,1,9,0,6,5,0,2},
    {0,0,0,8,0,4,0,0,0},
    {0,9,0,0,0,0,0,5,0},
    {5,0,0,2,0,3,0,0,6},
    {0,7,0,0,0,0,0,2,0},
    {0,0,0,4,0,7,0,0,0},
    {8,0,2,5,0,1,7,0,3},
    {0,5,0,0,0,0,0,8,0}
};

int encontrarNoAsignado(int &x,int &y) {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            if(tablero[i][j]==0) {
                x=i;
                y=j;
                return 1;
            }
        }
    }
    return 0;
}

int hayConflicto(int x,int y,int num) {
    //validarFila
    for(int i=0;i<MAX;i++) {
        if (tablero[x][i]==num)
            return 1;
    }
    //validar Col
    for(int i=0;i<MAX;i++) {
        if (tablero[i][y]==num)
            return 1;
    }

    //validar Tablero
    int iniCol=y-y%3;
    int iniFila=x-x%3;
    for(int i=iniFila;i<iniFil+3;i++) {
        for(int j=iniCol;j<iniCol+3;j++) {
            if(tablero[i][j]==num)
                return 1;
        }
    }
    return 0;
}

int resuelveSudoku() {
    int x, y;
    if (!encontrarNoAsignado(x,y)) return 1 ;
    for(int i=1;i<=9;i++) {
        if (!hayConflicto(x,y,i)) {
            tablero[x][y]=i;
            if (resuelveSudoku())
                return 1;
            else
                tablero[x][y]=0;
        }
    }
    return 0;
}

void imprimeTablero() {
    for(int i=0;i<MAX;i++) {
        if(i%3==0) cout<<endl;
        for(int j=0;j<MAX;j++) {
            if (j%3==0)
                cout<<" ";
            if (tablero[i][j]==0) {
                cout<<"* ";
            }else {
                cout<<tablero[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    imprimeTablero();
    cout<<endl<<endl;
    if (resuelveSudoku())
        imprimeTablero();
    return 0;
}
