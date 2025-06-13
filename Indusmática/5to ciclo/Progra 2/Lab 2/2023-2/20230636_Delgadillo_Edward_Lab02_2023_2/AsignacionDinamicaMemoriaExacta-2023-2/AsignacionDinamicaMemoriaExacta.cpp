/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AsignacionDinamicaMemoriaExacta.h"

using namespace std;
#define LINEA 120

void lecturaDeProductos(const char*nombArch,
        char***&productos,int*&stock,double*&precios){
    
    ifstream arch(nombArch,ios::in);
    apertura(arch.is_open(),nombArch);
    
    int nd=0,bufStock[200]{};
    char**bufPro[200]{};
    double bufPrecio[200]{};
    while(true){
        bufPro[nd]=leerProducto(arch);
        if(arch.eof())break;
        arch>>bufPrecio[nd];
        arch.get();
        arch>>bufStock[nd++];
        arch.get();
    }
    nd++;
    pasarInfo(productos,stock,precios,bufPro,bufStock,bufPrecio,nd);
}

void apertura(bool abierto,const char*nombArch){
    
    if(not abierto){
        cout<<"Error en "<<nombArch; exit(1);
    }
}

char**leerProducto(ifstream &arch){
    
    char*codigo;
    codigo=leerCadena(arch,',');
    if(arch.eof())return nullptr;
    char**producto=new char*[2]{};
    producto[0]=codigo;
    producto[1]=leerCadena(arch,',');
    return producto;
}

char*leerCadena(ifstream &arch,char deli){
    
    char aux[100],*p;
    arch.getline(aux,100,deli);
    if(arch.eof())return nullptr;
    p=new char[strlen(aux)+1];
    strcpy(p,aux);
    return p;
}
    
void pasarInfo(char***&productos,int*&stock,double*&precios,
            char***bufPro,int*bufStock,double*bufPrecio,int nd){
    
    productos=new char**[nd]{};
    stock=new int[nd]{};
    precios=new double[nd]{};
    for (int i = 0; i < nd; i++) {
        productos[i]=bufPro[i];
        stock[i]=bufStock[i];
        precios[i]=bufPrecio[i];
    }
    stock[nd-1]=-1;
    precios[nd-1]=-1;    
}

//BIT-434,Campana Extractora modelo Glass,375.09,10

void pruebaDeLecturaDeProductos(const char*nombArch,
        char***productos,int*stock,double*precios){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);
    arch.precision(2);
    arch<<fixed;
    arch<<"Codigo   "<<left<<setw(60)<<"Titulo"<<"  "<<"Stock"<<"  "<<"  Precio"<<
            endl;
    for (int i = 0; productos[i]; i++) {
        imprimirProducto(arch,productos[i],stock[i],precios[i]);
    }
}

void imprimirProducto(ofstream &arch,char**producto,int stock,double precio){
    
    arch<<producto[0]<<"  "<<left<<setw(60)<<producto[1]<<"  "<<right<<setw(5)<<
            stock<<"  "<<setw(8)<<precio<<endl;
}

    //JXD-139,50375303,6,24/08/2023

void lecturaDePedidos(const char*nombArch,
        int*&fechaPedidos,char***&codigoPedidos,int***&dniCantPedidos){
    
    ifstream arch(nombArch,ios::in);
    apertura(arch.is_open(),nombArch);
    
    int bufFechaPed[300]{},**bufDniCantPed[300]{},numFechas=0;
    char **bufCodPed[300]{};
    char codigo[8],c;
    int fecha,dni,cant,dd,mm,aa,pos,numCodigosEnFechas[300]{},
            numClientesEnFechas[300]{};
    while(true){
        arch.getline(codigo,10,',');
        if(arch.eof())break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        arch.get();
        fecha=aa*10000+mm*100+dd;
        pos=buscarFecha(bufFechaPed,fecha);
        if(pos!=-1){
            agregarCodigo(bufCodPed[pos],numCodigosEnFechas[pos]++,codigo);
            agregarCliente(bufDniCantPed[pos],numClientesEnFechas[pos]++,dni,cant);
        }
        else{
            crearFecha(fecha,bufFechaPed[numFechas],bufCodPed[numFechas],
                    bufDniCantPed[numFechas]);
            
            agregarCodigo(bufCodPed[numFechas],numCodigosEnFechas[numFechas]++,
                    codigo);
            agregarCliente(bufDniCantPed[numFechas],numClientesEnFechas[numFechas]++,
                    dni,cant);
            numFechas++;
        }
    }
    numFechas++;
//    for (int i = 0; bufCodPed[i]; i++) {
//        for (int j = 0; j < numCodigosEnFechas[i]; j++) {
//            cout<<bufCodPed[i][j]<<endl;
//        }
//        cout<<endl<<endl;
//    }

    
    hacerExacto(bufCodPed,numCodigosEnFechas,bufDniCantPed,numClientesEnFechas);
    brindarInfo(fechaPedidos,codigoPedidos,dniCantPedidos,
            bufFechaPed,bufCodPed,bufDniCantPed,numFechas);
}

void brindarInfo(int*&fechaPedidos,char***&codigoPedidos,int***&dniCantPedidos,
            int*bufFechaPed,char***bufCodPed,int***bufDniCantPed,int nd){
    
    fechaPedidos=new int[nd]{};
    codigoPedidos=new char**[nd]{};
    dniCantPedidos=new int**[nd]{};
    
    for (int i = 0; i < nd; i++) {
        fechaPedidos[i]=bufFechaPed[i];
        codigoPedidos[i]=bufCodPed[i];
        dniCantPedidos[i]=bufDniCantPed[i];
    }
}

void hacerExacto(char***bufCodPed,int*numCodigosEnFechas,
        int***bufDniCantPed,int*numClientesEnFechas){
    
    for (int i = 0; bufCodPed[i]; i++) {
//        cout<<bufCodPed[i][0]<<endl;
        ajustarCodigos(bufCodPed[i],numCodigosEnFechas[i]);
    }
    for (int i = 0; bufDniCantPed[i]; i++) {
//        cout<<bufDniCantPed[i][0][0]<<endl;
        ajustarClientes(bufDniCantPed[i],numClientesEnFechas[i]);
    }
}

void ajustarCodigos(char**&codigos,int nd){
    
    char**nuevo=new char*[nd+1]{};
    for (int i = 0; i <nd; i++) {
        nuevo[i]=codigos[i];
    }
    delete codigos;
    codigos=nuevo;
}

void ajustarClientes(int**&clientes,int nd){
    
    int**nuevo=new int*[nd+1]{};
    for (int i = 0; i <nd; i++) {
        nuevo[i]=clientes[i];
    }
    delete clientes;
    clientes=nuevo;
}


void crearFecha(int fechaRefe,int&fecha,char**&codigos,int**&clientes){
    
    fecha=fechaRefe;
    codigos=new char*[100]{};
    clientes=new int*[100]{};
}            


int buscarFecha(int*bufFechaPed,int fecha){
    
    for (int i = 0; bufFechaPed[i]; i++) {
        if(fecha==bufFechaPed[i])return i;
    }
    return -1;
}

void agregarCodigo(char**codigos,int pos,const char*codigo){
    
    codigos[pos]=new char[8];
    strcpy(codigos[pos],codigo);
}
    
void agregarCliente(int**clientes,int pos,int dni,int cant){
    
    clientes[pos]=new int[2];
    completarCliente(clientes[pos],dni,cant);
}

void completarCliente(int*cliente,int dni,int cant){
    
    cliente[0]=dni;
    cliente[1]=cant;
}



    
void pruebaDeLecturaDePedidos(const char*nombArch,
        int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos){

    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);
    
    for (int i = 0; fechaPedidos[i]; i++) {
        imprimirInfoFecha(arch,fechaPedidos[i],codigoPedidos[i],dniCantPedidos[i]);
        arch<<endl;
    }
}

void imprimirInfoFecha(ofstream &arch,int fecha,char**codigos,int**clientes){
    
    arch<<"Fecha: "<<fecha<<endl;
    arch<<"Codigo   "<<"Cliente "<<"  "<<"Cantidad"<<endl;
    for (int i = 0; codigos[i]; i++) {
        arch<<codigos[i]<<"  ";
        imprimirCliente(arch,clientes[i]);
    }
}

void imprimirCliente(ofstream &arch,int*cliente){
    
    arch<<cliente[0]<<"    "<<setw(2)<<cliente[1]<<endl;
}


     
void reporteDeEnvioDePedidos(const char*nombArch,
        char***productos,int*stock,double*precios,
        int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);   
    arch.precision(2);
    arch<<fixed<<setw(LINEA/2)<<"REPORTE ENTREGA DE PEDIDOS"<<endl;
    for (int i = 0; fechaPedidos[i]; i++) {
        imprimirFecha(arch,fechaPedidos[i],codigoPedidos[i],dniCantPedidos[i],
                productos,stock,precios);
        imprimeLinea(arch,LINEA,'-');
        arch<<"--Clientes"<<endl;
        imprimirClientesEnFecha(arch,dniCantPedidos[i],codigoPedidos[i],
                productos,stock,precios);
    }
}

void imprimirClientesEnFecha(ofstream &arch,int**clientes,char**codigos,
        char***productos,int*stock,double*precios){
    
    int dni,j=0;
    arch<<"No.  "<<left<<setw(8)<<"DNI"<<"  "<<"Numero de citas  "<<
            "Total de gastos"<<endl;
    for (int i = 0; clientes[i]; i++) {
        dni=sacarDni(clientes[i]);
        if(dni){
            imprimirInfoCliente(arch,++j,dni,clientes,codigos,
                    productos,stock,precios);
        }
    }
}

int sacarDni(int*cliente){
    return cliente[0];
}

void imprimirInfoCliente(ofstream &arch,int num,int dniRefe,
        int**clientes,char**codigos,
        char***productos,int*stock,double*precios){
    
    arch<<right<<setw(2)<<num<<")  "<<setw(8)<<dniRefe<<"  ";
    
    int dni,veces=0,cant,posPro;
    double precio,totalGastos=0;
    char *codigo;
    for (int i = 0; clientes[i]; i++) {
        dni=sacarDni(clientes[i]);
        if(dni==dniRefe){
            veces++;
            cant=sacarCant(clientes[i]);
            cambiarDni(clientes[i],0);
            codigo=codigos[i];
            posPro=buscarProducto(productos,codigo);
            if(posPro!=-1){
                precio=precios[posPro];
                totalGastos+=precio*cant;
            }
        }
    }
    arch<<right<<setw(15)<<veces<<"  "<<setw(15)<<totalGastos<<endl;
}

int sacarCant(int*cliente){
    return cliente[1];
}

void cambiarDni(int*cliente,int nuevoDni){
    cliente[0]=nuevoDni;
}

void imprimirFecha(ofstream &arch,
        int fecha,char**codigos,int**clientes,
        char***productos,int*stock,double*precios){
    
    imprimeLinea(arch,LINEA,'=');
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<"FECHA: "<<setfill('0')<<right<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<
            aa<<setfill(' ')<<endl;
    imprimeLinea(arch,LINEA,'=');
    arch<<"No.  "<<left<<setw(8)<<"DNI"<<"  "<<setw(68)<<"Producto"<<"  "<<
            "Cantidad  "<<"Precio  "<<"Total de ingresos"<<endl;
    imprimeLinea(arch,LINEA,'-');
    double totalIngresado=0,totalPerdido=0;
    for (int i = 0; clientes[i]; i++) {
        imprimirPedido(arch,i,clientes[i],codigos[i],
                productos,stock,precios,
                totalIngresado,totalPerdido);
    }
    imprimeLinea(arch,LINEA,'-');
    imprimirTotales(arch,totalIngresado,totalPerdido);
    
}

void imprimeLinea(ofstream &arch,int n,char c){
    
    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}


void imprimirPedido(ofstream &arch,int i,int*cliente,char*codigo,
        char***productos,int*stock,double*precios,
        double &totalIngresado,double &totalPerdido){
    
    int pos=buscarProducto(productos,codigo);
    int cant;
    double precio,ingreso;
    char *titulo;
    if(pos!=-1){
        cant=cliente[1];
        precio=precios[pos];
        titulo=darTitulo(productos[pos]);
        ingreso=cant*precio;
        
        arch<<right<<setw(2)<<i+1<<")  "<<right<<setw(8)<<cliente[0]<<"  "<<
                codigo<<" "<<left<<setw(60)<<titulo;
        arch<<"  "<<right<<setw(8)<<cliente[1]<<"  "<<setw(8)<<precio<<"  ";
        
        if(verStock(stock[pos],cant)){
            arch<<right<<setw(13)<<ingreso<<endl;
            totalIngresado+=ingreso;
        }
        else{
            arch<<right<<setw(10)<<"SIN STOCK"<<endl;
            totalPerdido+=ingreso;
        }
    }
}

int buscarProducto(char***productos,char*codigo){
    
    for (int i = 0; productos[i]; i++) {
        if(iguales(productos[i],codigo))return i;
    }
    return -1;
}

bool iguales(char**producto,char*codigo){
    
    return strcmp(producto[0],codigo)==0;
}


char* darTitulo(char**producto){
    
    return producto[1];
}

bool verStock(int &stock,int cant){
    
    if(not stock)return false;
    if(stock>=cant){
        stock-=cant;
        return true;
    }
    return false;
}

void imprimirTotales(ofstream &arch,double totalIngresado,double totalPerdido){
    
    arch<<left<<setw(LINEA-15)<<"Total ingresado:"<<right<<setw(10)<<
            totalIngresado<<endl;
    arch<<left<<setw(LINEA-15)<<"Total perdido por falta de sotck:"<<
            right<<setw(10)<<totalPerdido<<endl;
}
