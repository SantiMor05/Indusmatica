
#include <iostream>
#define MAX 9
using namespace std;

int tablero[MAX][MAX] = {
    {0, 2, 0, 0, 0, 0, 0, 9, 0},
    {3, 0, 1, 9, 0, 6, 5, 0, 2},
    {0, 0, 0, 8, 0, 4, 0, 0, 0},
    {0, 9, 0, 0, 0, 0, 0, 5, 0},
    {5, 0, 0, 2, 0, 3, 0, 0, 6},
    {0, 7, 0, 0, 0, 0, 0, 2, 0},
    {0, 0, 0, 4, 0, 7, 0, 0, 0},
    {8, 0, 2, 5, 0, 1, 7, 0, 3},
    {0, 5, 0, 0, 0, 0, 0, 8, 0}
};


void imprimirTablero() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << tablero[i][j];
            if ((j + 1) % 3 == 0 and j != MAX - 1) cout << "|";
            else cout << " ";
        }
        if ((i + 1) % 3 == 0 and i != MAX - 1) cout << "\n------------------";
        cout << endl;
    }
    cout << endl;
}

bool verificar(int x, int y, int num) {
    //fila
    for (int i = 0; i < MAX; i++) {
        if (tablero[x][i] == num)return false;
    }

    //columna
    for (int i = 0; i < MAX; i++) {
        if (tablero[i][y] == num)return false;
    }

    //bloque
    int fil1 = x / 3 * 3;
    int col1 = y / 3 * 3;

    for (int i = fil1; i < fil1 + 3; i++) {
        for (int j = col1; j < col1 + 3; j++) {
            if (tablero[i][j] == num) return false;
        }
    }

    return true;
}

int resolverSudoku(int x, int y) {
    if (x == MAX) {
        return 1;
    }
    int nx = x, ny = y;
    if (y + 1 == MAX) {
        ny = 0;
        nx ++;
    } else ny ++;
    if (tablero[x][y] == 0) {
        for (int i = 1; i <= MAX; i++) {
            if (verificar(x, y, i)) {
                tablero[x][y] = i;
                if (resolverSudoku(nx, ny))return 1;
                tablero[x][y] = 0;
            }
        }
    } else {
        return resolverSudoku(nx, ny);
    }

    return 0;
}


int main() {
    cout << "Inicio:" << endl;
    imprimirTablero();
    cout << "Solucion:" << endl;
    resolverSudoku(0, 0);
    imprimirTablero();
    return 0;
}

//Esteban estuvo aqui :v dxdxdxXDxdXdXD
//Terrible error de concepto
