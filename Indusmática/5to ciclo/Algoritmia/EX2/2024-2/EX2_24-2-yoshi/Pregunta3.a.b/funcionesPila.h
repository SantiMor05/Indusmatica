/* 
 * File:   funcionesPila.h
 * Author: anaro
 *
 * Created on 20 de abril de 2025, 19:56
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, const struct Elemento & elemento); 
struct Elemento desapilar(struct Pila &);
struct Elemento cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimir(const struct Pila &);

#endif /* FUNCIONESPILA_H */
