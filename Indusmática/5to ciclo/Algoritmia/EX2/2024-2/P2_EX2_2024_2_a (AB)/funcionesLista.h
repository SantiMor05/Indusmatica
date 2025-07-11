/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, const struct Elemento & elemento);
void insertarAlFinal(struct Lista &, const struct Elemento & elemento);
void insertarEnOrden(struct Lista &, const struct Elemento & elemento);

struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, const struct Elemento & elemento);
struct Nodo * seEncuentra(const struct Lista &, const struct Elemento & elemento);
struct Elemento retornaCabeza(const struct Lista & lista);

bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, const struct Elemento & elemento);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

