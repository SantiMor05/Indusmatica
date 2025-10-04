#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Proyecto {
    int id;
    int costo;
    int ganancia;
    int beneficio;
    vector<int> predecesores;
};

bool compara(Proyecto p1, Proyecto p2) {
    return (double)(p1.ganancia * p1.beneficio)/p1.costo>(double)(p2.ganancia * p2.beneficio)/p2.costo;
}

struct Solucion {
    int ganancia;
    vector<int> proyectos;
    int presupuestoRestante;
};


bool verificarRestriccion(const Solucion & sol,const vector<int> & predecesores) {
    if (predecesores.empty()) return true;

    for (int i=0;i<predecesores.size();i++) {
        bool encontro = false;
        for (int j=0;j<sol.proyectos.size();j++) {
            if (predecesores[i] == sol.proyectos[j]) {
                encontro = true;
            }
        }
        if (encontro == false) return false;
    }

    return true;

}

void calculoVoraz(vector<Proyecto> proyectos, int presupuesto) {
    sort(proyectos.begin(), proyectos.end(),compara);
    for(int i = 0; i < proyectos.size(); i++) {
        cout << proyectos[i].id << " ";
    }
    cout << endl;
    Solucion sol;
    sol.presupuestoRestante = presupuesto;
    sol.ganancia = 0;

    for(int i = 0; i < proyectos.size(); i++) {
        if (verificarRestriccion(sol,proyectos[i].predecesores)){
            if(sol.presupuestoRestante-proyectos[i].costo >= 0) {
                sol.ganancia += proyectos[i].ganancia;
                sol.proyectos.push_back(proyectos[i].id);
                sol.presupuestoRestante-=proyectos[i].costo;
                proyectos.erase(proyectos.begin()+i);
                i=-1;
            }

        }
    }

    for(int i = 0; i < sol.proyectos.size(); i++) {
        cout << sol.proyectos[i] << " ";
    }
    cout << endl;
    cout << sol.ganancia << endl;
}

int main() {
    vector<Proyecto> proyectos={
        {1,80,150,2,{}},
        {2,20,80,5,{4}},
        {3,100,300,1,{1,2}},
        {4,100,150,4,{}},
        {5,50,80,2,{}},
        {6,10,50,1,{2}},
        {7,50,120,2,{6}},
        {8,50,150,4,{6}}
    };

    int presupuesto=250;
    calculoVoraz(proyectos,presupuesto);

    return 0;
}
