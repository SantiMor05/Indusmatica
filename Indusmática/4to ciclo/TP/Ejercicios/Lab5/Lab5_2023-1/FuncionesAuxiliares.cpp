#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_PRUEBA 40

using namespace std;


void leerStock(int &cant_prod, int *cod_prod, int *codigo_almacen, int *stock, 
        const char *nombStock){
   
    ifstream archStock(nombStock, ios::in);
    if(not archStock.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombStock << endl;
        exit(1);
    }
    
    cant_prod = 0;
    while(true){
        archStock >> cod_prod[cant_prod];
        if(archStock.eof())break;
        
        archStock >> codigo_almacen[cant_prod] >> stock[cant_prod];
        cant_prod++;
    }
    
    
}

void probarDatos(int cant_prod, int *cod_prod, int *codigo_almacen, int *stock, 
        const char *nombPrueba){
    
    
    ofstream archPrueba(nombPrueba, ios::out);
    if(not archPrueba.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombPrueba << endl;
        exit(1);
    }
    
    archPrueba << "Codigo producto" << setw(15) << "Almacen" << setw(10) <<
            "Stock" << endl;
    imprimirCaracter('=', MAX_CAR_PRUEBA, archPrueba); 
    for(int i = 0; i < cant_prod; i++){
        archPrueba << setw(10) <<cod_prod[i] << setw(19) << codigo_almacen[i] << 
                setw(10) << stock[i] << endl;
    }
    
}

void pedirDatos(int &fecha_ini, int &fecha_fin){
    
    int dd, mm, aa;
    char car;
    
    while(true){
        
        cout << "Ingrese un rango de fechas: " << endl;
        cout << "Ingrese la fecha inicial (dd/mm/aa): ";
        cin >> dd >> car >> mm >> car >> aa;
        fecha_ini = aa * 10000 + mm * 100 + dd;
        
        cout << "Ingrese la fecha final (dd/mm/aa): ";
        cin >> dd >> car >> mm >> car >> aa;
        fecha_fin = aa * 10000 + mm * 100 + dd;
        
        if(fecha_ini > fecha_fin){
            cout << "Rango de fechas invalido" << endl;
        }
        
    }
    
}

void actualizarDatos(int fecha_ini, int fecha_fin,int *ingresos, int *salidas,
        int *enviado, int *recibido, int cant_prod, int *cod_prod, 
        int *codigo_almacen, const char *nombTransacciones){
    
    int almacen, dd,mm,aa, fecha, hora, producto, cantidad, destino, pos,
            pos_destino;
    char car, tipo;
    
    ifstream archTransacciones(nombTransacciones, ios::in);
    if(not archTransacciones.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombTransacciones <<
                endl;
        exit(1);
    }
    
    while(true){
        
        archTransacciones >> almacen;
        if(archTransacciones.eof())break;
        archTransacciones >> dd >> car >> mm >> car;
        fecha = dd * 10000 + mm * 100 + dd;
        if(fecha >= fecha_ini and fecha <= fecha_fin){
            while(archTransacciones.get() != '\n'){
                archTransacciones >> hora >> car >> hora >> car >> hora;
                archTransacciones >> producto >> cantidad >> tipo;
                
                pos = buscarPosicion(almacen, producto, cant_prod, cod_prod,
                        codigo_almacen);
                if(tipo == 'I'){
                    ingresos[pos] += cantidad;
                }
                else if (tipo == 'S'){
                    salidas[pos] += cantidad;
                }
                else if(tipo == 'T'){
                    enviado[pos] += cantidad;
                    archTransacciones >> destino;
                    pos_destino = buscarPosicion(destino, producto, cant_prod, 
                            cod_prod, codigo_almacen);
                    recibido[pos_destino] += cantidad;
                }
            } 
        }
        else{
            while(archTransacciones.get() != '\n');
        } 
    }
}


int buscarPosicion(int almacen, int producto, int cant_prod, int *cod_prod,
                        int *codigo_almacen){
    
    for(int i = 0; i < cant_prod; i++){
        if(cod_prod[i] == producto and codigo_almacen[i] == almacen) 
            return i;
    }
    return -1;
}

void imprimirCaracter(char car , int n, ofstream &archSalida){
    
    for(int i = 0; i < n; i++)
        archSalida.put(car);
    archSalida << endl;
    
}