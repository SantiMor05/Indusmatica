/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

#include <fstream>
using namespace std;


void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, Elemento &);
void insertarAlFinal(struct Lista &, int);

struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);
int retornaCabeza(const struct Lista & lista);

bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void destruir(struct Lista &);
void imprime(const struct Lista &);


void operator >>(ifstream &arch,Elemento &elemento);
void completarElemento(ifstream &arch,Elemento &elemento);
int hallarPrepa(char complejidad,int perDispo);
int hallarEstViaje(double distancia,int esPunta);
void ordenar(Lista &lista,bool condi);
void sacarDigitos(int &digitoP,int &digitoAnt,int tiempoP,int tiempoAnt,
        bool condi);
#endif /* FUNCIONESLISTA_H */

