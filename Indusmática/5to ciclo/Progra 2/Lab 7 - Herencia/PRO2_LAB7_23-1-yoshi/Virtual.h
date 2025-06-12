/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Usuario
 *
 * Created on 10 de junio de 2025, 15:56
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"


class Virtual : public Alumno{
private:
    char* licencia;
    double total;
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char* cad) const;
    void insertarDatoV(int codigo,const char *cad, int escala,const char *lic);
    void imprimir(ofstream &arch);
    void actualiza(double monto);
};

#endif /* VIRTUAL_H */

