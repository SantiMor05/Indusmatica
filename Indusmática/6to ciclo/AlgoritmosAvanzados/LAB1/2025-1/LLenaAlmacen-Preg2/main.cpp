#include <iostream>
using namespace std;

#define ANCHO 6
#define ALTO 3
#define N 8

int almacen[ALTO][ANCHO]{};

// int mov[16][2] {};

// void cargarMov() {
//     mov[0][0] = -2;     mov[0][1]= -2;
//     mov[1][0] = -2;     mov[1][1]= -1;
//     mov[2][0] = -2;     mov[2][1]= 0;
//     mov[3][0] = -2;     mov[3][1]= 1;
//     mov[4][0] = -2;     mov[4][1]= 2;
//     mov[5][0] = -1;     mov[5][1]= 2;
//     mov[6][0] = 0;     mov[6][1]= 2;
//     mov[7][0] = 1;     mov[7][1]= 2;
//     mov[8][0] = 2;     mov[8][1]= 2;
//     mov[9][0] = 2;     mov[9][1]= 1;
//     mov[10][0] = 2;     mov[10][1]= 0;
//     mov[11][0] = 2;     mov[11][1]= -1;
//     mov[12][0] = 2;     mov[12][1]= -2;
//     mov[13][0] = 1;     mov[13][1]= -2;
//     mov[14][0] = 0;     mov[14][1]= -2;
//     mov[15][0] = -1;     mov[15][1]= -2;
// } No se puede hacer por movimientos de esta manera (como el problema del caballo), porque
// no se sabe cuando parar.En el problema del caballo había un límite de movimientos que rompiar la recursión

//Hacemos movimientos, para verificar que todo alrededor es cero

int mov[8][2];

void movimientos() {
    mov[0][0] = -1;     mov[0][1] = -1;
    mov[1][0] = -1;     mov[1][1] = 0;
    mov[2][0] = -1;     mov[2][1] = 1;
    mov[3][0] = 0;     mov[3][1] = 1;
    mov[4][0] = 1;     mov[4][1] = 1;
    mov[5][0] = 1;     mov[5][1] = 0;
    mov[6][0] = 1;     mov[6][1] = -1;
    mov[7][0] = 0;     mov[7][1] = -1;
}


int solu[ALTO][ANCHO]{};

void copiaSolu() {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            solu[i][j] = almacen[i][j];
        }
    }
}

int validarAlrededor(int fil, int col) {
    int nfil, ncol;
    for (int i = 0; i < N; i++) {
        nfil = fil + mov[i][0];
        ncol = col + mov[i][1];
        if (nfil >= 0 && ncol >= 0 and nfil < ALTO and ncol < ANCHO) {
            if (almacen[nfil][ncol] != 0) return 0;
        }
    }
    return 1;
}

void siguienteCasilla(int &nfil,int &ncol,int fil,int col) {
    if (col + 1 >= ANCHO) {
        nfil = fil + 1;
        ncol = 0;
    }
    else {
        nfil = fil;
        ncol = col + 1;
    }
}

void imprimeSolu() {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            cout << solu[i][j] << " ";
        }
        cout << endl;
    }
}

int buscarMaxPalets(int fil, int col, int &max, int cant) {
    if (fil == ALTO - 1 && col == ANCHO - 1) {
        if (cant > max) {
            max = cant;
            copiaSolu();
        }
        return 0; //Necesitamos iterar por todas las soluciones posibles
    }
    int nfil, ncol, entro;
    for (int i = 0; i < 2; i++) { //Hay dos opciones, se rellena la casilla con el palet o no se hace
        if (validarAlrededor(fil,col) and i == 0 and (fil != 0 or col != 0) ){
            almacen[fil][col] = cant + 1;
            cant++;
            entro = 1;
        }
        siguienteCasilla(nfil,ncol,fil,col);
        if (buscarMaxPalets(nfil,ncol,max,cant)) return 1;
        almacen[fil][col] = 0;
        cant--;
        if (!entro)break;
    }

    return 0;
}

int main() {

    int max = 0;
    movimientos();
    buscarMaxPalets(0,0,max, 0);
    cout << max << endl;
    imprimeSolu();
    return 0;
}