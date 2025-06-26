/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalisisSentimiento.cpp
 * Author: kenyi
 * 
 * Created on 23 de junio de 2025, 07:59 PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#include "AnalisisSentimiento.h"

void AnalisisSentimiento::cargar_lexicon() {
    ifstream arch("lexicon.csv", ios::in);
    arch.clear();
    arch.seekg(0, ios::beg);
    if (!arch) {
        cout << "Error al abrir el archivo lexicon.csv";
        exit(1);
    }

    leerLexicon(arch);
    //    imprimirLexicon();
    arch.close();
}

void AnalisisSentimiento::imprimirLexicon() {
    for (auto m : lexicon) {
        cout << m.first << " " << m.second << endl;
    }
}

void AnalisisSentimiento::leerLexicon(ifstream& arch) {
    string palabra;
    char aux[20];
    int polaridad;
    while (true) {
        getline(arch, palabra, ',');
        if (arch.eof())break;
        arch>>polaridad;
        arch.get();
        lexicon[palabra] = polaridad;
    }
}

void AnalisisSentimiento::cargar_comentarios_restaurantes() {
    ifstream arch("comentarios.csv", ios::in);
    arch.clear();
    arch.seekg(0, ios::beg);
    if (!arch) {
        cout << "Error al abrir el archivo comentarios.csv";
        exit(1);
    }

    leerComentarios(arch);
    arch.close();
}

void AnalisisSentimiento::cargar_comentarios_restaurantes2() {
    ifstream arch("comentarios.csv", ios::in);
    arch.clear();
    arch.seekg(0, ios::beg);
    if (!arch) {
        cout << "Error al abrir el archivo comentarios.csv";
        exit(1);
    }
    leerComentarios2(arch);
    arch.close();
}

void AnalisisSentimiento::leerComentarios(ifstream& arch) {
    string sitio, comentario;
    while (true) {
        getline(arch, sitio, ',');
        if (arch.eof())break;
        getline(arch, comentario);
        procesarComentario(comentario);
        stringstream comentario_stream(comentario);
        string palabra_extraida;
        Oracion oracion;
        int polaridad_total = 0;
        int cantidad_palabras = 0;

        while (comentario_stream >> palabra_extraida) {
            int polaridad = 0;
            if (lexicon.find(palabra_extraida) != lexicon.end()) {
                polaridad = lexicon[palabra_extraida];
            }

            Palabra palabra;
            palabra.SetTexto(palabra_extraida);
            palabra.SetPolaridad(polaridad);

            oracion.agregar(palabra);

            polaridad_total += polaridad;
            cantidad_palabras++;
        }
        oracion.SetCantidad_palabras(cantidad_palabras);
        oracion.SetPolaridad_total(polaridad_total);

        comentarios[sitio].push_back(oracion);
    }

}

void AnalisisSentimiento::leerComentarios2(ifstream& arch) {
    string sitio, comentario, linea;
    while (true) {
        getline(arch, linea);
        if (arch.eof())break;
        sitio = linea.substr(0, linea.find(','));
        comentario = linea.substr(linea.find(',') + 1);
        procesarComentario(comentario);

        Oracion oracion;
        int polaridad_total = 0;
        int cantidad_palabras = 0;

        int pos = 0;
        while ((pos = comentario.find(' ')) != string::npos) {
            string palabra_extraida = comentario.substr(0, pos);
            int polaridad = 0;

            if (lexicon.find(palabra_extraida) != lexicon.end()) {
                polaridad = lexicon[palabra_extraida];
            }

            Palabra palabra;
            palabra.SetTexto(palabra_extraida);
            palabra.SetPolaridad(polaridad);

            oracion.agregar(palabra);

            polaridad_total += polaridad;
            cantidad_palabras++;

            comentario.erase(0, pos + 1);
        }

        int polaridad = 0;

        if (lexicon.find(comentario) != lexicon.end()) {
            polaridad = lexicon[comentario];
        }

        Palabra palabra;
        palabra.SetTexto(comentario);
        palabra.SetPolaridad(polaridad);

        oracion.agregar(palabra);

        polaridad_total += polaridad;
        cantidad_palabras++;

        oracion.SetCantidad_palabras(cantidad_palabras);
        oracion.SetPolaridad_total(polaridad_total);

        comentarios[sitio].push_back(oracion);
    }
}

void AnalisisSentimiento::procesarComentario(string& comentario) {
    string resultado = "";
    char ant;
    for (char c : comentario) {

        if (isalpha(c) or (c == ' ' and ant != ' ')) {
            resultado += tolower(c);
            ant = c;
        }
    }
    comentario = resultado;
}

void AnalisisSentimiento::imprimir_analisis() {
    ofstream arch("Reporte.txt", ios::out);
    if (!arch) {
        cout << "Error al abrir el archivo Reporte.txt";
        exit(1);
    }

    int contador, pos, neg, neu;
    for (auto m : comentarios) {
        contador = 1;
        arch << "Restaurante: " << m.first << endl;
        pos = 0, neg = 0, neu = 0;
        for (Oracion v : m.second) {
            //            arch << "Comentario " << contador << ": " << endl;
            //            v.imprimir(arch);
            //            arch << endl;
            if (v.GetPolaridad_total() > 0) {
                //                arch << "Comentario Positivo" << endl;
                pos++;
            } else if (v.GetPolaridad_total() < 0) {
                //                arch << "Comentario Negativo" << endl;
                neg++;
            } else {
                //                arch << "Comentario Neutro" << endl;
                neu++;
            }
            //            contador++;
            //            imprimirLinea(arch, 150, '-');
        }
        arch << "Comentario positivos: " << pos << endl;
        arch << "Comentario negativo: " << neg << endl;
        arch << "Comentario neutro: " << neu << endl;
        imprimirLinea(arch, 150, '=');
    }
}

void AnalisisSentimiento::imprimir_analisis2() {
    ofstream arch("Reporte2.txt", ios::out);
    if (!arch) {
        cout << "Error al abrir el archivo Reporte.txt";
        exit(1);
    }

    int contador, pos, neg, neu;
    for (auto m : comentarios) {
        contador = 1;
        arch << "Restaurante: " << m.first << endl;
        pos = 0, neg = 0, neu = 0;
        Oracion oracion_mayor = m.second[0];
        arch << "Oracion con mayor polaridad: " << endl;
        oracion_mayor.imprimir(arch);
        arch << oracion_mayor.GetPolaridad_total() << endl;
        Oracion oracion_menor = m.second[m.second.size() - 1];
        arch << endl << "Oracion con menor polaridad: " << endl;
        oracion_menor.imprimir(arch);
        arch << oracion_menor.GetPolaridad_total() << endl << endl;
        for (Oracion v : m.second) {

            if (v.GetPolaridad_total() > 0) {
                pos++;
            } else if (v.GetPolaridad_total() < 0) {
                //                arch << "Comentario Negativo" << endl;
                neg++;
            } else {
                if (neu < 5) {
                    arch << "Comentario Neutro " << neu + 1 << ": " << endl;
                    v.imprimir(arch);
                    arch << endl;
                }
                neu++;
            }
        }
        arch << endl;
        arch << "Comentario positivos: " << pos << endl;
        arch << "Comentario negativo: " << neg << endl;
        arch << "Comentario neutro: " << neu << endl;
        imprimirLinea(arch, 150, '=');
    }
}

void AnalisisSentimiento::imprimirLinea(ofstream& arch, int n, char c) {
    for (int i = 0; i < n; i++)arch.put(c);
    arch << endl;
}

void AnalisisSentimiento::ordenar_comentarios() {
    for (auto &map : comentarios) {
        //        vector <Oracion >oracion = ;
        sort(map.second.begin(), map.second.end());
    }
}

