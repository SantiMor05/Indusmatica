#include <iostream>
using namespace  std;
#define M 4
int matriz[M][M] = {0};

void llenarValores(int x,int &inix, int &finx) {
    if (x>=0 and x<=1) {
        inix = 0;
        finx = 1;
    }else {
        inix = 2;
        finx = 3;
    }
}

bool validarCentro(int valor) {
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=2;j++) {
            if (matriz[i][j]==valor)
                return false;
        }
    }
    return true;
}

bool validarChijaukay(int x,int y,int valor) {
    int inix, finx, iniy, finy;
    llenarValores(x,inix,finx);
    llenarValores(y,iniy,finy);
    for (int i =inix; i<=finx; i++) {
        for (int j =iniy; j<=finy; j++) {
            if (matriz[i][j] == valor)
                return false;
        }
    }
    if ( (x==1 and y==1) or (x==1 and y==2) or (x==2 and y==1) or (x==2 and y==2))
        if (validarCentro(valor)) {
            return true;
        }else return false;
    return true;
}

bool validarTipakay(int x,int y,int valor) {
    for (int i=0;i<M;i++) {
        if (matriz[x][i] == valor or matriz[i][y] == valor)
            return false;
    }
    return true;
}

bool validarFinal() {
    for (int i=0;i<M;i++) {
        for (int j=0;j<M;j++) {
            if (matriz[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool SudokuAjedrezChifaCocinaFusion(int x, int y) {
    if (x>=M) {
        if (validarFinal()) return true;
        return false;
    }
    if (y==M)
        return SudokuAjedrezChifaCocinaFusion(x+1,0);
    for (int i=1; i<=4; i++) {
        if (validarChijaukay(x,y,i) and validarTipakay(x,y,i)) {
            matriz[x][y] = i;
            if (SudokuAjedrezChifaCocinaFusion(x,y+1))
                return true;
            matriz[x][y] = 0;
        }
    }
    return false;
}

int main() {

    if (SudokuAjedrezChifaCocinaFusion(0,0)) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }else
        cout << "No se encontro solucion";

    return 0;
}