#include <iostream>
using namespace std;
#define MAX 6
double matriz[6][6] {
    {0.00 ,2.24, 2.69, 4.00, 2.06, 3.35},
    {2.24, 0.00, 4.50, 5.39, 1.50, 5.59},
    {2.69, 4.50, 0.00, 5.59, 4.74, 2.55},
    {4.00, 5.39, 5.59, 0.00, 4.03, 3.91},
    {2.06, 1.50, 4.74, 4.03, 0.00, 5.10},
    {3.35, 5.59, 2.55, 3.91, 5.10, 0.00}
};

int visitados[MAX]{};
int respuesta[MAX]{};
int cantVisit = 0;

int pasoValido(int i) {
    for (int j = 0; j < MAX; j++) {
        if (visitados[j] == i)
            return 0;
    }
    return 1;
}

int calcRutas(int pos,int n,double &minimo,int &solus,double &dist) {
    if (cantVisit==n) {
        solus++;
        if (minimo>dist+matriz[pos][0]) {
            minimo = dist+matriz[pos][0];
            for (int j = 0; j < MAX; j++) {
                respuesta[j] = visitados[j];
            }
        }
        return 0;
    }
    for (int i=1;i<=n;i++) {
        if (pasoValido(i)) {
            visitados[cantVisit] = i;
            cantVisit++;
            dist += matriz[pos][i];
            if (calcRutas(i,n,minimo,solus,dist)) {
                return 1;
            }else {
                cantVisit--;
                visitados[cantVisit] = 0;
                dist -= matriz[pos][i];
                // i=1;
            }

        }
    }
    return 0;
}

int main() {
    double minimo=9999;
    int solus=0;
    double distancia;
    calcRutas(0,MAX-1,minimo,solus,distancia);
    cout <<"Número de rutas generadas: "<< solus << endl;
    cout<<"Ruta optima: 0 ";
    for (int i=0;i<MAX-1;i++) {
        cout<<respuesta[i]<<" ";
    }
    cout<<"(distancia "<<minimo<<")"<<endl;
    return 0;
}