/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 27 de octubre de 2024, 16:56
 */

#include <iostream>
#include <string>
#include "Elemento.h"
#include "ArbolBB.h"
using namespace std;

#include "funcionesABB.h"
#include "funcionesAB.h"
/*
 *  ARBOLES BINARIOS 2024-2
 *  Clase ABB
 */

void revisar(NodoArbol*p,string contra,bool&vali){
    
    if(not p or not vali)return;
    
    if(p->elemento.letra!=contra[p->elemento.numero-1]){
        vali=false;
        return;
    }
    revisar(p->izquierda,contra,vali);
    revisar(p->derecha,contra,vali);
    
}

int main(int argc, char** argv) {

    ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    Elemento ele;
    
    ele.numero=4;
    ele.letra='P';
    insertar(arbol,ele);
    
    ele.numero=2;
    ele.letra='U';
    insertar(arbol,ele);
    
    ele.numero=1;
    ele.letra='P';
    insertar(arbol,ele);
    
    ele.numero=3;
    ele.letra='C';
    insertar(arbol,ele);
    
    ele.numero=6;
    ele.letra='0';
    insertar(arbol,ele);
    
    ele.numero=5;
    ele.letra='2';
    insertar(arbol,ele);
    
    ele.numero=7;
    ele.letra='2';
    insertar(arbol,ele);
    
    ele.numero=8;
    ele.letra='4';
    insertar(arbol,ele);
    
    int cant=numeroNodos(arbol.arbolBinario);
    enOrden(arbol);
//    cout<<endl<<cant<<endl;
    int n;
    cout<<endl<<"Ingrese el número máximo de intentos: ";
    cin>>n;
    
    string contra;
    bool vali;
    int i;
    for (i = 0; i < n; i++) {
        cout<<"Intento "<<i+1<<
                "/"<<n<<". Igrese la contraseña: ";
        cin>>contra;
        if(contra.length()==cant){
            vali=true;
            revisar(arbol.arbolBinario.raiz,contra,vali);
            if(vali) cout<<"Acceso concedido."<<endl;
            else cout<<"Contraseña incorrecta. Intento fallido."
                    <<endl;
        }
        else cout<<"Longitud incorrecta. Intento fallido."<<
                endl;
    }
    if(i==n)cout<<"Se llegó al número de intentos fallidos "
            "permitidos."<<endl;

    
    return 0;
}
