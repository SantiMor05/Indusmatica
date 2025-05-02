/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones_Auxiliares.cpp
 * Author: Lenovo
 * 
 * Created on 29 de abril de 2025, 07:46 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1
using namespace std;
//Indices
enum CLIENTE{DNI, NOM};
enum LIBRO{COD, NOML, AUT, PED, STK};
enum PEDPORLIB{dniPEd, nomPed};

//COmunes
char *leerCadenaExacta(ifstream &arch, char delimitador){
    char buff[100], *cad;
    arch.getline(buff, 100, delimitador);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}
//Cargar cliente

void cargaClientes(const char*nombArch, void *&cli){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    //Ejemplo
    //AperturaDeUnArchivoDeTextosParaLeer(arch, "NombreArchivo.csv");
    
    void **clientes;
    void *registro;
    void *buffClientes[100]{};
    int numDat = 0;
    while (true) {
        registro = leerRegistro(arch);
        if(arch.eof())break;
        buffClientes[numDat] = registro;
        numDat++;
    }
    clientes = new void*[numDat + 1]{};
    for (int i = 0; i < numDat; i++)clientes[i] = buffClientes[i];
    cli = clientes;
    muestraclientes(cli);
}
/*
  54393647,Reyes Tang Edward 
  67066631,Arca Amezquita Edric Ronald
  //DNI, NOMBRE
*/
void *leerRegistro(ifstream &arch){
    void **registro;
    int *dni, auxDni;
    char *nomb;
    arch>>auxDni;
    if(arch.eof())return nullptr;
    arch.get();
    dni = new int;
    *dni = auxDni;
    registro = new void*[2]{};
    registro[DNI] = dni;
    registro[NOM] = leerCadenaExacta(arch);
    return registro;
}
//Crear reserva
void crearReserva(const char*nombArch, void *&res){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    
    void *buffRes[300]{};
    void **reservas;
    void *registro;
    int numDat = 0;
    while (true) {
        registro = leerLibros(arch);
        if(arch.eof())break;
        buffRes[numDat] = registro;
        numDat++;
    }
    reservas = new void*[numDat + 1]{};
    for (int i = 0; i < numDat; i++)reservas[i] = buffRes[i];
    res = reservas;
    //muestrareservas(reservas);
    mostrarRservas("pruebareservas.txt", res);
}
/*
 IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
 YDK7687,El otonio del patriarca,Gabriel Garcia Marquez,60,82.02
 //CODIGO, NOMBRE, AUTOR, CANTIDAD, PRECIO
 */
void *leerLibros(ifstream &arch){
    void **libros;
    char *cod, *nombre, *autor, c;
    int *stock, auxStock;
    double auxPre; //No se usa
    
    cod = leerCadenaExacta(arch, ',');
    if(arch.eof())return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, ',');
    stock = new int;
    arch>>auxStock>>c>>auxPre; 
    arch.get();
    *stock = auxStock;
    
    //COD, NOML, AUT, PED, STK
    libros = new void*[5]{};
    libros[COD] = cod;
    libros[NOML] = nombre;
    libros[AUT] = autor;
    //Con la cantidad de stock tienes la cantidad de pedidos
    libros[PED] = crearMemoriaExactaStock(auxStock);
    libros[STK] = stock;
    return libros;
}
void *crearMemoriaExactaStock(int cantPed){
    void **registro = new void*[cantPed]{};
    return registro;
}

void mostrarRservas(const char*nombArch, void *res){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);
    arch<<fixed<<setprecision(2);
    void **reservas = (void **)res;
    for (int i = 0; reservas[i]; i++) {
        imprimirUnaReserva(arch, reservas[i]);
    }
}
void imprimirUnaReserva(ofstream &arch, void *res){
    //COD, NOML, AUT, PED, STK
    void **reserva = (void **)res;
    char *codigo = (char *)reserva[COD],
         *nombre = (char *)reserva[NOML],
         *autor = (char *)reserva[AUT];
    int *stock = (int *)reserva[STK];
    arch<<left<<setw(12)<<codigo<<setw(64)<<nombre
        <<setw(30)<<autor<<right<<setw(4)<<*stock<<endl;
}
//Cargar Reserva
/*
  69200503,ZQY9966
  14268463,BHD6079
  //DNI_CLI, COD_LIB
*/
void cargarReserva(const char*nombArch, void *cli, void *res){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    
    void **clientes = (void **)cli;
    void **reservas = (void **)res;
   
    int dniCli, posCli, posLib;
    char *codLib;
    int *stockActual;
    calcularStockActual(stockActual, reservas);

    while (true) {
        arch>>dniCli;
        if(arch.eof())break;
        arch.get();
        codLib = leerCadenaExacta(arch);
        posCli = buscarCliente(dniCli, clientes);
        posLib = buscarLibro(codLib, reservas);
        if(posCli != NO_ENCONTRADO and posLib != NO_ENCONTRADO){
            agregarPedido(clientes[posCli], reservas[posLib], stockActual[posLib]);
        }
    }
}

int buscarCliente(int dniCli, void **clientes){
    for (int i = 0; clientes[i]; i++) {
        if(sonIguales(dniCli, clientes[i]))return i;
    }
    return NO_ENCONTRADO;
}
int buscarLibro(char *codLib, void **reservas){
    for (int i = 0; reservas[i]; i++) {
        if(sonIguales(codLib, reservas[i]))return i;
    }
    return NO_ENCONTRADO;

}
bool sonIguales(int dniCli, void *cli){
    void **clientes = (void **)cli;
    int *dni = (int *)clientes[DNI];
    return dniCli == *dni;
}
bool sonIguales(char *codLib, void *res){
    void **reserva = (void **)res;
    char *cod = (char *)reserva[COD];
    return strcmp(cod, codLib) == 0;
}
void calcularStockActual(int *&stockActual, void **reservas){
    int numDat = 0;
    while (reservas[numDat])numDat++;
    stockActual = new int[numDat + 1]{};
    void **aux;
    for (int i = 0; reservas[i]; i++) {
        pasarStock(stockActual[i], reservas[i]);
    }
}
void pasarStock(int &stockActual, void *res){
    void **reserva = (void **)res;
    int *stock = (int *)reserva[STK];
    stockActual = *stock;
}
//DNI, NOM
//COD, NOML, AUT, PED, STK
void agregarPedido(void *cli, void *res, int &stockActual){
    void **cliente = (void **)cli, **reserva = (void **)res;
    void **pedido = (void **)reserva[PED];
    int *dniCLi = (int *)cliente[DNI];
    char *nombCLi = (char *)cliente[NOM];
    int numDat = 0;
    if(stockActual > 0){
        while (pedido[numDat])numDat++;
        actualizarPed(dniCLi, nombCLi, pedido[numDat]);
        stockActual--;
    }
}
void actualizarPed(int *dniCli, char *nombCLi, void *&pedido){
    //dniPEd, nomPed
    void **registroCLiente;
    registroCLiente = new void*[2]{};
    registroCLiente[dniPEd] = dniCli;
    registroCLiente[nomPed] = nombCLi;
    pedido = registroCLiente;
}