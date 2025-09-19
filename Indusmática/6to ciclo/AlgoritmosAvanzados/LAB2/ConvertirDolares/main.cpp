#include <cmath>
#include <iostream>
#include<iomanip>
#include<climits>

using namespace std;

int maxGanancia(int *precios, int n, int k) {
    int dp[k + 1][n];

    for (int i = 0; i <= k; i++)
        dp[i][0] = 0;


    for (int i = 0; i < n; i++)
        dp[0][i] = 0;


    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int maximo = INT_MIN;
            for (int m = 0; m < j; m++) {
                maximo = max(maximo, precios[j] - precios[m] + dp[i - 1][m]);
                dp[i][j] = max(maximo, dp[i][j - 1]);
            }
        }
    }

    cout << endl;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << dp[i][j];
        cout << endl;
    }
    cout << endl;

    return dp[k][n - 1];
}

int main() {
    int k = 3;
    int precios[] = {315, 322, 385, 375, 365, 380, 390, 375, 400};
    int n = sizeof(precios) / sizeof(precios[0]);

    cout << "La ganancia es " << maxGanancia(precios, n, k) << endl;


    return 0;
}
