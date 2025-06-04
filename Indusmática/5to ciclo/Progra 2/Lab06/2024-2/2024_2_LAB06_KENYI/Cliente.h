/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: kenyi
 *
 * Created on 3 de junio de 2025, 05:17 PM
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
    void inicializa();
    void elimina();
    void operator=(const Cliente &orig);
    void setTotalPagado(double totalPagado);
    double getTotalPagado() const;
    void setDescuento(double descuento);
    double getDescuento() const;
    void setDistrito(const char* distrito);
    void getDistrito(char*) const;
    void setNombre(const char* nombre);
    void getNombre(char*) const;
    void setDni(int dni);
    int getDni() const;
    void modifica(int aten, double prec,double desc);
};

void operator<<(ofstream &arch,Cliente  &cliente);
void operator>>(ifstream &arch, Cliente &cliente);

#endif /* CLIENTE_H */

