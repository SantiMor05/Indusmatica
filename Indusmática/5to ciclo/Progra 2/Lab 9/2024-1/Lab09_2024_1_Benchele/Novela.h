/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:22 PM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include <string>
#include <fstream>
#include "Libro.h"
using namespace std;



class Novela: public Libro {
    
private:
    //char *autor;
    string autor;
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(string autor);
    string GetAutor() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* NOVELA_H */

