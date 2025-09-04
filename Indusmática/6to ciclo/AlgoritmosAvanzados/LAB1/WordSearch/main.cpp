#include <iostream>
using namespace std;
#define N 3
#define M 4

char tablero[N][M] {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};

int buscaInicio(int &x,int &y, char letra,char aux[][M]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(tablero[i][j] == letra and aux[i][j] != 'I' and aux[i][j] != '*') {
                x=i;
                y=j;
                aux[i][j]='I';
                return 1;
            }
        }
    }
    return 0;
}

int existePalabra(string palabra,int x,int y,int letra,char aux[][M]) {
    if (x<0 or y<0 or x>=N or y>=M or aux[x][y]=='*') return 0;
    if (letra==palabra.length())
        return 1;
    if (palabra[letra]==tablero[x][y]) {
        char temp = palabra[letra];
        aux[x][y]='*';
        if (existePalabra(palabra,x+1,y,letra+1,aux)||existePalabra(palabra,x,y-1,letra+1,aux)||
            existePalabra(palabra,x,y+1,letra+1,aux)||existePalabra(palabra,x-1,y,letra+1,aux))
            return 1;
        else
            tablero[x][y]=temp;
    }
    return 0;
}

void inicializaMatriz(char aux[][M],char car) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            aux[i][j]=car;
        }
    }
}

int existe(string palabra,int letra, char aux[][M]) {
    int x,y;
    inicializaMatriz(aux,'0');
    for(int i=0;i<N*M;i++) {
        if (buscaInicio(x,y,palabra[letra],aux)) {
            if (existePalabra(palabra,x,y,letra,aux)==1)
                return 1;
        }else {
            return 0;
        }
    }
    return 0;
}

int main() {
    char aux[N][M];
    string palabras[3];
    palabras[0] = "ABCCED";
    palabras[1] = "SEE";
    palabras[2] = "ABCB";

    for (int i = 0; i < 3; i++) {
        if (existe(palabras[i],0, aux))
            cout << palabras[i] << "=> TRUE"<<endl;
        else
            cout << palabras[i] << "=> FALSE"<<endl;
    }
    return 0;
}