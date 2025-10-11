#include <iostream>
using namespace std;
#define LADOS 3

void ordenar(int*a,int*b,int*h,int*w,int n) {
    for (int i=0;i<n*LADOS-1;i++) {
        for (int j=i+1;j<n*LADOS;j++) {
            int  ta,tb,tw,th;
            if (b[j]>b[i]||b[j]==b[i] and a[j]>a[i]||(b[j]==b[i] and a[j]==a[i]) and w[j]>w[i]) {
                ta=a[i];tb=b[i];tw=w[i];th=h[i];
                a[i]=a[j];b[i]=b[j];w[i]=w[j];h[i]=h[j];
                a[j]=ta; b[j]=tb; w[j]=tw; h[j]=th;
            }
        }
    }
}

void rotaciones(int*l1,int*l2,int*l3,int*a,int*b,int*h,int*w,int n,int*peso) {
    int cont=0;
    for (int i=0;i<n;i++) {
        if (l1[i]<l2[i]) {
            a[cont]=l1[i];
            b[cont]=l2[i];
        }else {
            a[cont]=l2[i];
            b[cont]=l1[i];
        }
        h[cont]=l3[i];
        w[cont]=peso[i];
        cont++;

        if (l1[i]<l3[i]) {
            a[cont]=l1[i];
            b[cont]=l3[i];
        }else {
            a[cont]=l3[i];
            b[cont]=l1[i];
        }
        h[cont]=l2[i];
        w[cont]=peso[i];
        cont++;

        if (l2[i]<l3[i]) {
            a[cont]=l2[i];
            b[cont]=l3[i];
        }else {
            a[cont]=l3[i];
            b[cont]=l2[i];
        }
        h[cont]=l1[i];
        w[cont]=peso[i];
        cont++;
    }
    ordenar(a,b,h,w,n);
}

int calcAlturaMaxima(int*l1,int*l2,int*l3,int*peso,int lados,int n) {
    int dp[n*lados][n*lados]{};
    int a[n*lados],b[n*lados],h[n*lados],w[n*lados];
    rotaciones(l1,l2,l3,a,b,h,w,n,peso);
    int best = 0;
    for (int i = 0; i < n*lados; ++i) {
        dp[i][i] = h[i];                         // caso base: solo i
        for (int j = 0; j < i; ++j) {
            if (a[i] < a[j] && b[i] < b[j] && w[i] <= w[j]) {
                int cand = h[i] + dp[j][j];
                dp[i][j] = cand;                 // matriz de candidatos
                if (cand > dp[i][i]) dp[i][i] = cand;
            }
        }
        if (dp[i][i] > best) best = dp[i][i];
    }
    return best;
}

int main() {
    // int l1[]{1,2};
    // int l2[]{3,15};
    // int l3[]{4,6};

    // int l1[]{1,2};
    // int l2[]{3,15};
    // int l3[]{4,6};
    // int peso[]{2,10};

    int l1[]{4,1,3};
    int l2[]{6,1,4};
    int l3[]{7,3,2};
    int peso[]{10,5,4};
    int n=sizeof(l1)/sizeof(l1[0]);
    cout<<"La altura maxima es "<<calcAlturaMaxima(l1,l2,l3,peso,LADOS,n)<<endl;
    return 0;
}