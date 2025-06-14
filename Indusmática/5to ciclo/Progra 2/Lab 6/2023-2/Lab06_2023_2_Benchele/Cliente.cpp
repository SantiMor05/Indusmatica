/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Lenovo
 * 
 * Created on 3 de junio de 2025, 08:11 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cliente.h"
using namespace std;

Cliente::Cliente() {
    inicializar();
}

Cliente::Cliente(const Cliente& orig) {
    inicializar();
    *this = orig;
}

Cliente::~Cliente() {
    if(nombre != nullptr)delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(const char* nomb) {
    if(nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if(nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

ProductoEntregado *Cliente::GetProductos_entregados(){
    return productos_entregados;
}

void Cliente::inicializar(){
    nombre = nullptr;
    cantidad_productos_entregados = 0;
    monto_total = 0.0;
}

void Cliente::operator =(const class Cliente &orig){
    char aux[60];
    orig.GetNombre(aux);
    SetNombre(aux);
    dni = orig.dni;
    telefono = orig.telefono;
    cantidad_productos_entregados = orig.cantidad_productos_entregados;
    monto_total = orig.monto_total;
    for (int i = 0; i < cantidad_productos_entregados; i++) {
        productos_entregados[i] = orig.productos_entregados[i];
    }
}

/*
 79464412,PORTUGAL RAFFO ALEXANDER,3902394
 16552775,YALLICO PAREDES LOURDES CARMELA,960176666
 DNI NOMBRE TELEFONO
 */
bool operator >>(ifstream &arch, class Cliente &cliente){
    char aux[100];
    int dni, tel;
    arch>>dni;
    if(arch.eof())return false;
    arch.get();
    cliente.SetDni(dni);
    arch.getline(aux, 100, ',');
    cliente.SetNombre(aux);
    arch>>tel;
    cliente.SetTelefono(tel);
    return true;
}


void Cliente::operator +=(class Pedido pedido){
    char cod[10];
    double precio;
    pedido.GetCodigo(cod);
    precio = pedido.GetPrecio_producto();
    productos_entregados[cantidad_productos_entregados].SetCodigo(cod);
    productos_entregados[cantidad_productos_entregados].SetPrecio(precio);
    cantidad_productos_entregados++;
    monto_total += precio;
}



void operator <<(ofstream &arch, class Cliente &cliente){
    arch<<fixed<<setprecision(2);
    
    char nombre[100], cod[100];
    
    cliente.GetNombre(nombre);
    arch<<cliente.GetDni()<<" "<<left<<setw(44)<<nombre<<right<<setw(12)<<cliente.GetTelefono()
        <<setw(12)<<cliente.GetMonto_total()<<setw(4)<<" ";
    arch<<left<<setw(22)<<"Productos entregados: ";
    
    if(cliente.GetCantidad_productos_entregados() == 0){
        arch<<"NO SE LE ENTREGARON PRODUCTOS";
    }
    else{
        class ProductoEntregado *pEntregado = cliente.GetProductos_entregados();
        for (int i = 0; i < cliente.GetCantidad_productos_entregados(); i++) {
            pEntregado[i].GetCodigo(cod);
            arch<<left<<setw(10)<<cod;
        }
    }
}