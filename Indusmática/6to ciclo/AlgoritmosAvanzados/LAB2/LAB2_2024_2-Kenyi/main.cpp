#include <iostream>
#include <cmath>

using namespace std;



void aterrizajes(int * arr, int n) {
    int dp[n]{};
    for (int i = 1; i < n; i++) {
        int minimo = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (arr[j]+j>=i)
            minimo = min(minimo,dp[j]+1);
        }
        dp[i] = minimo;
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
}

int main() {
    int combustible[]={1, 2, 1, 4, 2, 3, 5, 2, 4, 2, 6};
    int n=sizeof(combustible)/sizeof(combustible[0]);

    aterrizajes(combustible,n);

    return 0;
}

