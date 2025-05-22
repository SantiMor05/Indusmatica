/* 
 * File:   funcionesPila.h
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 03:41 PM
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, int ); 
int desapilar(struct Pila &);
int cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimir(const struct Pila &);

#endif /* FUNCIONESPILA_H */

