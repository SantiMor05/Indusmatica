#include <iostream>
#include <vector>
#include <algorithm>

#define N 8
using namespace std;

struct Proyecto {
    int id;
    int costo;
    int ganancia;
    int beneficio;
    vector<int> predecesores;
};


bool compara(const Proyecto &p1,const Proyecto &p2) {
    return (double)(p1.beneficio * p1.ganancia) / p1.costo > (double)(p2.beneficio * p2.ganancia) / p2.costo;
}

struct Solucion {
    vector<int> proyectos;
    int ganancia{};
    int presupuesto{};
};


bool verificarPredecesor(const vector<int> & sol, const Proyecto & proyecto) {
    if (proyecto.predecesores.empty())return true;
    int cont=0;
    for (int predecesore : proyecto.predecesores) {
        for (auto p : sol) {
            if (p==predecesore) cont++;
        }
    }
    if (cont == proyecto.predecesores.size()) return true;
    return false;
}

void algoritmoVoraz(Proyecto *proyectos, int n, int presupuesto) {
    sort(proyectos, proyectos + n, compara);

    vector<Proyecto> cart;
    cart.insert(cart.begin(), proyectos, proyectos + n);
    Solucion solucion;
    solucion.ganancia = 0;
    solucion.presupuesto = presupuesto;

    for (int j = 0; j < n; j++) {
        if (cart[j].costo <= solucion.presupuesto and !cart.empty()) {
            if (verificarPredecesor(solucion.proyectos,cart[j])) {
                solucion.ganancia += cart[j].ganancia;
                solucion.presupuesto -= cart[j].costo;
                solucion.proyectos.push_back(cart[j].id);
                cart.erase(cart.begin()+j);
                j=-1;
            }
        }
    }
    for (int i=0;i<n;i++) {
        cout << proyectos[i].id << " ";
    }
    cout << endl;
    cout << solucion.ganancia << endl;
    for (int proyecto : solucion.proyectos) {
        cout << proyecto << " ";
    }
}

int main() {
    Proyecto proyectos[] = {
        {1, 80, 150, 2,{}},
        {2, 20, 80, 5, {4}},
        {3, 100, 300, 1, {1, 2}},
        {4, 100, 150, 4, {}},
        {5, 50, 80, 2, {}},
        {6, 10, 50, 1, {2}},
        {7, 50, 120, 2, {6}},
        {8, 50, 150, 4, {6}}
    };
    int presupuesto = 250;
    algoritmoVoraz(proyectos,N, presupuesto);

    return 0;
}
