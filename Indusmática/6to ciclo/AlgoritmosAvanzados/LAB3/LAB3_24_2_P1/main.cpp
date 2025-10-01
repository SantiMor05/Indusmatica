#include <iostream>
#include<vector>
#include<algorithm>
//yoshi kbro
using namespace std;

//problema de predecesores

//restricción: presupuesto
//fórmula de criterio voraz: (ganancia*beneficio)/costo  -> maximizar ganancia y beneficio, minimizar costo
struct Proyecto {
    int id;
    int costo;
    int ganancia;
    int beneficio;
    vector<int> predecesores;
};

bool compara(Proyecto a, Proyecto b) {
    return (double) (a.ganancia * a.beneficio) / a.costo > (double) (b.ganancia * b.beneficio) / b.costo;
}

bool verifica(Proyecto proy, vector<int> solu) {
    if (proy.predecesores.size() == 0) return true;
    int cont = 0;
    for (int i = 0; i < proy.predecesores.size(); i++) {
        for (int j = 0; j < solu.size(); j++) {
            if (proy.predecesores[i] == solu[j]) cont++;
        }
    }
    if (cont == proy.predecesores.size()) return true;
    return false;
}

void seleccionaProyectos(Proyecto *cartera, int presupuesto, int n) {
    int i = 0, parcial = 0, ganancia = 0;
    vector<int> solu;
    vector<Proyecto> copia;
    sort(cartera, cartera + n, compara);

    copia.insert(copia.begin(), cartera, cartera + n);

    while (i < n and parcial < presupuesto and copia.size() > 0) {
        if (presupuesto >= parcial + copia[i].costo and verifica(copia[i], solu)) {
            parcial += copia[i].costo;
            solu.push_back(copia[i].id);
            ganancia += copia[i].ganancia;
            copia.erase(copia.begin() + i);
            i = 0;
        } else {
            i++;
        }
    }
    cout<<"Proyectos: ";
    for (int j = 0; j < solu.size(); j++) {
        cout << solu[j] << " ";
    }
    cout << endl <<"Ganancia: " <<ganancia;
}

int main() {
    Proyecto cartera[] = {
        {1, 80, 180, 2, {}},
        {2, 20, 80, 5, {4}},
        {3, 100, 300, 1, {1, 2}},
        {4, 100, 150, 4, {}},
        {5, 50, 80, 2, {}},
        {6, 10, 50, 1, {2}},
        {7, 50, 120, 2, {6}},
        {8, 50, 150, 4, {6}}
    };

    int presupuesto = 250;
    int n = sizeof(cartera) / sizeof(cartera[0]);

    seleccionaProyectos(cartera, presupuesto, n);
}
