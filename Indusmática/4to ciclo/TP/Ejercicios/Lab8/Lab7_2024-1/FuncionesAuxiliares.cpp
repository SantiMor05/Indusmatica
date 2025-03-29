#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 150

using namespace std;

void pedirDatos(char *&facu1, char *&facu2) {

    cout << "Ingrese el codigo de dos facultades" << endl;
    cout << "Ingrese el codigo de la facultad 1: ";
    facu1 = leerCadenaExactaConsola();
    cout << "Ingrese el codigo de la facultad 2: ";
    facu2 = leerCadenaExactaConsola();

}

char *leerCadenaExactaConsola() {

    char arr[40];

    cin >> arr;
    int longitud = strlen(arr);
    pasarAMayusculas(arr);
    char *ptr = new char[longitud + 1];
    strcpy(ptr, arr);

}

void pasarAMayusculas(char *arr) {
    char car;
    for (int i = 0; arr[i]; i++) {
        car = arr[i];
        if (car >= 'a' and car <= 'z')
            arr[i] += 'A' - 'a';
    }

}

void leerCalificaciones(int &cant_alumnos, int *arrCodigoAlumnos,
        int *arrNumCursos, double *arrSumaPonderada, double *arrNumCreditos,
        const char *nombCali) {

    ifstream archCali(nombCali, ios::in);
    if (not archCali.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCali << endl;
        exit(1);
    }

    char aux[10];
    int alumno, pos;
    double nota, credito;
    cant_alumnos = 0;
    while (true) {
        archCali >> aux;
        if (archCali.eof())break;
        archCali >> credito;
        while (archCali.get() != '\n') {
            archCali >> alumno >> nota;
            pos = buscarAlumno(alumno, cant_alumnos, arrCodigoAlumnos);
            if (pos == -1) {
                arrCodigoAlumnos[cant_alumnos] = alumno;
                pos = cant_alumnos;
                cant_alumnos++;
            }
            arrNumCursos[pos]++;
            arrSumaPonderada[pos] += nota * credito;
            arrNumCreditos[pos] += credito;

        }
    }
}

void leerAlumnos(int cant_alumnos, int *arrCodigoAlumnos, char **arrAlumnos,
        char **arrFacultad, const char *nombAlum) {

    ifstream archAlum(nombAlum, ios::in);
    if (not archAlum.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombAlum << endl;
        exit(1);
    }

    int alumno, pos;

    while (true) {
        archAlum >> alumno;
        if (archAlum.eof())break;
        archAlum.get();
        pos = buscarAlumno(alumno, cant_alumnos, arrCodigoAlumnos);
        if(pos != -1){
            arrAlumnos[pos] = leerCadenaExacta(archAlum, 1);
            arrFacultad[pos] = leerCadenaExacta(archAlum, 2);
        }
        else
            while(archAlum.get() != '\n');
        
    }

}

void emitirReporte(char *facu1, char *facu2, int cant_alumnos,
        int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
        double *arrNumCreditos, char **arrAlumnos, char **arrFacultad,
        double *promedio, const char *nombReporte, const char *nombFacu) {


    char nombre_mayor[100];
    int alumno_mayor;
    double creditos_mayor = 0;
    
    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    imprimirEncabezado(nombFacu, facu1, facu2, archReporte);

    ordenarAlumnos(cant_alumnos, arrCodigoAlumnos, arrNumCursos,
            arrSumaPonderada, arrNumCreditos, arrAlumnos, arrFacultad,
            promedio);
    archReporte << setprecision(2) << fixed;
    for (int i = 0; i < cant_alumnos; i++){
        if(strcmp(facu1,arrFacultad[i]) == 0 or 
                strcmp(facu2,arrFacultad[i]) == 0){
            archReporte << left << arrCodigoAlumnos[i] << " - " << setw(50) <<
                    arrAlumnos[i] << right << setw(3) << arrNumCursos[i] << 
                    setw(19) << arrSumaPonderada[i] << setw(20)  << 
                    arrNumCreditos[i] << setw(20) << promedio[i] << left <<
                    setw(11) << " " << arrFacultad[i] << endl;
            
            if(arrNumCreditos[i] > creditos_mayor){
                creditos_mayor = arrNumCreditos[i];
                strcpy(nombre_mayor,arrAlumnos[i]);
                alumno_mayor = arrCodigoAlumnos[i];
            }
            
        }
    }
    imprimirCaracter('=', archReporte);
    archReporte <<"Alumno con mayor numero de creditos matriculados : " <<
            nombre_mayor << " [" << alumno_mayor <<"] con " << creditos_mayor <<
            " matriculados" << endl;
}

void ordenarAlumnos(int cant_alumnos, int *arrCodigoAlumnos, int *arrNumCursos,
        double *arrSumaPonderada, double *arrNumCreditos, char **arrAlumnos,
        char **arrFacultad, double *promedio) {
    int resultado;
    for (int i = 0; i < cant_alumnos - 1; i++) {
        if (promedio[i] == 0) {
            promedio[i] = arrSumaPonderada[i] / arrNumCreditos[i];
        }
        for (int j = i + 1; j < cant_alumnos; j++) {
            if (promedio[j] == 0)
                promedio[j] = arrSumaPonderada[j] / arrNumCreditos[j];
            resultado = strcmp(arrFacultad[i], arrFacultad[j]);
            if (resultado > 0 or (resultado == 0 and promedio[i] < promedio[j])) {
                intercambiarInt(i, j, arrCodigoAlumnos);
                intercambiarInt(i, j, arrNumCursos);
                intercambiarDouble(i, j, arrSumaPonderada);
                intercambiarDouble(i, j, arrNumCreditos);
                intercambiarDouble(i, j, promedio);
                intercambiarCadenas(arrAlumnos[i], arrAlumnos[j]);
                intercambiarCadenas(arrFacultad[i], arrFacultad[j]);
            }
        }
    }

}

void intercambiarCadenas(char *&cad1, char *&cad2) {
    char *ptr = cad1;
    cad1 = cad2;
    cad2 = ptr;
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

void imprimirEncabezado(const char *nombFacu, char *facu1, char *facu2,
        ofstream &archReporte) {

    ifstream archFacu(nombFacu, ios::in);
    if (not archFacu.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombFacu << endl;
        exit(1);
    }

    char aux[50], facultad[15], nombre1[50], nombre2[50], *ptr;
    int longitud;

    while (true) {
        archFacu >> aux;
        if (archFacu.eof())break;
        archFacu >> facultad;
        if (strcmp(facultad, facu1) == 0)
            strcpy(nombre1, aux);
        else if (strcmp(facultad, facu2) == 0)
            strcpy(nombre2, aux);
    }

    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP" <<
            endl;
    archReporte << setw(MAX_CAR / 2 + 23) << "PROMEDIO PONDERADO DE LOS ALUMNOS "
            "MATRICULADOS" << endl;

    archReporte << setw(MAX_CAR / 2 + 6) << "CICLO: 2024-1" << endl;
    formatearNombre(nombre1);
    formatearNombre(nombre2);
    longitud = strlen(nombre1);
    archReporte << setw(MAX_CAR / 2 + longitud / 2) << nombre1 << endl;
    archReporte << setw(MAX_CAR / 2) << "Y" << endl;
    //    ptr = strstr(nombre2, " ");
    longitud = strlen(nombre2);
    archReporte << setw(MAX_CAR / 2 + (longitud - 1) / 2) << nombre2 << endl;
    imprimirCaracter('=', archReporte);
    archReporte << setw(10) << "ALUMNO" << setw(60) << "No. de Cursos" <<
            setw(18) << "Suma Ponderada" << setw(20) << "No. de Creditos" <<
            setw(22) << "Promedio Ponderado" << setw(12) << "Facultad" << endl;
    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte) {
    for (int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
}

void formatearNombre(char *nombre) {
    for (int i = 0; nombre[i]; i++) {
        if (nombre[i] == '_')
            nombre[i] = ' ';
    }
}

char *leerCadenaExacta(ifstream &archAlum, int opcion) {

    char nombre[70];

    if (opcion == 1)
        archAlum.getline(nombre, 70, ',');
    else
        archAlum.getline(nombre, 70);

    int longitud = strlen(nombre);
    char *ptr = new char [longitud + 1];

    strcpy(ptr, nombre);
    return ptr;
}

int buscarAlumno(int alumno, int cant_alumnos, int *arrCodigoAlumnos) {
    for (int i = 0; i < cant_alumnos; i++) {
        if (arrCodigoAlumnos[i] == alumno)
            return i;
    }
    return -1;
}

//void insertarOrdenado(int alumno, int cant_alumnos, int *arrCodigoAlumnos, 
//        int *arrNumCursos, double *arrSumaPonderada, double *arrNumCreditos,
//        int &pos){
//    int i;
//    for(i = cant_alumnos - 1; i >= 0; i--){
//        if(alumno <= arrCodigoAlumnos[i]){
//            arrCodigoAlumnos[i+1] = arrCodigoAlumnos[i];
//            arrNumCursos[i+1] = arrNumCursos[i];
//            arrSumaPonderada[i+1] = arrSumaPonderada[i];
//            arrNumCreditos[i+1] = arrNumCreditos[i];
//        }
//        else{
//            break;
//        }
//    }
//    arrCodigoAlumnos[i+1] = arrCodigoAlumnos[i];
//    pos = i + 1;
//    cant_alumnos++;
//}

//int buscarAlumno(int alumno, int cant_alumnos, int *arrCodigoAlumnos){
//    
//    int ini = 0, fin = cant_alumnos - 1, medio;
//    
//    while(ini <= fin){
//        medio =(ini + fin) / 2;
//        if(arrCodigoAlumnos[medio] == alumno) return medio;
//        else if(arrCodigoAlumnos[medio] > alumno){
//            fin = medio - 1;
//        }
//        else 
//            ini = medio + 1;
//    }
//    return -1;
//}