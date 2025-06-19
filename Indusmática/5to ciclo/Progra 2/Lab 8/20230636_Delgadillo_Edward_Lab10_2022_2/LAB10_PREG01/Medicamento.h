/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicamento.h
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:47 PM
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <fstream>
using namespace std;

class Medicamento {
public:
    Medicamento();
//    Medicamento(const Medicamento& orig);
    virtual ~Medicamento();
    
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void leer(ifstream&arch);
    virtual void imprimir(ofstream&arch);
    virtual bool esDeMarca()=0;
    
    bool operator >(Medicamento&medi);
private:
    int codigo;
    char*nombre;
    int stock;
    double precio;
};

void operator <<(ofstream&arch,Medicamento&medi);
#endif /* MEDICAMENTO_H */

