#include <iostream>
#define N 8
#define M 8
using namespace std;

int mov[M][2];
int tablero[N][N]{};

void movimientos() {
    // X                 Y
    mov[0][0] = -2;
    mov[0][1] = 1;
    mov[1][0] = -1;
    mov[1][1] = 2;
    mov[2][0] = 1;
    mov[2][1] = 2;
    mov[3][0] = 2;
    mov[3][1] = 1;
    mov[4][0] = 2;
    mov[4][1] = -1;
    mov[5][0] = 1;
    mov[5][1] = -2;
    mov[6][0] = -1;
    mov[6][1] = -2;
    mov[7][0] = -2;
    mov[7][1] = -1;
}

void imprimir() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] / 10 == 0) cout << "0";
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int recorridoCaballo(int x, int y, int cont) {
    if (cont == N * N + 1) {
        // imprimir();
        return 1;
    }
    for (int i = 0; i < M; i++) {
        int nx = x + mov[i][0], ny = y + mov[i][1];
        if (nx < N and nx >= 0 and ny < N and ny >= 0 and tablero[nx][ny] == 0) {
            tablero[nx][ny] = cont;
            if (recorridoCaballo(nx, ny, cont + 1)) return 1;
            tablero[nx][ny] = 0;
        }
    }
    return 0;
}

int main() {
    cout << "Inicio:" << endl;
    imprimir();
    movimientos();
    tablero[0][0] = 1;
    recorridoCaballo(0, 0, 2);
    cout << "Solucion:" << endl;
    imprimir();

    return 0;
}
