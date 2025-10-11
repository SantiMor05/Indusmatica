#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tarea {
    char id;
    int horaMax;
    int ganancia;
};

struct Respuesta {
    vector<char> tarea;
    int ganancia;
};

bool operator <(const Tarea& t1, const Tarea& t2) {
    return t1.ganancia > t2.ganancia;
}

void borrarInvalidos(vector<Tarea>&ta,int hora) {
    for (int i=0;i<ta.size();i++) {
        if (ta[i].horaMax<=hora) {
            ta.erase(ta.begin()+i);
            i=0;
        }
    }
}

Respuesta selecTareas(vector<Tarea>ta,int n) {
    sort(ta.begin(),ta.end());
    Respuesta res;
    res.ganancia = 0;
    int i=1;
    while (i<=n and ta.size()>0){
        res.tarea.push_back(ta[0].id);
        res.ganancia+=ta[0].ganancia;
        ta.erase(ta.begin());
        borrarInvalidos(ta,i);
        i++;
    }
    return res;
}

int main() {
    vector<Tarea> tareas{
        // {'A',2,100},
        // {'B',1,19},
        // {'C',2,27},
        // {'D',1,25},
        // {'E',3,15}
        {'A',4,20},
        {'B',1,10},
        {'C',2,40},
        {'D',2,30},
    };
    Respuesta rpta=selecTareas(tareas,tareas.size());
    cout<<"Se consideran las tareas: ";
    for (int i=0;i<rpta.tarea.size();i++) {
        cout<<rpta.tarea[i]<<", ";
    }
    cout<<"Con una ganancia de: "<<rpta.ganancia<<endl;
    return 0;
}