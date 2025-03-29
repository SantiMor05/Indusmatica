#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_PRUEBA 40
#define MAX_CAR 155
using namespace std;

void leerStock(int &cant_prods, int *almacen, int *producto, int *stock,
        const char *nombStock) {

    ifstream archStock(nombStock, ios::in);
    if (not archStock.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombStock << endl;
        exit(1);
    }
    cant_prods = 0;
    while (true) {
        archStock >> producto[cant_prods];
        if (archStock.eof())break;
        archStock >> almacen[cant_prods] >> stock[cant_prods];
        cant_prods++;
    }
}

void probarDatos(int cant_prods, int *almacen, int *producto, int *stock,
        const char *nombPrueba) {

    ofstream archPrueba(nombPrueba, ios::out);
    if (not archPrueba.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombPrueba << endl;
        exit(1);
    }

    archPrueba << "Producto" << setw(12) << "Almacen" << setw(12) << "Stock" <<
            endl;

    imprimirCaracter('=', MAX_CAR_PRUEBA, archPrueba);

    for (int i = 0; i < cant_prods; i++) {
        archPrueba << producto[i] << setw(13) << almacen[i] << setw(13) <<
                stock[i] << endl;
    }
}

void calcularStockFinal(int cant_prods, int *salidas, int *ingresos, 
        int *enviados, int *recibidos, int *stock_final, int *stock){
    
    for(int  i = 0; i < cant_prods; i++){
        stock_final[i] = stock[i] + ingresos[i] + recibidos[i] - salidas[i] -
                enviados[i];
    }
    
}

void ordenar(int cant_prods, int *almacen, int *producto, int *stock, 
        int *salidas, int *ingresos,int *enviados, int *recibidos, 
        int *stock_final){
    
    
    for(int  i = 0; i < cant_prods; i++){
        for(int j = 0; j < cant_prods; j++){
            if(producto[i] < producto[j] or (producto[i] == producto[j] and
                    stock_final[i] > stock_final[j])){
                intercambiarInt(i,j,almacen);
                intercambiarInt(i,j,producto);
                intercambiarInt(i,j,stock);
                intercambiarInt(i,j,salidas);
                intercambiarInt(i,j,ingresos);
                intercambiarInt(i,j,enviados);
                intercambiarInt(i,j,recibidos);
                intercambiarInt(i,j,stock_final);
            }
        }
    }
    
}

void emitirReporte(int fecha_ini,int fecha_fin, int cant_prods, int *almacen, 
        int *producto, int *stock, int *salidas, int *ingresos,int *enviados, 
        int *recibidos, int *stock_final, const char *nombReporte){
    
    int cod_prod;
    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    imprimirEncabezado(fecha_ini,fecha_fin, archReporte);
    cod_prod = 1;
    for(int i = 0; i < cant_prods; i++){
        if(cod_prod != producto[i]){
            cod_prod = producto[i];
            imprimirEncabezadoProducto(cod_prod, archReporte);
        }
        archReporte << almacen[i] << setw(15) << stock[i] << setw(17) << 
                ingresos[i] << setw(14) << salidas[i] << setw(18) << 
                enviados[i] << setw(22) << recibidos[i] << setw(26) << 
                stock_final[i];
        if(stock_final[i] < 0){
            archReporte << setw(35) <<"Trans. Incorrectas";
        }
        archReporte << endl;
    }
}

void eliminar(int &cant_prods, int *almacen, int *producto, int *stock, 
        int *salidas, int *ingresos,int *enviados, int *recibidos, 
        int *stock_final){
    
    int minimo;
    cout << "Ingrese un stock final mínimo: ";
    cin >> minimo;
    
    for(int i = 0; i < cant_prods; i++){
        if(minimo >= stock_final[i]){
            for(int j = i; j < cant_prods - 1; j++){
                almacen[j] = almacen[j+1];
                producto[j] = producto[j+1];
                stock[j] = stock[j+1];
                salidas[j] = salidas[j+1];
                ingresos[j] = ingresos[j+1];
                enviados[j] = enviados[j+1];
                recibidos[j] = recibidos[j+1];
                stock_final[j] = stock_final[j+1];
            }
            cant_prods--;
            i--;
        }
    }
    
}

void imprimirEncabezadoProducto(int cod_prod, ofstream &archReporte){
    
    imprimirCaracter('=', MAX_CAR, archReporte);
    archReporte << "PRODUCTO: " << setw(8) << cod_prod << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
    archReporte << "ALMACEN" << setw(18) << "STOCK INICIAL" << setw(15) <<
            "INGRESOS" << setw(15)<< "SALIDAS" << setw(25) << "ENVIADOS A"
            " OTRO ALM." << setw(20) << "RECIBIDOS DE ALM." << setw(20) <<
            "STOCK FINAL" << setw(20) << "OBSERVACION" << endl;
     imprimirCaracter('-', MAX_CAR, archReporte);
}

void imprimirEncabezado(int fecha_ini, int fecha_fin, ofstream &archReporte){
    
    archReporte << setw(MAX_CAR / 2 + 17) << "CONSOLIDADO DE STOCKS POR "
            "PRODUCTO"  << endl;
    int dd, mm, aa;
    descalcularFecha(dd,mm,aa,fecha_ini);
    archReporte << setw(MAX_CAR / 2 - 10) << "DEL " << setfill('0') << setw(2) << dd
            << "/" << setw(2) << mm << "/" << aa << " AL ";
    descalcularFecha(dd,mm,aa,fecha_fin);
    archReporte << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << endl
            << setfill(' ');
    //imprimirCaracter('=', MAX_CAR, archReporte);
}


void descalcularFecha(int &dd,int &mm,int &aa,int fecha){
    
    dd = fecha % 100;
    fecha /= 100;
    mm = fecha % 100;
    aa = fecha / 100;
    
}

void intercambiarInt(int i,int j,int *arr){
    
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void actualizarDatos(int fecha_ini, int fecha_fin, int cant_prods, int *almacen,
        int *producto, int *stock, int *salidas, int *ingresos, int *enviados,
        int *recibidos, const char *nombTransa) {

    int cod_alma, dd, mm, aa, fecha, cod_prod, cant_prod, destino, pos,
            pos_dest;
    char car, tipo;

    ifstream archTransa(nombTransa, ios::in);
    if (not archTransa.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombTransa << endl;
        exit(1);
    }
    //10007   30/09/2022   9:03:33   33947   198   I   10:26:56   18683   66   I 
    while (true) {

        archTransa >> cod_alma;
        if (archTransa.eof())break;
        archTransa >> dd >> car >> mm >> car >>aa;
        fecha = calcularFecha(dd, mm, aa);
        if (fecha >= fecha_ini and fecha <= fecha_fin) {
            while (archTransa.get() != '\n') {
                saltarTexto(' ', archTransa);
                archTransa >> cod_prod >> cant_prod >> tipo;
                pos = buscarPosicion(cod_alma, cod_prod, cant_prods, almacen,
                            producto);
                if(tipo == 'S'){
                    salidas[pos] += cant_prod;
                }
                else if(tipo == 'I'){
                    ingresos[pos] += cant_prod;
                }
                if (tipo == 'T') {
                    archTransa >> destino;
                    enviados[pos] += cant_prod;
                    pos_dest = buscarPosicion(destino, cod_prod, cant_prods, almacen,
                            producto);
                    recibidos[pos_dest] += cant_prod;
                } 
            }

        } else
            while (archTransa.get() != '\n');
    }

}

int buscarPosicion(int cod_alma, int cod_prod, int cant_prods, int *almacen,
        int *producto) {

    for(int i = 0; i < cant_prods; i++){
        if(cod_alma == almacen[i] and cod_prod == producto[i])
            return i;
    }
    return -1;
}

void saltarTexto(char deli, ifstream &archTransa) {

    char car;
    archTransa >> ws;
    while (true) {
        car = archTransa.get();
        if (car == deli)break;
    }

}

void solicitarFechas(int &fecha_ini, int &fecha_fin) {

    int dd, mm, aa;
    char car;

    while (true) {
        cout << "Ingrese un rango de fechas" << endl;
        cout << "Ingrese la fecha inicial (dd/mm/aaaa): ";
        cin >> dd >> car >> mm >> car >> aa;

        fecha_ini = calcularFecha(dd, mm, aa);

        cout << "Ingrese la fecha final (dd/mm/aaaa): ";
        cin >> dd >> car >> mm >> car >> aa;

        fecha_fin = calcularFecha(dd, mm, aa);
        if (fecha_fin > fecha_ini) break;
    }


}

int calcularFecha(int dd, int mm, int aa) {

    return dd + mm * 100 + aa * 10000;

}

void imprimirCaracter(char car, int n, ofstream &archSalida) {

    for (int i = 0; i < n; i++) {
        archSalida.put(car);
    }
    archSalida << endl;
}