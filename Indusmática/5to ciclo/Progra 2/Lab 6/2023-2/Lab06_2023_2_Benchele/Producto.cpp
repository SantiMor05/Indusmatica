/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Lenovo
 * 
 * Created on 3 de junio de 2025, 08:11 PM
 */

#include <iostream> 
#include <iomanip> 
#include <cstring>
#include "Producto.h"
#include "Pedido.h"
using namespace std;

Producto::Producto() {
    inicializa();
}

Producto::Producto(const Producto& orig) {
    inicializa();
    *this = orig;
}

Producto::~Producto() {
    elimina();
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(const char* desc) {
    if(descripcion != nullptr)delete descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}

void Producto::GetDescripcion(char *desc) const {
    if(descripcion == nullptr)desc[0] = 0;
    else strcpy(desc, descripcion);
}

void Producto::SetCodigo(const char* cod) {
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Producto::GetCodigo(char *cod) const {
    if(codigo == nullptr)cod[0] = 0;
    else strcpy(cod, codigo);
}


void Producto::inicializa(){
    codigo = nullptr;
    descripcion = nullptr;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}
void Producto::elimina(){
    if(codigo != nullptr)delete codigo;
    if(descripcion != nullptr)delete descripcion;
}

void Producto::operator =(const class Producto &orig){
    char aux[60];
    orig.GetCodigo(aux);
    SetCodigo(aux);
    orig.GetDescripcion(aux);
    SetDescripcion(aux);
    precio = orig.precio;
    stock = orig.stock;
    cantidad_clientes_servidos = orig.cantidad_clientes_servidos;
    cantidad_clientes_no_servidos = orig.cantidad_clientes_no_servidos;
    
    for (int i = 0; i < cantidad_clientes_servidos; i++) {
        clientes_servidos[i] = orig.clientes_servidos[i];
    }
    for (int i = 0; i < cantidad_clientes_no_servidos; i++) {
        clientes_no_servidos[i] = orig.clientes_no_servidos[i];
    }
}



/*
 BIT-434,Campana Extractora modelo Glass,375.09,10
 SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,3
 CODIGO DESCRIPCION PRECIO STOCK
 */
bool operator >>(ifstream &arch, class Producto &producto){
    char aux[100], c;
    double precio;
    int stock;
    arch.getline(aux, 10    , ',');
    if(arch.eof())return false;
    producto.SetCodigo(aux);
    arch.getline(aux, 100, ',');
    producto.SetDescripcion(aux);
    arch>>precio>>c>>stock;
    arch.get();
    producto.SetPrecio(precio);
    producto.SetStock(stock);
    return true;
}


bool Producto::operator +=(class Pedido &pedido){
    pedido.SetPrecio_producto(precio); 
    if(0 < stock){
        clientes_servidos[cantidad_clientes_servidos] = pedido.GetDni_cliente();
        cantidad_clientes_servidos++;
        stock--;
        return true;
    }
    else{
        clientes_no_servidos[cantidad_clientes_no_servidos] = pedido.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}

int *Producto::GetClientes_no_servidos(){
    return clientes_no_servidos;
}

int *Producto::GetClientes_servidos(){
    return clientes_servidos;
}

void operator <<(ofstream &arch, class Producto &producto){
    arch<<fixed<<setprecision(2);
    
    char cod[10], desc[60];
    
    producto.GetCodigo(cod);
    producto.GetDescripcion(desc);
    arch<<left<<setw(10)<<cod<<setw(60)<<desc<<right<<setw(12)<<producto.GetPrecio()
        <<setw(10)<<producto.GetStock()<<endl;
    
    arch<<endl;
    arch<<setw(7)<<" "<<left<<setw(24)<<"Clientes atendidos: ";
    if(producto.GetCantidad_clientes_servidos() != 0){
        int *servidos = producto.GetClientes_servidos();
        for (int i = 0; i < producto.GetCantidad_clientes_servidos(); i++) {
            arch<<left<<setw(10)<<servidos[i];
        }
    }
    else{
        arch<<"NO SE ATENDIERON PEDIDOS";
    }
    arch<<endl; 
    arch<<setw(7)<<" "<<left<<setw(24)<<"Clientes no atendidos: ";
    if(producto.GetCantidad_clientes_no_servidos() != 0){
        int *noServidos = producto.GetClientes_no_servidos();
        for (int i = 0; i < producto.GetCantidad_clientes_no_servidos(); i++) {
            arch<<left<<setw(10)<<noServidos[i];
        }
    }
    else{
        arch<<"NO HAY CLIENTES SIN ATENDER";
    }
}