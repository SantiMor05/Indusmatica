/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Usuario
 *
 * Created on 10 de junio de 2025, 15:54
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char* nombre;
    int escala;
    double total;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void construir();
    void setTotal(double total);
    double getTotal() const;
    void setEscala(int escala);
    int getEscala() const;
    void setNombre(const char* nombre);
    void getNombre(char *cad) const;
    void setCodigo(int codigo);
    int getCodigo() const;
};

#endif /* ALUMNO_H */

