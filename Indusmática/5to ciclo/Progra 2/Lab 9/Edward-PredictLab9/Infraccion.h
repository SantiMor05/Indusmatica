/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:24 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H

#include <fstream>
#include <string>
using namespace std;

class Infraccion {
public:
//    Infraccion();
//    Infraccion(const Infraccion& orig);
//    virtual ~Infraccion();
    
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(string gravedad);
    string GetGravedad() const;
    void SetDescripcion(string descripcion);
    string GetDescripcion() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;

    void leer(ifstream&arch);
    bool operator <(const Infraccion&i)const;
    
private:
    int codigo;
    string descripcion;
    string gravedad;
    double multa;
};

#endif /* INFRACCION_H */

