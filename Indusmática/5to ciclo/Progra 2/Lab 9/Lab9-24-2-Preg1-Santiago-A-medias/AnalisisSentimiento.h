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
#include <map>

class AnalisisSentimiento {
private:
    map<string,vector<Oracion>> comentarios;
    map<string, int> lexicon;
    void procesar_oracion(string &comentario);
    
public:
    AnalisisSentimiento();
    AnalisisSentimiento(const AnalisisSentimiento& orig);
    virtual ~AnalisisSentimiento();
    void cargar_lexicon();
    void cargar_comentarios_restaurantes();
    void imprimir_analisis();
};

#endif /* ANALISISSENTIMIENTO_H */

