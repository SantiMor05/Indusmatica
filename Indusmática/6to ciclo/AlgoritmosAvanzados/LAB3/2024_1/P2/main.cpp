#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 5

struct paquete {
    int peso;
    int ganancia;
};

bool operator<(paquete p1, paquete p2) {
    return (double)p1.ganancia/p1.peso > (double)p2.ganancia/p2.peso;
}

void cargaContenedor(paquete*paq,int &result,int &sobrante,int n,int peso) {
    sort(paq,paq+n);
    result=0;
    sobrante=peso;

    for (int i=0;i<n;i++) {
        if (sobrante-paq[i].peso>=0) {
            result+=paq[i].ganancia;
            sobrante-=paq[i].peso;
        }
    }
}

int main() {
    paquete paq[]{{2,10},{3,15},{4,10},{12,24},{2,8}};
    int n = sizeof(paq) / sizeof(paq[0]);
    int peso = 16;
    int result,sobrante;
    cargaContenedor(paq,result,sobrante,n,peso);

    cout<<result<<" "<<sobrante<<endl;
    return 0;
}