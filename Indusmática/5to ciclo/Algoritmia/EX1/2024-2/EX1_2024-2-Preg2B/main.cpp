/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 12:43
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "funcionesCola.h"
#include "Elemento.h"

using namespace std;

/*
 * Se usará colas para resolver el problema
 */

void sistemaCajero(Cola &cola, int cantClientes){
    Elemento cliente, atendiendo;
    int seg = 0; //Los segundos
    int anteriorAtencion = 0;
    int vipAtendidos = 0, vipNoAtendidos = 0;
    bool esVip = false;
    while(true){
        
        if(cantClientes == 0 and esColaVacia(cola)) break;
        
        if(seg % 15 == 0 and seg != 0 and cantClientes != 0){//Llega un cliente
            cliente.ingreso = seg;
            if(esVip){
                cliente.tipo = 1;
                esVip = false;
            }
            else{
                cliente.tipo = 0;
                esVip = true;
            }
            encolaPrioridad(cola, cliente);
            cantClientes--;
        }
        
        if(!esColaVacia(cola) and (anteriorAtencion + 20 <= seg or 
                anteriorAtencion == 0)){
            
            anteriorAtencion = seg;
            while(!esColaVacia(cola)){
                atendiendo = desencolar(cola);
                if(atendiendo.tipo == 1){//Si es vip
                    if(atendiendo.ingreso + 10 >= seg){
                        vipAtendidos++;
                        break;
                    } 
                    else vipNoAtendidos++;
                }
                else break;
            }
        }
        seg +=5;
    }
    
    cout << "RESULTADOS DE LA SIMULACIÓN DEL DESPACHO DE ENTRADAS" << endl;
    cout << "Cliente VIP atendidos: " << vipAtendidos << endl;
    cout << "Clientes VIP no atendidos: " << vipNoAtendidos << endl;
    
}

int main(int argc, char** argv) {
    
    Cola cola;
    
    construir(cola);
    
    sistemaCajero(cola, 50);

    return 0;
}

