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

struct Resultado {
    int ganancia;
    vector<int> proyectos;
};

bool operator < (const Proyecto& p1, const Proyecto& p2) {
    return (double)(p1.ganancia*p1.beneficio)/p1.costo > (double)(p2.ganancia*p2.beneficio)/p2.costo;
}

int validarPredecesores(vector<int>pred,vector<int>selec) {
    if (pred.empty()) return 1;
    int cont=0;
    for (int i=0;i<pred.size();i++) {
        for (int j=0;j<selec.size();j++) {
            if (pred[i]==selec[j])
                cont++;
        }
    }
    if (cont==pred.size())return 1;
    else return 0;
}

Resultado seleccionarProyectos(vector<Proyecto>proy,int presupuesto,int n) {
    Resultado resultado;
    resultado.ganancia=0;
    sort(proy.begin(),proy.end());
    int i=0;
    while (!proy.empty() and i<n and presupuesto>0) {
        if (presupuesto-proy[i].costo>=0 and validarPredecesores(proy[i].predecesores,resultado.proyectos)) {
            resultado.proyectos.push_back(proy[i].id);
            resultado.ganancia += proy[i].ganancia;
            presupuesto-=proy[i].costo;
            proy.erase(proy.begin()+i);
            i=0;
        }else {
            i++;
        }
    }
    return resultado;
}

int main() {
    vector<Proyecto> proyectos{
        {1,80,150,2,{}},
        {2,20,80,5,{4}},
        {3,100,300,1,{1,2}},
        {4,100,150,4,{}},
        {5,50,80,2,{}},
        {6,10,50,1,{2}},
        {7,50,120,2,{6}},
        {8,50,150,4,{6}},
    };

    int n =proyectos.size();
    int presupuesto=250;

    Resultado resultado = seleccionarProyectos(proyectos,presupuesto,n);

    cout<<"Ganancia: "<<resultado.ganancia<<endl;
    cout<<"Proyectos: ";
    for (int i=0;i<resultado.proyectos.size();i++) {
        cout<<resultado.proyectos[i]<<" ";
    }
    cout<<endl;
    return 0;
}