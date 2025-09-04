#include <iostream>
using namespace std;
#define N 4

int mov[N][2];

char tablero[N][N] {
    {'*','*','*','*'},
    {'*','*','*','*'},
    {'*','*','*','*'},
    {'*','*','*','*'}
};

int esValido(int fila,int colum) {
    for (int i = 0; i < fila; i++) {
        if (tablero[i][colum] == 'Q' ) {
            return 0;
        }
    }

    for (int i = fila-1 , j=colum-1; i>=0 and j>=0; i--,j--) {
        if (tablero[i][j] == 'Q' ) {
            return 0;
        }
    }

    for (int i = fila-1 , j=colum+1; i>=0 and j<N; i--,j++) {
        if (tablero[i][j] == 'Q' ) {
            return 0;
        }
    }
    return 1;
}

void imprimeTablero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j]<<' ';
        }
        cout << endl;
    }
    cout << endl;
}

int haySolucion(int fila) {
    if (fila==N) {
        imprimeTablero();
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (esValido(fila,i)) {
            tablero[fila][i]='Q';
            if (haySolucion(fila+1)) {
                return 1;
            }else
                tablero[fila][i]='*';
        }
    }
    return 0;
}


int main() {
    imprimeTablero();
    cout << endl<<endl;
    if (haySolucion(0))
    return 0;
}