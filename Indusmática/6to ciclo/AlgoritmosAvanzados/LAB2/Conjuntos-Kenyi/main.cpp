#include <iostream>

using namespace std;


void subconjunto(int *paq, int n, int pesos) {
    int dp[n + 1][pesos + 1]{};

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= pesos; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= pesos; j++) {
            if (j - paq[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - paq[i - 1]];
            else dp[i][j] = dp[i - 1][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= pesos; j++) {
    //         dp[i][j]=dp[i-1][j];
    //         if (j-paq[i-1] >= 0 and dp[i-1][j-paq[i-1]]!=0) {
    //             dp[i][j]++;
    //         }
    //     }
    // }

    int indicePeso=pesos, cant=0,conforman[n]{};
    for (int i=0;i<=n;i++) {
        if (dp[i][indicePeso]==1) {
            conforman[cant]=paq[i-1];
            cant++;
            indicePeso-=paq[i-1];
            i=0;
        }
        if (indicePeso<=0)break;
    }


    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= pesos; i++) {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
}

void ordenar(int *paq, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (paq[i] > paq[j]) {
                int t = paq[i];
                paq[i] = paq[j];
                paq[j] = t;
            }
        }
    }
}

int main() {
    int paq[] = {2,3,5};
    int pesos = 10;
    int n = sizeof(paq) / sizeof(paq[0]);
    ordenar(paq, n);
    for (int i = 0; i < n; i++)
        cout << paq[i] << " ";
    cout << endl << endl;
    subconjunto(paq, n, pesos);
    return 0;
}
