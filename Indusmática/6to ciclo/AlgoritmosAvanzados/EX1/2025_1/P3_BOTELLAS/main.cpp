#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Orden {
    int id;
    int cant;
};

struct Linea {
    int id;
    vector<Orden> ordenes;
    double tiempo;
};

bool operator<(const Linea& l1, const Linea& l2) {
    if (l1.tiempo==l2.tiempo) return l1.id < l2.id;
    else
        return l1.tiempo < l2.tiempo;
}

double tiempo(Orden ord) {
    return 6*ord.cant;
}

void seleccionarOrdenes(vector<Orden>ord,vector<Linea>&lin,int n,int m) {
    for (int i = 0; i < n; i++) {
        lin[0].ordenes.push_back(ord[i]);
        lin[0].tiempo+=tiempo(ord[i]);
        sort(lin.begin(),lin.end());
    }
}

int main() {
    vector<Orden> ordenes{
        {1,103},
        {2,58},
        {3,88},
        {4,126},
        {5,195},
        {6,90},
        {7,54},
        {8,195},
        {9,124},
        {10,113},
        {11,193},
        {12,55},
        {13,97},
        {14,97},
        {15,169},
        {16,50},
        {17,167},
        {18,74},
        {19,79},
        {20,109}
    };
    vector<Linea> lineas{
        {1,{},0},
        {2,{},0},
        {3,{},0},
        {4,{},0},
        {5,{},0},
    };
    cout.precision(1);
    cout<<fixed;
    seleccionarOrdenes(ordenes,lineas,ordenes.size(),lineas.size());
    for (int i=0;i<lineas.size();i++) {
        cout<<"Linea "<<lineas[i].id<<", ";
        for (int j=0;j<lineas[i].ordenes.size();j++) {
            cout<<"Orden"<<lineas[i].ordenes[j].id<<"("<<lineas[i].ordenes[j].cant<<"), ";
        }
        cout<<lineas[i].tiempo<<endl;
    }
    return 0;
}