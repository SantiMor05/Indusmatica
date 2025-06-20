
/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 26 de mayo de 2025, 12:42 PM
 */

#include <iostream>

using namespace std;

int cuentaceros(int *arr,int ini,int fin,int cont){
    
    if(ini>fin) return cont;
    int med = (ini+fin)/2;
    
    if(arr[med]==0)
        //izquierda
        return cuentaceros(arr,ini,med-1,cont+fin-med+1);
    else
        //derecha
        return cuentaceros(arr,med+1,fin,cont);
    
}


//{1,1,1,1,0,0,0};
// 0 1 2 3 4 5 6
int main(int argc, char** argv) {
    int arr[]={1,1,1,1,0,0,0};
    int n=7;
    
    cout << cuentaceros(arr,0,n-1,0);

    return 0;
}

