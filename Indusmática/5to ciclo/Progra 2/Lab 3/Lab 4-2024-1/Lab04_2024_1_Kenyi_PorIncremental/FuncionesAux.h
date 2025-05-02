/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAux.h
 * Author: kenyi
 *
 * Created on 1 de mayo de 2025, 04:42 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
void cargaclientes(void *&clientes);

void *leerReg(ifstream &arch);

char *leerExato(ifstream &arch, int max, char del);

void incrementarEspacio(void **&pt, int &nd, int &cap);

void creareserva(void *&reserva);

void *leerRegReserva(ifstream &archLib);

void cargareservar(void *clientes, void *&reserva);

int buscarClientes(int dni, void **regCli);

int buscarReserva(char *cod, void **regRes);

void *colocarSolicitante(void **regCli);

void colocarCliente(void *res,void *cli,int &cantCli);
#endif /* FUNCIONESAUX_H */
