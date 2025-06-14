/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medico.h
 * Author: santi
 *
 * Created on 12 de junio de 2025, 22:04
 */

#ifndef MEDICO_H
#define MEDICO_H

#include <fstream>
using namespace std;

class Medico {

private:
    int codigo;
    char *nombre;
    char *especialidad;

public:
    Medico();
//    Medico(const Medico& orig);
    virtual ~Medico();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char *buffer) const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void inicializa();
    void leerDatos(ifstream &arch);

};

#endif /* MEDICO_H */

