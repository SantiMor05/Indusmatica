/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:23
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <fstream>
using namespace std;

class Libro {
private:
    string nombre;
    int paginas;
    double peso;
    
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(string &nombre);
    string GetNombre() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    
};

#endif /* LIBRO_H */

