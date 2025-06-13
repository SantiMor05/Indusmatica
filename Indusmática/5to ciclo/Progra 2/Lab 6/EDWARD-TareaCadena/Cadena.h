/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.h
 * Author: 00123
 *
 * Created on 1 de junio de 2025, 11:24 AM
 */

#ifndef CADENA_H
#define CADENA_H

class Cadena {
public:
    Cadena(int capa=0);
    Cadena(const char*cad);
    Cadena(const Cadena& orig);
    virtual ~Cadena();
    void operator =(const Cadena&cad);
    void assign(const char*cad);
    void assign(const Cadena&cad);
    void operator =(const char*cad);
    void append(const char*cad);
    void append(const Cadena&cad);
    void swap(Cadena&cad);

    Cadena operator +(const Cadena&cad);
    int compare(const char*cad);
    int compare(const Cadena&cad);
    bool operator ==(const Cadena&cad);
    bool operator >(const Cadena&cad);
    bool operator <(const Cadena&cad);
    bool operator >=(const Cadena&cad);
    bool operator <=(const Cadena&cad);
    
    int length();
    void print();
    
private:
    char*contenedor;
    int longitud;
    int capacidad;
};

#endif /* CADENA_H */

