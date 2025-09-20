#include <iostream>
#define M 6
#define W 26
using namespace std;

int calcularFactible(int (*dp)[W], int peso_ind, int *pesos, int m) {
    if (m <= 0) return 0;
    int k=0;
    for (int i = 0; i <= m; i++) {
        if (dp[i][peso_ind] == 1) {
            k=i;
            break;
        }
    }
    return 1 + calcularFactible(dp, peso_ind - pesos[k- 1], pesos, k - 1);
}

void mochilon(int *pesos, int m, int w) {
    int dp[M][W]{};

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= w; j++) {
            if (j - pesos[i - 1] >= 0 and dp[i - 1][j] != 1) {
                dp[i][j] = dp[i - 1][j - pesos[i - 1]];
            } else dp[i][j] = dp[i - 1][j];
        }
    }


    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= w; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int pesoInd, cant;
    for (int i = w; i >= 0; i--) {
        if (dp[m][i]) {
            pesoInd = i;
            cant = calcularFactible(dp, pesoInd, pesos, m);
            if (cant <= m) {
                cout << i << "  "<<cant;
                break;
            }
        }
    }
}

int main() {
    int pesos[] = {7, 2, 5, 5, 10};
    int m = sizeof(pesos) / sizeof(pesos[0]);
    int w = 25;

    mochilon(pesos, M-1, W-1);


    return 0;
}
