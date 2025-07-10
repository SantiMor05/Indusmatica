/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: Lenovo
 * 
 * Created on 8 de julio de 2025, 05:27 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#include "Plato.h"
#include "funcionesABB.h"
#include "ArbolBB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesAB.h"
#include "ArbolB.h"
#include "NodoArbol.h"
#include "funcionesLista.h"
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

////////////////////////////////////////////////////////////////////////////////PREGUNTA 1
//////////////////////////////////////PREGUNTA 1 A

int encontrarInicioLote(int *arr, int ini, int fin, int cant){
    if(ini >= fin)return ini;
    
    int med = (ini + fin)/2;
    
    if((med == 0 or arr[med - 1] != arr[med]) and arr[med] == cant){//Si el anterior es diferente es el inicio
        return med;
    }
    
    if(arr[med] >= cant){//SI el anterior es igual o el del medio es mayor que el buscado -> Se va a la izquierda
        return encontrarInicioLote(arr, ini, med, cant);
    }
    else{
        return encontrarInicioLote(arr, med + 1, fin, cant);
    }
}
int encontrarFinLote(int *arr, int ini, int fin, int cant){
    if(ini >= fin)return ini;
    
    int med = (ini + fin)/2;
    
    if(arr[med] != arr[med + 1] and arr[med] == cant){ //Si el siguiente es diferente es el final
        return med;
    }
    
    if(arr[med] > cant){//SI el del medio es mayor que el buscado -> Se va a la izquierda
        return encontrarFinLote(arr, ini, med, cant);
    }
    else{
        return encontrarFinLote(arr, med + 1, fin, cant);
    }
}
void pregunta1_A(){
    int lote[] = {15872, 15865, 15866, 14357, 14365, 14368, 14370, 19258, 19260};
    int arr[] = {3, 4, 4, 6, 6, 6, 6, 8, 8};
    //int arr[] = {3, 4, 4, 4, 4, 6, 6, 6, 6, 8, 8};
    //int arr[] = {3, 4, 5};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    //int cantProductos = 6;
    //int cantProductos = 3;
    int cantProductos = 8;

    cout << "Para encontrar los lotes de " << cantProductos << " productos: " << endl;
    
    int iniLot = 0, finLot = 0;
    iniLot = encontrarInicioLote(arr, 0, n - 1, cantProductos);
    finLot = encontrarFinLote(arr, 0, n - 1, cantProductos);

    cout << "Lote inicial: " << lote[iniLot] << endl;
    cout << "Lote final: " << lote[finLot] << endl;
    
    
//    while (true) {
//        cin >> cantProductos;
//        if(cantProductos == -1){
//            break;
//        }
//        iniLot = encontrarInicioLote(arr, 0, n - 1, cantProductos);
//        finLot = encontrarFinLote(arr, 0, n - 1, cantProductos);
//        cout << "Para encontrar los lotes de " << cantProductos << " productos: " << endl;
//        cout << "Lote inicial: " << lote[iniLot] << endl;
//        cout << "Lote final: " << lote[finLot] << endl;
//    }

}

////////////////////////////////////////////////////////////////////////////////PREGUNTA 1

//////////////////////////////////////PREGUNTA 1 B

struct Plato llenarPlato(string nomb, int cantDis, int cantRes){
    Plato plato;
    plato.nombre = nomb;
    plato.cantidadDisponible = cantDis;
    plato.cantidadReservada = cantRes;
    plato.porcentajeReservas = (cantRes*100.00)/(double)(cantDis);
    return plato;
}
struct Plato *leerDatos(){
    ifstream arch("Platos.txt", ios::in);
    if(not arch.is_open()){
        cout <<"Error " << endl;
        exit(1);
    }
    struct Plato *arrPla, buffer[100];
    int i = 0;
    
    string nomb;
    int cantDis, cantRes;
    char c;
    double porcentaje;
    
    while (true) {
        getline(arch, nomb, ',');
        if(arch.eof())break;
        arch>>cantDis>>c>>cantRes;
        arch.get();
        buffer[i] = llenarPlato(nomb, cantDis, cantRes);
        i++;
    }
    arrPla = new Plato[i + 1]{};

    int k = i;
    for (int g = 0; g < k; g++) {
        arrPla[g] = buffer[g];
    }
    arrPla[i + 1].cantidadDisponible = 0;

    
    return arrPla;
}

void intercambiar(Plato &k, Plato &g){
    Plato aux;
    aux = k;
    k = g;
    g = aux;
}

void ordenamientoQuick(Plato *arr, int ini, int fin){
    if(ini >= fin)return;
    
    
    int med = (ini + fin)/2;
        
    //Como pibot el ultimo
    
    intercambiar(arr[fin], arr[med]);
    int limite = fin;
    for (int i = fin - 1; i >= ini; i--) {
        if(arr[fin].porcentajeReservas > arr[i].porcentajeReservas){
            intercambiar(arr[i], arr[--limite]);
        }

    }
    
    intercambiar(arr[fin], arr[limite]);

    ordenamientoQuick(arr, ini, limite - 1);
    ordenamientoQuick(arr, limite + 1, fin);
}

void pregunta1_B(){
    struct Plato *arr = leerDatos();

    int n = 0;
    
    for (n = 0; arr[n].cantidadDisponible; n++);
    //cout << n << endl;
    
    ordenamientoQuick(arr, 0, n - 1);
    

    cout << "Top 3 platos con mayor porcentaje de resservas: " << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << endl << arr[i].nombre << " - " << arr[i].porcentajeReservas << "%" << endl;
    }

    /*
    La complejidad promedio del algoritmo QuickSort es: 𝑂(𝑛log(𝑛))
     */
}

////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////PREGUNTA 2
//////////////////////////////////////PREGUNTA 2 A

///////Inciso: ii
bool encontrarRecursivo(NodoArbol *pArbol, int numero, int suma){ 

    if(pArbol){

        suma = suma * 2 + pArbol->elemento.numero;
        if(suma == numero)return true;

        return encontrarRecursivo(pArbol->derecha, numero, suma) or 
               encontrarRecursivo(pArbol->izquierda, numero, suma);
    }
    return false;
}
bool encontrarNumero(ArbolBinario arbolDigital, int numero){
    if(esArbolVacio(arbolDigital))return false;
    
    if(encontrarRecursivo(arbolDigital.raiz, numero, 0))return true;
    return false;
}

////////
///////Inciso: iii

int calcularBinario(Cola camino){
    int suma = 0;
    Elemento aux;
    
    for (int i = 0; i < longitud(camino.lista); i++) {
        aux = desencolar(camino);
        suma = suma * 2 + aux.numero;
        encolar(camino, aux);
    }
    
    return suma;
}

void imprimirCola(Cola camino){
    string cam;
    Elemento aux;
    aux = desencolar(camino); //Para que no imprima el 0 de la nariz
    encolar(camino, aux); //Para que no imprima el 0 de la nariz
    //Lo mandamos siempre al final ese 0 de la raiz e imprimimos hasta 1 menos
    for (int i = 0; i < longitud(camino.lista) - 1; i++) {
        aux = desencolar(camino);
        cam += to_string(aux.numero);
        encolar(camino, aux);
    }
    
    //Para que salga recto y piola
    int max = 8, faltantes;
    faltantes = max - cam.size();
    cam = cam + string(faltantes, ' ');
    cout << cam;
}



bool primer_vez = true;
int binarios[] =  {0, 1, 3, 5, 9, 14};

bool encontro(int decimal){
    int n = sizeof(binarios)/sizeof(binarios[0]);
    for (int i = 0; i < n; i++) {
        if(decimal == binarios[i])return true;
    }
    return false;
}

void recorrerEImprimirRecursivoReal(NodoArbol *pArbol, Cola camino){
    if(pArbol){
        Elemento aux;
        aux = pArbol->elemento;
        encolar(camino, aux);
        if(longitud(camino.lista) > 1){ //Para que no imprima el 0 de la raiz
            int decimal = calcularBinario(camino);
            if(encontro(decimal)){ //Si está dentro de los numeros solicitado
                imprimirCola(camino);
                cout << ": " << setw(2) << decimal << endl;
            }
        }
        recorrerEImprimirRecursivoReal(pArbol->izquierda, camino);
        recorrerEImprimirRecursivoReal(pArbol->derecha, camino);
    }
}
void recorrerEImprimirRecursivo(ArbolBinario arbolDigital){
    Cola camino;
    construir(camino);
    recorrerEImprimirRecursivoReal(arbolDigital.raiz, camino);
}
void pregunta2a(){
    ArbolBinario arbolDigital;
    construir(arbolDigital);
    
    /*
                    root 
                  /     \ 
              1 (1)     0 
            /     \ 
         1 (3)     0 
        /         /   \   
     1         1 (5)  0 
       \             / 
        0 (14)     1 (9)

    */
    
    Elemento temp;
    NodoArbol *n1,*n2, *n3, *n4,*n5,*n6,*n7, *n8, *n9;
    
    //Inciso: i
    temp.numero = 0;
    n1 = crearNuevoNodo(nullptr, temp, nullptr);
    temp.numero = 1;
    n2 = crearNuevoNodo(nullptr, temp, n1);
    temp.numero = 1;
    n3 = crearNuevoNodo(n2, temp, nullptr);
    
    temp.numero = 1;
    n5 = crearNuevoNodo(nullptr, temp, nullptr);
    temp.numero = 0;
    n6 = crearNuevoNodo(n5, temp, nullptr);
    temp.numero = 1;
    n7 = crearNuevoNodo(nullptr, temp, nullptr);
    
    temp.numero = 0;
    n8 = crearNuevoNodo(n7, temp, n6);
    
    temp.numero = 1;
    n4 = crearNuevoNodo(n3, temp, n8);
    
    temp.numero = 0;
    n9 = crearNuevoNodo(nullptr, temp, nullptr);
    
    temp.numero = 0;
    plantarArbolBinario(arbolDigital, n4, temp, n9);
    
    //recorrerEnOrden(arbolDigital);
    //1 0 1 1 1 0 1 0 0 0 
    
    
    int numerosEnElArbol[] = {0, 1, 3, 5, 9, 14, 7, 4, 2};
    //int numero = numerosEnElArbol[8];
    
    //int numero = 10;
    int numero = 12;

    //Inciso: ii
    if(encontrarNumero(arbolDigital, numero))cout << "Se econtró el numero " << numero << " en el arbol" << endl;
    else cout << "No se econtró el numero " << numero << " en el arbol" << endl;
    
    /*
     Ejemplo con 11
     acumulado = 0;
     acumulado = acumulado * 2 + 1; // → 1
     acumulado = acumulado * 2 + 0; // → 2
     acumulado = acumulado * 2 + 1; // → 5
     acumulado = acumulado * 2 + 1; // → 11 
     
     11 ÷ 2 = 5  → 1
     5 ÷ 2 = 2  → 1
     2 ÷ 2 = 1  → 0
     1 ÷ 2 = 0  → 1
     
     11 ÷ 2 = x  → 1
     x ÷ 2 = y  → 1
     y ÷ 2 = z  → 0
     z ÷ 2 = 0  → 1 
     * 
     A binario
      11|_2
         5|_2
       1   2|_2
         1   1
           0
     */
    
    //Inciso: iii
    recorrerEImprimirRecursivo(arbolDigital);
}

////////////////////////////////////////////////////////////////////////////////PREGUNTA 2
//////////////////////////////////////PREGUNTA 2 B

void cargarDatos(ArbolBinarioBusqueda &arbol){
    ifstream arch("Contrase.txt", ios::in);
    if(not arch.is_open()){
        cout << "ERROR" << endl;
        exit(1);
    }
    
    Elemento temp;
    while (true) {
        arch>>temp.numero;
        if(arch.eof())break;
        arch.get();
        arch>>temp.car;
        insertar(arbol, temp);
    }

}


bool compararPosYCar(NodoArbol *pArbol, char letra, int pos){
    if(pArbol == nullptr)return false;
    
    if(pArbol->elemento.numero == pos){
        return letra == pArbol->elemento.car;  //Encuentra la posicion correcta y lo compara con la letra
    }
    else{
        if(pArbol->elemento.numero < pos){
            return compararPosYCar(pArbol->derecha, letra, pos);
        }
        else{
            return compararPosYCar(pArbol->izquierda, letra, pos);
        }
    }
}
bool verificarContrasenia(NodoArbol *pArbol, char *palabra){
    for (int i = 0; i < strlen(palabra); i++) {
        if(not compararPosYCar(pArbol, palabra[i], i + 1))return false; //Significa que la letra no esta en la posicion correcta
    }
    return true; //Todas estan en la posicon correcta
}
bool analizarContrasenia(ArbolBinarioBusqueda arbol){
    int i = 0;
    
    int numerosMaxIntentos;
    //cin >> numerosMaxIntentos;
    numerosMaxIntentos = 3;

    char palabras[numerosMaxIntentos][10] = { "PUKE24", "PUKE2024", "PUCP2024" };
    //char palabras[numerosMaxIntentos][10] = { "PUKE23", "PUKE2024", "PUCP2025" };
    
    bool correcto = false;
    
    while (i < numerosMaxIntentos) {
        //cin >> palabra;
        cout << "Intento " << i + 1 << "/" << numerosMaxIntentos <<". Ingrese la contraseña: " << palabras[i] << endl;
        if(numeroNodos(arbol.arbolBinario) != strlen(palabras[i])){
            cout << "Longitud incorrecta. Intento fallido." << endl;
        }
        else{
            if(verificarContrasenia(arbol.arbolBinario.raiz, palabras[i])){
                return true;
            }
            else{
                cout << "Contraseña incorrecta. Intento fallido." << endl;
            }
        }
        i++;
    }
    return false;
}
void pregunta2b(){
    ArbolBinarioBusqueda arbol;
    construir(arbol);
   
    cargarDatos(arbol);
    
    //recorrerEnOrden(arbol.arbolBinario);
    cout << endl;
    
    if(analizarContrasenia(arbol))cout << "Acceso concedido" << endl;
    else cout << "Se llegó al número de intentos fallidos permitidos" << endl;
}

////////////////////////////////////////////////////////////////////////////////PREGUNTA 3
//////////////////////////////////////PREGUNTA 3 A

NodoArbol *buscarNodo(NodoArbol *pArbol, int numero){
    if(pArbol == nullptr)return nullptr;
    
    while (pArbol) {
        if(pArbol->elemento.numero == numero)return pArbol;
        if(pArbol->elemento.numero < numero){
            pArbol = pArbol->derecha;
        }
        else{
            pArbol = pArbol->izquierda;
        }
    }
    return pArbol;
}



void recorridoDiagonal(ArbolBinarioBusqueda arbol){
    if(esArbolVacio(arbol.arbolBinario))return;
    Cola cola1, cola2;
    
    construir(cola1); //Trababjo
    construir(cola2); //Impresion
    
    NodoArbol *pRec = arbol.arbolBinario.raiz;
    
    Elemento temp;
    
    encolar(cola1, pRec->elemento);
    
    while (!esColaVacia(cola1)) {
        temp = desencolar(cola1);
        pRec = buscarNodo(arbol.arbolBinario.raiz, temp.numero);
        
        while (pRec) {
            encolar(cola2, pRec->elemento);
            if(pRec->izquierda)encolar(cola1, pRec->izquierda->elemento);
            pRec = pRec->derecha;
        }        
    }

    while (!esColaVacia(cola2)) {
        temp = desencolar(cola2);
        cout << temp.numero << " ";
    }

}
void pregunta3a(){
    struct ArbolBinarioBusqueda arbol;
    struct Elemento elemento;
    construir(arbol);
    
    elemento.numero = 100;
    insertar(arbol, elemento);
    elemento.numero = 50;
    insertar(arbol, elemento);
    elemento.numero = 150;
    insertar(arbol, elemento);
    elemento.numero = 125;
    insertar(arbol, elemento);
    elemento.numero = 175;
    insertar(arbol, elemento);
    elemento.numero = 200;
    insertar(arbol, elemento);
    elemento.numero = 25;
    insertar(arbol, elemento);
    elemento.numero = 75;
    insertar(arbol, elemento);
    elemento.numero = 40;
    insertar(arbol, elemento);
    
    
    recorridoDiagonal(arbol);
    cout << endl;
}
////////////////////////////////////////////////////////////////////////////////PREGUNTA 3
//////////////////////////////////////PREGUNTA 3 B

void recorridoDiagonalInverso(ArbolBinarioBusqueda arbol){
    if(esArbolVacio(arbol.arbolBinario))return;
    Cola cola;
    Pila pila;
    
    construir(cola); //Trababjo
    construir(pila); //Impresion
    
    NodoArbol *pRec = arbol.arbolBinario.raiz;
    
    Elemento temp;
    
    encolar(cola, pRec->elemento);
    
    while (!esColaVacia(cola)) {
        temp = desencolar(cola);
        pRec = buscarNodo(arbol.arbolBinario.raiz, temp.numero);
        
        while (pRec) {
            apilar(pila, pRec->elemento);
            if(pRec->izquierda)encolar(cola, pRec->izquierda->elemento);
            pRec = pRec->derecha;
        }        
    }
    
    while (!esPilaVacia(pila)) {
        temp = desapilar(pila);
        cout << temp.numero << " ";
    }


}
void pregunta3b(){
    struct ArbolBinarioBusqueda arbol;
    struct Elemento elemento;
    construir(arbol);
    
    elemento.numero = 100;
    insertar(arbol, elemento);
    elemento.numero = 50;
    insertar(arbol, elemento);
    elemento.numero = 150;
    insertar(arbol, elemento);
    elemento.numero = 125;
    insertar(arbol, elemento);
    elemento.numero = 175;
    insertar(arbol, elemento);
    elemento.numero = 200;
    insertar(arbol, elemento);
    elemento.numero = 25;
    insertar(arbol, elemento);
    elemento.numero = 75;
    insertar(arbol, elemento);
    elemento.numero = 40;
    insertar(arbol, elemento);
    
    
    recorridoDiagonalInverso(arbol);
    cout << endl;
}