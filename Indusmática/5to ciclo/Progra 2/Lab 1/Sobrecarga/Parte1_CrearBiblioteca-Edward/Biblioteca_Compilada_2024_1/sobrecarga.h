/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: 00123
 *
 * Created on 9 de abril de 2025, 02:31 PM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H

bool operator >>(ifstream &arch,struct Libro &libro);
bool operator >>(ifstream &arch,struct Cliente &cliente);
bool operator >>(struct LibroSolicitado &libroSoli,struct Libro*libros);
void actualizar(struct LibroSolicitado &libroSoli,struct Libro &libro);
bool operator <<(struct Cliente &cliente,struct LibroSolicitado &libroSoli);
void agregarLibro(struct LibroSolicitado &libroModi,
        struct LibroSolicitado &libroSoli);
void operator ++(struct Cliente &cliente);
void operator <<(ofstream &arch,const struct Libro &libro);
void operator <<(ofstream &arch,const struct Cliente &cliente);
void imprimirLibEntre(ofstream &arch,const struct LibroSolicitado &libroSoli);
void imprimirLibNOEntre(ofstream &arch,const struct LibroSolicitado &libroSoli);

#endif /* SOBRECARGA_H */

