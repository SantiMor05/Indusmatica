/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalisisSentimiento.cpp
 * Author: 00123
 * 
 * Created on 23 de junio de 2025, 05:05 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include <cctype>
#include "Oracion.h"
#include "AnalisisSentimiento.h"
//AnalisisSentimiento::AnalisisSentimiento() {
//}
//
//AnalisisSentimiento::AnalisisSentimiento(const AnalisisSentimiento& orig) {
//}
//
//AnalisisSentimiento::~AnalisisSentimiento() {
//}

void AnalisisSentimiento::cargar_lexicon() {

    ifstream arch("lexicon.csv",ios::in);
    if(!arch){
        cout<<"Error en "<<"lexicon.csv"; exit(1);
    }
//    abandona,-2
    string palabra;
    int pola;
    while(true){
        getline(arch,palabra,',');
        if(arch.eof())break;
        arch>>pola;
        arch.get();
        lexicon[palabra]=pola;
    }
//    for(auto i:lexicon)
//        cout<<i.first<<"  "<<i.second<<endl;
}
void AnalisisSentimiento::cargar_comentarios_restaurantes() {

    ifstream arch("comentarios.csv",ios::in);
    if(!arch){
        cout<<"Error en "<<"comentarios.csv"; exit(1);
    }
    string rest,texto;
    Oracion oracion;
    
    while(true){
        getline(arch,rest,',');
        if(arch.eof())break;
        getline(arch,texto);
        preProcesar(texto);
//        cout<<texto<<endl;
        oracion=procesar(texto);
        comentarios[rest].push_back(oracion);
    }
}

Oracion AnalisisSentimiento::procesar(string texto) {

    Oracion oracion;
    int i=0,k=0,pola;
    map<string,int>::iterator it;
    string aux;
    
    
//    cout<<texto<<endl;
//    cout<<texto.length()<<endl;
    
    while(i<texto.length()){
        k=texto.find(' ',i);
        if(k==string::npos)
//        if(k==-1)
            k=texto.length();
        aux=texto.substr(i,k-i);
        it=lexicon.find(aux);
        if(it!=lexicon.end()){
            pola=lexicon[aux];
            oracion.agregar(aux,pola);
        }
        i=k+1;
    }
    return oracion;
}


void AnalisisSentimiento::preProcesar(string &texto) {

//    "El hotel impecable todo muy limpio."
    string aux;
    for (int i = 0; i < texto.length(); i++) {
        if(isalpha(texto[i]) or texto[i]==' '){
            if(isalpha(texto[i]))
                aux+=tolower(texto[i]);
            else 
                aux+=texto[i];
        }
    }
    texto=aux;
}


void AnalisisSentimiento::imprimir_analisis() {

    ofstream arch("reporte.txt",ios::out);
    if(!arch){
        cout<<"Error en "<<"reporte.txt"; exit(1);
    }
    
    for(auto retaurante:comentarios){
        arch<<"Restaurante: "<<retaurante.first<<endl;
        imprimirEstadistica(arch,retaurante.second);
        imprimeLinea(arch,'-',50);
    }
}

void AnalisisSentimiento::imprimirEstadistica(ofstream& arch, 
        vector<Oracion>& oraciones) {

    int posi=0,nega=0,neutros=0;
    int i=0;
    arch<<"  Oraciones con polaridad 0: "<<endl;
    for(auto oracion:oraciones){
        oracion.estadistico(posi,nega,neutros);
        if(i<5){
            if(oracion.getPolaridad_total()==0){
                oracion.imprimir(arch);
                i++;
            }
        }
    }
    auto it1=oraciones.begin();
    auto it2=oraciones.end()-1;
    arch<<"  Oracion con mas polaridad: "<<endl;
    it1->imprimir(arch);
    arch<<"  Oracion con menor polaridad: "<<endl;;
    it2->imprimir(arch);
    
//    for(auto oraciones)

    
    
    arch<<"  Positivos: "<<posi<<"  Negativos: "<<nega<<"  "
            <<"Neutros: "<<neutros<<endl;
}


void AnalisisSentimiento::imprimeLinea(ofstream& arch, char c, int n) {

    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}

void AnalisisSentimiento::ordenar_comentarios() {

    for(auto restaurante:comentarios){
        sort(restaurante.second.begin(),
                restaurante.second.end());
    }
}

