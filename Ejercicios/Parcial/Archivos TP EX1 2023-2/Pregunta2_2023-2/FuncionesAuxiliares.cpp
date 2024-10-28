#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_PRUEBA 50
#define MAX_CAR 120

using namespace std;

void leerAlumnos(int &cant_alumnos, int *alumno, char *escala, 
        const char *nombAlumnos){
    
    ifstream archAlumnos(nombAlumnos, ios::in);
    if(not archAlumnos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombAlumnos << endl;
        exit(1);
    }
    //20227341  Diaz_Antezano_Magali_Silvana    D
    cant_alumnos = 0;
    while(true){
        
        archAlumnos >> alumno[cant_alumnos];
        if(archAlumnos.eof())break;
        saltarTexto(' ', archAlumnos);
        archAlumnos >> escala[cant_alumnos];
        cant_alumnos++;
    }
    
}

void leerCursos(int &cant_cursos, int *curso, double *creditos, 
        const char *nombCursos){
    
    ifstream archCursos(nombCursos, ios::in);
    if(not archCursos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombCursos << endl;
        exit(1);
    }
    cant_cursos = 0;
    //231289    Turbomaquinas_Y_Maquinas_De_Desplazamiento_Positivo    3.00
    while(true){
        archCursos >> curso[cant_cursos];
        if(archCursos.eof())break;
        saltarTexto(' ', archCursos);
        archCursos >> creditos[cant_cursos];
        cant_cursos++;
    }
    
}

void leerEscalas(int &cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, const char *nombEscalas){
    
    char car;
    ifstream archEscalas(nombEscalas, ios::in);
    if(not archEscalas.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombEscalas << endl;
        exit(1);
    }
    cant_escalas = 0;
    //2021-2    C    288.65
    while(true){
        
        archEscalas >> anho[cant_escalas];
        if(archEscalas.eof())break;
        archEscalas  >> car >> ciclo[cant_escalas] >> 
                escala_escala[cant_escalas] >> costo[cant_escalas];
        
        cant_escalas++;
    }
}

void actualizarDatos(int cant_alumnos, int *alumno, char *escala, 
        int cant_cursos, int *curso, double *creditos, int cant_escalas, 
        int *anho, int *ciclo, char *escala_escala, double *costo, 
        int *cant_alumn_escalas, double *cant_creditos, 
        double *total_ingresos, const char *nombMatricula){
    
    int aa, semestre, cod_alum, escala_alum, cod_curso;
    int pos_alum, pos_escala, pos_curso;
    char car;
    ifstream archMatricula(nombMatricula, ios::in);
    if(not archMatricula.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombMatricula << endl;
        exit(1);
    }
    //2023-2    20231938    481203    375219    231286    231292
    while(true){
        archMatricula >> aa;
        if(archMatricula.eof())break;
        archMatricula >>car >>semestre >> cod_alum;
        pos_alum = buscar(cod_alum, cant_alumnos, alumno);
        escala_alum = escala[pos_alum];
        pos_escala = buscarEscala(aa, semestre, escala_alum, cant_escalas, 
                anho, ciclo, escala_escala);
        (cant_alumn_escalas[pos_escala])++;
        while(archMatricula.get() != '\n'){
            archMatricula >> cod_curso;
            pos_curso = buscar(cod_curso, cant_cursos, curso);
            cant_creditos[pos_escala] += creditos[pos_curso];
            total_ingresos[pos_escala] +=  creditos[pos_curso] * 
                    costo[pos_escala];
        }
        
    }
    
}

void imprimirReporte(int cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, int *cant_alumn_escalas, double *cant_creditos, 
        double *total_ingresos, const char *nombReporte){
    
    ofstream archReporte(nombReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    imprimirEncabezado(archReporte);
    archReporte << setprecision(2) << fixed;
    for(int i = 0; i < cant_escalas; i++){
        archReporte << setfill('0') << setw(2) << i + 1 << setfill(' ') << ")" 
                << setw(6) << anho[i] << "-" << ciclo[i] << setw(14) << 
                escala_escala[i] << setw(18) << cant_alumn_escalas[i] << 
                setw(23) << costo[i] << setw(25) << cant_creditos[i] << 
                setw(23) << total_ingresos[i] << endl;
    }
}

void imprimirEncabezado(ofstream &archReporte){
    
    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" << endl
            << endl;
    archReporte << setw(MAX_CAR / 2 + 20) << "RELACION DE INGRESOS POR CICLOS "
            "Y ESCALAS" << endl << endl;
    
    imprimirCaracter('=', MAX_CAR, archReporte);
    archReporte << setw(10) << "CICLO" << setw(18) << "ESCALA" << setw(20) <<
            "CANT.ALUMNOS" << setw(22) << "VALOR CREDITO" << setw(24) <<
            "CANT.CREDITOS" << setw(24) << "TOTAL DE INGRESOS" << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
}

void ordenar(int cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, int *cant_alumn_escalas, double *cant_creditos, 
        double *total_ingresos){
    
    for(int i = 0; i < cant_escalas; i++){
        for(int j = i +1; j < cant_escalas; j++){
            if(cant_alumn_escalas[i] < cant_alumn_escalas[j] or 
                    (cant_alumn_escalas[i] == cant_alumn_escalas[j] and 
                    total_ingresos[i] > total_ingresos[j])){
                intercammbiarInt(i,j,anho);
                intercammbiarInt(i,j,ciclo);
                intercammbiarInt(i,j,cant_alumn_escalas);
                intercammbiarChar(i,j,escala_escala);
                intercammbiarDouble(i,j,costo);
                intercammbiarDouble(i,j,cant_creditos);
                intercammbiarDouble(i,j,total_ingresos);
            }
        }
    }
    
}

void intercammbiarInt(int i,int j,int *arr){
    
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
    
}

void intercammbiarChar(int i,int j,char *arr){
    
    char aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
    
}

void intercammbiarDouble(int i,int j,double *arr){
    
    double aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
    
}

int buscarEscala(int aa, int semestre, char escala_alum, int cant_escalas, 
                int *anho, int *ciclo, char *escala_escala){
    
    for(int  i = 0; i < cant_escalas; i++){
        if(aa == anho[i] and semestre == ciclo[i] and 
                escala_alum == escala_escala[i])
            return i;
    }
    return -1;
}


int buscar(int codigo, int n, int *arr){
    
    for(int  i = 0; i < n; i++){
        if(codigo == arr[i]) return i;
    }
    return -1;
}

void reportePrueba(int &cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, const char *nomReporte){
    
    ofstream archReporte(nomReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nomReporte << endl;
        exit(1);
    }
    
    archReporte << "Ciclo" << setw(15) << "Escala" << setw(12) << "Costo" << 
            endl;
    
    imprimirCaracter('=', MAX_CAR_PRUEBA, archReporte);
    archReporte << setprecision(2) << fixed;
    for(int i=0; i < cant_escalas; i++){
        archReporte << anho[i] << "-" << ciclo[i] << setw(12) << 
                escala_escala[i] << setw(15) << costo[i] << endl;
    }
     
}

void imprimirCaracter(char car, int n, ofstream &archReporte){
    
    for(int  i = 0; i < n; i++)
        archReporte.put(car);
    archReporte << endl;
}

void saltarTexto(char deli, ifstream &archEntrada){
    
    char car;
    archEntrada >> ws;
    while(true){
        car = archEntrada.get();
        if(car ==deli) break;
    }
}