/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: santi
 *
 * Created on 4 de junio de 2025, 20:06
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>
using namespace std;

class Estante {
    
private:
    char *codigo;
    int anchura;
    int altura;
    Libro libros[50];
    Espacio *espacios;
    int cantidad_libros;
    
    void buscarEspacios(int &ancho, int &alto);
    
public:
    Estante();
//    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *buffer) const;
    void inicializa();
//    void operator =(const Estante &estante);
    void asignaEspacios();
    bool operator +=(const Libro &libro);

};

void operator >>(ifstream &arch, Estante &estante);


#endif /* ESTANTE_H */

