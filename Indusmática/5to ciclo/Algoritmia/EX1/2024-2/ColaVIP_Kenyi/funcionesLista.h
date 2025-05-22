/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
void construirPrioridad(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, int);
void insertarAlFinal(struct Lista &, int);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(int elemento, struct Nodo *);
/*Esta es la funcion para crear un nodo con prioridad*/
struct Nodo * crearNodoPrioridad(int elemento, char prioridad, struct Nodo *);

struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);
char retornaCabeza(const struct Lista &);
void insertarencola(struct Lista & tad, int elemento);
void insertarencolaPrioridad(struct Lista & tad, int elemento, char prioridad);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);
void imprimePrioridad(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

