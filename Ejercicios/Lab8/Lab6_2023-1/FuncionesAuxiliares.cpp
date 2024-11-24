#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 120
#define MAX_LIBROS_ALUM 4
#define MAX_LIBROS_DOC 6
#define MAX_LIBROS_VIS 2


using namespace std;

void leerDatosLibros(int &cant_libros, struct Libros *libros,
        const char *nomblibros) {

    ifstream archLibros(nomblibros, ios::in);
    if (not archLibros.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nomblibros << endl;
        exit(1);
    }

    cant_libros = 0;
    while (true) {
        leerLibro(archLibros, libros[cant_libros]);
        if (archLibros.eof())break;
        cant_libros++;
    }
}

void leerLibro(ifstream &archLibros, struct Libros &libros) {

    char car;
    archLibros.getline(libros.codigo, 8, ',');
    if (archLibros.eof())return;
    archLibros.getline(libros.titulo, 40, ',');
    archLibros.getline(libros.autor, 40, ',');
    archLibros >> libros.cantidad >> car >> libros.precio;
    archLibros.get();

}

void leerDatosUsuarios(int &cant_usuarios, struct Usuarios *usuarios,
        const char *nombUsuario) {

    ifstream archUsuario(nombUsuario, ios::in);
    if (not archUsuario.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombUsuario << endl;
        exit(1);
    }

    cant_usuarios = 0;
    while (true) {
        leerUsuario(archUsuario, usuarios[cant_usuarios]);
        if (archUsuario.eof())break;
        cant_usuarios++;
    }
}

void leerUsuario(ifstream &archUsuario, struct Usuarios &usuarios) {
    char car;
    archUsuario >> usuarios.dni;
    if (archUsuario.eof())return;
    archUsuario.get();
    archUsuario.getline(usuarios.nombre, 40, ',');
    archUsuario >> usuarios.categoria >> car >> usuarios.calificacion;

}

void leerDatosSolicitudes(int &cant_solicitudes, struct Solicitudes *solicitudes,
        const char *nombSoli) {

    ifstream archSoli(nombSoli, ios::in);
    if (not archSoli.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombSoli << endl;
        exit(1);
    }
    cant_solicitudes = 0;
    while (true) {
        leerSolicitud(archSoli, solicitudes[cant_solicitudes]);
        if (archSoli.eof())break;
        cant_solicitudes++;
    }
}

void leerSolicitud(ifstream &archSoli, struct Solicitudes &solicitudes) {
    archSoli >> solicitudes.usuario;
    if (archSoli.eof())return;
    archSoli >> solicitudes.libro;
}

void imprimirReporte(int cant_libros, struct Libros *libros, int cant_usuarios,
        struct Usuarios *usuarios, int cant_solicitudes,
        struct Solicitudes *solicitudes, const char *nombReporte) {

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirLibros(cant_libros, libros, archReporte);
    imprimirUsuarios(cant_usuarios, usuarios, archReporte);
    imprimirSolicitudes(cant_solicitudes, solicitudes, archReporte);
}

void ordenarUsuarios(int cant_usuarios, struct Usuarios *usuarios){
    for(int i = 0; i < cant_usuarios - 1; i++){
        for(int j = i + 1; j < cant_usuarios;j++){
            if(usuarios[i].categoria  > usuarios[j].categoria or 
                    (usuarios[i].categoria  == usuarios[j].categoria and 
                    usuarios[i].calificacion < usuarios[j].calificacion)){
                intercambiarUsuarios(usuarios[i], usuarios[j]);
            }
        }
    }
}

void intercambiarUsuarios(struct Usuarios &usuarios1, struct Usuarios &usuarios2){
    
    struct Usuarios aux;
    
    aux = usuarios1;
    usuarios1 = usuarios2;
    usuarios2 = aux;
}

void atenderSolicitudes(int cant_libros, struct Libros *libros, 
        int cant_usuarios, struct Usuarios *usuarios, int cant_solicitudes,
        struct Solicitudes *solicitudes, const char *nombDenegados){
    
    ofstream archDenegados(nombDenegados, ios::out);
    if (not archDenegados.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombDenegados << endl;
        exit(1);
    }
    
    int pos_libro;
    int max;
    for(int i = 0; i < cant_usuarios; i++){ //Recorremos los usuarios
        for(int j = 0; j < cant_solicitudes;j++){ //Recorremos las solicitudes
            if(solicitudes[j].usuario == usuarios[i].dni){
                max = encontrarMax(usuarios[i]);
                if(usuarios[i].cant_prestados < max){
                    pos_libro = buscarLibro(solicitudes[j].libro, cant_libros,
                        libros);
                    if(pos_libro != -1){
                        if(libros[pos_libro].cantidad > 0){
                            libros[pos_libro].cantidad--;
                            usuarios[i].cant_prestados++;
                            libros[pos_libro].prestados++;
                        }
                        else{
                            usuarios[i].cant_no_prestados++;
                            archDenegados << left << setw(12) << 
                                    solicitudes[j].usuario << 
                                    solicitudes[j].libro << endl;
                        }
                    }
                }
                else{
                    usuarios[i].cant_no_prestados++;
                    usuarios[i].calificacion *= 90.0 / 100;
                    archDenegados << left << setw(12) << solicitudes[j].usuario 
                            << solicitudes[j].libro << endl;
                }
                
            }
        }
    }
}


int encontrarMax(const struct Usuarios &usuarios){
    
    if(usuarios.categoria == 'A')
        return MAX_LIBROS_ALUM;
    else if (usuarios.categoria == 'D')
        return MAX_LIBROS_DOC;
    else return MAX_LIBROS_VIS;
    
}

int buscarLibro(char *cod_libro, int cant_libros, struct Libros *libros){
    
    for(int i = 0; i < cant_libros; i++){
        if(strcmp(cod_libro, libros[i].codigo) == 0)
            return i;
    }
    return -1;
}

void imprimirLibros(int &cant_libros, struct Libros *libros,
        ofstream &archReporte) {

    archReporte << "LIBROS" << endl;
    imprimirCaracter('=', archReporte);
    archReporte << "Codigo" << setw(10) << "Titulo" << setw(39) << "Autor" <<
            setw(32) << "Cantidad" << setw(12) << "Precio" << setw(12) <<
            "Prestados" << endl;
    imprimirCaracter('-', archReporte);

    archReporte << setprecision(2) << fixed;
    for (int i = 0; i < cant_libros; i++) {
        archReporte << left << setw(10) << libros[i].codigo << setw(40) <<
                libros[i].titulo << setw(30) << libros[i].autor << right <<
                setw(5) << libros[i].cantidad << setw(14) << libros[i].precio <<
                setw(9) << libros[i].prestados << endl;
    }
}

void imprimirUsuarios(int cant_usuarios, struct Usuarios *usuarios,
        ofstream &archReporte) {
    archReporte << endl;
    imprimirCaracter('=', archReporte);
    archReporte << "USUARIOS" << endl;
    imprimirCaracter('=', archReporte);
    archReporte << "Dni" << setw(15) << "Nombre" << setw(43) << "Categoria" <<
            setw(16) << "Calificacion" << setw(15) << "Prestados" << setw(16) <<
            "No Prestados" << endl;
    imprimirCaracter('-', archReporte);

    for (int i = 0; i < cant_usuarios; i++) {
        archReporte << left << setw(12) << usuarios[i].dni << setw(40) <<
                usuarios[i].nombre << right << setw(5) << usuarios[i].categoria
                << setw(16) << usuarios[i].calificacion << setw(15) <<
                usuarios[i].cant_prestados << setw(15) << 
                usuarios[i].cant_no_prestados << endl;
    }
}

void imprimirSolicitudes(int cant_solicitudes, struct Solicitudes *solicitudes, 
        ofstream &archReporte){
    
    archReporte << endl;
    imprimirCaracter('=', archReporte);
    archReporte << "SOLICITUDES" << endl;
    imprimirCaracter('=', archReporte);
    
    archReporte << "Dni" << setw(14) << "Libro" << endl;
    imprimirCaracter('-', archReporte);
    
    for(int i = 0; i < cant_solicitudes; i++){
        archReporte <<left << setw(12) << solicitudes[i].usuario << 
                solicitudes[i].libro << right << endl;
    }
}

void imprimirCaracter(char car, ofstream &archReporte) {
    for (int i = 0; i < MAX_CAR; i++)
        archReporte.put(car);
    archReporte << endl;
}