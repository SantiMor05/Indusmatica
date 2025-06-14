/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: santi
 *
 * Created on 1 de junio de 2025, 13:20
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;

public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotalPagado(double totalPagado);
    double GetTotalPagado() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetDistrito(char* dist);
    void GetDistrito(char *buffer) const;
    void SetNombre(char* nomb);
    void GetNombre(char *buffer) const;
    void SetDni(int dni);
    int GetDni() const;
    void inicializa();
    void operator =(const Cliente &cli);
};

void operator >> (ifstream &arch, Cliente &cli);
void operator << (ofstream &arch, Cliente &cli);

#endif /* CLIENTE_H */

