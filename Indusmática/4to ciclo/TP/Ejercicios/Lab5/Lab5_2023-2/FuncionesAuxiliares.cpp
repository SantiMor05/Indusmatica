#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 100

using namespace std;

void leerAlumnos(int &cant_alumnos,int *cod_alum, int *escala_alum, 
        const char *nombAlumnos){
    
    ifstream archAlumnos(nombAlumnos, ios::in);
    if(not archAlumnos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombAlumnos << endl;
        exit(1);
    }
    
    cant_alumnos = 0;
    while(true){
        
        archAlumnos >> cod_alum[cant_alumnos];
        if(archAlumnos.eof())break;
        
        saltarTexto(archAlumnos);
        
        archAlumnos >> escala_alum[cant_alumnos];
        
        cant_alumnos++;
    }
    
}

void leerCursos(int &cant_cursos, int *cod_curso, double *credito_curso, 
        const char *nombCursos){
    
    ifstream archCursos(nombCursos, ios::in);
    if(not archCursos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombCursos << endl;
        exit(1);
    }
    cant_cursos = 0;
    while(true){
        
        archCursos >> cod_curso[cant_cursos];
        if(archCursos.eof())break;
        saltarTexto(archCursos);
        
        archCursos >> credito_curso[cant_cursos];
        
        cant_cursos++;
    }
    
}

void actualizarDatos(int cant_alumnos,int *cod_alum, int *escala_alum, 
        double *total_creditos, int *cant_cursos_matri, double *pago,
        int cant_cursos, int *cod_curso, double *credito_curso,
        int *alum_matriculados, double *total_ingresos, int cant_escalas, 
        double *escala, const char *nombMatricula){
    
    int codigo, alumno, pos_alumno, pos_curso, pos_escala;
    
    ifstream archMatricula(nombMatricula, ios::in);
    if(not archMatricula.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombMatricula << endl;
        exit(1);
    }
    
    while(true){
        archMatricula >> alumno;
        if(archMatricula.eof())break;
        
        archMatricula >> codigo;
        
        pos_alumno = buscarDato(alumno, cant_alumnos, cod_alum);
        pos_curso = buscarDato(codigo, cant_cursos, cod_curso);
        pos_escala = escala_alum[pos_alumno] - 1;
        
        //Para alumnos
        total_creditos[pos_alumno] += credito_curso[pos_curso];
        (cant_cursos_matri[pos_alumno])++;
        pago[pos_alumno] += credito_curso[pos_curso] * escala[pos_escala];
        
        //Para cursos
        (alum_matriculados[pos_curso])++;
        total_ingresos[pos_curso] = credito_curso[pos_curso] * 
                escala[pos_escala];
    }
    
    
}

void ordenarAlumnos(int cant_alumnos,int *cod_alum, int *escala_alum, 
        double *total_creditos, int *cant_cursos_matri, double *pago){
    int pos_mayor;
    
    for(int i = 0; i < cant_alumnos; i++){
        pos_mayor = i;
        for(int j = i + 1; j < cant_alumnos; j++){
            if(pago[j] > pago[pos_mayor]){
                pos_mayor = j;
            }
        }
        intercambiarInt(i,pos_mayor, cod_alum);
        intercambiarInt(i,pos_mayor, escala_alum);
        intercambiarInt(i,pos_mayor, cant_cursos_matri);
        intercambiarDouble(i,pos_mayor,total_creditos);
        intercambiarDouble(i,pos_mayor,pago);
    }
    
}

void imprimirReporte(int cant_alumnos, int *cod_alum, int *escala_alum, 
        double *total_creditos, int *cant_cursos_matri, double *pago, 
        int cant_cursos, int *cod_curso, double *credito_curso, 
            int *alum_matriculados, double *total_ingresos, 
        const char *nombReporte){
    
    ofstream archReporte(nombReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    
    
    imprimirEncabezadoAlumnos(archReporte);
    
    archReporte << setprecision(2) << fixed;
    
    for(int i = 0; i < cant_alumnos; i++){
        archReporte << setfill('0') << setw(2) << i + 1 << ")" << setfill(' ') 
                << setw(10) << cod_alum[i] << setw(8) << escala_alum[i] <<
                setw(22) << total_creditos[i] << setw(19) << 
                cant_cursos_matri[i] << setw(30) << pago[i] << endl;
    }
    
    imprimirCaracter('=', archReporte);
    
    imprimirEncabezadoCursos(archReporte);
    
    for(int i = 0; i < cant_cursos; i++){
        archReporte << setfill('0') << setw(2) << i + 1 << ")" << setfill(' ') 
                << setw(8) << cod_curso[i] << setw(12) << credito_curso[i] <<
                setw(23) << alum_matriculados[i] << setw(29) << 
                total_ingresos[i] << endl;
    }
    
}

void imprimirEncabezadoCursos(ofstream &archReporte){
    
    archReporte << endl << setw(MAX_CAR / 2 + 17) << "RELACION DE INGRESOS POR "
            "CADA CURSO" << endl;
    
    imprimirCaracter('=', archReporte);
    
    archReporte << setw(10) << "CURSO" << setw(15) << "CREDITOS" << setw(30) <<
            "ALUMNOS MATRICULADOS" << setw(25) << "TOTAL DE INGRESOS" << endl;
    
    imprimirCaracter('-', archReporte);
}

void imprimirEncabezadoAlumnos(ofstream &archReporte){
    
    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" << endl;
    archReporte << endl << setw(MAX_CAR / 2 + 16) << "RELACION DE PAGOS DE LOS "
            "ALUMNOS" << endl;
    
    imprimirCaracter('=', archReporte);
    
    archReporte << setw(12) << "Alumno" << setw(12) << "ESCALA" <<  setw(25) <<
            "TOTAL DE CREDITOS" << setw(20) << "TOTAL DE CURSOS" << setw(25) <<
            "TOTAL A PAGAR" << endl;
    imprimirCaracter('-', archReporte);
    
}

void imprimirCaracter(char car, ofstream &archReporte){
    
    
    for(int i = 0; i < MAX_CAR; i++){
        archReporte.put(car);
    }
    archReporte << endl;
}

void ordenarCursos(int cant_cursos, int *cod_curso, double *credito_curso, 
            int *alum_matriculados, double *total_ingresos){
    
    int pos_mayor;
    
    for(int i = 0; i < cant_cursos; i++){
        pos_mayor = i;
        for(int j = i + 1; j < cant_cursos; j++){
            if(alum_matriculados[j] < alum_matriculados[pos_mayor]){
                pos_mayor = j;
            }
        }
        intercambiarInt(i,pos_mayor, cod_curso);
        intercambiarInt(i,pos_mayor, alum_matriculados);
        intercambiarDouble(i,pos_mayor,credito_curso);
        intercambiarDouble(i,pos_mayor,total_ingresos);
    }
}

void intercambiarDouble(int i,int j,double *arr){
    
    double aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
    
}

void intercambiarInt(int i, int j, int *arr){
    
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
    
}

int buscarDato(int codigo, int cant, int *cod){
    
    for(int i = 0; i < cant; i++){
        if(codigo == cod[i]) return i;
    }
    
    return -1;
}

void leerEscalas(int &cant_escalas, double *escala, const char *nombEscalas){
    
    ifstream archEscalas(nombEscalas, ios::in);
    if(not archEscalas.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombEscalas << endl;
        exit(1);
    }
    
    int escalas;
    double precio;
    
    
    cant_escalas = 0;
    while(true){
        
        archEscalas >> escalas;
        if(archEscalas.eof())break;
        archEscalas >> precio;
        
        escala[cant_escalas] = precio;
        
        cant_escalas++;
    }
    
}

void saltarTexto(ifstream &archAlumnos){
    
    archAlumnos >> ws;
    while(archAlumnos.get() != ' ');
    
}