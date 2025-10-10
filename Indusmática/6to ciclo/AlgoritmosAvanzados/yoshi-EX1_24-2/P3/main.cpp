#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> conjuntoUniversal = {1,2,3,4,5,6,7};
int m = conjuntoUniversal.size();
vector<int> copiaUniversal = {1,2,3,4,5,6,7};
vector<vector<int>> solu;


int cantElementosFaltantes(vector<int>subconjunto) {
    if (solu.empty()) return subconjunto.size();
    int elementosFaltantes = 0;
    for (int i = 0; i < subconjunto.size(); i++) {
        elementosFaltantes++;
        if (copiaUniversal[subconjunto[i]-1] == 0) elementosFaltantes--;
    }
    return elementosFaltantes;
}

bool compara(vector<int>a, vector<int>b) {
    return cantElementosFaltantes(a) > cantElementosFaltantes(b);
}

void marcarEnCopia(vector<int>subconjunto) {
    for (int i = 0; i < subconjunto.size(); i++) {
        copiaUniversal[subconjunto[i]-1] = 0;
    }
}

bool estamosTodos() {
    for (int i = 0; i < m; i++)
        if (copiaUniversal[i] != 0) return false;
    return true;
}

int main() {


    vector<vector<int>>subconjuntos = {{1,2,3},{2,4,5},{3,5,6},{6,7}};
    int n = subconjuntos.size();

    for (int i = 0; i < n; i++) {
        if (estamosTodos()) break;
        sort(subconjuntos.begin(), subconjuntos.end(), compara);
        solu.push_back(subconjuntos[0]);
        marcarEnCopia(subconjuntos[0]);
        subconjuntos.erase(subconjuntos.begin());
    }

    cout << "Solucion: " << endl;
    for (int i = 0; i < solu.size(); i++) {
        cout << "{";
        for (int j = 0; j < solu[i].size(); j++) {
            cout << solu[i][j] << " ";
        }
        cout << "}" << endl;
    }



    return 0;
}