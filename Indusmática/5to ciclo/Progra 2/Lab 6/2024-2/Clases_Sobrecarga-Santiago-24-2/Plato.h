/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plato.h
 * Author: santi
 *
 * Created on 1 de junio de 2025, 13:21
 */

#ifndef PLATO_H
#define PLATO_H

#include <fstream>
using namespace std;

class Plato {
private:
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsparado;
    double totalBruto;
    double totalNeto;
    
    
    
public:
    Plato();
    Plato(const Plato& orig);
    virtual ~Plato();
    void SetTotalNeto(double totalNeto);
    double GetTotalNeto() const;
    void SetTotalBruto(double totalBruto);
    double GetTotalBruto() const;
    void SetTotalEsparado(double totalEsparado);
    double GetTotalEsparado() const;
    void SetNoAtendidos(int noAtendidos);
    int GetNoAtendidos() const;
    void SetAtendidos(int atendidos);
    int GetAtendidos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPreparados(int preparados);
    int GetPreparados() const;
    void SetCategoria(char* categoria);
    void GetCategoria(char *buffer) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *buffer) const;
    void inicializa();
    void operator = (const Plato &plato);

};

void operator >> (ifstream &arch, Plato &plato);
void operator << (ofstream &arch, Plato &plato);
#endif /* PLATO_H */

