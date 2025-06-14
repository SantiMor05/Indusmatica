/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conreceta.h
 * Author: santi
 *
 * Created on 12 de junio de 2025, 22:12
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "Medicamento.h"
#include "Medico.h"


class Conreceta : public Medicamento{
private:
    int codmed;
    char *especialidad;

public:
    Conreceta();
//    Conreceta(const Conreceta& orig);
    virtual ~Conreceta();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char *buffer) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void inicializa();
    void asigna(ifstream &arch, int medicamento, int cantidad,
            const Medico &medico,int fecha);
    void imprimir(ofstream &arch);
};

#endif /* CONRECETA_H */

