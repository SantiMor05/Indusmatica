#include <iostream>

using namespace std;

void cortes(int * precio, int n) {
    int dp[n]{};

    for (int i = 1; i <= n; i++) {
        int maximo=INT_MIN;
        for (int j = 1; j <= i; j++) {
            maximo=max(precio[j-1]+dp[i-j],maximo);
        }
        dp[i]=maximo;
    }

    for (int i = 0; i <= n; i++) {
        cout << dp[i] << " ";
    }
}

int main() {
    int precio[]={2,5,7,8};
    int n=sizeof(precio)/sizeof(precio[0]);

    cortes(precio,n);
    return 0;
}
