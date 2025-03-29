#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "FuncionesAuxiliares.h"

#define MAX_CAR_PRUEBA 20
#define MAX_CAR 30

using namespace std;


void leerDatos(double *x,double *y, int &numDat, const char *nombreArch){
    
    int x1, y1;
    
    numDat = 0;
            
    ifstream archDatos(nombreArch, ios::in);
    
    if(not archDatos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombreArch << endl;
        exit(1);
    }
    
    while(true){
        
        archDatos >> x[numDat];
        if(archDatos.eof())break;
        archDatos >> y[numDat];
        
        numDat++;
        
    }
    
}


void probarDatos(double *x,double *y, int numDat, const char *nombReporte){
    
    ofstream archReporte(nombReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    archReporte << setw(6) << "X" << setw(10) << "Y" << endl;
    imprimirCaracter('=', MAX_CAR_PRUEBA,archReporte);
    
    archReporte << setprecision(2) << fixed;
    
    for (int i = 0; i < numDat; i++) {
        archReporte << setw(8) << x[i] << setw(10) << y[i] << endl;
    }

}

void imprimirCaracter(char car, int n, ofstream &archReporte){
    
    for(int i = 0; i < n; i++)
        archReporte.put(car);
    
    archReporte << endl;
    
}

void imprimirReporteFinal(double *x,double *y,int numDat, 
        const char *nombReporte){
    
    ofstream archReporte(nombReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    double area, perimetro;
    int lados;
    
    lados = numDat; //La cantidad de lados es igual a la de vertices
    
    calcularAreaYPerimetro(numDat, x, y, area, perimetro);
    
    archReporte << setw(6) << "X" << setw(10) << "Y" << endl;
    imprimirCaracter('=', MAX_CAR_PRUEBA,archReporte);
    
    
    archReporte << setprecision(2) << fixed;
     
    for (int i = 0; i < numDat; i++) {
        archReporte << setw(8) << x[i] << setw(10) << y[i] << endl;
    }
    
    imprimirCaracter('-', MAX_CAR_PRUEBA,archReporte);
    archReporte << "Area: " << area << endl;
    archReporte << "Perimetro: " << perimetro << endl;
    archReporte << "N° de lados: " << lados << endl;

}

void calcularAreaYPerimetro(int numDat, double *x, double *y, double &area, 
        double &perimetro){
    
    double s1, s2;
    int aux;
    s1 = s2 = 0;
    perimetro = 0;
    for (int i = 0; i < numDat; i++){
        if(i+1 == numDat) aux = 0;
        else aux = i + 1;
        
        s1 += x[aux] * y[i];
        
        s2 += x[i] * y[aux];
        
        perimetro += sqrt(pow(x[aux] - x[i], 2) + pow(y[aux] - y[i], 2));
    }
    
    
    area = (s1 - s2) / 2;
}