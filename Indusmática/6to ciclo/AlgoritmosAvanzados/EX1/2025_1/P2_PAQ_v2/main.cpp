#include <algorithm>
#include <iostream>
using namespace std;
enum{A,B,H,W};

void ordenar(int paqMax[][4],int n) {
    for (int i=0;i<n*3-1;i++) {
        for (int j=i+1;j<n*3;j++) {
            int  ta,tb,tw,th;
            if (paqMax[j][B]>paqMax[i][B]||paqMax[j][B]==paqMax[i][B] and paqMax[j][A]>paqMax[i][A]||
                (paqMax[j][B]==paqMax[i][B] and paqMax[j][A]==paqMax[i][A]) and paqMax[j][W]>paqMax[i][W]) {
                ta=paqMax[i][A];tb=paqMax[i][B];tw=paqMax[i][W];th=paqMax[i][H];
                paqMax[i][A]=paqMax[j][A];paqMax[i][B]=paqMax[j][B];paqMax[i][W]=paqMax[j][W];paqMax[i][H]=paqMax[j][H];
                paqMax[j][A]=ta; paqMax[j][B]=tb; paqMax[j][W]=tw; paqMax[j][H]=th;
            }
        }
    }
}

void rotaciones(int paqMaxima[][4],int paq[][4],int n) {
    int cont=0;
    for (int i=0;i<n;i++) {
        if (paq[i][0]<paq[i][1]) {
            paqMaxima[cont][0]=paq[i][0];
            paqMaxima[cont][1]=paq[i][1];
        }else {
            paqMaxima[cont][0]=paq[i][1];
            paqMaxima[cont][1]=paq[i][0];
        }
        paqMaxima[cont][2]=paq[i][2];
        paqMaxima[cont][3]=paq[i][3];
        cont++;

        if (paq[i][0]<paq[i][2]) {
            paqMaxima[cont][0]=paq[i][0];
            paqMaxima[cont][1]=paq[i][2];
        }else {
            paqMaxima[cont][0]=paq[i][2];
            paqMaxima[cont][1]=paq[i][0];
        }
        paqMaxima[cont][2]=paq[i][1];
        paqMaxima[cont][3]=paq[i][3];
        cont++;

        if (paq[i][1]<paq[i][2]) {
            paqMaxima[cont][0]=paq[i][1];
            paqMaxima[cont][1]=paq[i][2];
        }else {
            paqMaxima[cont][0]=paq[i][2];
            paqMaxima[cont][1]=paq[i][1];
        }
        paqMaxima[cont][2]=paq[i][0];
        paqMaxima[cont][3]=paq[i][3];
        cont++;
    }
    ordenar(paqMaxima,n);
}

int calcAlturaMaxima(int paq[][4],int n) {
    //cant combinaciones n*3
    int paqMaxima[n*3][4];
    rotaciones(paqMaxima,paq,n);
    int dp[n*3][n*3]{};
    int best=0;
    for (int i = 0; i < n*3; ++i) {
        dp[i][i] = paqMaxima[i][H];                         // caso base: solo i
        for (int j = 0; j < i; ++j) {
            if (paqMaxima[i][A] < paqMaxima[j][A] && paqMaxima[i][B] < paqMaxima[j][B] && paqMaxima[i][W] <= paqMaxima[j][W]) {
                int cand = paqMaxima[i][H] + dp[j][j];
                dp[i][j] = cand;                 // matriz de candidatos
                if (cand > dp[i][i]) dp[i][i] = cand;
            }
        }
        if (dp[i][i] > best) best = dp[i][i];
    }

    return best;
}

int main() {
    // int paq[][4] {
        // {1,3,4,15},
        // {2,15,6,10}
    // };

    // int paq[][4] {
    // {1,3,4,2},
    // {2,15,6,10}
    // };

    int paq[][4] {
    {4,6,7,10},
    {1,1,3,5},
    {3,4,2,4}
    };

    int n=sizeof(paq)/sizeof(paq[0]);
    int altura=calcAlturaMaxima(paq,n);
    cout<<"La altura maxima es "<<altura<<endl;
    return 0;
}