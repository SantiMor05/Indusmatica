/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, int);
void insertarAlFinal(struct Lista &, int);
struct Nodo * obtenerNodoAnterior(const struct Lista & tad, struct Elemento elemento);

struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);

bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void imprime(const struct Lista &);

//

char* verificarDia(int num);

#endif /* FUNCIONESLISTAS_H */
