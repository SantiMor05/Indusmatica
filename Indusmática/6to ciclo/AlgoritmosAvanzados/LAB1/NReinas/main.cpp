#include <iostream>
using namespace std;
#define N 4
#define DIAGONALES 4

int matriz[N][N];

int diagonales[4][2];

void movimientos() {
    diagonales[0][0] = -1;  diagonales[0][1] = -1;
    diagonales[1][0] = -1;  diagonales[1][1] = 1;
    diagonales[2][0] = 1;  diagonales[2][1] = 1;
    diagonales[3][0] = 1;  diagonales[3][1] = -1;
}


void imprimeMatriz() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int validarCasilla(int fil,int col) {
    //No necesito garantizar que no haya otra reina en la fila
    //ya que por la forma en que haga el for en la recursion ya garantiza
    //que solo haya una reina en cada fila

    for (int i = 0; i < N; i++) {
        if (matriz[i][col] == 1) return 0; //Hay otra reina en la fila
    }

    //Verificamos las diagonales
    int ncol = col, nfil = fil;
    for (int i = 0; i < DIAGONALES; i++) {
        for (int j = 1; j < N; j++) {
            ncol = col + diagonales[i][1] * j;
            nfil = fil + diagonales[i][0] * j;
            if (ncol >= 0 && ncol <  N && nfil >= 0 && nfil < N
                && matriz[nfil][ncol] == 1) return 0;
        }
    }
    return 1;
}

int posicionarReinas(int fil) {

    if (fil == N) {
        imprimeMatriz();
        cout << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (validarCasilla(fil, i)) {
            matriz[fil][i] = 1;
            if (posicionarReinas(fil + 1)) return 1;
            matriz[fil][i] = 0;
        }
    }
    return 0;
}

int main() {

    movimientos();
    posicionarReinas(0);
    //imprimeMatriz();


    return 0;
}