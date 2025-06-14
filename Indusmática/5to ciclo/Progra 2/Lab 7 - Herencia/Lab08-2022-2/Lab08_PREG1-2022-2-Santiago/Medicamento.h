/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicamento.h
 * Author: santi
 *
 * Created on 12 de junio de 2025, 22:09
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <fstream>
using namespace std;

class Medicamento {
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;

public:
    Medicamento();
//    Medicamento(const Medicamento& orig);
    virtual ~Medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void inicializa();
    void buscarLeerMedicamento(ifstream &arch, int medicamento);
    void imprimir(ofstream &arch);
};

#endif /* MEDICAMENTO_H */

