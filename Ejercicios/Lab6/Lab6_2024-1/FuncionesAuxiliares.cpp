#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 135
#define MAX_CAR_NOMBRE 40

using namespace std;


char *pedirFacultad(){

    char *nombre;
    nombre = new char[35];
    cout << "Ingrese la facultad deseada (separada por _) : ";
    cin >> nombre;
    
    pasarAMayusculas(nombre);   
    
    return nombre;
    
}

int buscarCodigoFacu(char *nombre, const char *nombFacu){
    
    int codigo, comparacion;
    ifstream archFacu(nombFacu, ios::in);
    if(not archFacu.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombFacu << endl;
        exit(1);
    }
    
    char facu[35];
    while(true){
        archFacu >> facu;
        if(archFacu.eof())break;
        archFacu >> codigo;
        comparacion = comparar(nombre, facu);
        if(comparacion == 0){
            return codigo;
        }
    }
    
}

int comparar(char *cadena1, char *cadena2){
    int i = 0;
    while(cadena1[i] == cadena2[i]){
        if(cadena1[i] == 0)return 0;
        i++;
    }
    return cadena1[i] - cadena2[i];
}

void pasarAMayusculas(char *facultad){
    for(int i = 0; facultad[i]; i++){
        if(facultad[i] >= 'a' and facultad[i] <= 'z')
            facultad[i] += 'A' - 'a';
    }
}

void leerAlumnos(int &num_alumnos, int *arrCodigoAlumnos, int *arrNumCursos, 
        double *arrSumaPonderada, double *arrNumCreditos, const char *nombCali){
    
    
    char curso[8];
    double creditos, nota;
    int alumno, pos;
    
    ifstream archCali(nombCali, ios::in);
    if(not archCali.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombCali << endl;
        exit(1);
    }
    
    while(true){
        
        archCali >> curso;
        if(archCali.eof())break;
        archCali >> creditos;
        while(archCali.get() != '\n'){
            archCali >> alumno >> nota;
            pos = buscarAlumno(alumno, num_alumnos, arrCodigoAlumnos);
            if(pos >= 0){
                //Se encontró, actualizamos datos
                arrNumCursos[pos]++;
                arrSumaPonderada[pos] += nota * creditos;
                arrNumCreditos[pos] += creditos;
            }
            else{
                //No se encontró, insertamos alumno ordenadamente;
                insertarOrdenado(num_alumnos, arrCodigoAlumnos, arrNumCursos, 
                        arrSumaPonderada, arrNumCreditos, alumno, nota, 
                        creditos);
            }
        }
        
    }
}

int buscarAlumno(int alumno, int num_alumnos, int *arrCodigoAlumnos){
    
    int ini, fin, medio;
    ini = 0;
    fin = num_alumnos - 1;

    while(ini <= fin){
        medio = (ini + fin) / 2;
        if(alumno == arrCodigoAlumnos[medio]) return medio;
        else if(alumno > arrCodigoAlumnos[medio]) 
            ini = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

void insertarOrdenado(int &num_alumnos, int *arrCodigoAlumnos, int *arrNumCursos, 
        double *arrSumaPonderada, double *arrNumCreditos, int alumno,
        int nota, double creditos){
    
    if(num_alumnos == 0)
        arrCodigoAlumnos[0] = alumno;
    else{
        int  i = num_alumnos - 1;
        for(i = num_alumnos - 1; i >= 0; i--){
            if(alumno < arrCodigoAlumnos[i]){
                arrCodigoAlumnos[i+1] = arrCodigoAlumnos[i];
                arrNumCursos[i+1] = arrNumCursos[i];
                arrSumaPonderada[i+1] = arrSumaPonderada[i];
                arrNumCreditos[i+1] = arrNumCreditos[i];
            }
            else
                break;
        }
        arrCodigoAlumnos[i+1] = alumno;
        arrNumCursos[i+1] = 1;
        arrSumaPonderada[i+1] = nota * creditos;
        arrNumCreditos[i+1] = creditos;
    }
    num_alumnos++;
}


void imprimirReporte(const char *nombAlumnos, char *facultad, int num_alumnos, 
        int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada, 
        double *arrNumCreditos,  const char *nombReporte){
    
    
    ifstream archAlumnos(nombAlumnos, ios::in);
    if(not archAlumnos.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombAlumnos << endl;
        exit(1);
    }
    
    ofstream archReporte(nombReporte, ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    
    int alumno,facu, pos,cod_facultad;
    char nombre[MAX_CAR_NOMBRE];
    cod_facultad = buscarCodigoFacu(facultad, "Facultades.txt");
    imprimirEncabezado(facultad, archReporte);
    archReporte << setprecision(2) << fixed;
    while(true){
        archAlumnos >> alumno;
        if(archAlumnos.eof())break;
        pos = buscarAlumno(alumno, num_alumnos, arrCodigoAlumnos);
        if(pos >= 0){
            archAlumnos >> nombre >> facu;
            if(facu == cod_facultad){
                formatearNombre(nombre);
                archReporte << setw(10) << alumno << " - " << setw(40) << left <<
                        nombre << right <<setw(6) << arrNumCursos[pos] << 
                        setw(22) << arrSumaPonderada[pos] << setw(24) << 
                        arrNumCreditos[pos]  << setw(21) << 
                        arrSumaPonderada[pos] /  arrNumCreditos[pos] << endl;
            }
        }
        else{
            while(archAlumnos.get() != '\n');
        }
    }
}
    


void formatearNombre(char *nombre){
    
    char aux[MAX_CAR_NOMBRE];
    int pos, cont = 0;
    for(int i = 0; nombre[i]; i++){
        if(nombre[i] == '/'){
            nombre[i] = ' ';
            cont++;
            if(cont == 2){
                pos = i + 1;
                nombre[i] = 0;
                break;
            }
        }
    }
    
    copiarFormateada(aux, &nombre[pos]);
    concatenar(aux, " ");
    concatenar(aux, nombre);
    copiarFormateada(nombre, aux);
    pasarATipoOracion(nombre);
}

void pasarATipoOracion(char *nombre){
    bool mayuscula = true;
    char car;
    for(int i = 0; nombre[i]; i++){
        car = nombre[i];
        if(not mayuscula){
            if(car >= 'A' and car <= 'Z'){
                nombre[i] += 'a' - 'A';
            }
        }
        if(car == ' ')
            mayuscula = true;
        else mayuscula = false;
    }
    
}

void concatenar(char *cadena1, char *cadena2){
    
    int pos = strlen(cadena1);
    copiarFormateada(&cadena1[pos], cadena2);
}

int strlen(char *cadena){
    
    int i = 0;
    for(i = 0; cadena[i]; i++);
    return i;
    
}

void imprimirEncabezado(char *facultad, ofstream &archReporte){
    
    char aux[35];
    copiarFormateada(aux, facultad);
    
    archReporte << setw(MAX_CAR / 2 + 12) << "INSTITUCION EDUCATIVA_TP"  << 
            endl;
    archReporte << setw(MAX_CAR / 2 + 23) << "PROMEDIO PONDERADO DE LOS "
            "ALUMNOS MATRICULADOS" << endl;
    archReporte << setw(MAX_CAR / 2 + 6) << "CICLO : 2024-1" << endl;
    
    int longitud = calcularLongitudTexto(facultad);
    
    archReporte << setw(MAX_CAR / 2 + longitud / 2) << aux << endl;
    imprimirCaracter('=', archReporte);
    
    archReporte << setw(20) << "ALUMNO" << setw(45) << "No. de Cursos" << 
            setw(20) << "Suma Ponderada" << setw(25) << "No. de Creditos" <<
            setw(20) << "Prom Ponderado" << endl;
    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte){
    
    for(int  i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
}

void copiarFormateada(char *aux, const char *facultad){
    int i;
    for(i = 0; facultad[i]; i++){
        if(facultad[i] == '_' or  facultad[i] == '-')
            aux[i] = ' ';
        else
            aux[i] = facultad[i];
    }
    aux[i] = 0;
}

int calcularLongitudTexto(char *facultad){
    
    int i;
    
    for(i = 0 ; facultad[i]; i++);
    return i;
}