#include <iostream>
using namespace std;

int hallarMejorOpcion(int*pesos,int*valores,int n,int w) {
    int solus[n][w]{};

    for(int j=1;j<w;j++) {
        for(int i=1;i<n;i++) {
            int quedaPeso=j-pesos[i];
            if (quedaPeso>=0) {
                int nuevo=valores[i]+solus[i-1][quedaPeso];
                solus[i][j]=max(solus[i-1][j],nuevo);
            }
            else {
                solus[i][j]=solus[i-1][j];
            }
        }
    }
    return solus[n-1][w-1];
}

int main() {
    int pesos[]{0,2,1,3,2};
    int valores[]{0,12,10,20,15};
    int n=sizeof(pesos)/sizeof(pesos[0]);
    int w=6;
    cout << "La mejor opcion es: "<< hallarMejorOpcion(pesos,valores,n,w) << endl;

    return 0;
}