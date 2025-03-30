/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armas.h
 * Author: santi
 *
 * Created on 30 de marzo de 2025, 12:43
 */

#ifndef ARMAS_H
#define ARMAS_H

struct Arma{
    char codigo;
    int poder;
    int tipo;
    char prerequisito[3];
    int nprerequisitos;
};

#endif /* ARMAS_H */

