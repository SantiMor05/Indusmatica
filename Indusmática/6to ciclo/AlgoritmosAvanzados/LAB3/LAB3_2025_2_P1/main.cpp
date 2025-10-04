#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


struct Pais {
    int id;
    string nombre;
    int color;
    vector<int> listaIdPaisesLimite;

};

struct Solucion {
    int numColor;
    vector<int> listaIdPaises;
    vector<string> listaNombresPaises;

};

bool comparaPaises(Pais a, Pais b) {

    return (a.listaIdPaisesLimite.size() > b.listaIdPaisesLimite.size()
        or (a.listaIdPaisesLimite.size() == b.listaIdPaisesLimite.size()
        and a.nombre.compare(b.nombre) < 0));
}

bool verificaFronteras(Pais pais, Solucion solucion) {

    for (int i=0; i<pais.listaIdPaisesLimite.size(); i++) { //si comparte límite con la solucion no se pinta
        for (int j=0; j<solucion.listaIdPaises.size(); j++) {
            if (pais.listaIdPaisesLimite.at(i) == solucion.listaIdPaises.at(j)) {
                return false;
            }
        }
    }
    return true;

}


void colorearMapa(Pais *structPaises, int cantPaises) {

    vector<Pais> paises;
    paises.insert(paises.begin(), structPaises, structPaises + cantPaises);

    vector<Solucion> soluciones;
    soluciones.clear();


    while (paises.size() > 0) { //hasta ingregsar todos los paises
        sort(paises.begin(), paises.end(), comparaPaises);

        //se inserta el pais con más límites como primero en la solucion
        int n=soluciones.size();
        Solucion siguienteSolu = {n+1, {}, {}};
        soluciones.push_back(siguienteSolu);
        soluciones.at(soluciones.size()-1).listaIdPaises.push_back(paises.at(0).id);
        soluciones.at(soluciones.size()-1).listaNombresPaises.push_back(paises.at(0).nombre);

        //se ingresan todos los paises posibles a la solucion
        for (int i=1; i<paises.size(); i++) {

            if (verificaFronteras(paises.at(i), soluciones.at(soluciones.size()-1))) {
                soluciones.at(soluciones.size()-1).listaIdPaises.push_back(paises.at(i).id);
                soluciones.at(soluciones.size()-1).listaNombresPaises.push_back(paises.at(i).nombre);

                paises.erase(paises.begin()+i); //se borran si ya se pintaron
                i--; //lo entregué sin esta línea y me salían 5 soluciones DX
            }
        }

        paises.erase(paises.begin() + 0); //el + 0 es solo para entenderme XD
    }

    cout<<"Cantidad de colores: "<<soluciones.size()<<endl;
    for (int i=0; i<soluciones.size(); i++) {
        cout << "Color "<<soluciones.at(i).numColor<<": ";
        for (int j=0; j<soluciones.at(i).listaIdPaises.size(); j++) {
            cout << soluciones.at(i).listaNombresPaises.at(j)<<", ";
        }
        cout << endl;
    }



}


int main() {
    Pais paises[] = { {1, "Argentina",0, {4,2,8,3,11}},
                        {2, "Bolivia",0, {9,3,8,1,4}},
                        {3, "Brasil", 0,{11,1,8,2,9,5,12,7,10}},
                        {4, "Chile",0, {9,2,1}},
                        {5, "Colombia",0, {12,3,9,6}},
                        {6, "Ecuador",0, {5,9}},
                        {7, "Guyana",0, {12,3,10}},
                        {8, "Paraguay",0, {2,3,1}},
                        {9, "Peru",0, {6,5,3,2,4}},
                        {10, "Surinam", 0, {7,3}},
                        {11, "Uruguay", 0, {3,1}},
                        {12, "Venezuela",0, {5,3,7}},
    };
    int cantPaises = sizeof(paises)/sizeof(paises[0]);

    colorearMapa(paises, cantPaises);

    return 0;
}



// for (int i=0; i<paises.size(); i++) {
//     cout<<paises.at(i).id<<" "<<paises.at(i).nombre<<" ";
//     for (int j=0; j<paises.at(i).listaIdPaisesLimite.size(); j++) {
//         cout<<paises.at(i).listaIdPaisesLimite.at(j)<<" ";
//     }
//     cout<<endl;
// }


// bool verificaFronteras(Pais pais, Solucion solucion) {
//
//     for (int i=0; i<pais.listaIdPaisesLimite.size(); i++) { //si comparte límite con la solucion no se pinta
//         for (int j=0; j<solucion.listaIdPaises.size(); j++) {
//             if (pais.listaIdPaisesLimite.at(i) == solucion.listaIdPaises.at(j)) {
//                 return false;
//             }
//         }
//     }
//     return true;
//
// }


