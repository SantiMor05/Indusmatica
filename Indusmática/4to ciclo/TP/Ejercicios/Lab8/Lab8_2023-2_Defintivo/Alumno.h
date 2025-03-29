/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: santi
 *
 * Created on 9 de noviembre de 2024, 11:40
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#define MAX_CAR_ALUMNO 50

struct Alumno{
    int codigo;
    char nombre[MAX_CAR_ALUMNO];
    char escala;
};

#endif /* ALUMNO_H */

