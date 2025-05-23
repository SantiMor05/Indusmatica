/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * 
 * Created on 5 de mayo de 2025, 10:55
 */

#include <iostream>
#include <iomanip>
#include "Elemento.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

using namespace std;

/*constructor de Cola*/
void construir(struct Cola & cola){
    construir(cola.lista); //se inicializa el puntero cola
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, const struct Elemento & elemento){
    //cout <<"Encolando... " <<elemento.numero << endl;
    insertarAlFinal(cola.lista, elemento); // se utiliza el puntero cola
}

struct Elemento desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    struct Elemento elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

void imprimir(const struct Cola & cola){
    imprimir(cola.lista);
}

void imprimeCola(Cola &cola){
    
    int n = cola.lista.longitud;
    Elemento elemento;
     
    cout << "Avion" << setw(20) << "Hora de llegada" << setw(24) <<
            "Nueva hora de llegada" << endl;
    
    for(int  i = 0; i < n; i++){
        elemento = desencolar(cola);
        cout << elemento.numero << setw(12) << elemento.horaLlegada / 100 <<
                ":" << elemento.horaLlegada % 100 << setw(18) << 
                elemento.nuevaHora / 100 << ":" << elemento.nuevaHora % 100 <<
                endl;
        encolar(cola,elemento);
    }
    
}