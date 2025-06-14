/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: santi
 *
 * Created on 4 de junio de 2025, 19:55
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;

class Libro {
    
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
    
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
    void inicializa();
    void operator = (const Libro &lib);

};

void operator >> (ifstream &arch, Libro &libro);

#endif /* LIBRO_H */

