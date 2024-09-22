#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 100
#define MAX_CAR_NOMB 45

using namespace std;

void abrirArchivos(ifstream &archCartelera, ifstream &archCli,
        ofstream &archReporte, const char *nombCartelera,
        const char* nombClientes, const char *nombReporte) {

    archCartelera.open(nombCartelera, ios::in);
    if (not archCartelera.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo" << nombCartelera << endl;
        exit(1);
    }

    archCli.open(nombClientes, ios::in);
    if (not archCli.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo" << nombClientes << endl;
        exit(1);
    }

    archReporte.open(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo" << nombReporte << endl;
        exit(1);
    }
}

void leerProcesarImprimirDatos(ifstream &archCartelera, ifstream &archCli,
        ofstream &archReporte) {

    int cod_dist;

    imprimirEncabezado(archReporte);

    while (true) {
        archCartelera >> cod_dist;
        if (archCartelera.eof())break;
        archReporte << "Distrito: " << cod_dist << " - ";
        leerImprimirTexto(archCartelera, archReporte, 0);
        archReporte << endl;
        imprimirCaracter('-', archReporte);

        leerImprimirPeliculas(archCartelera, archCli, archReporte, cod_dist);
    }

}

void leerImprimirPeliculas(ifstream &archCartelera, ifstream &archCli,
        ofstream &archReporte, int cod_dist) {

    int cod_sala, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin, duracion,
            hh_peli, min_peli, seg_peli;
    double entrada;
    char alimentos, car;

    while (archCartelera.get() != '\n') {

        archReporte << left << setw(10) << "SALA" << setw(10) << "COSTO" <<
                setw(12) << "INICIO" << setw(11) << "FIN" << setw(15) <<
                "DURACION" << "SE PUEDO INGRESAR CON ALIMENTOS" << right <<
                endl;
        imprimirCaracter('-', archReporte);

        archCartelera >> cod_sala >> entrada >> alimentos >> hh_ini >> car >>
                min_ini >> car >> seg_ini >> hh_fin >> car >> min_fin >> car
                >> seg_fin;
        //Leemos el nombre de la peliculas
        archCartelera >> ws;
        while (true) {
            car = archCartelera.get();
            if (car == ' ') break;
            if (car == '\n') {
                archCartelera.unget();
                break;
            }
        }
        archReporte << cod_sala << setw(10) << entrada << setw(3) << " ";
        imprimirHora(hh_ini, min_ini, seg_ini, archReporte);
        archReporte << setw(4) << " ";
        imprimirHora(hh_fin, min_fin, seg_fin, archReporte);
        archReporte << setw(5) << " ";
        calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin,
                duracion, hh_peli, min_peli, seg_peli);
        imprimirHora(hh_peli, min_peli, seg_peli, archReporte);
        if (alimentos == 'S') archReporte << setw(24) << "SI" << endl;
        else archReporte << setw(24) << "NO" << endl;
        imprimirCaracter('-', archReporte);

        buscarPersonas(archCli, hh_ini, min_ini, seg_ini, duracion, alimentos,
                archReporte, cod_dist);
        
    }

}

void buscarPersonas(ifstream &archCli, int hh_ini, int min_ini, int seg_ini,
        int duracion, char alimentos, ofstream &archReporte, int cod_dist) {

    int cod1, cod2, hh, min, seg, hh_dura, min_dura, seg_dura, dni;
    int hora, hora_ini, duracion_max, cant_personas;
    bool entro = false;
    char car, comida;
    archCli.clear();
    archCli.seekg(0, ios::beg);
    cant_personas = 0;
    while (true) {
        archCli >> cod1;
        if (archCli.eof())break;
        archCli >> cod2;

        if (cod1 == cod_dist or cod_dist == cod2) {

            archCli >> hh >> car >> min >> car >> seg >> hh_dura >> car >>
                    min_dura >> car >> seg_dura >> comida;

            hora = hh * 3600 + min * 60 + seg;
            hora_ini = hh_ini * 3600 + min_ini * 60 + seg_ini;
            duracion_max = hh_dura * 3600 + min_dura * 60 + seg_dura;

            if (comida == alimentos and hora_ini >= hora and
                    duracion <= duracion_max) {

                if (not entro) {
                    imprimirEncabezadoListaPersonas(archReporte);
                    entro = true;
                }
                archCli >> dni;
                archReporte << dni << setw(4) << " ";
                leerImprimirTexto(archCli, archReporte, MAX_CAR_NOMB);
                imprimirHora(hh, min, seg, archReporte);
                archReporte << setw(4) << " ";
                imprimirHora(hh_dura, min_dura, seg_dura, archReporte);
                if (comida == 'S')
                    archReporte << setw(11) << "SI" << endl;
                else
                    archReporte << setw(11) << "NO" << endl;
                
                cant_personas++;
            }
            else while (archCli.get() != '\n');

        } else while (archCli.get() != '\n');
    }
    imprimirCaracter('-', archReporte);
    if(cant_personas > 0){
        archReporte << "TOTAL DE PERSONAS = " << cant_personas << endl;
    }
    else 
        archReporte << "Ningun cinefilo cumple con las condiciones para "
                "asistir a esta funcion" << endl;
       
    imprimirCaracter('=', archReporte);
}

void imprimirEncabezadoListaPersonas(ofstream &archReporte) {

    archReporte << "PERSONAS QUE PODRIAN ASISTIR" << endl;
    archReporte << left << setw(3) << " " << setw(9) << "DNI" << setw(47) <<
            "NOMBRE" << setw(10) << "HORA" << setw(14) << "DURACION" <<
            "ALIMENTOS" << right << endl;

}

void imprimirHora(int hh, int min, int seg, ofstream &archReporte) {

    archReporte << setfill('0') << setw(2) << hh << ":" << setw(2) << min <<
            ":" << setw(2) << seg << setfill(' ');

}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &duracion, int &hh_peli,
        int &min_peli, int &seg_peli) {


    int aux;
    duracion = (hh_fin * 3600 + min_fin * 60 + seg_fin) -
            (hh_ini * 3600 + min_ini * 60 + seg_ini);
    aux = duracion;

    hh_peli = aux / 3600;
    aux %= 3600;
    min_peli = aux / 60;
    seg_peli = aux % 60;

}

void leerImprimirTexto(ifstream &archCartelera, ofstream &archReporte, int n) {

    char car;
    int cont = 0;
    archCartelera >> ws;
    while (true) {
        car = archCartelera.get();
        if (car == ' ' or car == '\n') break;

        if (car == '_') car = ' ';
        archReporte.put(car);
        cont++;
    }
    if (n > cont) archReporte << setw(n - cont) << " ";

}

void imprimirCaracter(char car, ofstream &archReporte) {

    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }
    archReporte << endl;
}

void imprimirEncabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 34) << "LISTADOS DE LAS PERSONAS QUE "
            "PODRIAN ASISTIR A LAS SIGUIENTES PELICULAS" << endl;

    imprimirCaracter('=', archReporte);

}