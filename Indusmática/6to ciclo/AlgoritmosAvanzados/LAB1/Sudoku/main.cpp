#include <iomanip>
#include <iostream>
#define N 9
#define NUMEROS 9

using namespace std;

int matriz[N][N] =
    {
    {0,2,0,0,0,0,0,9,0},
    {3,0,1,9,0,6,5,0,2},
    {0,0,0,8,0,4,0,0,0},
    {0,9,0,0,0,0,0,5,0},
    {5,0,0,2,0,3,0,0,6},
    {0,7,0,0,0,0,0,2,0},
    {0,0,0,4,0,7,0,0,0},
    {8,0,2,5,0,1,7,0,3},
    {0,5,0,0,0,0,0,8,0},
};

int cont = 0;

int verificar(int num,int fil,int col) {

    //Revisamos la fila (en horizontal)
    for (int i = 0; i < N; i++) {
        //if (i == col) continue;
        if (num == matriz[fil][i]) return 0;
    }
    //Revisamos la columna (en vertical)
    for (int i = 0; i < N; i++) {
        //if (i == fil)continue;
        if (num == matriz[i][col]) return 0;
    }

    //Revisamos el bloque
    int fil1 = fil / 3 * 3;
    int col1 = col / 3 * 3;

    for (int i = fil1; i < fil1 + 3; i++) {
        for (int j = col1; j < col1 + 3; j++) {
            if (i == fil && j == col) continue;
            if (matriz[i][j] == num) return 0;
        }
    }

    return 1;
}

int posibilidades[9]{1,2,3,4,5,6,7,8,9};

void imprimirMatriz() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(2) << matriz[i][j];
        }
        cout << endl;
    }
}

void incrementarValor(int &nfil, int &ncol, int fil, int col) {
    if (col + 1 >= N) {
        ncol=0;
        nfil  = fil + 1;
    }
    else ncol = col + 1;
}

int resolverSudoku(int fil, int col) {
    if (fil == N) {
        imprimirMatriz();
        return 1;
    }
    int nfil = fil, ncol = col;
    if (matriz[fil][col] == 0) {
        for (int i = 0; i < NUMEROS; i++) {
            if (verificar(posibilidades[i], fil, col)) {
                matriz[fil][col] = posibilidades[i];
                incrementarValor(nfil,ncol, fil,col);
                if (resolverSudoku(nfil, ncol)) return 1;
                matriz[fil][col] = 0;
            }
        }
    }
    else {
        incrementarValor(nfil,ncol, fil, col);
        return resolverSudoku(nfil, ncol);
    }
    return 0;
}

int main() {
    resolverSudoku(0, 0);
    return 0;
}
