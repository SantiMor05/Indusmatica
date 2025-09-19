#include <iostream>
using namespace std;

int subconjunto(int*paq,int n,int peso,int*conforman) {
    int dp[n+1][peso+1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= peso; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= peso; j++) {
            dp[i][j]=dp[i-1][j];
            if (j-paq[i-1] >= 0 and dp[i-1][j-paq[i-1]]!=0) {
                    dp[i][j]++;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= peso; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int indicePeso=peso, cant=0;
    for (int i=0;i<=n;i++) {
        if (dp[i][indicePeso]==1) {
            conforman[cant]=paq[i-1];
            cant++;
            indicePeso-=paq[i-1];
            i=0;
        }
        if (indicePeso<=0)break;
    }
    return dp[n][peso];
}

void ordenar(int*paq,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (paq[i]>paq[j]) {
                int temp = paq[i];
                paq[i] = paq[j];
                paq[j] = temp;
            }
        }
    }
}

int main() {
    int paq[]={2,3,5,10,6,4};
    int n=sizeof(paq)/sizeof(paq[0]);
    ordenar(paq,n);
    for (int i = 0; i < n; i++)
        cout << paq[i] << " ";
    cout << endl<<endl;

    int conforman[n]{}, peso=8;
    if (subconjunto(paq, n, peso,conforman)!=0){
        cout<<"SE PUEDE"<<endl<<"PESO "<<peso<<" CONFORMADO POR: ";
        for(int i=0;i<n;i++)
            if(conforman[i]!=0)
                cout<<conforman[i]<<" ";
        cout<<endl;
    }
    return 0;
}