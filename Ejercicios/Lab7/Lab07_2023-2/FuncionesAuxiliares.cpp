#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 120


using namespace std;

int pedirCiclo() {

    int aa, semestre;
    char car;

    cout << "Ingrese el ciclo para el cual se emitira el reporte (aaaa-s): ";
    cin >> aa >> car >> semestre;

    return aa * 10 + semestre;

}

void leerAlumnos(int &cant_alumnos, int *alumno, char **nombre,
        char *escala_alum, const char *nombAlum) {

    ifstream archAlum(nombAlum, ios::in);
    if (not archAlum.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombAlum << endl;
        exit(1);
    }

    cant_alumnos = 0;

    while (true) {
        archAlum >> alumno[cant_alumnos];
        if (archAlum.eof()) break;
        nombre[cant_alumnos] = leerCadenaExacta(archAlum);
        formatearNombre(nombre[cant_alumnos]);
        archAlum >> escala_alum[cant_alumnos];
        cant_alumnos++;
    }
    

}

void formatearNombre(char *nombre){
    
    char car;
    for(int i = 0; i < nombre[i]; i++){
        
        car = nombre[i];
        if(car == '_')
            nombre[i] = ' ';
        if(car >= 'a' and car <='z')
            nombre[i] += 'A' - 'a';
        
    }
    
}

char *leerCadenaExacta(ifstream &archAlum) {

    char nombre[200];
    int longitud;

    archAlum >> nombre;
    longitud = strlen(nombre);
    char *ptr = new char[longitud + 1];
    strcpy(ptr, nombre);

    return ptr;
}

void strcpy2(char *destino, const char *fuente) {
    int i;
    for (i = 0; fuente[i]; i++) {
        destino[i] = fuente[i];
    }
    destino[i] = 0;
}

int strlen(char *nombre) {

    int i = 0;
    for (i = 0; nombre[i]; i++);
    return i;
}

void leerCursos(int &cant_cursos, int *curso, double *creditos,
        const char *nombCurso) {


    char nombre[100];

    ifstream archCurso(nombCurso, ios::in);
    if (not archCurso.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCurso << endl;
        exit(1);
    }

    cant_cursos = 0;
    while (true) {
        archCurso >> curso[cant_cursos];
        if (archCurso.eof()) break;
        archCurso >> nombre >> creditos[cant_cursos];
        cant_cursos++;
    }

}

void leerEscalas(int &cant_escalas, int *ciclo_escala, char *escala,
        double *costo, const char *nombEscala) {

    int aa, semestre;
    char car;
    ifstream archEscala(nombEscala, ios::in);
    if (not archEscala.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombEscala << endl;
        exit(1);
    }

    cant_escalas = 0;

    while (true) {
        archEscala >> aa;
        if (archEscala.eof())break;
        archEscala >> car >> semestre;
        ciclo_escala[cant_escalas] = aa * 10 + semestre;
        archEscala >> escala[cant_escalas] >> costo[cant_escalas];

        cant_escalas++;
    }
}

void ordenarAlumnos(int cant_alumnos, int *alumno, char **nombre,
        char *escala_alum) {

    for (int i = 0; i < cant_alumnos; i++) {
        for (int j = i + 1; j < cant_alumnos; j++) {

            if (alumno[i] > alumno[j]) {
                intercambiarInt(i, j, alumno);
                intercambiarChar(i, j, escala_alum);
                intercambiarCadena(nombre[i], nombre[j]);

            }
        }
    }
}

void ordenarCursos(int cant_cursos, int *curso, double *creditos) {

    for (int i = 0; i < cant_cursos; i++) {
        for (int j = i + 1; j < cant_cursos; j++) {

            if (curso[i] > curso[j]) {
                intercambiarInt(i, j, curso);
                intercambiarDouble(i, j, creditos);
            }
        }
    }
}

void intercambiarInt(int i, int j, int *arr) {

    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiarDouble(int i, int j, double *arr) {

    double aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiarChar(int i, int j, char *arr) {

    char aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiarCadena(char *&ptr1, char *&ptr2) {

    char * aux = ptr1;
    ptr1 = ptr2;
    ptr2 = aux;
}

void leerMatricula(int ciclo, int cant_alumnos, int *alumno, char *escala_alum, 
        int *cursos_alum, double *creditos_alum, double *monto, int cant_cursos, 
        int *curso, double *creditos, int cant_escalas, int *ciclo_escala, 
        char *escala, double *costo, const char *nombMatri) {
    
    ifstream archMatri(nombMatri, ios::in);
    if (not archMatri.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMatri << endl;
        exit(1);
    }
    
    int aa, semestre, cod_alumno, cod_curso, pos_alumno, pos_curso, pos_escala;
    char car;
    while(true){
        archMatri >> aa;
        if(archMatri.eof())break;
        archMatri >> car >> semestre;
        if(aa * 10 + semestre == ciclo){
            archMatri >> cod_alumno;
            pos_alumno = buscar(cod_alumno, cant_alumnos, alumno);
            if(pos_alumno != -1){
                pos_escala = buscarEscala(ciclo, escala_alum[pos_alumno], 
                        cant_escalas, ciclo_escala, escala);
                while(archMatri.get() != '\n'){
                    archMatri >> cod_curso;
                    pos_curso = buscar(cod_curso, cant_cursos, curso);
                    if(pos_curso != -1){
                        cursos_alum[pos_alumno]++;
                        creditos_alum[pos_alumno] += creditos[pos_curso];
                        monto[pos_alumno] += creditos[pos_curso] * 
                                costo[pos_escala];
                    }
                }
            }
            else
                while(archMatri.get() != '\n'); 
        }
        else
            while(archMatri.get() != '\n');
    }
}


int buscarEscala(int ciclo, char escala_alum, int cant_escalas, 
        int *ciclo_escala, char *escala){
    
    for (int i = 0; i < cant_escalas; i++){
        if(ciclo == ciclo_escala[i] and escala_alum == escala[i])
            return i;
    }
    
    return -1;
}

int buscar(int cod, int cant, int *arr){
    int i;
    for(i = 0; i < cant; i++){
        if(cod == arr[i])
            return i;
    }
    return -1;
}

void ordenarArreglos(int cant_alumnos, int *alumno, char **nombre, 
        char *escala_alum, int *cursos_alum, double *creditos_alum, 
        double *monto){
    
    for(int i = 0; i < cant_alumnos; i++){
        for(int j = i + 1; j < cant_alumnos; j++){
            if(escala_alum[j] < escala_alum[i] or 
                    (escala_alum[j] == escala_alum[i] and 
                    strcmp(nombre[i], nombre[j]) > 0)){
                intercambiarInt(i,j,alumno);
                intercambiarInt(i,j,cursos_alum);
                intercambiarChar(i,j,escala_alum);
                intercambiarDouble(i,j,creditos_alum);
                intercambiarDouble(i,j,monto);
                intercambiarCadena(nombre[i], nombre[j]);
                
            }
        }
    }
    
}

void emitirReporte(int ciclo, int cant_alumnos, int *alumno, char **nombre, 
        char *escala_alum, int *cursos_alum, double *creditos_alum, 
        double *monto, const char *nombReporte){
    
    
    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    imprimirEncabezado(ciclo, archReporte);
    archReporte << setprecision(2) << fixed;
    
    double suma = 0;
    for(int i = 0; i < cant_alumnos; i++){
        archReporte << setfill('0') << setw(2) << i + 1 << ")" << setfill(' ')
                << setw(12) << alumno[i] << " - " << left << setw(40) << 
                nombre[i] << right << setw(4) << cursos_alum[i] << setw(19) << 
                creditos_alum[i] << setw(12) << escala_alum[i] << setw(17) << 
                monto[i] << endl;
        suma += monto[i];
    }
    
    imprimirCaracter('-', archReporte);
    archReporte << "MONTO TOTAL PAGADO: " << setw(90) << suma << endl;
     imprimirCaracter('=', archReporte);
}

void imprimirEncabezado(int ciclo, ofstream &archReporte){
    
    int aa = ciclo / 10;
    int semestre = ciclo % 10;
    
    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 18) << "DETALLE DE PAGOS REALIZADO POR "
            "CICLO " << endl;
    archReporte << setw(MAX_CAR/2) << "CICLO: " << aa << "-" << semestre << 
            endl;
    
    imprimirCaracter('=', archReporte);
    
    archReporte << "No." << setw(15) << "ALUMNO" << setw(50) << "No. de Cursos"
            << setw(15) <<  "CREDITOS" << setw(12) << "ESCALA" << setw(18) <<
            "MONTO PAGADO" << endl;
    imprimirCaracter('-', archReporte);
}


void imprimirCaracter(char car, ofstream &archReporte){
    
    for(int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
}