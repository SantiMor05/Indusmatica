#ifndef MEMORIAPORINCREMENTOS_HPP
#define MEMORIAPORINCREMENTOS_HPP

void cargar_estructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, char ***cadenas, int **enteros, double **reales);

void reporte_de_repartidores(const char*nombre_archivo, char ***repartidores, int ***clientes, double ***subtotales);

void reporte_por_repartidor(char ***repartidores, int ***clientes, double ***subtotales);


void completarSubtotales(double ***&subtotales,char ***repartidores,
        double **reales,char***cadenas,int cantRepar,int *ndClieDeRepar);
void completarSub(double**subtotal,char*codigo,
        double**reales,char***cadenas,int cantRepar);
void completarCli(int***&clientes,int**enteros,char***cadenas,
        char***repartidores,int cantRepar,int*nd);
void buscar(char***cadenas,int**enteros,char*codigo,int**&cliente,int &nd,int &capa);
void aumentarEspacio(int**&cliente,int &nd,int &capa);
void completarReparti(char ***&repartidores,char***cadenas,
        const struct ConjuntoDeRepartidores &conjRepartidores,int &nd);
bool yaEsta(char ***&repartidores,int nd,char*codigo);
void incrementarEspacio(char ***&repartidores,int &nd,int &capa);
void agregarReparti(char**&repartidor,char*codigo,
        const struct ConjuntoDeRepartidores &conjRepartidores);
void pasarInfo(double*&subtotal,double*real);

void imprimirRepar(ofstream &arch,char**repartidor,int**cliente,double**subTotales);
void imprimirCli(ofstream &arch,int**cliente,double**subtotal);

#endif /* MEMORIAPORINCREMENTOS_HPP */

