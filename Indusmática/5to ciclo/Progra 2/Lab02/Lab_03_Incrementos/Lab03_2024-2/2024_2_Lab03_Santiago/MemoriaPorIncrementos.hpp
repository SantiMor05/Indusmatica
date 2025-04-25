#ifndef MEMORIAPORINCREMENTOS_HPP
#define MEMORIAPORINCREMENTOS_HPP

#include <fstream>
using namespace std;

void cargar_estructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, char ***cadenas, int **enteros, double **reales);

void reporte_de_repartidores(const char*nombre_archivo, char ***repartidores, int ***clientes, double ***subtotales);

void reporte_por_repartidor(char ***repartidores, int ***clientes, double ***subtotales);

void cargar_estructuras(char ***&repartidores, int ***&clientes, 
        double ***&subtotales, char ***cadenas, int **enteros, double **reales);
void cargarPedido(int **&clientes,double **&subtotales, char ***cadenas, 
        int **enteros,double **reales,char *cod, int &numDat, int &cap);
void cargarPedido(int *&clientes, double *&subtotales, int *enteros, 
        double *reales);
void incrementarEspacios(int **&clientes, double **&subtotales, int &numDat, 
        int &cap);
void incrementarEspacios(char ***&repartidores, int ***&clientes, 
        double ***&subtotales, int &numDat, int &cap);
int contarClientes(int **clientes);
double sumarMonto(double **subtotales);
void imprimirClientesMontos(ofstream &arch, int **clientes, double **subtotales);
#endif /* MEMORIAPORINCREMENTOS_HPP */

