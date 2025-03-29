/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cursos.h
 * Author: santi
 *
 * Created on 9 de noviembre de 2024, 11:42
 */

#ifndef CURSOS_H
#define CURSOS_H
#define MAX_CAR_CURSO 60

struct Curso{
    int codigo;
    int alumnos;
    char nombre[MAX_CAR_CURSO];
    double creditos;
    double monto_pagado;
};

#endif /* CURSOS_H */

