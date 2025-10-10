#include <iostream>
using namespace std;

bool evaluarValido(char* cadena,int n) {
    int cantAbren = 0;
    int cantCierran = 0;
    int ContandoAbiertos = 1;
    for (int i = 0; i < n; i++) {
        if (ContandoAbiertos) {
            if (cadena[i] == '(')
                cantAbren++;
            else {
                cantCierran++;
                ContandoAbiertos = 0;
            }
        }else {
            if (cadena[i] == ')')
                cantCierran++;
            else {
                if (cantAbren!=cantCierran) return false;
                ContandoAbiertos = 1;
                cantAbren = 1;
                cantCierran = 0;
            }
        }
    }
    if (cantAbren != cantCierran) return false;
    return true;
}

void FormaCadenaParentesis(int i, int n, char* cadena) {
    if (i==n) return;
    for(int j=0; j<2; j++) {
        if (j==0)
            cadena[i] = '(';
        else
            cadena[i] = ')';
        if (i==n-1) {
            if (evaluarValido(cadena,n)) cout << cadena << endl;
        }
        FormaCadenaParentesis(i+1,n,cadena);
    }
}

int main() {
    int n = 4;
    char cadena[2*n];

    FormaCadenaParentesis(0,2*n,cadena);


    return 0;
}