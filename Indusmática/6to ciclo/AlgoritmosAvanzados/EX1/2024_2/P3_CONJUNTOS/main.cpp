#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct S {
    int id;
    vector<int>numeros;
};

vector<int> usados;
int cUsados=0;

int repetidos(vector<int> v) {
    int rep=0;
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<usados.size(); j++) {
            if (v[i]==usados[j]) {
                rep++;
                break;
            }
        }
    }
    return rep;
}

bool operator <(const S &a,const S &b) {
    return repetidos(a.numeros)<repetidos(b.numeros);
}

vector<int> slecConjunt(vector<int>U,vector<S>S,int nu,int ns) {
    vector<int> respuesta;
    for (int i=0;i<ns;i++) {
        if (usados.size()>=nu) {
            return respuesta;
        }
        for (int j=0;j<S[0].numeros.size();j++) {
            usados.push_back(S[0].numeros[j]);
        }
        respuesta.push_back(S[0].id);
        S.erase(S.begin());
        sort(S.begin(),S.end());
    }
}

int main() {
    vector<int> U{1,2,3,4,5,6,7};
    vector<S>S{
        {1,{1,2,3}},
        {2,{2,4,5}},
        {3,{3,5,6}},
        {4,{6,7}},
    };
    vector<int>rpta= slecConjunt(U,S,U.size(),S.size());
    cout<<"Al seleccionar los subconjuntos"<<endl;
    for (int i=0; i<rpta.size(); i++) {
        cout << rpta[i] << " ";
    }
    cout <<endl<< "Hemos cubierto a U"<<endl;
    return 0;
}
