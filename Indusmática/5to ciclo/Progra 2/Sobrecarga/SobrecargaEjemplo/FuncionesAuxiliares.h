/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 30 de enero de 2025, 17:02
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include "Vector.h"
using namespace std;

void operator !(struct Vector &v);
//void operator +(struct Vector &v, int n);
struct Vector & operator + (struct Vector &v, int n);
void operator += (struct Vector &v1, const struct Vector &v2);
struct Vector operator +(const struct Vector &v1, const struct Vector &v2);
//void operator <<(ostream &out, const struct Vector &v);
ostream & operator <<(ostream &out, const struct Vector &v);
istream & operator >>(istream &in, struct Vector &v);
//void operator >>(istream &in, struct Vector &v);

#endif /* FUNCIONESAUXILIARES_H */

