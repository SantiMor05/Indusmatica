#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "MetodoExactoDeMemoria.h"
#include "AperturaDeArchivos.h"
using namespace std;

#define INCREMENTOS 5
#define MAX_CAR_PRUEBA_LIBROS 80
#define NO_ENCONTRADO -1
#define MAX_CAR 120

void lecturaDeLibros(const char *nombArch, char ***&libros, int **&stock){
    
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    
    int numDat = 0, cap = 0, cant, *dato;
    double precio;
    char **libro, car;
    libros = nullptr;
    stock = nullptr;
    
    while(true){
        libro = leerLibro(arch);
        if(libro == nullptr)
            break;
        if(numDat == cap)
            incrementarEspacios(libros, stock, numDat, cap);
        libros[numDat - 1] = libro;
        arch >> cant >> car >> precio;
        arch.get(); //Leemos el salto de linea
        stock[numDat - 1] = new int[2]{};
        dato = stock[numDat - 1];
        dato[0] = cant;
        numDat++;
    }
    
}

char **leerLibro(ifstream &arch){
    
    char *cod, *nombre, *autor;
    
    cod = leerCadenaExacta(arch, ',');
    if(cod == nullptr)
        return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    autor = leerCadenaExacta(arch, ',');
    
    char **aux =new char *[3];
    aux[0] = cod;
    aux[1] = nombre;
    aux[2] = autor;
    return aux;
}


char *leerCadenaExacta(ifstream &arch, char deli){
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}

void incrementarEspacios(char ***&libros, int **&stock, int &numDat, int &cap){
    
    cap += INCREMENTOS;
    if(libros == nullptr){
        libros = new char **[cap]{};
        stock = new int *[cap]{};
        numDat = 1;
    }
    else{
        char *** auxLibros = new char **[cap]{};
        int **auxStock = new int *[cap]{};
        for(int i = 0; i < numDat; i++){
            auxLibros[i] = libros[i];
            auxStock[i] = stock[i];
        }
        
        delete libros;
        delete stock;
        libros = auxLibros;
        stock =auxStock;
    }
    
}

void pruebaDeLecturaDeLibros(const char *nombArch, char ***libros, int **stock){
    
    ofstream arch;
    
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);
    
    arch << "PRUEBA LIBROS" << endl;
    imprimirLinea(arch, MAX_CAR_PRUEBA_LIBROS, '=');
    arch << "Codigo" << setw(12) << "Nombre" << setw(60) << "Stock" << endl;
    imprimirLinea(arch, MAX_CAR_PRUEBA_LIBROS, '-');
    char **libro;
    int *dato;
    for(int i = 0; libros[i]; i++){
        libro = libros[i];
        dato = stock[i];
        arch << left << setw(12) << libro[0] << setw(60) << libro[1] << right <<
                setw(4) << dato[0] << endl;
    }
}

void imprimirLinea(ofstream &arch, int n, char car){
    for(int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
    
}


void atencionDePedidos(const char *nombArch, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos){
    
    ifstream arch;
    
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombArch);
    
    int numClientes = 0,capClientes = 0, numPedidos = 0, capPedidos = 0, pos;
    int ndPedCliente[200]{}, capPedCliente[200], pedido, dni, *cliente,
            numlibros[200]{}, caplibros[200]{};
    char codigo[10];
    pedidosAtendidos = nullptr;
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    
    while(true){
        arch >> pedido;
        if(arch.eof())break;
        arch.get();
        arch >> dni;
        pos = buscarCliente(dni,pedidosClientes);
        if(pos == NO_ENCONTRADO){
            if(numClientes == capClientes)
                aumentarEspaciosClientes(pedidosClientes, numClientes, capClientes);
            pos = numClientes - 1;
            pedidosClientes[pos] = new int[5]{};
            capPedCliente[pos] = 5;
            ndPedCliente[pos] = 3;
            cliente = pedidosClientes[pos];
            cliente[0] = dni;            
            cliente[1] = 0;    
            numClientes++;
        }
        insertarPedidoCliente(pedidosClientes[pos], pedido, ndPedCliente[pos], 
                capPedCliente[pos]);
        
        insertarPedidos(arch, pedido, libros, stock, pedidosLibros, pedidosAtendidos,
                numPedidos, capPedidos, numlibros, caplibros);
    }
    
}


void insertarPedidos(ifstream &arch, int pedido, char ***libros, int **stock, 
        char ***&pedidosLibros, bool **&pedidosAtendidos, int &numDat, int &cap,
        int *numlibros, int *caplibros){
    
    
    char codigo[10], **libroPedido, *cad;
    int pos_cod;
    while(arch.get() != '\n'){
        arch >> codigo;
        if(pedido >= cap){
            incrementarEspacios(pedidosLibros, pedidosAtendidos, numDat, cap,
                    pedido);
        }
        if(numlibros[pedido] == caplibros[pedido])
            incrementarEspacios(pedidosLibros[pedido],pedidosAtendidos[pedido],
                    numlibros[pedido], caplibros[pedido]);
        cad = asignarCadena(codigo);
        libroPedido = pedidosLibros[pedido];
        libroPedido[numlibros[pedido] - 1] = cad;
        
        verificarStock(codigo, libros, stock, pedidosAtendidos[pedido],
                numlibros[pedido] - 1);
        
        numlibros[pedido]++;
    }
    
}


void verificarStock(char *codigo, char ***libros, int **stock, 
        bool *pedidosAtendidos, int pos){
    char **libro;
    int *datos;
    for(int i = 0; libros[i]; i++){
        libro = libros[i];
        if(strcmp(libro[0], codigo) == 0){
            datos = stock[i];
            if(datos[0] > 0){
                datos[0]--;
                pedidosAtendidos[pos] = true;
            }
            else{
                datos[1]++;
                pedidosAtendidos[pos] = false;
            }
        }
    }
    
}

char *asignarCadena(char *codigo){
    char *aux = new char [strlen(codigo) + 1];
    strcpy(aux, codigo);
    return aux;
}

void incrementarEspacios(char **&pedidosLibros,bool *&atendidos, int &numlibros,
                    int &caplibros){
    caplibros += INCREMENTOS;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char*[caplibros]{};
        atendidos = new bool[caplibros]{};
        numlibros = 1;
    }
    else{
        char**aux = new char*[caplibros]{};
        bool *auxBool = new bool[caplibros]{};
        for(int i = 0; i < numlibros; i++){
            aux[i] = pedidosLibros[i]; 
            auxBool[i] = atendidos;
        }
            
        delete pedidosLibros;
        delete atendidos;
        atendidos = auxBool;
        pedidosLibros = aux;
    }
    
}

void incrementarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, 
        int &numDat, int &cap,int pedido){
    
    cap = pedido + INCREMENTOS;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[cap]{};
        pedidosAtendidos = new bool*[cap]{};
        
    }
    else{
        char ***auxPedido = new char**[cap]{};
        bool **auxAtendido = new bool*[cap]{};
        for(int i = 0; i < numDat + 1; i++){
            auxPedido[i] = pedidosLibros[i];
            auxAtendido[i] = pedidosAtendidos[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        
        pedidosLibros = auxPedido;
        pedidosAtendidos = auxAtendido;
    }
    
    numDat = pedido;
}

void insertarPedidoCliente(int *&pedidosClientes, int pedido, int &nd, 
                int &cap){
    
    if(nd == cap)
        incrementarEspacios(pedidosClientes, nd, cap);
    
    int pos = pedidosClientes[1] + 2;
    pedidosClientes[1]++;
    pedidosClientes[pos] = pedido;
    nd++;    
}

void incrementarEspacios(int *&pedidosClientes, int &nd, int &cap){
    
    cap += INCREMENTOS;
    if(pedidosClientes == nullptr){
        pedidosClientes = new int[cap]{};
        nd = 1;
    }
    else{
        int *aux = new int [cap]{};
        for(int i = 0; i < nd; i++)
            aux[i] = pedidosClientes[i];
        
        delete pedidosClientes;
        pedidosClientes = aux;
    }
    
}

void aumentarEspaciosClientes(int **&pedidosClientes, int &numDat, 
        int &cap){
    
    cap += INCREMENTOS;
    if(pedidosClientes == nullptr){
        pedidosClientes = new int *[cap]{};
        numDat = 1;
    }
    else{
        int **auxStock = new int *[cap]{};
        for(int i = 0; i < numDat; i++){
            auxStock[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes =auxStock;
    }
    
}

int buscarCliente(int dni,int **pedidosClientes){
    int *dato;
    if(pedidosClientes == nullptr)
        return NO_ENCONTRADO;
    for(int i = 0; pedidosClientes[i]; i++){
        dato = pedidosClientes[i];
        if(dni == dato[0])
            return i;
    }
    return NO_ENCONTRADO;
}

void ordenarPedidosClientes(int **pedidosClientes){
    
    int n = 0;
    for(; pedidosClientes[n]; n++);
    
    qsort(pedidosClientes,0, n - 1); 
    
}

void qsort(int **pedidosClientes,int izq, int der){
    
    if(izq >= der)
        return;
    int limite = izq;
    cambiar(pedidosClientes[izq], pedidosClientes[(izq + der) / 2]);
    
    for(int i = izq + 1; i <= der; i++){
        if(comparar(pedidosClientes[izq], pedidosClientes[i]) > 0)
            cambiar(pedidosClientes[++limite], pedidosClientes[i]);  
    }
    
    cambiar(pedidosClientes[limite], pedidosClientes[izq]);
    qsort(pedidosClientes, 0, limite - 1);
    qsort(pedidosClientes,limite +1, der);
}

void cambiar(int *&a, int *&b){
    
    int *aux = a;
    a = b;
    b = aux;
}


int comparar(int *pedidoI, int *pedidoD){
    if(pedidoI[1] != pedidoD[1])
        return pedidoD[1] - pedidoI[1];
    else{
        return pedidoI[0] - pedidoD[0];
    }
}

void reporteDeEntregaDePedidos(const char *nombArch, int **pedidosClientes,
            char ***pedidoLibros,bool **pedidosAtendidos){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombArch);
    
    arch << "REPORTE DE TOP 5" << endl;
    arch << "ATENCION DE PEDIDOS" << endl;
    imprimirLinea(arch, MAX_CAR, '=');
    int *dato;
    for(int i = 0; i < 5 and pedidosClientes[i]; i++){
        dato = pedidosClientes[i];
        arch << "CLIENTE: " << setw(10) << dato[0] << setw(30) <<
                "CANTIDAD DE PEDIDOS: " << setw(4) << dato[1] << endl;
        imprimirLinea(arch, MAX_CAR, '=');
        
        
        imprimirPedidos(arch, pedidosClientes[i], pedidoLibros, pedidosAtendidos);
        
    }
}

void imprimirPedidos(ofstream &arch, int *pedidosClientes, char ***pedidoLibros, 
        bool **pedidosAtendidos){
    
    int n = pedidosClientes[1] + 2;
    
    int pos;
    char **libros;
    bool *atendidos;
    for(int i = 2; i < n; i++){
        arch << setw(20) << "Pedido No." << setw(20) << "Codigo del libro" <<
                setw(18) << "Observacion" << endl;
        imprimirLinea(arch, MAX_CAR, '-');
        pos = pedidosClientes[i];
        arch << setw(12) << " " << setfill('0') << setw(6) << pos << setfill(' ');
        if(pedidoLibros[pos] != nullptr){
            libros = pedidoLibros[pos];
            atendidos = pedidosAtendidos[pos];
            for(int j = 0; libros[j]; j++){
                if(j != 0) arch << setw(18) << " ";
                
                arch << setw(12) << libros[j] << setw(15) << " ";
              
                if(atendidos[j] == true) arch << "ATENDIDO" << endl;
                else arch << "NO ATENDIDO" << endl;
                
            }
            imprimirLinea(arch, MAX_CAR, '-');
        }
        
    }
    
}