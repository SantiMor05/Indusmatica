#include <iomanip>
#include <iostream>
using namespace std;

#define N 8

int tablero[N][N]{};
int mov[N][2];

void movimientos() {
    //Horario
    mov[0][0] = -1;      mov[0][1] = -1;
    mov[1][0] = -1;      mov[1][1] = 0;
    mov[2][0] = -1;      mov[2][1] = 1;
    mov[3][0] = 0;      mov[3][1] = 1;
    mov[4][0] = 1;      mov[4][1] = 1;
    mov[5][0] = 1;      mov[5][1] = 0;
    mov[6][0] = 1;      mov[6][1] = -1;
    mov[7][0] = 0;      mov[7][1] = -1;

}

void imprimir() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

int validarCasilla(int fil, int col) {
    if (fil >= 0 and col >= 0 and fil < N and col < N and tablero[fil][col] == 0)return 1;
    return 0;
}


int moverRey(int fil, int col, int nMov) {

    if (nMov > N * N) {
        imprimir();
        return 1;
    }


    int nfil, ncol;
    for (int i = 0; i < N; i++) {
        nfil = fil + mov[i][0];
        ncol = col + mov[i][1];
        if (validarCasilla(nfil, ncol)) {
            tablero[nfil][ncol] = nMov;
            if (moverRey(nfil, ncol, nMov + 1)) return 1;
            tablero[nfil][ncol] = 0;
        }

    }


    return 0;
}

int main() {
    movimientos();
    int fil, col;

    cout << "Ingresa la fila donde comenzara el rey: ";
    cin >> fil;

    cout << "Ingresa la columna donde comenzara el rey: ";
    cin >> col;
    if (validarCasilla(fil, col)) {
        tablero[fil - 1][col - 1] = 1;
        moverRey(fil - 1, col - 1, 2);
    }
    else {
        cout << "La casilla ingresada no está dentro del tablero" << endl;
    }
    return 0;
}