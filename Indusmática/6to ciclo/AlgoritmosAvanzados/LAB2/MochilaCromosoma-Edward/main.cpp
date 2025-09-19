#include <iostream>
using namespace std;

void identificarPaquetes(int solus[][11],int n,int w,int*pesos,int pesoBuscado) {

    if (pesoBuscado==0)return;

    for(int i=0;i<n;i++) {
        if (solus[i][pesoBuscado]==1) {
            cout<<pesos[i]<<" ";
            identificarPaquetes(solus,n,w,pesos,pesoBuscado-pesos[i]);
            break;
        }
    }
}

void hallarPaquetes(int*pesos,int n,int w,int pesoBuscado) {
    int solus[4][11]{};

    for(int i=0;i<n;i++) {
        solus[i][0]=1;
    }

    for(int j=1;j<w;j++) {
        for(int i=1;i<n;i++) {
            if (solus[i-1][j]==1) {
                solus[i][j]=1;
                continue;
            }
            int quedaPeso=j-pesos[i];
            if (quedaPeso>=0) {
                solus[i][j]=solus[i-1][quedaPeso];
            }
            else {
                solus[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<w;j++) {
            cout<<solus[i][j]<<" ";
        }
        cout<<endl;
    }
    identificarPaquetes(solus,n,w,pesos,pesoBuscado);
}

int main() {

    int pesos[]{0,2,3,6};
    int n=sizeof(pesos)/sizeof(pesos[0]);
    int w=11,pesoBuscado=9;
    cout << "Los paquetes para llegar a 5 son: "<<endl;
    hallarPaquetes(pesos,n,w,pesoBuscado);

    return 0;
}