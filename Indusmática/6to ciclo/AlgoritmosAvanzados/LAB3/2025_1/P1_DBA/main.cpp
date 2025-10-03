#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Contenedor {
    int id;
    int velocidad;
};

struct Respuesta {
    int disco;
    vector<int> tablas;
};

bool operator<(const Contenedor& c1, const Contenedor& c2) {
    return c1.velocidad > c2.velocidad;
}

void seleccionarTablas(vector<Contenedor>tablas,vector<Contenedor>discos,int nT,Respuesta*res) {
    sort(tablas.begin(),tablas.end());
    cout<<endl;
    int j=0;
    while (j<nT) {
        if (discos[0].velocidad-tablas[j].velocidad>=0) {
            res[discos[0].id-1].disco = discos[0].id;
            res[discos[0].id-1].tablas.push_back(tablas[j].id);
            discos[0].velocidad-=tablas[j].velocidad;
            sort(discos.begin(),discos.end());
            j++;
        }
    }
}

int main() {
    vector<Contenedor> tablas{
        {1,150},
        {2,100},
        {3,180},
        {4,50},
        {5,120},
        {6,10},
    };
    vector<Contenedor> discos{
        {1,250},
        {2,200},
        {3,200},
        {4,100}
    };

    Respuesta respuesta[discos.size()];
    seleccionarTablas(tablas,discos,tablas.size(),respuesta);
    for (int i=0;i<discos.size();i++) {
        cout<<"Disco: "<<respuesta[i].disco<<endl<<"Tablas: ";
        for (int j=0;j<respuesta[i].tablas.size();j++)
            cout<<respuesta[i].tablas[j]<<" ";
        cout<<endl;
    }
    return 0;
}