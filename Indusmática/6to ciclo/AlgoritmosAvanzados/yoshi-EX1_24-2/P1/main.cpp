#include <iostream>
using namespace std;

void obtenerMayor(int* meses,int n, int m) {
    int solu[n][m]{};

    for (int i = 1; i < n; i++) {
        for (int j = 2; j < m; j++) {
            int maximo=-1;
            for(int k=1;k<j;k++) {
                int nuevo=meses[j]-meses[k]+solu[i-1][k-1];
                maximo=max(maximo,nuevo);
            }
            solu[i][j]=max(maximo,solu[i][j-1]);
        }
    }
    cout << "Ganacia maxima: " << solu[n-1][m-1] << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << solu[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int meses[] = {120,100,150,125,120,150,200,250};
    int m = sizeof(meses)/sizeof(meses[0]);
    int numCompras = 2;
    obtenerMayor(meses,numCompras+1,m);

    return 0;
}