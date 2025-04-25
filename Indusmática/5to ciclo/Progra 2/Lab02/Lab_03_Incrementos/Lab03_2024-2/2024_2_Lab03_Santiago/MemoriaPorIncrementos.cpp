
#include "MemoriaPorIncrementos.hpp"
#include "ConjuntoDeRepartidores.hpp"
#include "AperturaDeArchivos.h"
#include "Comunes.hpp"
#include <cstring>
#include <iostream>
#include <iomanip>

#define INCREMENTOS 5

void cargar_estructuras(char ***&repartidores, int ***&clientes, 
        double ***&subtotales, char ***cadenas, int **enteros, double **reales) {

    ConjuntoDeRepartidores conjuntoRepartidores;
    cargar_conjunto_de_repartidores(conjuntoRepartidores,"repartidores.csv");
    int numDat = 0, cap = 0, np[200]{}, capacidad[200]{};
    repartidores = nullptr;
    clientes = nullptr;
    subtotales = nullptr;
    int n = conjuntoRepartidores.cantidad, pos;
    Repartidor *auxRepar;
    char **pedido, **repartidor, *cod, *nombre;
    for(int i = 0; i < n; i++){
        auxRepar = conjuntoRepartidores.conjunto_de_datos;
        cod = auxRepar[i].codigo;
        nombre = conjuntoRepartidores == cod;
        if(numDat == cap)
            incrementarEspacios(repartidores, clientes, subtotales, numDat, cap);
        repartidores[numDat - 1] = new char *[2];
        repartidor = repartidores[numDat - 1];
        repartidor[0] = cod;
        repartidor[1] = nombre;
        pos = numDat - 1;
        //Buscamos el codigo del repartidor en la cadenas
        cargarPedido(clientes[pos],subtotales[pos], cadenas, enteros,reales,
                cod, np[pos], capacidad[pos]);
        
        numDat++;
    }
}


void cargarPedido(int **&clientes,double **&subtotales, char ***cadenas, 
        int **enteros,double **reales,char *cod, int &numDat, int &cap){
    char **pedido;
    int *pedidoDNi, pos;
    double *montoPedido;
    for(int i = 0; cadenas[i]; i++){
        pedido = cadenas[i];
        if(strcmp(pedido[0], cod) == 0){
            pedidoDNi = enteros[i];
            montoPedido = reales[i];
            
            if(numDat == cap)
                incrementarEspacios(clientes, subtotales, numDat, cap);
            pos = numDat - 1;
            cargarPedido(clientes[pos], subtotales[pos], pedidoDNi, 
                    montoPedido);
            
            numDat++;
        }
    }
    
}


void cargarPedido(int *&clientes, double *&subtotales, int *enteros, 
        double *reales){
        
    int dni = enteros[0];
    int *persona = new int;
    double monto = reales[0];
    double *auxMonto = new double{monto};
    *persona = dni;
    clientes = persona;
    subtotales= auxMonto;     
}

void incrementarEspacios(int **&clientes, double **&subtotales, int &numDat, 
        int &cap){
    
    cap += INCREMENTOS;
    if(clientes == nullptr){
        clientes = new int *[cap]{};
        subtotales = new double *[cap]{};
        numDat = 1;
    }
    else{
        int **auxClientes = new int *[cap]{};
        double **auxSubtotales = new double *[cap]{};
        for(int i = 0; i < numDat; i++){
            auxClientes[i] = clientes[i];
            auxSubtotales[i] = subtotales[i];
        }
        delete clientes;
        delete subtotales;
        clientes = auxClientes;
        subtotales = auxSubtotales;
    }
    
}

void incrementarEspacios(char ***&repartidores, int ***&clientes, 
        double ***&subtotales, int &numDat, int &cap){
    
    cap += INCREMENTOS;
    if(repartidores == nullptr){
        repartidores = new char **[cap]{};
        clientes = new int **[cap]{};
        subtotales = new double **[cap]{};
        numDat = 1;
    }
    else{
        char ***auxRepartidores = new char **[cap]{};
        int ***auxClientes = new int **[cap]{};
        double ***auxSubtotales = new double **[cap]{};
        for(int i = 0; i < numDat; i++){
            auxRepartidores[i] = repartidores[i];
            auxClientes[i] = clientes[i];
            auxSubtotales[i] = subtotales[i];
        }
        delete repartidores;
        delete clientes;
        delete subtotales;
        repartidores = auxRepartidores;
        clientes = auxClientes;
        subtotales = auxSubtotales;
    }
}

void reporte_de_repartidores(const char*nombre_archivo, char ***repartidores,
        int ***clientes, double ***subtotales) {
    ofstream arch;
    
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombre_archivo);
    
    arch << setprecision(2) << fixed;
    char **repartidor;
    for(int i = 0; repartidores[i]; i++){
        repartidor = repartidores[i];
        if(clientes[i] != nullptr)
            arch << repartidor[1] << "," << contarClientes(clientes[i]) << ","
                    <<sumarMonto(subtotales[i]) << endl;
        else
            arch << repartidor[1] << "," << 0 << "," << 0 << endl;
    }
    
}

int contarClientes(int **clientes){
   return obtener_cantidad_de_cliente(clientes);
}


double sumarMonto(double **subtotales){
    double *monto;
    double suma = 0;
    for(int i = 0; subtotales[i]; i++){
        monto = subtotales[i];
        suma += *monto;
    }
    return suma;
}

void reporte_por_repartidor(char ***repartidores, int ***clientes, double ***subtotales) {

    
    ofstream arch;
    char nombre[200];
    char **repartidor;
    for(int i = 0; repartidores[i]; i++){
        repartidor = repartidores[i];
        obtener_nombre_archivo_por_repartidor(nombre,repartidor[0]);
        AperturaDeUnArchivoDeTextosParaEscribir(arch, nombre);
        arch << setprecision(2) << fixed;
        imprimir_linea(arch, '=');
        arch << "CODIGO REPARTIDOR: " << repartidor[0] << endl;
        arch << "NOMBRE REPARTIDOR: " << repartidor[1] << endl;
        imprimir_linea(arch, '=');
        
        arch << setw(12) << "DNI CLIENTE" << setw(18) << "MONTO POR PEDIDO" <<
                endl;
        imprimir_linea(arch, '-');
        
        if(clientes[i] != nullptr){
            imprimirClientesMontos(arch, clientes[i], subtotales[i]);
        }
        imprimir_linea(arch, '=');
        arch.close();
    }
}


void imprimirClientesMontos(ofstream &arch, int **clientes, double **subtotales){
    int *dni;
    double *monto;
    for(int i = 0; clientes[i]; i++){
        dni = clientes[i];
        monto = subtotales[i];
        arch << setw(12) << *dni << setfill('.') << setw(16) << *monto <<
                setfill(' ') << endl;
    }
    
}