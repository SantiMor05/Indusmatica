
#include <stdio.h>
#include <math.h>

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



int main() {
	int paq[] = {1,2,4,12,1};
	int i,j, n = 5, parcial, peso_mayor=0, mcomb, peso = 15;
	int opcion = (int)pow(2,n);
	int cromo[n]; 
	
	for(i=0; i<opcion; i++){
		parcial=0;
		carga_binaria(i, n,cromo);/*Toma i y lo vuelve binario en cromo*/
		for (j=0; j<n; j++){
			parcial=parcial+paq[j]*cromo[j]; /*Sacar la suma del peso*/
		}
		if (parcial<=peso && peso_mayor<=parcial){
			peso_mayor=parcial;
			mcomb = i;
		}
	}
	
	printf("Peso: %d  Comb: %d\n",peso_mayor, mcomb);
	return 0;
}
