/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:20 PM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
#include <string>
using namespace std;

class Libro {
    
private:
    //char *nombre;
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
    void SetNombre(string nombre);
    string GetNombre() const;

    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};

#endif /* LIBRO_H */

