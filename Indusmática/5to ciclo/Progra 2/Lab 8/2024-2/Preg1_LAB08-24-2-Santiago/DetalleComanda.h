/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DetalleComanda.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 10:58
 */

#ifndef DETALLECOMANDA_H
#define DETALLECOMANDA_H

#include "Producto.h"
#include <fstream>
using namespace std;

class DetalleComanda {

private:
    int id;
    Producto *pedido;
public:
    DetalleComanda();
    DetalleComanda(const DetalleComanda& orig);
    virtual ~DetalleComanda();
    void SetId(int id);
    int GetId() const;
    void inicializa();
    void operator =(const DetalleComanda& orig);
    void leerComanda(ifstream &arch);
    void imprimirDatos(ofstream &arch);
    //virtual int verifica(int tipo_prote);
};



#endif /* DETALLECOMANDA_H */

