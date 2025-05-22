/* 
 * File:   funcionesPila.cpp
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 03:41 PM
 */

#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

using namespace std;

/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(const struct Pila  & pila){
    return longitud(pila.lista);
}

/* push, añade un elemento a la parte superior de la pila */
void apilar(struct Pila & pila, int elemento){
    insertarAlInicio(pila.lista, elemento);
    cout<<"Apilando: "<<elemento<<endl;
}

/* pop, elimina un elemento de la parte superior de la pila*/
int desapilar(struct Pila & pila){
    
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	return -1; //O cualquier otro valor que no se encuentre en la pila
    }	
    else{
        int elemento = cima(pila);
        eliminaCabeza(pila.lista);
        return elemento;
    }
}

/*examina un elemento situado en la parte superior de la pila*/
int cima(const struct Pila & pila){
    
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
        return -1; //O cualquier otro valor que no se encuentre en la pila
    }		
    return retornaCabeza(pila.lista);
}


/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    if(esPilaVacia(pila)){
        cout<<"La pila está vacía no se puede mostrar"<<endl;
    }
    else
        imprime(pila.lista);
}

///*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}

