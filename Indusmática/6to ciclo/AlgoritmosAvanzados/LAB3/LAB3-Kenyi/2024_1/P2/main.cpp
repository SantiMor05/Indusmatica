#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Paquete {
    int id;
    int ganancia;
    int peso;
};

struct Solucion {
    int pesorestante;
    int ganancia;
};

bool compara(const Paquete &p1,const Paquete &p2) {
    return (double)p1.ganancia / p1.peso > (double)p2.ganancia / p2.peso;
}

void calculoVoraz(vector<Paquete>  &paq,int pesoTotal) {
    sort(paq.begin(), paq.end(),compara);
    for(int i=0;i<paq.size();i++) {
        cout<<paq[i].id<<" ";
        cout<<paq[i].ganancia<<" ";
        cout<<paq[i].peso<<" ";
        cout<<endl;
    }
    Solucion solucion;
    solucion.pesorestante = pesoTotal;
    solucion.ganancia = 0;
    for(int i=0;i<paq.size();i++) {
        if (solucion.pesorestante-paq[i].peso>=0) {
            solucion.ganancia += paq[i].ganancia;
            solucion.pesorestante -= paq[i].peso;
        }
    }

    cout<< "Peso sobreante en el contenedor: "<< solucion.pesorestante<<" Tn"<<endl;
    cout<< "Ganancia de la exportacion: "<< solucion.ganancia<<" en miles de dolares"<<endl;
}

int main() {
    vector<Paquete> paquetes = {
        {1,10,2},
        {2,15,3},
        {3,10,5},
        {4,14,12},
        {5,8,2},
        {6,5,5}
    };
    int pesoTotal = 20;
    calculoVoraz(paquetes,pesoTotal);

    return 0;
}
