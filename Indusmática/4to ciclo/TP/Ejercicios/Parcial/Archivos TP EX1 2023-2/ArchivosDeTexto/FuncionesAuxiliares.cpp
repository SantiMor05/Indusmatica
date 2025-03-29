#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 120
#define MAX_CAR_NOMBRE 40
#define MAX_CAR_CURSO 55

using namespace std;

void solicitarCiclo(int &ciclo, int &anho) {
    char car;
    cout << "Ingrese el ahno y ciclo a visualizar (aaaa-c) :";
    cin >> anho >> car >> ciclo;

}

void procesarDatos(int ciclo, int anho, const char *nombAlumnos,
        const char *nombCursos, const char *nombEscalas,
        const char *nombMatricula, const char *nombReporte) {

    ifstream archAlumnos(nombAlumnos, ios::in);
    if (not archAlumnos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombAlumnos << endl;
        exit(1);
    }

    ifstream archCursos(nombCursos, ios::in);
    if (not archCursos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCursos << endl;
        exit(1);
    }

    ifstream archEscalas(nombEscalas, ios::in);
    if (not archEscalas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombEscalas << endl;
        exit(1);
    }

    ifstream archMatricula(nombMatricula, ios::in);
    if (not archAlumnos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMatricula << endl;
        exit(1);
    }

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirReporte(ciclo, anho, archAlumnos, archCursos, archEscalas, 
            archMatricula, archReporte);

}

void imprimirReporte(int ciclo, int anho, ifstream &archAlumnos,
        ifstream &archCursos, ifstream &archEscalas, ifstream &archMatricula,
        ofstream &archReporte) {

    int alumno, cont;
    double credito, creditos_total, monto_total_alumno, ingreso_total;
    char escala;

    imprimirEncabezado(ciclo, anho, archReporte);
    archReporte << setprecision(2) << fixed;
    
    cont = ingreso_total = 0;
    
    while (true) {

        archAlumnos >> alumno;
        if (archAlumnos.eof())break;
        archReporte << "ALUMNO: " << setw(10) << alumno << " - ";
        imprimirTexto(' ', MAX_CAR_NOMBRE, archAlumnos, archReporte);
        archAlumnos >> escala;
        archReporte << setw(20) << "ESCALA: " << escala << endl;


        credito = buscarEscala(escala, ciclo, anho, archEscalas);
        creditos_total = monto_total_alumno = 0;
        imprimirCursosMatriculados(ciclo, anho, credito, alumno, creditos_total,
                monto_total_alumno, archMatricula, archCursos, archReporte);
        imprimirEstadisticasAlumno(creditos_total, monto_total_alumno, 
                archReporte);
        
        ingreso_total += monto_total_alumno;
        cont++;
    }
    imprimirResumen(cont, ingreso_total, archReporte);

}

void imprimirResumen(int cont, double ingreso_total, ofstream &archReporte){
    
    archReporte << "RESUMEN:" << endl;
    archReporte << "CANTIDAD TOTAL DE ALUMNOS:" << setw(6) << cont << setw(25)
            << "MONTO TOTAL PAGADO" << setw(16) << ingreso_total << endl;
    
}

void imprimirEstadisticasAlumno(double creditos_total, double monto_total, 
        ofstream &archReporte){
    
    imprimirCaracter('-', archReporte);
    archReporte << "TOTAL CREDITOS:" << setw(10) << creditos_total << setw(25)
            << "TOTAL MONTO PAGAGO:" << setw(12) << monto_total << endl;
    imprimirCaracter('=', archReporte);
}

void imprimirCursosMatriculados(int ciclo, int anho, double credito, int alumno,
        double &creditos_total, double &monto_total, ifstream &archMatricula,
        ifstream &archCursos, ofstream &archReporte) {

    int aa, semestre, cod_alum, curso, cont = 0;
    char car;

    imprimirEncabezadoCursos(archReporte);

    archMatricula.clear();
    archMatricula.seekg(0, ios::beg);

    while (true) {
        archMatricula >> aa;
        if (archMatricula.eof())break;
        archMatricula >> car >> semestre >> cod_alum;
        if (aa == anho and ciclo == semestre and cod_alum == alumno) {
            while (archMatricula.get() != '\n') {
                archMatricula >> curso;
                archReporte << setw(10) << " " << setfill('0') << setw(2) <<
                        cont + 1 << ")" << setfill(' ') << setw(8) << curso <<
                        " - ";
                buscarImprimirCurso(curso, credito, creditos_total,
                        monto_total, archCursos, archReporte);


                cont++;
            }
        } else
            while (archMatricula.get() != '\n');
    }
}

void buscarImprimirCurso(int curso, double credito, double &creditos_total,
        double &monto_total, ifstream &archCursos,
        ofstream &archReporte) {

    int cod_curso;
    double cant_creditos, monto;
    archCursos.clear();
    archCursos.seekg(0, ios::beg);

    while (true) {
        archCursos >> cod_curso;
        if (archCursos.eof())break;
        if (cod_curso == curso) {
            imprimirTexto(' ', MAX_CAR_CURSO, archCursos, archReporte);
            archCursos >> cant_creditos;
            monto = cant_creditos * credito;
            archReporte << setw(5) << cant_creditos << setw(24) << monto<<endl;
            creditos_total += cant_creditos;
            monto_total += monto;
        } else
            while (archCursos.get() != '\n');
    }


}

void imprimirEncabezadoCursos(ofstream &archReporte) {

    imprimirCaracter('-', archReporte);
    archReporte << setw(35) << "CURSO MATRICULADO" << setw(51) << "CREDITOS" <<
            setw(25) << "MONTO PAGADO" << endl;
}

double buscarEscala(char escala, int ciclo, int anho, ifstream &archEscalas) {


    int semestre, aa;
    char esca, car;
    double costo;

    archEscalas.clear();
    archEscalas.seekg(0, ios::beg);

    while (true) {
        archEscalas >> aa;
        if (archEscalas.eof())break;
        archEscalas >> car >> semestre;
        archEscalas >> esca >> costo;
        if (aa == anho and ciclo == semestre and escala == esca)
            return costo;
    }

    return -1;
}

void imprimirTexto(char deli, int n, ifstream &archAlumnos,
        ofstream &archReporte) {
    int cont = 0;
    char car;
    archAlumnos >> ws;

    while (true) {
        car = archAlumnos.get();
        if (car == deli)break;
        if (car == '_') car = ' ';
        archReporte.put(car);
        cont++;
    }
    archReporte << setw(n - cont) << " ";
}

void imprimirEncabezado(int ciclo, int anho, ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 18) << "DETALLE DE PAGOS REALIZADO "
            "POR CICLO" << endl;
    archReporte << setw(MAX_CAR/2) << "CICLO: " << anho << "-" << ciclo << endl;

    imprimirCaracter('=', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte) {

    for (int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;

}