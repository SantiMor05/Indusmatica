#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 120
#define MAX_CAR_PRO 50
#define MAX_CAR_ALMA 35

using namespace std;


void procesarDatos(const char *nombProductos, const char *nombAlmacen, 
        const char *nombStock,const char *nombTransa, const char *nombReporte){
    
    
    ifstream archProductos(nombProductos, ios::in);
    if(not archProductos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombProductos << endl;
        exit(1);
    }
    
    ifstream archAlmacen(nombAlmacen, ios::in);
    if(not archAlmacen.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombAlmacen << endl;
        exit(1);
    }
    
    ifstream archStock(nombStock, ios::in);
    if(not archStock.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombStock << endl;
        exit(1);
    }
    
    ifstream archTransa(nombTransa, ios::in);
    if(not archTransa.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombTransa << endl;
        exit(1);
    }
    
    ofstream archReporte(nombReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    procesarInformacion(archAlmacen, archProductos, archStock, archTransa,
            archReporte);
    
}


void imprimirEncabezado(ofstream &archReporte){
    
    archReporte << setw(MAX_CAR / 2 + 23) << "DETALLE DE MOVIMIENTOS DE "
            "ALMACENES POR PRODUCTO" << endl;
    imprimirCaracter('=', archReporte);
    
}

void imprimirCaracter(char car, ofstream &archReporte){
    
    for(int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;    
}

void procesarInformacion(ifstream &archAlmacen, ifstream &archProductos, 
        ifstream &archStock, ifstream &archTransa, ofstream &archReporte){
    
    
    imprimirEncabezado(archReporte);
    int producto, suma, errores;
    while(true){
        suma = errores = 0;
        archProductos >> producto;
        if(archProductos.eof())break; 
        archReporte << "PRODUCTO: " << setw(8) << producto << " - ";
        leerImprimirTexto(')', MAX_CAR_PRO, archProductos, archReporte);  
        archReporte << endl;
        imprimirCaracter('=', archReporte);
        buscarImprimirStock(producto, suma, errores, archAlmacen, archStock, 
                archTransa, archReporte);
        archReporte << "STOCK FINAL DEL PRODUCTO EN TODOS LOS ALMACENES: " <<
                setw(12) << suma << setw(35) << "Errores en las transacciones" 
                << setw(3) << errores << endl; 
        imprimirCaracter('=', archReporte);
    }
}

void buscarImprimirStock(int producto, int &suma, int &errores, 
        ifstream &archAlmacen, ifstream &archStock, ifstream &archTransa,  
        ofstream &archReporte){
    
    int cod_prod, almacen, stock, operaciones, stockFinal;
    archStock.clear();
    archStock.seekg(0, ios::beg);
    
    while(true){
        archStock >> cod_prod;
        if(archStock.eof())break;
        if(producto == cod_prod){
            archStock >> almacen >> stock;
            buscarImprimirAlmacen(almacen,archAlmacen, archReporte);
            archReporte << setw(18) << "STOCK INICIAL:" << setw(8) <<
                    stock << endl;
            imprimirCaracter('-', archReporte);
            imprimirEncabezadoTransacciones(archReporte);
            buscarTransacciones(producto, almacen, operaciones, 
                    archTransa, archReporte);
            stockFinal = stock + operaciones;
            suma += stockFinal;
            imprimirStockFinal(stockFinal, errores, archReporte);
        }
        else 
            while(archStock.get()!= '\n');
    }
    
}

void imprimirStockFinal(int stockFinal, int &errores, ofstream &archReporte){
    
    archReporte << "STOCK FINAL :" << setw(10) << stockFinal;
    if(stockFinal < 0){
        archReporte << " (ERROR EN TRANSACCIONES)";
        errores++;
    }
        
    archReporte << endl;
    imprimirCaracter('=', archReporte);
    
}

void buscarTransacciones(int producto, int almacen, int &operaciones, 
        ifstream &archTransa, ofstream &archReporte){
    
    int dd,mm,aa, cod_alma, hh,min,seg,cod_prod, cant_prod, destino, opcion;
    int ingresos, salidas, enviados, recibidos;
    char tipo,car;
    
    archTransa.clear();
    archTransa.seekg(0, ios::beg);
    ingresos = salidas = enviados = recibidos = 0;
    while(true){
        
        archTransa >> cod_alma;
        if(archTransa.eof())break;
        archTransa >> dd >> car >> mm >> car >> aa;
        while(archTransa.get() != '\n'){
            archTransa >> hh >> car >> min >> car >> seg >> cod_prod >> 
                    cant_prod >> tipo;
            if(tipo == 'T'){
                archTransa >> destino;
            }
                
            if(cod_prod == producto and (almacen == cod_alma or  
                    almacen == destino)){
                imprimirFechaHora(dd,mm,aa,'/', archReporte);
                archReporte << setw(5) << " ";
                imprimirFechaHora(hh,min,seg,':', archReporte);
                archReporte << setw(12) << cant_prod << setw(8) << " ";
                imprimirTransaccion(tipo, destino, almacen, cod_alma,opcion,
                        archReporte);
                if(opcion == 1) ingresos += cant_prod;
                else if(opcion == 2) salidas += cant_prod;
                else if(opcion == 3) recibidos += cant_prod;
                else if(opcion == 4) enviados += cant_prod;
            }
        }
    }
    imprimirEstadisticasAlmacen(ingresos, salidas, recibidos, enviados, 
            archReporte);
    operaciones = ingresos - salidas - enviados + recibidos;
}


void imprimirEstadisticasAlmacen(int ingresos, int salidas, int recibidos, 
        int enviados, ofstream &archReporte){
    
    imprimirCaracter('-', archReporte);
    archReporte << "TOTAL DE INGRESOS DESDE EL PROVEEDOR: "  << setw(25) <<
            ingresos << endl;
    archReporte << "TOTAL DE SALIDAS HACIA EL CLIENTE: "  << setw(28) <<
            salidas << endl;;
    archReporte << "TOTAL DE TRANSFERENCIAS ENVIADAS A OTROS ALMACENES: "  
            << setw(11) << enviados << endl;;
    archReporte << "TOTAL DE TRANSFERENCIAS RECIBIDAS DESDE OTROS ALMACENES:"  
            << setw(7) << recibidos << endl;;
    imprimirCaracter('-', archReporte);
}

void imprimirTransaccion(char tipo, int destino, int almacen, int cod_alma,
        int &opcion, ofstream &archReporte){
    
    if(tipo == 'I'){
        archReporte << "Ingreso" << endl;
        opcion = 1;
    }
    else if(tipo == 'S'){
        archReporte << "Salida" << endl;
        opcion = 2;
    }
    else if(tipo == 'T'){
        if(destino == almacen){
            archReporte << "Transferencia desde otro almacen" << setw(8) << 
                      cod_alma << endl; 
            opcion = 3;
        }
        else{
            archReporte << "Transferencia a otro almacen" << setw(12) <<
                    destino << endl;
            opcion = 4;
        }   
    }
}

void imprimirFechaHora(int dd,int mm,int aa,char sep, ofstream &archReporte){
    
    archReporte << setfill('0') << setw(2) << dd << sep << setw(2) << mm <<
            sep << setw(2) << aa << setfill(' ');
    
}


void imprimirEncabezadoTransacciones(ofstream &archReporte){
    
    archReporte << "TRANSACCIONES" << endl;
    archReporte << "Fecha" << setw(16) << "Hora" << setw(16) << "Cantidad" <<
            setw(10) << "Tipo" << setw(37) << "Almacen" << endl;
    
}

void buscarImprimirAlmacen(int almacen, ifstream &archAlmacen, 
                    ofstream &archReporte){
    
    int distrito, cod_alma;
    
    archAlmacen.clear();
    archAlmacen.seekg(0, ios::beg);
    
    while(true){
        archAlmacen >> cod_alma;
        if(archAlmacen.eof())break;
        if(cod_alma == almacen){
            archReporte << "ALMACEN:" << setw(7) << almacen << " - ";
            leerImprimirTexto(' ', MAX_CAR_ALMA, archAlmacen,archReporte);
            archAlmacen >> distrito;
            archReporte << "DISTRITO:" << setw(7) << distrito;
            break;
        }
        else
            while(archAlmacen.get() != '\n');
    }
    
}

void leerImprimirTexto(char deli, int n, ifstream &archProductos, 
        ofstream &archReporte){
    
    
    int cont = 0;
    char car;
    archProductos >> ws;
    car = archProductos.get();
    if(car != '(') archReporte.put(car);
    
    while(true){
        car = archProductos.get();
        if(car == deli or car == '\n')break;
        if(car == '_') car = ' ';
        archReporte.put(car);
        cont++;
    }
    
    archReporte << setw(n - cont) << " ";
}