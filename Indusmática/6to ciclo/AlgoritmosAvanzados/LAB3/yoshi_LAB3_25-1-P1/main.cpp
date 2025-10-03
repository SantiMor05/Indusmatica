#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

struct Componente {
    int id;
    int velocidad;
};

bool compara(Componente a, Componente b) {
    return a.velocidad > b.velocidad;
}

int main() {
    Componente arrTablas[] = {1,150,2,100,3,180,4,50,5,120,6,10};
    Componente arrDiscos[] = {1,250,2,200,3,200,4,100};
    int m = sizeof(arrTablas)/sizeof(Componente);
    int n = sizeof(arrDiscos)/sizeof(Componente);
    vector<int>  solu[n];

    sort(arrTablas,arrTablas+m,compara);

    for(int i=0;i<m;i++) {
        sort(arrDiscos,arrDiscos+n,compara);
        if (arrDiscos[0].velocidad - arrTablas[i].velocidad >= 0) {
            solu[arrDiscos[0].id-1].push_back(arrTablas[i].id);
            arrDiscos[0].velocidad -= arrTablas[i].velocidad;
        }
    }

    for(int i=0;i<n;i++) {
        cout << "Disco " << i+1 << ": {";
        for(int j=0;j<solu[i].size();j++) {
            cout << solu[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}