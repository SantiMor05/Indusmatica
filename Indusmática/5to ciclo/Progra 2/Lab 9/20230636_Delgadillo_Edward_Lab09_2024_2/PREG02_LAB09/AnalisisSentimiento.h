/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalisisSentimiento.h
 * Author: 00123
 *
 * Created on 23 de junio de 2025, 05:05 PM
 */

#ifndef ANALISISSENTIMIENTO_H
#define ANALISISSENTIMIENTO_H

#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
#include "Oracion.h"

class AnalisisSentimiento {
public:
//    AnalisisSentimiento();
//    AnalisisSentimiento(const AnalisisSentimiento& orig);
//    virtual ~AnalisisSentimiento();
    void cargar_lexicon();
    void cargar_comentarios_restaurantes();
    void imprimir_analisis();
    void preProcesar(string &texto);
    Oracion procesar(string texto);
    void imprimeLinea(ofstream&arch,char,int n);
    void imprimirEstadistica(ofstream&arch,vector<Oracion>&oraciones);
    void ordenar_comentarios();
private:
    map<string,vector<Oracion>>comentarios;
    map<string,int>lexicon;
};

#endif /* ANALISISSENTIMIENTO_H */

