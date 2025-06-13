/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plato.h
 * Author: kenyi
 *
 * Created on 3 de junio de 2025, 05:17 PM
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
    double totalEsperado;
    double totalBruto;
    double totalNeto;
public:
    Plato();
    Plato(const Plato& orig);
    virtual ~Plato();
    void inicializa();
    void elimina();
    void operator=(const Plato &orig);
    void setTotalNeto(double totalNeto);
    double getTotalNeto() const;
    void setTotalBruto(double totalBruto);
    double getTotalBruto() const;
    void setTotalEsperado(double totalEsperado);
    double getTotalEsperado() const;
    void setNoAtendidos(int noAtendidos);
    int getNoAtendidos() const;
    void setAtendidos(int atendidos);
    int getAtendidos() const;
    void setDescuento(double descuento);
    double getDescuento() const;
    void setPreparados(int preparados);
    int getPreparados() const;
    void setCategoria(const char* categoria);
    void getCategoria(char*) const;
    void setPrecio(double precio);
    double getPrecio() const;
    void setNombre(const char* nombre);
    void getNombre(char*) const;
    void setCodigo(const char* codigo);
    void getCodigo(char*) const;
    void modifica(int aten,int noAten,double desc);
};

void operator>>(ifstream &arch, Plato &plato);
void operator<<(ofstream &arch, Plato &plato);


#endif /* PLATO_H */

