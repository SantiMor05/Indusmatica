/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.h
 * Author: santi
 *
 * Created on 31 de mayo de 2025, 20:07
 */

#ifndef CADENA_H
#define CADENA_H

#include <fstream>
using namespace std;

class Cadena {
private:
    char *cadena;
    int longitud;
    int capacidad;

public:
    Cadena();
    Cadena(const Cadena& orig);
    Cadena(const char *cad);
    Cadena(int n);
    virtual ~Cadena();
    void setCapacidad(int capacidad);
    int getCapacidad() const;
    void setLongitud(int longitud);
    int getLongitud() const;
    void setCadena(const char* cadena);
    void getCadena(char *buffer) const;
    void inicializa();
    void operator =(const Cadena& orig);
    void assign(const char *cad);
    void assign(const Cadena &cad);
    void operator = (const char *cad);
    void append(const char *cad);
    void append(const Cadena &cad);
    void swap(Cadena &cad);
    Cadena operator +(const Cadena &cad);
    
    //Comparacion
    int compare(const char *cad);
    int compare(const Cadena &cad);
    bool operator >(const Cadena &cad);
    bool operator ==(const Cadena &cad);
    bool operator <(const Cadena &cad);
    bool operator >=(const Cadena &cad);
    bool operator <=(const Cadena &cad);

    
    //Impresion
    void print();
};

void operator >>(ifstream &arch, Cadena &cad);

#endif /* CADENA_H */

