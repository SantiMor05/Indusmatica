#include <iostream>
using namespace std;
#define N 6// T

int max(int a, int b) {
    return (a > b) ? a : b;
}

int FabricioFloresValcarcel(int matriz[][N],int *Wpaq,int *Vpaq,int n, int pesoMax) {
    for(int i=1;i<=pesoMax;i++) {
        for(int j=1;j<n;j++) {
            if (Wpaq[j] > i) matriz[j][i] = matriz[j-1][i];
            else {
                int x = matriz[j-1][i-Wpaq[j]];
                matriz[j][i] = max(x+Vpaq[j],matriz[j-1][i]);
            }
        }
    }
    return matriz[n-1][pesoMax];
}

int coinrow(int* monedas,int m) {
    int F[m+1], max, aux;
    F[0] = 0;
    F[1] = monedas[0];
    for(int i=2;i<m+1;i++) {
        max = F[i-1];
        aux = monedas[i-1] + F[i-2];
        if (aux > max)
            max = aux;
        F[i] = max;
    }
    return F[m];
}

int main() {

    int monedas[] = {5, 1, 2, 10, 6, 2};
    int m = sizeof(monedas)/sizeof(monedas[0]);
    cout << "La subsecuencia creciente mas larga es: " << coinrow(monedas,m) << endl ;

    int Wpaq[] = {0,2,1,3,2};
    int Vpaq[] = {0,12,10,20,15};
    int pesoMax = 5;
    int n = sizeof(Wpaq)/sizeof(Wpaq[0]);
    int matriz[n][6] = {0};
    cout << "La mayor ganancia es: " << FabricioFloresValcarcel(matriz,Wpaq,Vpaq,n,pesoMax) << endl;

    return 0;// TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}




























