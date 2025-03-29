#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 140

using namespace std;

int pedirSemestre() {
    int aa, ciclo;
    char car;
    cout << "Ingrese ciclo para el cual se emitira el reporte (aaaa-c): ";
    cin >> aa >> car >> ciclo;

    return aa * 10 + ciclo;

}

void leerDatosAlumnos(int &cant_alumnos, struct Alumno *alumnos,
        const char *nombAlum) {

    ifstream archAlum(nombAlum, ios::in);
    if (not archAlum.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombAlum << endl;
        exit(1);
    }

    cant_alumnos = 0;
    while (true) {
        leerAlumno(archAlum, alumnos[cant_alumnos]);
        if (archAlum.eof())break;
        cant_alumnos++;
    }

}

void leerAlumno(ifstream &archAlum, struct Alumno &alumnos) {

    archAlum >> alumnos.codigo;
    if (archAlum.eof())return;
    archAlum.get();
    archAlum.getline(alumnos.nombre, MAX_CAR_ALUMNO, ',');
    archAlum >> alumnos.escala;
}

void leerDatosCurso(int &cant_cursos, struct Curso *cursos,
        const char *nombCurso) {

    ifstream archCurso(nombCurso, ios::in);
    if (not archCurso.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCurso << endl;
        exit(1);
    }

    cant_cursos = 0;

    while (true) {
        leerCurso(archCurso, cursos[cant_cursos]);
        if (archCurso.eof())break;
        cant_cursos++;
    }

}

void leerCurso(ifstream &archCurso, struct Curso &cursos) {

    archCurso >> cursos.codigo;
    if (archCurso.eof())return;
    archCurso.get();
    archCurso.getline(cursos.nombre, MAX_CAR_CURSO, ',');
    archCurso >> cursos.creditos;

}

void leerDatosEscalas(int &cant_escalas, struct Escala *escalas,
        const char *nombEscala) {

    ifstream archEscala(nombEscala, ios::in);
    if (not archEscala.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombEscala << endl;
        exit(1);
    }
    cant_escalas = 0;
    while (true) {
        leerEscala(archEscala, escalas[cant_escalas]);
        if (archEscala.eof())break;
        cant_escalas++;
    }
}

void leerEscala(ifstream &archEscala, struct Escala &escalas) {

    int aa, ciclo;
    archEscala >> aa;
    if (archEscala.eof())return;
    archEscala >> ciclo;
    escalas.semestre = aa * 10 + ciclo;
    archEscala.get();
    archEscala >> escalas.escala;
    archEscala.get();
    archEscala >> escalas.costo;
}

void procesarMatricula(int semestre, int cant_alumnos, struct Alumno *alumnos,
        int cant_cursos, struct Curso *cursos, int cant_escalas,
        struct Escala *escalas, const char *nombMatri) {

    ifstream archMatri(nombMatri, ios::in);
    if (not archMatri.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMatri << endl;
        exit(1);
    }
    int aa, ciclo;
    int cod_alumno, pos_alum, pos_escala, pos_curso, cod_curso;
    double costo;
    char car;
    while (true) {
        archMatri >> aa;
        if (archMatri.eof())break;
        archMatri >> car >> ciclo;
        if (aa * 10 + ciclo == semestre) {
            archMatri.get();
            archMatri >> cod_alumno;
            pos_alum = buscarAlumno(cod_alumno, cant_alumnos, alumnos);
            if (pos_alum != -1) {
                pos_escala = buscarEscala(alumnos[pos_alum].escala,
                        cant_escalas, escalas);
                costo = escalas[pos_escala].costo;
                while (archMatri.get() != '\n') {
                    archMatri >> cod_curso;
                    pos_curso = buscarCurso(cod_curso, cant_cursos, cursos);
                    if (pos_curso != -1) {
                        cursos[pos_curso].alumnos++;
                        cursos[pos_curso].monto_pagado +=
                                cursos[pos_curso].creditos * costo;
                    }
                }
            }

        } else
            while (archMatri.get() != '\n');
    }

}

void ordenarCursos(int cant_cursos, struct Curso *cursos) {
    struct Curso aux;
    for (int i = 0; i < cant_cursos - 1; i++) {
        for (int j = i + 1; j < cant_cursos; j++) {
            if (cursos[i].alumnos > cursos[j].alumnos or
                    (cursos[i].alumnos == cursos[j].alumnos and
                    strcmp(cursos[i].nombre, cursos[j].nombre) < 0)) {
//                intercambiarInt(cursos[i].alumnos, cursos[j].alumnos);
//                intercambiarInt(cursos[i].codigo, cursos[j].codigo);
//                intercambiarDouble(cursos[i].creditos, cursos[j].creditos);
//                intercambiarDouble(cursos[i].monto_pagado,
//                        cursos[j].monto_pagado);
//                intercambiarCadenas(cursos[i].nombre, cursos[j].nombre);
                aux = cursos[i];
                cursos[i] = cursos[j];
                cursos[j] = aux;
            }
        }
    }

}

void emitirReporte(int semestre, int cant_cursos, struct Curso *cursos,
        const char *nombReporte) {

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirEncabezado(archReporte, semestre);
    double suma = 0;
    for (int i = 0; i < cant_cursos; i++) {
        modificarTexto(cursos[i].nombre);
        archReporte << setfill('0') << setw(2) << i + 1 << ")" << setfill(' ')
                << setw(10) << cursos[i].codigo << " - " << left << setw(55) <<
                cursos[i].nombre << right << setw(5) << cursos[i].creditos <<
                setw(12) << cursos[i].alumnos << setw(17) <<
                cursos[i].monto_pagado << endl;
        suma += cursos[i].monto_pagado;
    }

    imprimirCaracter('-', archReporte);
    archReporte << "MONTO TOTAL PAGADO:" << setw(86) << suma << endl;
    imprimirCaracter('=', archReporte);
}

void modificarTexto(char *cadena) {
    char car;
    for (int i = 0; cadena[i]; i++){
        car = cadena[i];
        if(car >= 'a' and car <= 'z')
            cadena[i] += 'A' - 'a';
    }
}

void imprimirEncabezado(ofstream &archReporte, int semestre) {
    int aa, ciclo;
    aa = semestre / 10;
    ciclo = semestre % 10;
    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 18) << "DETALLE DE PAGOS REALIZADOS "
            "POR CICLO" << endl;
    archReporte << setw(MAX_CAR / 2) << "CICLO: " << aa << "-" << ciclo << endl;
    imprimirCaracter('=', archReporte);
    archReporte << setprecision(2) << fixed;
    archReporte << "No." << setw(12) << "CURSO" << setw(63) << "CREDITOS" <<
            setw(15) << "ALUMNOS.MAT" << setw(15) << "MONTO PAGADO" << endl;
    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte) {
    for (int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
}

void intercambiarCadenas(char *cad1, char *cad2) {
    char aux[100];
    strcpy(aux, cad1);
    strcpy(cad1, cad2);
    strcpy(cad2, aux);
}

void intercambiarDouble(double &num1, double &num2) {
    double aux = num1;
    num1 = num2;
    num2 = aux;
}

void intercambiarInt(int &num1, int &num2) {
    int aux = num1;
    num1 = num2;
    num2 = aux;
}

int buscarEscala(char escala, int n, struct Escala *escalas) {

    for (int i = 0; i < n; i++) {
        if (escala == escalas[i].escala)
            return i;
    }
    return -1;
}

int buscarCurso(int cod_curso, int n, struct Curso *cursos) {

    for (int i = 0; i < n; i++) {
        if (cod_curso == cursos[i].codigo)
            return i;
    }
    return -1;
}

int buscarAlumno(int cod, int n, struct Alumno *alumno) {
    for (int i = 0; i < n; i++) {
        if (cod == alumno[i].codigo)
            return 1;
    }
    return -1;
}