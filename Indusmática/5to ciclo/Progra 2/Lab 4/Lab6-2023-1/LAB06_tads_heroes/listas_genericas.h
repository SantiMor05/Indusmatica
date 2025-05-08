
/* 
 * File:   listas_genericas.h
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 04:32 PM
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H

void crear_lista_heroes(void *arreglo, void*&lista, void*(*leer)(void*));
void construirLista(void *&lista);
void insertaFinal(void *lst, void *reg);
void imprimir_lista_heroes(void *lista, void (*imprime)(void *, ofstream&));
void eliminar_lista_heroes_repetidos(void *lst, int eliminar(const void*, const void*));




#endif /* LISTAS_GENERICAS_H */


