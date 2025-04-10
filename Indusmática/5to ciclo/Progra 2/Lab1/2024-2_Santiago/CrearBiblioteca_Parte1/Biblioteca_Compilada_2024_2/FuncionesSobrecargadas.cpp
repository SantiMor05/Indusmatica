#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Estructuras.h"

using namespace std;



//Adicionales

void imprimirPlatos(ofstream &out, const struct PlatoSolicitado *platos,
        int n){
    
    for(int i = 0; i < n; i++){
        out << setw(5) << " " << " - " << platos[i].codigo << setw(8) <<
                platos[i].precio << setw(6) << platos[i].cantidad << setw(8) <<
                platos[i].precio * platos[i].cantidad << endl << endl;
    }
    
}
int buscarPlato(struct PlatoSolicitado *platosSolicitados, const char *codigo, 
        int n){

    for (int i = 0; i < n; i++)
        if (strcmp(platosSolicitados[i].codigo, codigo) == 0)
            return i;

    return -1;

}

int buscarRepartidor(struct Repartidor *arregloRepartidores, const char *codigo){

    for (int i = 0; strcmp(arregloRepartidores[i].codigo, "FIN") != 0; i++)
        if (strcmp(arregloRepartidores[i].codigo, codigo) == 0)
            return i;


    return -1;
}

int buscarClienteEnRapartidor(struct OrdenDeCompra *ordenesDeCompra,
        int dni, int n) {

    for (int i = 0; i < n; i++)
        if (ordenesDeCompra[i].dniDelCliente == dni)
            return i;
    return -1;
}



//LECTURA

void operator>>(ifstream &arch, struct Plato &plato) {
    char aux[30];

    arch.getline(plato.codigo, 7, ',');
    if (arch.eof())return;

    arch.getline(plato.nombre, 60, ',');
    arch >> plato.precio;
    arch.get();
    //Obviamos el tipo de plato
    arch.getline(aux, 30);

    plato.totalDePedidos = plato.totalRecaudado = 0;

}

void operator>>(ifstream &arch, struct Repartidor &repartidor) {

    arch.getline(repartidor.codigo, 7, ',');
    if (arch.eof())
        return;
    arch.getline(repartidor.nombre, 60, ',');
    arch.getline(repartidor.tipoDeVehiculo, 15);
    repartidor.pagoPorEntregas = repartidor.cantidadDeOrdenes = 0;

}

void operator>>(ifstream &arch, struct Pedido &pedido) {

    arch >> pedido.dniDelCliente >> pedido.codigoDelPlato >> pedido.cantidad
            >> pedido.codigoDelRepartidor >> pedido.distanciaARecorrer;

    pedido.precio = 0;

}



//Operaciones

bool operator<=(struct Pedido &pedido, struct Plato *arregloPlatos) {
    for (int i = 0; strcmp("FIN", arregloPlatos[i].codigo) != 0; i++) {
        if (strcmp(pedido.codigoDelPlato, arregloPlatos[i].codigo) == 0) {
            if(arregloPlatos[i].precio == 0)
                cout << pedido.codigoDelPlato << endl;
            pedido.precio = arregloPlatos[i].precio;
            arregloPlatos[i].totalDePedidos += pedido.cantidad;
            arregloPlatos[i].totalRecaudado += pedido.precio * pedido.cantidad;
            return true;
        }
    }
    cout << pedido.codigoDelPlato << " no se encuentra" << endl;
    return false;
}

void operator<=(struct Repartidor *arregloRepartidores, const struct Pedido &pedido) {
    int pos = buscarRepartidor(arregloRepartidores, pedido.codigoDelRepartidor);
    int posPlato, cantPlaSol;
    if (pos != -1) {
        int n = arregloRepartidores[pos].cantidadDeOrdenes;
        int posOrden =
                buscarClienteEnRapartidor(arregloRepartidores[pos].ordenesDeCompra,
                pedido.dniDelCliente, n);

        if (posOrden == -1) {//Debemos agregar al cliente en el arreglo
            posOrden = arregloRepartidores[pos].cantidadDeOrdenes;
            arregloRepartidores[pos].ordenesDeCompra[posOrden].dniDelCliente = pedido.dniDelCliente;
            arregloRepartidores[pos].ordenesDeCompra[posOrden].cantidadDePlatos = 0;
            arregloRepartidores[pos].ordenesDeCompra[posOrden].montoPorCobrar = 0;
            arregloRepartidores[pos].cantidadDeOrdenes++;
        }
        //Ya esta en el arreglo
        //Buscamos si ya se solicito el plato
        cantPlaSol = arregloRepartidores[pos].ordenesDeCompra[posOrden].cantidadDePlatos;
        posPlato =
                buscarPlato(arregloRepartidores[pos].ordenesDeCompra[posOrden].platosSolicitados,
                pedido.codigoDelPlato, cantPlaSol);
        if (posPlato == -1) {
            //Agregamos el plato a la orden
            posPlato = arregloRepartidores[pos].ordenesDeCompra[posOrden].cantidadDePlatos;
            arregloRepartidores[pos].ordenesDeCompra[posOrden].cantidadDePlatos++;
            strcpy(arregloRepartidores[pos].ordenesDeCompra[posOrden].platosSolicitados[posPlato].codigo,
                    pedido.codigoDelPlato);
            arregloRepartidores[pos].ordenesDeCompra[posOrden].platosSolicitados[posPlato].precio = pedido.precio;
            arregloRepartidores[pos].ordenesDeCompra[posOrden].platosSolicitados[posPlato].cantidad = 0; 

        }
        //El plato ya esta en la orden
        arregloRepartidores[pos].ordenesDeCompra[posOrden].distancia = pedido.distanciaARecorrer;
        arregloRepartidores[pos].ordenesDeCompra[posOrden].platosSolicitados[posPlato].cantidad += pedido.cantidad;
    }
}


void operator !(struct OrdenDeCompra &orden){
    
    double suma = 0;
    int n = orden.cantidadDePlatos;
    for(int i = 0; i < n; i++){
        suma += orden.platosSolicitados[i].cantidad *
                orden.platosSolicitados[i].precio;
    }
    
    orden.montoPorCobrar = suma;
    double distancia = orden.distancia;
    if(distancia < 8)
        orden.pagoPorEnvio = 10.5;
    else if(distancia < 12)
        orden.pagoPorEnvio = 14.80;
    else if(distancia < 20)
        orden.pagoPorEnvio = 23.60;
    else 
        orden.pagoPorEnvio = 31.70;
}

void operator !(struct Repartidor &repartidor){
    int n = repartidor.cantidadDeOrdenes;
    double suma = 0;
    
    for(int i = 0; i < n; i++)
        suma += repartidor.ordenesDeCompra[i].pagoPorEnvio;
    
    repartidor.pagoPorEntregas = suma;
}



//Impresion
void operator << (ofstream &out, const struct Plato &plato){
    
    out << left << setw(10) << plato.codigo << setw(55) << plato.nombre <<
            right << setw(8) << plato.precio << setw(8) << plato.totalDePedidos
            << setw(10) << plato.totalRecaudado << endl;
}

void operator << (ofstream &out, const struct Repartidor &repartidor){
    out << setprecision(2) << fixed <<endl;
    out << left << setw(10) << repartidor.codigo << setw(45) << repartidor.nombre
            << setw(12) << repartidor.tipoDeVehiculo << right << setw(10) <<
            repartidor.pagoPorEntregas << endl;
    out << "ORDENES ENTREGADAS: " << endl;
    
    int n = repartidor.cantidadDeOrdenes;
    for(int i = 0; i < n; i++){
        out << setw(5) << " " <<repartidor.ordenesDeCompra[i].dniDelCliente <<
                setw(8) << repartidor.ordenesDeCompra[i].distancia << setw(8)
                << repartidor.ordenesDeCompra[i].montoPorCobrar << setw(8) <<
                repartidor.ordenesDeCompra[i].pagoPorEnvio << endl;
        out << "Platos solicitados: " << endl;
        imprimirPlatos(out, repartidor.ordenesDeCompra[i].platosSolicitados,
                repartidor.ordenesDeCompra[i].cantidadDePlatos);
    }
}




