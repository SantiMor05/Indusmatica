#include <cmath>
#include <iostream>
using namespace std;
#define MAX 8

int mov[MAX][2];
int tablero[MAX][MAX];

void movimientos(){
    mov[0][0]=-2; mov[0][1]=1;
    mov[1][0]=-1; mov[1][1]=2;
    mov[2][0]=1; mov[2][1]=2;
    mov[3][0]=2; mov[3][1]=1;
    mov[4][0]=2; mov[4][1]=-1;
    mov[5][0]=1; mov[5][1]=-2;
    mov[6][0]=-1; mov[6][1]=-2;
    mov[7][0]=-2; mov[7][1]=-1;
}

void inicializa() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            tablero[i][j] = 0;
}

int valido(int x,int y) {
    if (x<MAX && y<MAX && x>=0 && y>=0 and tablero[x][y]==0)
        return 1;
    else
        return 0;
}

int saltocaballo(int x,int y,int nmov) {
    if (nmov == MAX*MAX+1) return 1;
    for (int i = 0; i < MAX; i++) {
        int nx=x+mov[i][0];
        int ny=y+mov[i][1];
        if (valido(nx,ny)) {
            tablero[nx][ny] = nmov;
            if (saltocaballo(nx,ny,nmov+1))
                return 1;
            tablero[nx][ny] = 0;
        }
    }
    return 0;
}

int main() {
    movimientos();
    inicializa();
    tablero[0][0]=1;
    if (saltocaballo(0,0,2))
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++)
                cout << tablero[i][j] << " ";
            cout << endl;
        }
    return 0;
}