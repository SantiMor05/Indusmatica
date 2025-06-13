/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: esteban
 *
 * Created on 20 de abril de 2025, 18:46
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H


//Lectura De Libros
void lecturaDeLibros(const char *nombreArch, char***&libros, int**&stock);
char** lecturaLibro(ifstream &archLee);
char* lecturaExacta(ifstream &archLee,char delim);
int* lecturaStock(ifstream &archLee);

//Prueba de Lectura
void pruebaDeLecturaDeLibros(const char *nombreArch, char***libros, int**stock);

//Lectua de Pedidos
void atencionDePedidos(const char *nombreArch, char***libros, int**stock,
        int**& pedidosClientes, char***&pedidosLibros, bool**&pedidosAtendidos);
int buscamosCliente(int dniClien,int** pedidosClientes);
void agregamosCliente(int* cliente,int dniClien,int& ndPed,int numPed,int &numDat);
void modificamosCliente(int* cliente,int &ndPed,int numPed);
void agregamosLibrosYAtendidos(ifstream &archLee,char** bufferLibros,
        bool*bufferAtendibles,int &ndLib,char*** libros,int **stock);
int buscamosLibro(char*ptCodLibro,char***libros);   
void asignacionExacta(bool**& pedidosAtendidos,int**&pedidosClientes,
        char***&pedidosLibros,bool** bufferAtend,int** bufferClien,char*** bufferLib,
        int*ndLib,int*ndPed,int numDat);
//Prueba Lectura Pedidos
void reporteDeEntregaPedidos(const char *nombreArch, int** pedidosClientes,
        char*** pedidosLibros, bool** pedidosAtendidos);



#endif /* FUNCIONESAUX_H */
