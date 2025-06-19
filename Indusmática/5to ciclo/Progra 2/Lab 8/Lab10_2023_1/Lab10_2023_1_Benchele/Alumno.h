/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:02 PM
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
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    
    void setTotal(double total);
    double getTotal() const;
    void setCreditos(double creditos);
    double getCreditos() const;
    void setEscala(int escala);
    int getEscala() const;
    void setNombre(const char* nombre);
    void getNombre(char*) const;
    void setCodigo(int codigo);
    int getCodigo() const;
    
    void inicializa();
    void operator =(const class Alumno &orig);

    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza(double);
};

#endif /* ALUMNO_H */

