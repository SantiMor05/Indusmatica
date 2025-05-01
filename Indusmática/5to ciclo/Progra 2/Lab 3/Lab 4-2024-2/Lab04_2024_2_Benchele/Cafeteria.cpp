/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones_Auxiliares.cpp
 * Author: Lenovo
 * 
 * Created on 30 de abril de 2025, 10:30 AM
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Cafeteria.h"
#include "enums.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define MAX_LINEA 120
using namespace std;

//COmunes

void verificar_Apertura_I(ifstream &arch, const char*nombArch){
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}
void verificar_Apertura_O(ofstream &arch, const char*nombArch){
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

char *leerCadenaExacta(ifstream &arch, char delimitador){
    char buffer[200], *cad;
    arch.getline(buffer, 200, delimitador);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void imprimir_Linea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}

void incrementarEspacios(void **&puntGenerico, int &numDat, int &cap){
    void **aux;
    cap += INCREMENTO;
    if(puntGenerico == nullptr){
        puntGenerico = new void*[cap]{};
        numDat = 1;
    }
    else{
        aux = new void*[cap]{};
        for (int i = 0; i < numDat; i++) aux[i] = puntGenerico[i];
        delete puntGenerico;
        puntGenerico = aux;
    }
}
//Carga inventario

void cargarInventario(const char*nombArch, void  *&inv){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    
    void **inventario = (void **)inv; //No es necesario igualar porque no tiene ni un valor
    void *registro;
    int numDat = 0, cap = 0;
    inventario = nullptr;
    while (true) {
        registro = leerRegistro(arch);
        if(arch.eof())break;
        if(numDat == cap)incrementarEspacios(inventario, numDat, cap);
        inventario[numDat - 1] = registro;
        numDat++;
    }
    inv = inventario;
    //imprimirInventario("Reporte.txt", inv);
}

void imprimirInventario(const char*nombArch, void *&inv){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    arch<<fixed<<setprecision(2);
    
    void **inventario = (void **)inv;
    arch<<"CODIGO    NOMBRE                                            CANT. D     CANT. R     U. MEDIDA "<<endl;
    for (int i = 0; inventario[i]; i++)imprimeUnInventario(arch, inventario[i]);
}

void imprimeUnInventario(ofstream &arch, void *inv){
    void **unInven = (void **)inv;
     //invCodigo, invNombre, invCantDisponible, invCantRequerida, invUnidadMedida
    char *cod = (char *)unInven[invCodigo],
         *nomb = (char *)unInven[invNombre],
         *med = (char *)unInven[invUnidadMedida];
    double *cantDis = (double *)unInven[invCantDisponible],
           *cantReq = (double *)unInven[invCantRequerida];
    arch<<left<<setw(10)<<cod<<setw(40)<<nomb<<setw(20)<<*cantDis
        <<setw(10)<<*cantReq<<left<<setw(8)<<med<<endl;
}

/*
 I001,Café Arábica,50,kg
 I002,Café Robusta,30,kg
 //codigo, nombre, cantidad, unidad de medida
 */
void *leerRegistro(ifstream &arch){
    void **reg;
    char *cod, *nomd, *uniMed, c;
    double *cant, *cantRe;
    cod = leerCadenaExacta(arch, ',');
    if(arch.eof())nullptr;
    nomd = leerCadenaExacta(arch, ',');
    cant = new double;
    arch>>*cant>>c;
    uniMed = leerCadenaExacta(arch);
    cantRe = new double;
    *cantRe = 0; //EL valor 0 se tiene que pasar como puntero
    reg = new void*[5]{};
    //invCodigo, invNombre, invCantDisponible, invCantRequerida, invUnidadMedida
    reg[invCodigo] = cod;
    reg[invNombre] = nomd;
    reg[invCantDisponible] = cant;
    reg[invCantRequerida] = cantRe;
    reg[invUnidadMedida] = uniMed;
    
    return reg;
}

//Carga menu

void cargarMenu(const char*nombArch, void *&men){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    void **menu = nullptr;
    void *registro;
    int numDat = 0, cap = 0;
    while (true) {
        registro = leerMenu(arch);
        if(arch.eof())break;
        if(numDat == cap)incrementarEspacios(menu, numDat, cap);
        menu[numDat - 1] = registro;
        numDat++;
    }
    men = menu;
}

/*
 B001,Espresso Doble,Un espresso intenso con una mezcla de Café Arábica y Robusta para un sabor equilibrado y fuerte,C,2.50,120
 Café Latte,Suave y cremoso elaborado con una mezcla de cafés y leche vaporizada para una textura delicada,C,3.20,150
 //Codigo, nombre, descripcion, tipoDeBebida, precio, cantidadVEn
*/
void *leerMenu(ifstream &arch){
    void *reg;
    char *cod, *nom, *des, *tipo, auxTip, c;
    double *pre;
    int *cantVenESt;
    bool *disp;
    cod = leerCadenaExacta(arch, ',');
    if(arch.eof())return nullptr;
    nom = leerCadenaExacta(arch, ',');
    des = leerCadenaExacta(arch, ',');
    tipo = new char;
    pre = new double;
    cantVenESt = new int;
    disp = new bool;
    *disp = true;
    arch>>*tipo>>c>>*pre>>c>>*cantVenESt;
    arch.get();
    
    reg = asignarValoresReg(cod, nom, des, tipo, disp, pre, cantVenESt);
    
    return reg;
}
void *asignarValoresReg(char *cod, char *nom, char *des, char *tipo, bool *disp, double *pre, int *cantVenESt){
    void **reg;
    //bebCodigo, bebNombre, bebDescripcion, bebTipo, bebDisponible, bebPrecio, bebCantVent, bebInsumoInv;
    reg = new void*[8]{};
    reg[bebCodigo] = cod;
    reg[bebNombre] = nom;
    reg[bebDescripcion] = des;
    reg[bebTipo] = tipo;
    reg[bebDisponible] = disp;
    reg[bebPrecio] = pre;
    reg[bebCantVent] = cantVenESt;
    return reg;
}
//Actualizar menu
/*
  B001,I001,10,g
  B001,I002,8,g
  //COdigoBeb, codigoInsu, cantidad, unidadDeMEdida
 */

void actualizarMenu(const char*nombArch, void *inv, void *men){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    void **inventario = (void **)inv, **menu = (void **)men;
    char codMenu[5];
    char codInv[5];
    int posMen, posInv;
    char uniMed, c;
    double cantidad;
    
    int numdat = 0;
    while (menu[numdat])numdat++;

    int nd[numdat]{}, cap[numdat]{};
    while (true) {
        arch.getline(codMenu, 5, ',');
        if(arch.eof())break;
        arch.getline(codInv, 5, ',');
        arch>>cantidad>>c>>uniMed;
        arch.get();
        posMen = buscarMenu(codMenu, menu);
        posInv = buscarInv(codInv, inventario);
        if(posMen != NO_ENCONTRADO and posInv != NO_ENCONTRADO){
            actualizarUnMenu(inventario[posInv], menu[posMen], cantidad, uniMed, 
                             nd[posMen], cap[posMen]);
        }
    }
}

int buscarMenu(char *codMenu, void **menu){
    for (int i = 0; menu[i]; i++) {
        if(sonIgualesMen(codMenu, menu[i]))return i;
    }
    return NO_ENCONTRADO;

}
int buscarInv(char *codInv, void **inventario){
    for (int i = 0; inventario[i]; i++) {
        if(sonIgualesInv(codInv, inventario[i]))return i;
    }
    return NO_ENCONTRADO;

}

bool sonIgualesMen(char *codMenu, void *men){
    void **menu = (void **)men;
    char *cod = (char *)menu[bebCodigo];
    return strcmp(cod, codMenu) == 0;
}
bool sonIgualesInv(char *codInv, void *inv){
    void **inventario = (void **)inv;
    char *cod = (char *)inventario[invCodigo];
    return strcmp(cod, codInv) == 0;
}

void actualizarUnMenu(void *inv, void *&men, double cantidad, char uniMed, int &nd, int &cap){
    void **inventario = (void **)inv, **menu = (void **)men;
    void **insumos = (void **)menu[bebInsumoInv];
    void *regInsumo;
    
    actualizarInventario(inventario, cantidad, uniMed, menu);
    
    regInsumo = actualizarInsumo(inventario, cantidad, uniMed, menu);
    
    if(nd == cap)incrementarEspacios(insumos, nd, cap);
    insumos[nd - 1] = regInsumo;
    nd++;
    
    menu[bebInsumoInv] = insumos;
}

void *actualizarInsumo(void **inventario, double cantidad, char uniMed, void **menu){
    void **regIns;
    int *cantVentEst = (int *)menu[bebCantVent];
    double *cantReq;
    cantReq = new double;
    *cantReq = (double)cantidad*(*cantVentEst);
    char *med;
    med = new char;
    *med = uniMed;
    //insCodigoInv, insCant, insUnidadMedida
    regIns = new void*[3]{};
    regIns[insCodigoInv] = inventario;
    regIns[insCant] = cantReq;
    regIns[insUnidadMedida] = med;
    return regIns;
}

void actualizarInventario(void **inventario, int cantidad, char uniMed, void **menu){
    //invCodigo, invNombre, invCantDisponible, invCantRequerida, invUnidadMedida
    double *cantDis = (double *)inventario[invCantDisponible],
           *cantReq = (double *)inventario[invCantRequerida];
    int *cantVenEst = (int *)menu[bebCantVent];
    bool *disp = (bool *)menu[bebDisponible];
    
    *cantReq = (double)cantidad*(*cantVenEst);
    if(uniMed == 'g'){
        *cantReq = ((double)cantidad*(*cantVenEst))/1000;
    }
    
    if(*cantDis > *cantReq){
        *cantDis -= *cantReq;
        *cantReq += *cantReq;
        *disp = true;
    }
    else{
        *cantReq += *cantReq;
        *disp = false;
    }
    
    inventario[invCantDisponible] = cantDis;
    inventario[invCantRequerida] = cantReq;
    menu[bebDisponible] = disp;
}

//Reporte

void reporteMenu(const char*nombArch, void *men){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    arch<<fixed<<setprecision(2);
    
    void **menu = (void **)men;
    imprimirEncabezado(arch);
    imprimir_Linea(arch, '-');
    for (int i = 0; menu[i]; i++) {
        imprimirUnMenu(arch, menu[i]);
        imprimir_Linea(arch, '-');
    }

}

void imprimirEncabezado(ofstream &arch){
    for (int i = 0; i < (MAX_LINEA+12)/2; i++)arch.put('=');
    arch<<"Menu del dia";
    for (int i = 0; i < MAX_LINEA/2; i++)arch.put('=');
    arch<<endl<<endl;
}

void imprimirUnMenu(ofstream &arch, void *men){
    //bebCodigo, bebNombre, bebDescripcion, bebTipo, bebDisponible, bebPrecio, bebCantVent, bebInsumoInv;
    void **menu = (void **)men;
    char*tipoMen = (char *)menu[bebTipo],
        *nombre = (char *)menu[bebNombre],
        *descripcion = (char *)menu[bebDescripcion];
    bool *disponible = (bool *)menu[bebDisponible];
    double *precio = (double *)menu[bebPrecio];
    
    switch(*tipoMen){
        case 'C':
            arch<<"Cafe: ";
            break;
        case 'T':
            arch<<"Te: ";
            break;
        case 'I':
            arch<<"Infusion: ";
            break;
        case 'H':
            arch<<"Chocolate: ";
            break;
    }
    
    arch<<nombre<<endl;
    arch<<descripcion<<endl;
    arch<<"Precio: S/."<<*precio<<endl;
    arch<<"Disponible: ";
    
    switch(*disponible){
        case true:
            arch<<"Si "<<endl;
            break;
        default:
            arch<<"NO "<<endl;
            break;
    }
}


