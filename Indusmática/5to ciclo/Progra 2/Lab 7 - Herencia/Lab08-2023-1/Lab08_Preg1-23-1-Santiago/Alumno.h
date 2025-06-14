/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: santi
 *
 * Created on 11 de junio de 2025, 23:15
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;

public:
    Alumno();
    //Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *buffer) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void inicializa();
    void leerDatos(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ALUMNO_H */

