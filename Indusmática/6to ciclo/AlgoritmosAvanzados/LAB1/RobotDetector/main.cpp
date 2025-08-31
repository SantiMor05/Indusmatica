#include <iostream>
#define N 9
#define M 5
#define MOVS 8

int mov[MOVS][2];

void movimientos() {

    mov[0][0] = 0;    mov[0][1] = -1;
    mov[1][0] = 1;    mov[1][1] = -1;
    mov[2][0] = 1;    mov[2][1] = 0;
    mov[3][0] = 1;    mov[3][1] = 1;
    mov[4][0] = 0;    mov[4][1] = 1;
    mov[5][0] = -1;    mov[5][1] = 1;
    mov[6][0] = -1;    mov[6][1] = 0;
    mov[7][0] = -1;    mov[7][1] = -1;

}

char matriz[N][M] = {

    {'0','0','0','0','*'},
    {'0','0','0','0','0'},
    {'0','0','*','0','0'},
    {'0','0','0','0','0'},
    {'0','*','*','0','*'},
    {'0','*','*','0','*'},
    {'0','*','0','*','0'},
    {'*','*','*','*','0'},
    {'0','0','0','0','0'}
};
char solu[N][M];

void inicializa(char tablero[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tablero[i][j] = '0';
        }
    }
}

void imprime(char tablero[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void localizaMinas(int fil, int col) {
    int ncol, nfil;
    for (int i = 0; i < MOVS; i++) {
        ncol = col + mov[i][1];
        nfil = fil + mov[i][0];
        if (nfil >= 0 && nfil < N && ncol >= 0 && ncol < M)
            if (matriz[nfil][ncol] == '*')
                solu[nfil][ncol] = '*';
    }
}

int recorre(int fil, int col, char paso, int &cont) {

    if (fil == N -1 && col == M -1) {
        if (cont < 20) {
            imprime(solu);
            std::cout << std::endl;
        }
        cont++;
        return 0;
    }
    if (fil == 0 and col == 0)
        solu[fil][col] = paso;
    int nfil, ncol;

    localizaMinas(fil,col);

    for (int i = 0; i < MOVS; i++) {
        nfil = fil + mov[i][0];
        ncol = col + mov[i][1];
        if (nfil >= 0 && nfil < N && ncol >= 0 && ncol < M) {
             if (solu[nfil][ncol] == '0') {
                solu[nfil][ncol] = paso + 1;
                if (recorre(nfil, ncol, paso + 1, cont))
                    return 1;
                solu[nfil][ncol] = '0';
            }
        }
    }
    return 0;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    inicializa(solu);
    movimientos();
    char paso = 'A';
    int cont = 0;
    recorre(0,0, paso, cont);
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}