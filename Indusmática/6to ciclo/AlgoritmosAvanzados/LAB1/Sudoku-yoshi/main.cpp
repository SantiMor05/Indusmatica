#include <iostream>
using namespace std;
#define N 9
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

int contarCeros() {
    int cont = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == 0) cont++;
        }
    }
    return cont;
}

bool cumpleColFil(int i,int x,int y) {
    for (int j = 0; j < N; j++) {
        if (matriz[x][j] == i or matriz[j][y] == i)
            return false;
    }
    return true;
}

void retornaValoresCuadrante(int &inix,int &finx,int x) {
    if (x>=0 and x<=2) {
        inix = 0;
        finx = 2;
    }else {
        if (x<=5) {
            inix = 3;
            finx = 5;
        }else {
            inix = 6;
            finx = 8;
        }
    }
}

bool cumpleCuadrante(int i,int x,int y) {
    int inix, finx, iniy, finy;
    retornaValoresCuadrante(inix,finx,x);
    retornaValoresCuadrante(iniy,finy,y);
    for (int j = inix; j <= finx; j++) {
        for (int k = iniy; k <= finy; k++) {
            if (matriz[j][k]==i)
                return false;
        }
    }
    return true;
}

bool funcionAbueloQueCompraElBocon(int x, int y, int numCeros) {
    if (numCeros == 0) return true;
    if (x>=N)
        return true;
    if (y==N) {
        if (funcionAbueloQueCompraElBocon(x+1,0,numCeros))
            return true;
        return false;
    }
    if (matriz[x][y] == 0) {
            for (int i=1; i<=9; i++) {
                if (cumpleCuadrante(i,x,y) and cumpleColFil(i,x,y)) {
                    matriz[x][y] = i;
                    if (funcionAbueloQueCompraElBocon(x,y+1,numCeros-1))
                        return true;
                        matriz[x][y] = 0;
                }
            }
    }else {
        return funcionAbueloQueCompraElBocon(x,y+1,numCeros);
    }
    return false;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    int numCeros = contarCeros();
    bool respuesta = funcionAbueloQueCompraElBocon(0,0,numCeros);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}