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
        oracion=procesar(texto);
        comentarios[rest].push_back(oracion);
    }
}

Oracion AnalisisSentimiento::procesar(string texto) {

    Oracion oracion;
    int i=0,k=0,pola;
    string aux;
    while(i<texto.length()){
        k=texto.find(' ',i);
        if(k==-1)
            k=texto.length()-1;
        aux=texto.substr(i,k);
        pola=lexicon[aux];
        oracion.agregar(aux,pola);
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
    
    for(auto comentario:comentarios){
        arch<<"Restaurante: "<<comentario.first<<endl;
        imprimirEstadistica(arch,comentario.second);
        imprimeLinea(arch,'-',50);
    }
}

void AnalisisSentimiento::imprimirEstadistica(ofstream& arch, 
        vector<Oracion>& oraciones) {

    int posi=0,nega=0,neutros=0;
    for(auto oracion:oraciones){
        oracion.estadistico(posi,nega,neutros);
    }
    arch<<"  Positivos: "<<posi<<"  Negativos: "<<nega<<"  "
            <<"Neutros: "<<neutros<<endl;
}


void AnalisisSentimiento::imprimeLinea(ofstream& arch, char c, int n) {

    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}



