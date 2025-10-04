#include <algorithm>
#include <iostream>
#include <vector>
#define P 5
using namespace std;

struct nodo {
    int ganancia;
    int peso;
};

struct sol {
    int ganancia;
    int residual;
};

bool compara(nodo a,nodo b) {
    return (double)a.ganancia/a.peso > (double)b.ganancia/b.peso;
}

void calcularPaquete(int * gan, int * pesos,int peso) {
    vector<nodo> paquetes;
    for(int i = 0; i < P; i++) {
        nodo node;
        node.ganancia=gan[i];
        node.peso=pesos[i];
        paquetes.push_back(node);
    }
    sort(paquetes.begin(), paquetes.end(),compara);

    sol solucion;
    solucion.ganancia=0;
    solucion.residual=peso;
    // for (auto n: paquetes) {
    //     cout << n.ganancia << " " << n.peso << endl;
    // }

    for (auto n: paquetes) {
        if (n.peso <= solucion.residual) {
            solucion.ganancia+=n.ganancia;
            solucion.residual-=n.peso;
        }
    }

    cout << "Ganancia: " << solucion.ganancia << endl;
    cout << "Residual: " << solucion.residual << endl;
}

int main() {
    int ganacia[P]={10,15,10,24,8};
    int pesos[P]={2,3,5,12,2};

    calcularPaquete(ganacia,pesos,16);

    return 0;
}
