#include <iostream>
using namespace std;

void tareasMaximo(int *tareas, int n, int tiempo) {
    int dp[n + 1][tiempo + 1]{};
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= tiempo; j++) {
            if (j - tareas[i - 1] >= 0 and dp[i - 1][j] != 1) {
                dp[i][j] = dp[i - 1][j - tareas[i - 1]];
            } else dp[i][j] = dp[i - 1][j];
        }
    }

    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= tiempo; i++) {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = tiempo; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i;
            break;
        }
    }
}

int main() {
    int tareas[] = {1, 3, 6, 10, 16};
    int n = sizeof(tareas) / sizeof(tareas[0]);
    int tiempo = 24;

    tareasMaximo(tareas, n, tiempo);

    return 0;
}
