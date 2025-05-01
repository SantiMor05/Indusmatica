/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: alulab14
 * 
 * Created on 29 de abril de 2025, 03:03 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "cafeteria.h"
#include "pruebas.h"
using namespace std;

#define INCRE 5
#define LINEA 70

void cargarInventario(const char*nombArch, void*&inv){

    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch;exit(1);
    }
    int nd=0;
    void*bufInventario[buffer]{},**inventario;
    while(true){
        bufInventario[nd]=leeInsumo(arch);
        if(arch.eof())break;
        nd++;
    }
    nd++;
    pasarInfo(inventario,bufInventario,nd);
    inv=inventario;
}

void* leeInsumo(ifstream &arch){
    
    //    I001,Café Arábica,50,kg
    char *codigo;
    codigo=leeCadena(arch,',');
    if(arch.eof())return nullptr;
    
    char *nombre,*uniMed;
    double *cantDis=new double,*cantReque=new double(0);
    nombre=leeCadena(arch,',');
    arch>>*cantDis;
    arch.get();
    uniMed=leeCadena(arch,'\n');
    
    void**insumo=new void*[invNumCampos]{};
    insumo[invCodigo]=codigo;
    insumo[invNombre]=nombre;
    insumo[invCantDisponible]=cantDis;
    insumo[invCantRequerida]=cantReque;
    insumo[invUnidadMedida]=uniMed;
    return insumo;    
}

char* leeCadena(ifstream &arch,char deli){
    
    char aux[500],*p;
    arch.getline(aux,500,deli);
    if(arch.eof())return nullptr;
    p=new char[strlen(aux)+1];
    strcpy(p,aux);
    return p;
}
    
void pasarInfo(void**&inventario,void**bufInventario,int nd){
    
    inventario=new void*[nd]{};
    for (int i = 0; i < nd; i++) {
        inventario[i]=bufInventario[i];
    }
}

void cargarMenu(const char*nombArch, void*&mens){
    
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch;exit(1);
    }
    void**menus,*bufMenus[buffer]{};
    int nd=0;
    while(true){
        bufMenus[nd++]=leerMenu(arch);
        if(arch.eof())break;
    }
    pasarInfo(menus,bufMenus,nd);
    mens=menus;
}

void* leerMenu(ifstream &arch){
    
    //B012,Café Cold Brew,Café infusionado en frío con un sabor suave y menos ácido,C,3.50,95
    char*codigo,c;
    codigo=leeCadena(arch,',');
    if(arch.eof())return nullptr;
    char*nombre,*descrip,*tipo=new char;
    bool *disponible=new bool(true);
    double *precio=new double;
    int *cantVentEst=new int;
    
    nombre=leeCadena(arch,',');
    descrip=leeCadena(arch,',');
    arch>>*tipo>>c>>*precio>>c>>*cantVentEst;
    
    void**menu=new void*[bebNumCampos]{};
    menu[bebCodigo]=codigo;
    menu[bebNombre]=nombre;
    menu[bebDescripcion]=descrip;
    menu[bebTipo]=tipo;
    menu[bebDisponible]=disponible;
    menu[bebPrecio]=precio;
    menu[bebCantVent]=cantVentEst;
    return menu;
}
    
void actualizarMenu(const char*nombArch, void*ins,void*bebs){
    
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch;exit(1);
    }    
//    B001,I001,10,g
//    B001,I002,8,g
//    B002,I001,12,g
    char codBebida[5];
    void **insumos=(void**)ins,**bebidas=(void**)bebs;
    int pos;
    
    int cantBeb=0;
    while(bebidas[cantBeb++]);    
    int nd[cantBeb]{},capa[cantBeb]{};
    while(true){
        arch.getline(codBebida,5,',');
        if(arch.eof())break;
        pos=buscarBebida(codBebida,bebidas);
        if(pos!=-1){
            agregarInsumo(arch,bebidas[pos],nd[pos],capa[pos],insumos);
        }
        else while(arch.get()!='\n');
    }
}

int buscarBebida(const char*codBebida,void**bebidas){

    void**bebida;
    char *codigo;
    for (int i = 0; bebidas[i]; i++) {
        bebida=(void**)bebidas[i];
        codigo=(char*)bebida[bebCodigo];
        if(not strcmp(codigo,codBebida))return i;
    }
    return -1;
}   
    
void agregarInsumo(ifstream &arch,void*beb,int &nd,int &capa,void**ins){
    
//    B001,I001,10,g
//    B001,I002,8,g
//    B002,I001,12,g
    
    void**bebida=(void**)beb;
    void**insumos=(void**)ins;
    char*codInsumo,*uniMed;
    double*cantidad=new double;
    
    codInsumo=leeCadena(arch,',');
    arch>>*cantidad;
    arch.get();
    uniMed=leeCadena(arch,'\n');
    
    int posInsumo=buscarInsumo(insumos,codInsumo);
    if(posInsumo==-1)return;
    if(nd==capa)incrementar(bebida[bebInsumoInv],nd,capa);
    void**ingredientes=(void**)bebida[bebInsumoInv];    
    addInsumo(ingredientes[nd-1],insumos[posInsumo],cantidad,uniMed);
    nd++;
    
    int cantVentEst=*(int*)bebida[bebCantVent];
    
//    rara conversion double
    double resultado=((*cantidad)/1000)*(double)cantVentEst;
    bool *disponible;
    if(aumentarRequerido(insumos[posInsumo],resultado)){
        disponible=(bool*)bebida[bebDisponible];
        *disponible=false;
    }
}

int buscarInsumo(void**insumos,const char*codInsumo){
    
    void**insumo;
    char*codigo;
    for (int i = 0; insumos[i]; i++) {
        insumo=(void**)insumos[i];
        codigo=(char*)insumo[invCodigo];
        if(not strcmp(codigo,codigo))return i;
    }
    return -1;
}

bool aumentarRequerido(void*in,double resultado){
    
    void **insumo=(void**)in;
    double *cantReq=(double*)insumo[invCantRequerida];
    double *cantDis=(double*)insumo[invCantDisponible];
    (*cantReq)+=resultado;
    if((*cantReq) >(*cantDis))return true;
    return false;
}

void incrementar(void*&ins,int &nd,int &capa){
    
    void **insumos=(void**)ins;
    capa+=INCRE;
    if(not insumos){
        insumos=new void*[capa]{};
        nd=1;
    }
    else{
        void**aux=new void*[capa]{};
        for (int i = 0; i < nd; i++) {
            aux[i]=insumos[i];
        }
        delete insumos;
        insumos=aux;
    }
    ins=insumos;
}

void addInsumo(void*&ingre,void*insu,double*cantidad,
        const char*uniMed){
    
    void **ingrediente=new void*[3]{};
    void **insumo=(void**)insu;
    
    ingrediente[0]=insu;
    ingrediente[1]=cantidad;
    ingrediente[2]=(char*)uniMed;
}

void reporteMenu(const char*nombArch, void*bebs){
    
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch;exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    
    arch<<setfill('=')<<setw(LINEA/2)<<"Menu del dia"<<setw(LINEA/2)<<'='<<
            setfill(' ')<<endl;
    
    void**bebidas=(void**)bebs;
    for (int i = 0; bebidas[i]; i++) {
        imprimirBebida(arch,bebidas[i]);
    }
}

void imprimirBebida(ofstream &arch,void*beb){
    
    void**bebida=(void**)beb;
    bool*disponible=(bool*)bebida[bebDisponible];
    if(not *disponible)return;
    char *codigo,*nombre,*descripcion,*letratipo;
    const char*nombTipo;
    double *precio;
    
    letratipo=(char*)bebida[bebTipo];
    nombTipo=hallarNombre(letratipo);
    nombre=(char*)bebida[bebNombre];
    descripcion=(char*)bebida[bebDescripcion];
    precio=(double*)bebida[bebPrecio];
    arch<<nombTipo<<": "<<nombre<<endl;
    arch<<descripcion<<endl;
    arch<<"Precio: S/ "<<*precio<<endl;
    arch<<"Disponible: ";
    if(*disponible)arch<<"Si"<<endl;
    else arch<<"No"<<endl;
    imprimeLinea(arch,LINEA,'-');
}

const char*hallarNombre(char*letratipo){
    
    char letra=*letratipo,*nombre;
    if(letra=='C')return "Cafe";
    else if(letra=='T')return "Te";
    else if(letra=='I')return "Infusion";
    else return "Chocolate";
}

void imprimeLinea(ofstream &arch,int n,char c){
    
    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}
