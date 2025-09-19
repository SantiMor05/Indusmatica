#include <iostream>
using namespace std;
#define N 8


int hallarSubsecuenciaCreci(int*arr,int n) {

    int solus[N+1]{},mayor=0;
    for(int i=1;i<n;i++) {
        if (arr[i]>mayor) {
            solus[i]=solus[i-1]+1;
            mayor=arr[i];
        }
        else solus[i]=solus[i-1];
    }
    return solus[n-1];
}

int main() {
    int arr[N+1]{0,10,22,9,33,21,50,41,60};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Cantidad de subsecuencia mas larga: "<<hallarSubsecuenciaCreci(arr,n)<<endl;

    return 0;
}