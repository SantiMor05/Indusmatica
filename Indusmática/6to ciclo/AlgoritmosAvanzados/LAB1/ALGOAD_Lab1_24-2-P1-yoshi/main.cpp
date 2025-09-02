#include <iostream>
#include <cmath>
using namespace std;//

bool probarDiferenciaK(int* arr,int pos,int n,int k,int numSolutions,int* solu) {
    int cont = 0;
    for (int i=0;i<n;i++) {
        if (solu[i] == numSolutions+1) {
            cont++;
            if (abs(arr[pos]-arr[i])<=k)
                return true;
        }
    }
    if (cont==0) return true;
    return false;
}

int entraCandidato(int* arr,int pos,int n,int p,int k,int numSolutions,int* solu) {
    if (solu[pos]!=0) return 0; //ya tiene dueño entonces no se podría considerar en una nueva sol.
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (solu[i]==numSolutions+1)
            suma += arr[i];
    }
    if (suma+arr[pos] <= p ) {
        if (probarDiferenciaK(arr,pos,n,k,numSolutions,solu)){
            solu[pos] = numSolutions+1;
            if (suma+arr[pos] == p) return 2;
            return 1;
        }
        return 0;
    }
    return 0;
}

int HoyVoyASalirABuscarTodoLoQueQuiero_VoyADerrumbarMiCasaYAEmpezarDeNuevo(int* solu,int numSolutions,int n) {
    int pos;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (solu[i]==numSolutions+1) {
            if (flag) {
                pos = i;
                flag = false;
            }
            solu[i]=0;
        }
    }
    return pos;
}

void MochilaMultiobjetivo(int* arr,int pos,int n,int p,int k,int &numSolutions, int* solu) {
    if (pos>n) return;
    int sas = entraCandidato(arr,pos,n,p,k,numSolutions,solu);
    if (pos==n-1) { //llegamos a la posición final
        if (sas==2) {
            numSolutions++;
            return;
        }
        else {
            int posCero = HoyVoyASalirABuscarTodoLoQueQuiero_VoyADerrumbarMiCasaYAEmpezarDeNuevo(solu,numSolutions,n);
            MochilaMultiobjetivo(arr,posCero+1,n,p,k,numSolutions,solu);
        }
    }else{
        if (sas>0) {
            if (sas==2)
                MochilaMultiobjetivo(arr,0,n,p,k,++numSolutions,solu); // a empezar de cero pero buscando nueva sol.
            else
                MochilaMultiobjetivo(arr,pos+1,n,p,k,numSolutions,solu);
        }else
            MochilaMultiobjetivo(arr,pos+1,n,p,k,numSolutions,solu);
    }
}

void imprimirSolucion(int* solu, int n) {
    for (int i=0; i<n; i++)
        cout << solu[i] << " ";
}

int main() {

    int arr[] = {2, 8, 9, 6, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p=15, k=3;
    int solu[n] = {0};
    int numSolutions = 0;

    MochilaMultiobjetivo(arr,0,n,p,k,numSolutions,solu);
    cout << "Numero de pedidos que se pueden atender con " << p << "kg: " << numSolutions << endl;
    if (numSolutions>0) {
        cout << "Peso de los cortes de cada pedido: ";
        imprimirSolucion(solu,n);
    }else
        cout << "No se encontro solucion";


    return 0;
}