/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define MAX_CAR_LINEA 150

void lecturaDeProductos(const char* nomArch, char ***&productos, int *&stock, double *&precios){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    char ***buffProd = new char**[200]{}, *cod, *nombre;
    double precio, buffPrecio[200]{};
    int numDat=0, sto, buffStock[200]{};
    while(true){
        cod = leer_cadena(arch);
        if (arch.eof()) break;
        nombre = leer_cadena(arch);
        arch>>precio;
        arch.get();
        arch>>sto;
        arch.get();
        buffPrecio[numDat] = precio;
        buffStock[numDat] = sto;
        llenar_buffPRod(buffProd[numDat],cod,nombre);
        numDat++;
    }
    productos = new char**[numDat+1]{};
    stock = new int[numDat+1]{};
    precios = new double[numDat+1]{};
    for (int i = 0; i < numDat; i++) {
        productos[i] = buffProd[i];
        stock[i] = buffStock[i];
        precios[i] = buffPrecio[i];
    }
    delete buffProd;
}

void llenar_buffPRod(char **&buffProd, char *cod, char *nombre){
    buffProd = new char*[2]{};
    buffProd[0] = cod;
    buffProd[1] = nombre;
}

char* leer_cadena(ifstream &arch){
    char *cad, buffer[100];
    arch.getline(buffer,100,',');
    if (arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1]{};
    strcpy(cad,buffer);
    return cad;
}

void pruebaLecturaDeProductos(const char* nomArch, char ***productos, int *stock, double *precios){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<"Codigo"<<setw(15)<<"Nombre"<<setw(60)<<"Stock"<<setw(10)<<"Precio"<<endl;
    for (int i = 0; productos[i]; i++) {
        imprimir_prod(productos[i],arch);
        arch<<setw(10)<<stock[i]<<setw(10)<<precios[i]<<endl;
    }
}

void imprimir_prod(char **productos, ofstream &arch){
    arch<<productos[0]<<left<<"  "<<setw(60)<<productos[1]<<right;
}

void lecturaDePedidos(const char* nomArch, int *&fechaPedidos, char ***&CodigoPedidos, int ***&dniCantPedidos){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int numDat=0, buffFecha[300]{}, cant, fecha, dni, pos, nd[300]{},
            ***buffDniCant = new int**[300]{};
    char *cod, ***buffCodPed = new char**[300]{};
    while(true){
        cod = leer_cadena(arch);
        if (arch.eof()) break;
        arch>>dni;
        arch.get();
        arch>>cant;
        arch.get();
        fecha = leer_fecha(arch);
        pos = buscar_fecha(fecha,buffFecha,numDat);
        if (pos!=-1){
            colocar_cod(cod,buffCodPed[pos],nd[pos]);
            colocar_dni_cant(dni,cant,buffDniCant[pos],nd[pos]);
            nd[pos]++;
        }else{
            buffFecha[numDat] = fecha;
            buffCodPed[numDat] = new char*[50]{};
            buffDniCant[numDat] = new int*[50]{};
            colocar_cod(cod,buffCodPed[numDat],nd[numDat]);
            colocar_dni_cant(dni,cant,buffDniCant[numDat],nd[numDat]);
            nd[numDat]++;
            numDat++;
        }
    }
    fechaPedidos = new int[numDat+1]{};
    CodigoPedidos = new char**[numDat+1]{};
    dniCantPedidos = new int**[numDat+1]{};
    for (int i = 0; i < numDat; i++) {
        fechaPedidos[i] = buffFecha[i];
        exacto_dni_cant(dniCantPedidos[i],buffDniCant[i],nd[i]);
        exacto_pedidos(CodigoPedidos[i],buffCodPed[i],nd[i]);
        delete  buffCodPed[i];
        delete buffDniCant[i];
    }
    delete buffDniCant;
    delete buffCodPed;
}

void exacto_pedidos(char **&CodigoPedidos, char**&buffCodPed, int nd){
    CodigoPedidos = new char*[nd+1]{};
    for (int i = 0; i < nd; i++) {
        CodigoPedidos[i] = buffCodPed[i];
    }
}

void exacto_dni_cant(int **&dniCantPedidos, int **buffDniCant,int nd){
    dniCantPedidos = new int*[nd+1]{};
    for (int i = 0; i < nd; i++) {
        dniCantPedidos[i] = buffDniCant[i];
    }
}

void colocar_cod(char *cod, char **buffCodPed, int &nd){
    buffCodPed[nd] = cod;
}

void colocar_dni_cant(int dni,int cant,int **&buffDniCant, int &nd){
    buffDniCant[nd] = new int[2]{};
    coloc(buffDniCant[nd],dni,cant);
}

void coloc(int *&buffDniCant,int dni,int cant){
    buffDniCant[0] = dni;
    buffDniCant[1] = cant;
}

int buscar_fecha(int fecha, int *buffFecha,int numDat){
    for (int i = 0; i < numDat; i++)
        if (fecha==buffFecha[i]) return i;
    return -1;
}

int leer_fecha(ifstream &arch){
    int dd, mm, aa;
    arch>>dd;
    arch.get();
    arch>>mm;
    arch.get();
    arch>>aa;
    arch.get();
    return aa*10000 + mm*100 + dd;
}

void pruebaDeLecutraDePedidos(const char* nomArch, int *&fechaPedidos, char ***&CodigoPedidos, int ***&dniCantPedidos){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    for (int i = 0; fechaPedidos[i]; i++) {
        arch<<"Fecha: ";
        imprimir_fecha(arch,fechaPedidos[i]);
        arch<<"    | Pedidos: "<<endl<<"    CODIGO"<<setw(10)<<"DNI"<<setw(10)<<"CANT."<<endl;
        imprimir_pedidos(CodigoPedidos[i],dniCantPedidos[i],arch);
    }
}

void imprimir_pedidos(char **CodigoPedidos, int **dniCantPedidos, ofstream &arch){
    for (int i = 0; CodigoPedidos[i]; i++) {
        arch<<setw(12)<<CodigoPedidos[i];
        imprimir_dni_cant(arch,dniCantPedidos[i]);
        arch<<endl;
    }
}

void imprimir_dni_cant(ofstream &arch, int *dniCantPedidos){
    arch<<setw(10)<<dniCantPedidos[0]<<setw(6)<<dniCantPedidos[1];
}

void imprimir_fecha(ofstream &arch, int fechaPedidos){
    int dd, mm, aa;
    aa = fechaPedidos/10000;
    fechaPedidos %= 10000;
    mm = fechaPedidos/100;
    dd = fechaPedidos % 100;
    arch<<"FECHA: "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ')<<endl;
}

void reporteDeEnvioDePedidos(const char* nomArch, char ***productos,int *stock,
        double *precios, int *fechaPedidos, char ***CodigoPedidos, int ***dniCantPedidos){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<setw(100)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    imprimir_linea(arch,'=',MAX_CAR_LINEA);
    double totIngresado, totFaltaStock, TOTingre=0, TOTFalta=0;
    for (int i = 0; fechaPedidos[i]; i++) {
        totFaltaStock = 0;
        totIngresado = 0;
        imprimir_linea(arch,'=',MAX_CAR_LINEA);
        imprimir_fecha(arch,fechaPedidos[i]);
        imprimir_linea(arch,'=',MAX_CAR_LINEA);
        arch<<"No.   DNI"<<setw(40)<<"Producto"<<setw(30)<<"Cantidad"<<setw(12)<<
                "Precio"<<setw(40)<<"Total de Ingresos"<<endl;
        imprimir_linea(arch,'-',MAX_CAR_LINEA);
        imprimir_ped(dniCantPedidos[i],productos,stock,precios,CodigoPedidos[i],
                totFaltaStock, totIngresado,arch);
        imprimir_linea(arch,'-',MAX_CAR_LINEA);
        arch<<"Total ingresado: "<<totIngresado<<endl;
        arch<<"Total perdido por falta de stock: "<<totFaltaStock<<endl;
        TOTFalta += totFaltaStock;
        TOTingre += totIngresado;
    }
    imprimir_linea(arch,'=',MAX_CAR_LINEA);
    imprimir_linea(arch,'=',MAX_CAR_LINEA);
    arch<<"RESUMEN DE INGRESOS"<<endl;
    arch<<"Total de ingresos en el periodo: "<<TOTingre<<endl;
    arch<<"Total perdido por falta de stock: "<<TOTFalta<<endl;
    imprimir_linea(arch,'=',MAX_CAR_LINEA);
}

void imprimir_ped(int **dniCantPedidos, char ***productos, int *&stock, double *precios,
        char **CodigoPedidos, double &totFaltaStock, double &totIngresado, ofstream &arch){
    int pos;
    for (int i = 0; dniCantPedidos[i]; i++) {
        arch<<" "<<setfill('0')<<setw(2)<<i+1<<setfill(' ')<<")"<<setw(10);
        imprimir_dniOcant(dniCantPedidos[i],arch,0);
        arch<<setw(12)<<CodigoPedidos[i];
        pos = buscar_cod(CodigoPedidos[i],productos,arch);
        if (pos!=-1){
            imprimir_dniOcant(dniCantPedidos[i],arch,1);
            arch<<setw(10)<<precios[pos];
            stock[pos] -= cant(dniCantPedidos[i]);
            if (stock[pos]>0){
                arch<<setw(18)<<precios[pos]*cant(dniCantPedidos[i]);
                totIngresado += precios[pos]*cant(dniCantPedidos[i]);
            }
            else {
                arch<<setw(18)<<"SIN STOCK";
                totFaltaStock += precios[pos]*cant(dniCantPedidos[i]);
            }
        }
        arch<<endl;
    }
}

int cant(int *dniCantPedido){
    return dniCantPedido[1];
}

int buscar_cod(char *CodigoPedido, char ***productos, ofstream &arch){
    for (int i = 0; productos[i]; i++) {
        if(comparar(CodigoPedido,productos[i])){
            imprimir_nombre(productos[i],arch);
            return i;
        }
    }
    return -1;
}

void imprimir_nombre(char **productos, ofstream &arch){
    arch<<left<<"   "<<setw(60)<<productos[1]<<right;
}

bool comparar(char *CodigoPedido, char **producto){
    if (strcmp(CodigoPedido,producto[0])==0) return true;
    return false;
}

void imprimir_dniOcant(int *dniCantPedidos, ofstream &arch, int n){
    arch<<setw(12)<<dniCantPedidos[n];
}

void imprimir_linea(ofstream &arch,char c, int n){
    for (int i = 0; i < n; i++)
        arch.put(c);
    arch<<endl;
}
