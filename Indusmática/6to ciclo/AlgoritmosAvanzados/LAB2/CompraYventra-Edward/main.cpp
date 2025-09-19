#include <iostream>
#include <climits>
#include <cmath>
using namespace std;


int hallarGananciaMax(int*valores,int m,int n) {

    int solus[n][m]{};

    for(int i=1;i<n;i++) {
        for(int j=2;j<m;j++) {
            int maximo=INT_MIN;
            for(int k=1;k<j;k++) {
                int nuevo=valores[j]-valores[k]+solus[i-1][k-1];
                maximo=max(maximo,nuevo);
            }
            solus[i][j]=max(maximo,solus[i][j-1]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<solus[i][j]<<" ";
        }
        cout<<endl;
    }
    return solus[n-1][m-1];
}

int main() {

    int arr[]{0,315,322,385,375,365,380,390,375,400};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n=4;
    cout<<"La ganancia maxima con "<<n-1<<" compras es: "<<endl<<hallarGananciaMax(arr,m,n)<<endl;

    return 0;
}