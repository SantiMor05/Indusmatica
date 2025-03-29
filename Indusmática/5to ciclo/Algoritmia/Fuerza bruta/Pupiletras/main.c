/* 
 * File:   main.c
 * Author: Josué Sebastián Moreno Galvez
 *                 20203301 
 * Created on 2 de abril de 2022, 12:57
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXCOL 10
#define MAXFIL 4

int m[8][2];

void movimientos(){
    
    m[0][0] = -1 , m[0][1] = -1; /*Cada par es una coordenada*/
    m[1][0] =  0 , m[1][1] = -1; //Es decir cada fila es una coordenada
    m[2][0] =  1 , m[2][1] = -1;
    m[3][0] = -1 , m[3][1] =  0;
    m[4][0] =  1 , m[4][1] =  0;
    m[5][0] = -1 , m[5][1] =  1;
    m[6][0] =  0 , m[6][1] =  1;
    m[7][0] =  1 , m[7][1] =  1;
    
}

int busca(char tabla[][MAXCOL], char *palabra,int row,int col,int n){
    int nrow,ncol;
    int j;
    if(tabla[row][col]!= palabra[0])
        return 0;
    for(int i=0; i<8;i++){
        nrow = row + m[i][0];
        ncol = col + m[i][1];
        
        for(j=1; j<n; j++){
            if(nrow >= MAXFIL || nrow< 0 || ncol>=MAXCOL || ncol<0)
                break;
            if(tabla[nrow][ncol]!= palabra[j])
                break;
            nrow = nrow + m[i][0];
            ncol = ncol + m[i][1];
            /*MOSTRAR MATRIZ CON RESULTADOS*/
        }
        if(j==n)
            return 1;
    }
    return 0;
}


int  busca_palabras(char tabla[][MAXCOL], char *palabra, int n){
    
    for(int i=0; i<MAXFIL; i++){
        for (int j=0; j<MAXCOL; j++){
            if (busca(tabla, palabra,i,j,n))
                printf("La palabra esta en: %d  %d\n", i,j);
        }
    }
    
}

int main(int argc, char** argv) {
    int n=3;
    char tabla[][MAXCOL]= {
        {'H','J','A','S','S'},
        {'S','G','G','O','L'},
        {'A','O','J','K','E'},
        {'J','L','D','G','G'}
    };
    
    char palabra[]="GOL";
    movimientos();
    busca_palabras(tabla, palabra, n);

    return (EXIT_SUCCESS);
}

