#include <iostream>
#define N 9
#define M 5
#define MAX 8
using namespace std;

int mov[MAX][MAX];
char sol[N][M] {
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
char tablero[N][M] = {
    {' ', ' ', ' ', ' ', '*'},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', '*', '*', ' ', '*'},
    {' ', '*', '*', ' ', '*'},
    {'*', '*', ' ', '*', ' '},
    {'*', '*', '*', '*', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

void matrizmov() {
    mov[0][0] = 1;
    mov[0][1] = 0;
    mov[1][0] = 1;
    mov[1][1] = 1;
    mov[2][0] = 0;
    mov[2][1] = 1;
    mov[3][0] = -1;
    mov[3][1] = 1;
    mov[4][0] = -1;
    mov[4][1] = 0;
    mov[5][0] = -1;
    mov[5][1] = -1;
    mov[6][0] = 0;
    mov[6][1] = -1;
    mov[7][0] = 1;
    mov[7][1] = -1;
}

int esValido(int x, int y) {
    if (x >= 0 and x < N and y >= 0 and y < M and sol[x][y] == ' ')
        return 1;
    return 0;
}

void descubre(int x, int y) {
    for (int i = 0; i < MAX; i++) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if (esValido(nx, ny) and tablero[nx][ny] == '*')
            sol[nx][ny] = '*';
    }
}

int buscaminas(int x, int y, char paso) {
    if (x == N - 1 and y == M - 1) return 1;
    descubre(x, y);

    for (int i = 0; i < MAX; i++) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if (esValido(nx, ny)) {
            sol[nx][ny] = paso + 1;
            if (buscaminas(nx, ny, paso + 1))
                return 1;
            sol[nx][ny] = ' ';
        }
    }

    return 0;
}


int main() {
    char paso = 'A';
    matrizmov();
    sol[0][0] = paso;
    buscaminas(0, 0, paso);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
