#include <iostream>
#include <climits>
using namespace std;

int calcGanancia(int*meses,int n,int k) {
    int dp[k+1][n]{};
    for(int i=1;i<=k;i++) {
        for(int j=1;j<n;j++) {
            int maximo=INT_MIN;
            for(int k=0;k<j;k++) {
                maximo=max(maximo,meses[j]-meses[k]+dp[i-1][k]);
                maximo=max(maximo,dp[i][j-1]);
            }
            dp[i][j]=maximo;
        }
    }
    for (int i=0;i<=k;i++) {
        for (int j=0;j<n;j++) {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[k][n-1];
}

int main() {
    int n=8;
    // int k=1;
    int k=2;
    int meses[]{120,100,150,125,120,150,200,250};
    int ganancia = calcGanancia(meses,n,k);
    cout<<"La ganancia maxima sera "<<ganancia<<" soles"<<endl;
    return 0;
}