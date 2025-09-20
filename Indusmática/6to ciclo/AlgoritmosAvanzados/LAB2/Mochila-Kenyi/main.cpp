#include <iostream>
#include <cmath>
using namespace std;


int mochila(int *pesos, int *valor, int cap, int n) {
    int dp[n + 1][cap + 1]{};

    //en mochila, la primera fila y columna son 0
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= cap; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            if (pesos[i - 1] <= j) {
                dp[i][j] = max(dp[i-1][j], valor[i - 1] + dp[i - 1][j - pesos[i - 1]]);
            } else
                dp[i][j] = dp[i-1][j];
        }
    }


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][cap];
}

int main() {
    int peso[] = {2, 1, 3, 2};
    int n = sizeof(peso) / sizeof(peso[0]);
    int valor[] = {12, 10, 20, 15};
    int capa = 5;

    mochila(peso, valor, capa, n);

    return 0;
}
