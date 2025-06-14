/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 23:43
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <fstream>
using namespace std;

class Pedido {

private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *estado;
    double total;
    
   
public:
    Pedido();
    //Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEstado(char* estado);
    void GetEstado(char *buffer) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *buffer) const;
    void inicializa();
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    void imprimirFecha(ofstream &arch, int fecha);
    virtual void actualiza();
};

#endif /* PEDIDO_H */

