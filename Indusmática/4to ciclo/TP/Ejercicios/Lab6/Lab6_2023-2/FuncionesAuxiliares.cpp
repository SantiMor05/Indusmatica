#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_NOMBRE 45
#define MAX_CAR_APELLIDO 15
#define MAX_CAR 120

using namespace std;

int pedirCiclo() {

    int ciclo, anho;
    char car;
    cout << "Ingrese el anho y el ciclo para el cual se emitira el reporte "
            "(aaaa-c) : ";
    cin >> anho >> car >> ciclo;
    return anho * 10 + ciclo;

}

void leerAlumnos(int &cant_alumnos, int *alumnos, char *escala_alum,
        const char *nombAlumnos) {

    ifstream archAlumnos(nombAlumnos, ios::in);
    if (not archAlumnos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombAlumnos << endl;
        exit(1);
    }

    cant_alumnos = 0;
    while (true) {
        archAlumnos >> alumnos[cant_alumnos];
        if (archAlumnos.eof())break;
        archAlumnos >> escala_alum[cant_alumnos];
        cant_alumnos++;
    }

    ordenarAlumnos(cant_alumnos, alumnos, escala_alum);
}

void ordenarAlumnos(int cant_alumnos, int *alumnos, char *escala_alum) {

    for (int i = 0; i < cant_alumnos; i++) {
        for (int j = i + 1; j < cant_alumnos; j++) {
            if (alumnos[i] > alumnos[j]) {
                intercambiarInt(i, j, alumnos);
                intercambiarChar(i, j, escala_alum);
            }
        }
    }

}

void intercambiarInt(int i, int j, int *arr) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiarChar(int i, int j, char *arr) {
    char aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiarDouble(int i, int j, double *arr) {
    double aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void leerCursos(int &cant_cursos, int *curso, double *creditos,
        const char *nombCurso) {

    ifstream archCurso(nombCurso, ios::in);
    if (not archCurso.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCurso << endl;
        exit(1);
    }
    //109263    Algoritmia    4.25
    cant_cursos = 0;
    while (true) {
        archCurso >> curso[cant_cursos];
        if (archCurso.eof())break;

        //Saltamos el nombre del curso
        archCurso >> ws;
        while (archCurso.get() != ' ');

        archCurso >> creditos[cant_cursos];
        cant_cursos++;
    }
    ordernarCursos(cant_cursos, curso, creditos);
}

void ordernarCursos(int cant_cursos, int *curso, double *creditos) {

    for (int i = 0; i < cant_cursos; i++) {
        for (int j = i + 1; j < cant_cursos; j++) {
            if (curso[i] > curso[j]) {
                intercambiarInt(i, j, curso);
                intercambiarDouble(i, j, creditos);
            }
        }
    }

}

void leerEscalas(int &cant_escalas, int *ciclo, char *escala, double *costo,
        const char *nombEscalas) {


    int aa, semestre;
    char car;
    ifstream archEscalas(nombEscalas, ios::in);
    if (not archEscalas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombEscalas << endl;
        exit(1);
    }
    cant_escalas = 0;
    //2021-2    C    288.65
    while (true) {
        archEscalas >> aa;
        if (archEscalas.eof())break;
        archEscalas >> car >> semestre >> escala[cant_escalas] >>
                costo[cant_escalas];
        ciclo[cant_escalas] = aa * 10 + semestre;

        cant_escalas++;
    }
}

void leerMatricula(int ciclo_usuario, int cant_alumnos, int *alumnos,
        char *escala_alum, int *num_cursos, double *total_creditos,
        int cant_cursos, int *curso, double *creditos, int cant_escalas,
        int *ciclo, char *escala, double *costo, double *pago,
        const char *nombMatricula) {

    int aa, semestre, cod_alum, cod_curso;
    int ciclo_matri;
    int pos_alum, pos_curso, pos_escala;
    char car;
    ifstream archMatricula(nombMatricula, ios::in);
    if (not archMatricula.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMatricula << endl;
        exit(1);
    }
    //2023-2    20231938    481203    375219    231286    231292
    while (true) {
        archMatricula >> aa;
        if (archMatricula.eof())break;
        archMatricula >> car >> semestre >> cod_alum;
        ciclo_matri = aa * 10 + semestre;
        if (ciclo_matri == ciclo_usuario) {
            pos_alum = buscar(cod_alum, cant_alumnos, alumnos);
            pos_escala = buscarEscalas(cant_escalas, ciclo_matri,
                    escala_alum[pos_alum], ciclo, escala);
            if (pos_alum > 0) {
                while (archMatricula.get() != '\n') {
                    archMatricula >> cod_curso;
                    pos_curso = buscar(cod_curso, cant_cursos, curso);
                    if (pos_curso > 0) {
                        num_cursos[pos_alum]++;
                        total_creditos[pos_alum] += creditos[pos_curso];
                        pago[pos_alum] += creditos[pos_curso] * costo[pos_escala];
                    }
                }
            } else {
                while (archMatricula.get() != '\n');
            }
        }
        else
            while (archMatricula.get() != '\n');

    }
}

void emitirReporte(int ciclo, int cant_alumnos, int *alumnos, char *escala_alum,
        int *num_cursos, double *total_creditos, double *pago,
        const char *nombNombres, const char *nombApellidos,
        const char *nombReporte) {


    ifstream archNombres(nombNombres, ios::in);
    if (not archNombres.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombNombres << endl;
        exit(1);
    }

    ifstream archApellidos(nombApellidos, ios::in);
    if (not archApellidos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombApellidos << endl;
        exit(1);
    }

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    int codigo_alum, pos;
    char nombre[MAX_CAR_NOMBRE], apellido[MAX_CAR_APELLIDO];
    
    imprimirEncabezado(ciclo, archReporte);
    while (true) {
        archNombres >> codigo_alum;
        if (archNombres.eof())break;
        archNombres >> nombre;
        archApellidos >> apellido;
        if (archApellidos.eof())break;

        pos = buscar(codigo_alum, cant_alumnos, alumnos);
        if(pos > 0){
            modificaTexto(nombre, apellido);
            archReporte << codigo_alum << " - " << setw(45) << nombre << setw(8)
                    << num_cursos[pos] << setw(12) << total_creditos[pos] <<
                    setw(8) << escala_alum[pos] << setw(15) << pago[pos] << endl;
        }
    }
}

void imprimirEncabezado(int ciclo, ofstream &archReporte){
    
    int aa = ciclo / 10;
    int semestre = ciclo % 10;
    
    archReporte << setprecision(2) << fixed;
    
    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" << endl;
    archReporte << setw(MAX_CAR / 2 + 18) << "DETALLE DE PAGOS REALIZADO POR "
            "CICLO" << endl;
    archReporte << setw(MAX_CAR / 2) << "CICLO: " << aa << "-" << semestre << 
            endl;
    imprimirCaracter('=', archReporte);
    
    archReporte << setw(10) << "ALUMNOS" << setw(45) << "No. de Cursos" << 
            setw(18) << "CREDITOS" << setw(15) << "ESCALA" << setw(24) <<
            "MONTO PAGADO" << endl;
    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte){
    
    for(int i = 0; i <MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
}

void modificaTexto(char *cadena1, char *cadena2) {

    int longitud;
    for (int i = 0; cadena1[i]; i++) {
        if (cadena1[i] == '_'){
            cadena1[i] = 0;
            break;
        }
            
    }
    longitud = strlen(cadena1);
    char aux[MAX_CAR_NOMBRE];
    copiar(aux, cadena1);
    concatenar(aux, " ");
    concatenar(aux, cadena2);
    concatenar(aux, " ");
    concatenar(aux, &cadena1[longitud + 1]);
    
    copiar(cadena1, aux);
}

void concatenar(char *cadena1, const char *cadena2) {

    int longitud = strlen(cadena1);
    copiar(&cadena1[longitud], cadena2);
}

int strlen(char *cadena) {

    int i;
    for (i = 0; cadena[i]; i++);
    return i;
}

void copiar(char *destino, const char *fuente) {

    char car;
    int i;
    for (i = 0; fuente[i]; i++) {
        car = fuente[i];
        if (car >= 'a' and car <= 'z')
            car += 'A' - 'a';
        if(car == '_') car = ' ';
        destino[i] = car;
    }
    destino[i] = 0;
}

int buscarEscalas(int cant_escalas, int ciclo_matri,
        char escala_alum, int *ciclo, char *escala) {

    for (int i = 0; i < cant_escalas; i++) {
        if (ciclo_matri == ciclo[i] and escala_alum == escala[i])
            return i;
    }
    return -1;
}

int buscar(int codigo, int cant, int *arr) {

    int ini = 0, fin = cant - 1, medio;

    while (ini <= fin) {
        medio = (ini + fin) / 2;
        if (codigo == arr[medio]) return medio;
        else if (codigo > arr[medio])
            ini = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}