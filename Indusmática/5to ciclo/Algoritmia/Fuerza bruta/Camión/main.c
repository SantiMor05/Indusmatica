

/* 
 * File:   main.c
 * Author: Josué Sebastián Moreno Galvez
 *                 20203301 
 * Created on 6 de abril de 2022, 20:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 15


void carga_binaria(int num, int n, int cromo[]){
	int i, res;
	for (i=0; i<n; i++)cromo[i]=0; /*0 0 0 0 0*/
	i=0;
	while(num>0){
		res= num%2;
		num=num/2;
		cromo[i] = res;
		i++;
	}
	
}

void imprime_solu(int almacen[][MAX],int n1, int n2, int n3, int n){
    int cromo[n];
    carga_binaria(n1, n, cromo);
    printf("Bahía 1: ");
    for(int i=0; i<n; i++){
        if(cromo[i]){
            printf("%d ", almacen[0][i]);
        }
    }
    
    carga_binaria(n2, n, cromo);
    printf("Bahía 2: ");
    for(int i=0; i<n; i++){
        if(cromo[i]){
            printf("%d ", almacen[1][i]);
        }
    }
    
    carga_binaria(n3, n, cromo);
    printf("Bahía 3: ");
    for(int i=0; i<n; i++){
        if(cromo[i]){
            printf("%d ", almacen[2][i]);
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {
    
    int almacen[][MAX] = {{2,5,6,10},
                          {7,8,15,3},
                          {11,9,6,4}};
    int i,j, m=5, capacidad=20, n=4, peso, contador=0, sol=0;
    int valor, mvalor=0;
    int opcion = (int)pow(2,n);
    int cromo1[n], cromo2[n], cromo3[n]; 
	
    for(i=0; i<opcion; i++){
        carga_binaria(i, n,cromo1);/*Toma i y lo vuelve binario en cromo*/
	for(j=0; j<opcion; j++){
            carga_binaria(j, n,cromo2);/*Toma i y lo vuelve binario en cromo*/
            for(int k=0; k<opcion;k++){
                peso = 0;
                contador = 0; 
                carga_binaria(k, n,cromo3);/*Toma i y lo vuelve binario en cromo*/
                for(int l=0; l<n; l++){
                    if(cromo1[l]){
                        contador++;
                        peso+=almacen[0][l];
                    }
                    if(cromo2[l]){
                        contador++;
                        peso+=almacen[1][l];
                    }
                    if(cromo3[l]){
                        contador++;
                        peso+=almacen[2][l];
                    }
                }
                if(peso==capacidad && contador==m){
                    printf("Si hay solución\n");
                    imprime_solu(almacen,i,j,k, n);
                    sol=1;
                }
            }
        }
    }
    if(!sol) printf("No hay solucion\n");
    return (EXIT_SUCCESS);
}

