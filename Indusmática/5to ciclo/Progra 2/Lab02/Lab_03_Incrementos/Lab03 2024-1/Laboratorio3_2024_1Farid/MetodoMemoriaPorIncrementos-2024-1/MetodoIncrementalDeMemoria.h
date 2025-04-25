

/* 
 * File:   MetodoIncrementalDeMemoria.h
 * Author: Usuario
 *
 * Created on 24 de abril de 2025, 03:17 PM
 */

#ifndef METODOINCREMENTALDEMEMORIA_H
#define METODOINCREMENTALDEMEMORIA_H

#endif /* METODOINCREMENTALDEMEMORIA_H */

// LeerLibros
void lecturaDeLibros(const char* nomArch, char***&libros, int **&stock);
char **leerRegistroLibro(ifstream &arch);
char* leerExacto(ifstream &arch, int max, char deli);
void incrementarCap(char ***&libro, int **&stock, int &nd, int&cap);

//Mostrar Libros
void pruebaDeLecturaDeLibros(const char* nomArch, char ***libros, int **stock);

//Leer Pedidos
void atencionDePedidos(const char* nomArch, char*** libros, int**stock, int**&pedidosClientes,
        char ***&pedidosLibros, bool**&pedidosAtendidos);
int buscarCliente(int **pedidosClientes, int dni);
void incrementarCapClientes(int **&pedidosClientes, int &ndCli, int &capCli);
void agregarCliente(int **pedidosClientes, int &ndCli, int dni, int &pos_cli,
        int *ndPedCli, int *capPedCli);
void incrementarPedCli(int *&pedidosAtendidos, int &ndPedCli,
        int &capPedCli);
void agregarPedido(int *&pedidosClientes, int numPed, int &ndPedCli, int &capPedCli);
void incrementarCapLib(char ***&pedidosLibros, bool **&pedidosAtendidos,
        int numPed, int &capPedLib);
void leerLibros(ifstream &arch, bool **pedidosAtendidos, char ***pedidosLibros,
        int numPed, char ***libros, int ** stock);
void incrementarCapPedidos(bool *&pedidosAtendidos, char **&pedidosLibros,
        int &nd, int &cap);
int buscarLibro(char***libros, char* cod);
bool verificarStock(int *stock);



//OrdenarPedidos
void ordenarPedidosClientes(int **pedidosClientes);
int contarClientes(int **pedidosClientes);
void qSort(int **pedidosClientes, int izq, int der);
void cambiar(int *&datoI,int*&datoJ);




//ReporteDePedidos
void reporteDeEntregaDePedidos(const char* nomArch, int** pedidosClientes,
        char ***pedidosLibros, bool** pedidosAtendidos);
void mostrarLinea(ofstream &arch, char c);
void imprimirPedidos(ofstream &arch, int numPed, bool *pedidosAtendidos,
        char **pedidosLibros);
