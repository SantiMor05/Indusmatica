/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalisisSentimiento.h
 * Author: kenyi
 *
 * Created on 23 de junio de 2025, 07:59 PM
 */

#ifndef ANALISISSENTIMIENTO_H
#define ANALISISSENTIMIENTO_H
#include <map>
#include <vector>
#include "Oracion.h"

class AnalisisSentimiento {
private:
    map<string, vector<Oracion>> comentarios;
    map<string, int> lexicon;
public:
    void cargar_lexicon();
    void cargar_comentarios_restaurantes();
    void cargar_comentarios_restaurantes2();
    void imprimir_analisis();
    void imprimir_analisis2();
    void leerLexicon(ifstream &arch);
    void imprimirLexicon(); // metodo para probar lexicon;
    void leerComentarios(ifstream &arch);
    void leerComentarios2(ifstream &arch);
    void procesarComentario(string &comentario);
    void  imprimirLinea(ofstream &arch,int n,char c);
};

#endif /* ANALISISSENTIMIENTO_H */

