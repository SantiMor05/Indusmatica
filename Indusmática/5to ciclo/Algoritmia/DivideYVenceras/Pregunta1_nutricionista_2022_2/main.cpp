/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 20 de junio de 2025, 06:31 PM
 */

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

/*
 * 
 */

int posini, posfin;

void merge(int *arr, int ini, int med, int fin) {
    int l1 = med - ini + 1, l2 = fin - med, p1 = 0, p2 = 0;
    int A[l1 + 1], B[l2 + 1];
    for (int i = ini; i <= med; i++) A[i - ini] = arr[i];
    A[l1] = INT_MAX;
    for (int i = med + 1; i <= fin; i++) B[i - med - 1] = arr[i];
    B[l2] = INT_MAX;

    for (int i = ini; i <= fin; i++) {
        if (A[p1] > B[p2]) {
            arr[i] = B[p2];
            p2++;
        } else {
            arr[i] = A[p1];
            p1++;
        }
    }
}

void mergeSort(int *arr, int ini, int fin) {
    if (ini == fin)return;
    int med = (ini + fin) / 2;

    mergeSort(arr, ini, med);
    mergeSort(arr, med + 1, fin);
    merge(arr, ini, med, fin);

}

int calcularMenorValor(int *arr, int n) {
    int aux[n];
    for (int i = 0; i < n; i++) aux[i] = arr[i];
    mergeSort(aux, 0, n - 1);
    for (int i = 0; i < n; i++) cout << aux[i] << ' ';
    cout << endl;
    return aux[0];
}

int calcularCentro(int *arr, int ini, int med, int fin, int menorValor) {
    int contizq = 0, contder = 0;
    if (arr[med] != menorValor) return 0;
    for (int i = med; i > ini; i--) {
        if (arr[i] == arr[i - 1]) contizq++;
        else {
            posini = i + 1;
            break;
        }
    }

    for (int i = med; i < fin; i++) {
        if (arr[i] == arr[i + 1]) contder++;
        else {
            posfin = i + 1;
            break;
        }
    }

    return contder + contizq + 1;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int hallarDiasConsecutivos(int *arr, int ini, int fin, int menorValor, int &diaIni, int &diaFin) {
    if (ini == fin and ini == menorValor) return 1;
    else if (ini == fin)return 0;
    int med = (ini + fin) / 2, izq, der, centro;
    izq = hallarDiasConsecutivos(arr, ini, med, menorValor, diaIni, diaFin);
    der = hallarDiasConsecutivos(arr, med + 1, fin, menorValor, diaIni, diaFin);
    centro = calcularCentro(arr, ini, med, fin, menorValor);

    if (max(centro, max(izq, der)) == centro) {
        diaIni = posini;
        diaFin = posfin;
    }

    return max(centro, max(izq, der));

}

int main(int argc, char** argv) {
    int arr[] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93,
        94, 92, 91, 90, 88, 88, 88, 89, 90, 91,
        88, 88, 90, 90, 92, 89, 90, 88, 88, 88,
        88, 90, 91};
    int n = sizeof (arr) / sizeof (arr[0]);
    int menorValor = calcularMenorValor(arr, n), pos, diaIni, diaFin;
    cout << "El menor valor es: " << menorValor << endl;

    int rango = hallarDiasConsecutivos(arr, 0, n - 1, menorValor, diaIni, diaFin);
    cout << "El rango es : " << rango << " de los dias de " << diaIni << " y "
            << diaFin << endl;
    return 0;
}

