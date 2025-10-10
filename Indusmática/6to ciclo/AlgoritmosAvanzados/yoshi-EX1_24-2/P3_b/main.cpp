#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Tarea {
    char id;
    int horaMaxima;
    int ganancia;
};

bool compara(Tarea t1, Tarea t2) {
    return t1.ganancia > t2.ganancia;
}

int main() {
    // vector<Tarea> tareas = {
    // {'A',2,100},
    //     {'B',1,19},
    //     {'C',2,27},
    //     {'D',1,25},
    //     {'E',3,15}
    // };
    vector<Tarea> tareas = {
    {'A',4,20},
        {'B',1,10},
        {'C',2,40},
        {'D',2,30}
    };
    vector<char> solu;
    int n;
    int tiempo = 0;
    int ganancia = 0;
    sort(tareas.begin(), tareas.end(), compara);
    bool alguienEntro;
    while (true) {
        n = tareas.size();
        for (int i = 0; i < n; i++) {
            if (tareas[i].horaMaxima >= tiempo) {
                solu.push_back(tareas[i].id);
                ganancia+= tareas[i].ganancia;
                tareas.erase(tareas.begin() + i);
                alguienEntro = true;
                break;
            }

        }
        tiempo++;
        if (!alguienEntro) break;
        alguienEntro = false;
    }

    cout << "Solucion: {";
    for (int i = 0; i < solu.size(); i++) {
        cout << " " << solu[i];
    }
    cout << " }" << endl;
    cout << "Ganancia: " << ganancia << endl;

    return 0;
}