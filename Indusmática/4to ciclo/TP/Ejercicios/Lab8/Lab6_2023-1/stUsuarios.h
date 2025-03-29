/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stUsuarios.h
 * Author: santi
 *
 * Created on 10 de noviembre de 2024, 19:33
 */

#ifndef STUSUARIOS_H
#define STUSUARIOS_H

struct Usuarios{
    int dni;
    int cant_prestados;
    int cant_no_prestados;
    char nombre[40];
    char categoria;
    double calificacion;
};

#endif /* STUSUARIOS_H */

