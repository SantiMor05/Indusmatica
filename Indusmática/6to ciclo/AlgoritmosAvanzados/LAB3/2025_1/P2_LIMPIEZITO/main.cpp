#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LAV 5

struct Orden {
    int id;
    int tipo;
    int peso;
};

struct Lavadora {
    int id;
    int peso;
    vector<int>ordenes ;
    double tiempo;
};

bool operator <(Lavadora&l1,Lavadora&l2) {
    if (l1.tiempo!=l2.tiempo) return l1.tiempo < l2.tiempo;
    return l1.id < l2.id;
}

void asignarOrdenes(vector<Orden>ord,vector<Lavadora>&lav,int nL) {
    int i=0;
    while (i<ord.size()) {

        int fact;
        if (ord[i].tipo==0)
            fact=10;
        else
            fact=20;

        lav[0].peso+=ord[i].peso;
        lav[0].ordenes.push_back(ord[i].id);
        lav[0].tiempo+=((double)ord[i].peso/5)*fact;
        sort(lav.begin(),lav.end());

        i++;
    }
}

int main() {
    vector<Orden> ordenes{
        {1,1,10},
        {2,1,10},
        {3,0,8},
        {4,1,15},
        {5,0,9},
        {6,0,11},
        {7,1,12},
        {8,0,15},
        {9,1,6},
        {10,0,10},
        {11,1,8},
        {12,0,15},
        {13,1,11},
        {14,1,7},
        {15,1,7},
        {16,0,8},
        {17,0,9},
        {18,1,11},
        {19,0,12},
        {20,1,15},
    };
    vector<Lavadora>lavadoras{
        {1,0,{},0},
        {2,0,{},0},
        {3,0,{},0},
        {4,0,{},0},
        {5,0,{},0},
    };
    asignarOrdenes(ordenes,lavadoras,LAV);

    for (int i=0;i<lavadoras.size();i++) {
        cout<<"Lavadora "<<lavadoras[i].id<<" :"<<endl;
        for (int j=0;j<lavadoras[i].ordenes.size();j++) {
            cout<<lavadoras[i].ordenes[j]<<" ";
        }
        cout<<endl<<"Tiempo: "<<lavadoras[i].tiempo<<endl<<endl;
    }
    return 0;
}