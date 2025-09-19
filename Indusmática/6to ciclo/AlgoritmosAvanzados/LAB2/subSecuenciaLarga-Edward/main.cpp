#include <iostream>
using namespace std;

int hallarSubsecuenciaCreci(int*arr,int n) {

    int solus[n]{},mayor=INT_MIN;
    for(int i=1;i<n;i++) {
        if (arr[i]>mayor) {
            solus[i]=solus[i-1]+1;
            mayor=arr[i];
        }
        else {
            int cant=0,ant=INT_MIN;
            for(int j=1;j<i;j++) {
                if (arr[j]<arr[i] and arr[j]>ant) {
                    cant++;
                    ant=arr[j];
                }
            }
            if (cant>solus[i-1]) {
                solus[i]=cant;
                mayor=cant;
            }
            else solus[i]=solus[i-1];
        }
        cout<<solus[i]<<" ";
    }
    cout<<endl;
    return solus[n-1];
}

int main() {
    int arr[]{0,10,22,9,33,21,50,41,60};
    //int arr[]{0,-7,10,9,2,3,8,8,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Cantidad de subsecuencia mas larga: "<<hallarSubsecuenciaCreci(arr,n)<<endl;

    return 0;
}