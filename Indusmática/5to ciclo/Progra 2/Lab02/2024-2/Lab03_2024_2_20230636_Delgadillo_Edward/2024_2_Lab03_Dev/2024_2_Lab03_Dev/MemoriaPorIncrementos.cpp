
#include "ConjuntoDeRepartidores.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePedidos.hpp"
#include <cstring>
#include "MemoriaPorIncrementos.hpp"
#include "AperturaDeArchivos.h"
#define INCRE 5

void cargar_estructuras(char ***&repartidores, int ***&clientes,
        double ***&subtotales, 
        char ***cadenas, int **enteros, double **reales) {

    
    ConjuntoDeRepartidores conjRepartidores;
    cargar_conjunto_de_repartidores(conjRepartidores,"repartidores.csv");
    
    int cantRepar=0;
    completarReparti(repartidores,cadenas,conjRepartidores,cantRepar);
    int ndClieDeRepar[cantRepar]{};
    completarCli(clientes,enteros,cadenas,repartidores,cantRepar,ndClieDeRepar);
    completarSubtotales(subtotales,repartidores,reales,cadenas,cantRepar,ndClieDeRepar);
}

void completarSubtotales(double ***&subtotales,char ***repartidores,
        double **reales,char***cadenas,int cantRepar,int *ndClieDeRepar){

    subtotales=new double**[cantRepar]{};
    char**repartidor;
    int ndCli;
    for (int i = 0; i < cantRepar-1; i++) {
        ndCli=ndClieDeRepar[i];
        subtotales[i]=new double*[ndCli]{};
        
        repartidor=repartidores[i];
        completarSub(subtotales[i],repartidor[0],reales,cadenas,cantRepar);
    }   
}

void completarSub(double**subtotal,char*codigo,
        double**reales,char***cadenas,int cantRepar){
    
    char**cadena;
    double*real;
    int nd=0;
    for (int i = 0; cadenas[i]; i++) {
        cadena=cadenas[i];
        if(not strcmp(codigo,cadena[0])){
            real=reales[i];
            subtotal[nd]=retorna_referencia_a_real(real[0]);
//            pasarInfo(subtotal[nd],reales[i]);
            nd++;
        }
    }
}

void pasarInfo(double*&subtotal,double*real){
    
    subtotal=retorna_referencia_a_real(real[0]);
}

void completarCli(int***&clientes,int**enteros,char***cadenas,
        char***repartidores,int cantRepar,int*nd){
    
    clientes=new int**[cantRepar]{};
    int capa[cantRepar]{};
    
    char**repartidor;
    for (int i = 0; i < cantRepar-1; i++) {
        repartidor=repartidores[i];
        buscar(cadenas,enteros,repartidor[0],clientes[i],nd[i],capa[i]);
    }
}

void buscar(char***cadenas,int**enteros,char*codigo,int**&cliente,
        int &nd,int &capa){
    
    char**cadena;
    int*entero;
    for (int i = 0; cadenas[i]; i++) {
        cadena=cadenas[i];
        if(not strcmp(cadena[0],codigo)){
            entero=enteros[i];
            if(nd==capa)aumentarEspacio(cliente,nd,capa);
            cliente[nd-1]=retorna_referencia_a_entero(entero[0]);
            nd++;
        }
    }
}

void aumentarEspacio(int**&cliente,int &nd,int &capa){
    
    capa+=INCRE;
    if(not cliente){
        cliente=new int*[capa]{};
        nd=1;
    }
    else{
        int**aux=new int*[capa]{};
        for (int i = 0; i < nd; i++) {
            aux[i]=cliente[i];
        }
        delete cliente;
        cliente=aux;
    }
}


void completarReparti(char ***&repartidores,char***cadenas,
        const ConjuntoDeRepartidores &conjRepartidores,int &nd){
    
    char **cadena;
    int capa=0;
    repartidores=nullptr;
    for (int i = 0; cadenas[i]; i++) {
        cadena=cadenas[i];
        if(not yaEsta(repartidores,nd,cadena[0])){
            if(nd==capa)incrementarEspacio(repartidores,nd,capa);
            agregarReparti(repartidores[nd-1],cadena[0],conjRepartidores);
            nd++;
        }
    }
}

bool yaEsta(char ***&repartidores,int nd,char*codigo){
    
    char**repar;
    for (int i = 0; i < nd-1; i++) {
        repar=repartidores[i];
        if(not strcmp(repar[0],codigo))return true;
    }
    return false;
}    
void incrementarEspacio(char ***&repartidores,int &nd,int &capa){
    
    capa+=INCRE;
    if(not repartidores){
        repartidores=new char**[capa]{};
        nd=1;
    }
    else{
        char***aux=new char**[capa]{};
        for (int i = 0; i < nd; i++) {
            aux[i]=repartidores[i];
        }
        delete repartidores;
        repartidores=aux;
    }
}

void agregarReparti(char**&repartidor,char*codigo,
        const ConjuntoDeRepartidores &conjRepartidores){
    
    char*nombre=conjRepartidores==codigo;
    repartidor=new char*[2]{};
    repartidor[0]=mi_strdup(codigo);
    repartidor[1]=mi_strdup(nombre);
}
        


void reporte_de_repartidores(const char*nombArch, char ***repartidores, 
        int ***clientes, double ***subtotales) {
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombArch);
    arch.precision(2);
    arch<<fixed;
    
    for (int i = 0; repartidores[i]; i++) {
        imprimirRepar(arch,repartidores[i],clientes[i],subtotales[i]);
    }
}

void imprimirRepar(ofstream &arch,char**repartidor,int**cliente,double**subTotales){
    
    int ndCli=0;
    double subTot=0;
    while(cliente[ndCli])ndCli++;
    for (int i = 0; i < ndCli; i++) {
        subTot+=*subTotales[i];
    }
    arch<<repartidor[1]<<","<<ndCli<<","<<subTot<<endl;
}


void reporte_por_repartidor(char ***repartidores, int ***clientes, 
        double ***subtotales) {

    char**repar;
    for (int i = 0; repartidores[i]; i++) {
        repar=repartidores[i];
        char nombArch[50]{};
        obtener_nombre_archivo_por_repartidor(nombArch,repar[0]);
        ofstream arch(nombArch,ios::out);
        arch.precision(2);
        arch<<fixed;
        if(not arch.is_open()){
            cout<<"Error en "<<nombArch;
        }
        imprimir_linea(arch);
        arch<<" CODIGO REPARTIDOR: "<<repar[0]<<endl;
        arch<<" NOMBRE REPARTIDOR: "<<repar[1]<<endl;
        imprimir_linea(arch);
        arch<<"   DNI CLIENTE     MONTO POR PEDIDO"<<endl;
        imprimir_linea(arch,'-');
        imprimirCli(arch,clientes[i],subtotales[i]);
        imprimir_linea(arch);
    }
}

void imprimirCli(ofstream &arch,int**cliente,double**subtotal){
    
    int dni;
    for (int i = 0; cliente[i]; i++) {
        dni=*cliente[i];
        arch<<"    "<<left<<setfill('.')<<setw(25)<<dni<<setfill(' ')<<
                *subtotal[i]<<endl;
    }

}
