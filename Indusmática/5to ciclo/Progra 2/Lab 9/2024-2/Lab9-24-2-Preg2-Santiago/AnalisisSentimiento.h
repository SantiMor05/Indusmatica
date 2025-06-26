/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalisisSentimiento.h
 * Author: santi
 *
 * Created on 24 de junio de 2025, 22:41
 */

#ifndef ANALISISSENTIMIENTO_H
#define ANALISISSENTIMIENTO_H

#include "Oracion.h"
#include <fstream>
#include <map>

using namespace std;

class AnalisisSentimiento {
private:
    map<string,vector<Oracion>> comentarios;
    map<string, int> lexicon;
    void procesar_oracion(string &comentario);
    void imprimirLinea(ofstream &arch, char car);
    void imprimirNPrimeros(ofstream &arch, int n);
    
public:
    AnalisisSentimiento();
    AnalisisSentimiento(const AnalisisSentimiento& orig);
    virtual ~AnalisisSentimiento();
    void cargar_lexicon();
    void cargar_comentarios_restaurantes();
    void imprimir_analisis();
    void ordenar_comentarios();
};

#endif /* ANALISISSENTIMIENTO_H */

