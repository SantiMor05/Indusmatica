/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 18:17
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
    double creditos;
    double total;
    
public:
    Alumno();
//    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void inicializa();
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualizatotal(double escala);
};

#endif /* ALUMNO_H */

