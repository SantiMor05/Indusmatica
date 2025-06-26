/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalisisSentimiento.cpp
 * Author: santi
 * 
 * Created on 24 de junio de 2025, 22:41
 */

#include "AnalisisSentimiento.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

AnalisisSentimiento::AnalisisSentimiento() {
}

AnalisisSentimiento::AnalisisSentimiento(const AnalisisSentimiento& orig) {
}

AnalisisSentimiento::~AnalisisSentimiento() {
}

void AnalisisSentimiento::cargar_lexicon() {

    ifstream arch("lexicon.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo lexicon" << endl;
        exit(1);
    }
    string palabra;
    int polaridad;
    while (true) {
        getline(arch, palabra, ',');
        if (arch.eof())break;
        arch >> polaridad;
        lexicon[palabra] = polaridad;
        arch.get();
    }
}

void AnalisisSentimiento::cargar_comentarios_restaurantes() {

    ifstream arch("comentarios.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo lexicon" << endl;
        exit(1);
    }
    string restaurante;
    string comentario;
    int i = 0;
    while (true) {
        Oracion oracionAux;
        getline(arch, restaurante, ',');
        if (arch.eof())break;
        getline(arch, comentario);
        
        procesar_oracion(comentario);
        
        oracionAux.dividirPalabras(comentario, lexicon);
        
        comentarios[restaurante].push_back(oracionAux);

//        PRUEBAS
//        vector<Oracion>::iterator it = comentarios[restaurante].begin();
//        for(;it !=  comentarios[restaurante].end(); it++)
//            it->imprimir();
//            
//        i++;
    }

}

void AnalisisSentimiento::procesar_oracion(string &comentario){
    
    string limpio;
    
    for(char c : comentario){
        if(isalpha(c) or c == ' '){
            limpio += tolower(c);
        }
        else
            limpio += ' ';
    }
    
    limpio += ' ';
    
    comentario = limpio;
    
}


void AnalisisSentimiento::imprimir_analisis(){
    
    ofstream arch("Reporte.txt", ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    int negativos, positivos, neutros, polaridad;
    for(auto x : comentarios){
        negativos = positivos = neutros = 0;
        
        for(auto oracion : x.second){
            polaridad = oracion.GetPolaridad_total();
            if(polaridad > 0) 
                positivos++;
            else if(polaridad < 0)
                negativos++;
            else neutros++;
        }
        arch << left << setw(90)<< x.first << right <<setw(8) << positivos << 
                setw(8) << neutros << setw(8) << negativos << endl;
    }
    
}
