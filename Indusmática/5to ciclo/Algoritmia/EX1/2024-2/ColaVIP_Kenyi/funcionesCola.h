/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 06:06 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & cola);
void construirPrioridad(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
void encolarPrioridad(struct Cola & cola, int elemento, char prioridad);
char desencolar(struct Cola & cola);
int longitud(const struct Cola & cola);
void imprime(const struct Cola & cola);
void imprimePrioridad(const struct Cola & cola);
void destruirCola(struct Cola & cola);

#endif /* FUNCIONESCOLA_H */

