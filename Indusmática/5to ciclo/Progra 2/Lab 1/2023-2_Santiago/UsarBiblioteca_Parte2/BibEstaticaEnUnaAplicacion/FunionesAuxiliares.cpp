#include <iostream>
#include <iomanip>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "FuncionesAuxiliares.h"
#include "FuncionesSobrecargadas.h"


using namespace std;

#define MAX_CAR_CLI 140
#define MAX_CAR_PRO 90

void leerCliente(struct Cliente *clientes){
    
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes.csv");
    bool valor;
    int n = 0;
    
    while(true){
        valor = arch >> clientes[n];
        if(not valor) break;
        n++;
    }
    clientes[n].dni =0;
    
}

void leerProductoas(struct Producto *productos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Productos.csv");
    bool valor;
    int n = 0;
    
    while(true){
        valor = arch >> productos[n];
        if(not valor)break;
        n++;
    }
    strcpy(productos[n].codigo, "XXXXXXX");
}

void leerPedidos(struct Cliente *clientes, struct Producto *productos){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos.csv");
    bool valor;
    struct Pedido pedido;
    while(true){
        valor = arch >> pedido;
        if(not valor) break;
        else{
            valor = productos += pedido;
            if(valor)
                clientes += pedido;
        }
    }
}

void imprimirReporte(struct Cliente *clientes, struct Producto *productos){
    
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, "Reporte.txt");
    
    arch << "PRODUCTOS" << endl;
    imprimirCaracter('-', MAX_CAR_PRO, arch); 
    arch << "Codigo" << setw(15) << "Descripcion" << setw(56) << "Precio" <<
            setw(11) << "Stock" << endl;
    imprimirCaracter('=', MAX_CAR_PRO, arch); 
    
    for(int i = 0; strcmp(productos[i].codigo, "XXXXXXX") != 0; i++){
        arch << productos[i];
        arch << endl;
    }
    
    imprimirCaracter('=', MAX_CAR_CLI, arch); 
    arch << "CLIENTES" << endl;
    imprimirCaracter('-', MAX_CAR_CLI, arch);
    arch << "Dni" << setw(14) << "Nombre" << setw(43) << "Telefono" << setw(10)
            << "Monto" << endl;
    imprimirCaracter('=', MAX_CAR_CLI, arch); 
    for(int i = 0; clientes[i].dni != 0; i++)
        arch  << clientes[i];
    
}

void imprimirCaracter(char car, int n, ofstream &arch){
    
    for(int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
}