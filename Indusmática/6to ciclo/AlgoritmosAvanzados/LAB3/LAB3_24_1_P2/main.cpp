#include <iostream>
#include<algorithm>


using namespace std;


struct paquete {
    int ganancia;
    int peso;
};

struct solucion {
    int ganancia;
    int residual;
};

bool compara(const paquete &a, const paquete &b) {
    return (double) a.ganancia / a.peso > (double) b.ganancia / b.peso;
}

solucion cargaContenedor(paquete *paq, int cap, int n) {
    solucion sol;
    sort(paq, paq + n, compara);
    sol.ganancia = 0;
    sol.residual = cap;

    for (int i = 0; i < n; i++) {
        if (sol.residual - paq[i].peso >= 0) {
            sol.ganancia += paq[i].ganancia;
            sol.residual -= paq[i].peso;
        }
    }

    return sol;
}

int main() {
    paquete paq[] = {
        {10, 2}, {15, 3},
        {10, 5}, {24, 12}, {8, 2}
    };

    int cap = 16;
    int n = sizeof(paq) / sizeof(paq[0]);

    solucion sol = cargaContenedor(paq, cap, n);

    cout << "Ganancia: " << sol.ganancia << endl;
    cout << "Peso sobrante: " << sol.residual << endl;
    return 0;
}
