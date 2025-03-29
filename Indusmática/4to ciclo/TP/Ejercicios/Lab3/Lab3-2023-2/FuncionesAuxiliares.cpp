#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

#define MAX_CAR 130
#define MAX_CAR_CANAL 40
#define MAX_CAR_NOMBRE 40

using namespace std;

void abrirArchivos(ifstream &archCanal, ifstream &archTele, ifstream &archPrefe,
        ofstream &archReporte, const char *nombreCanal, const char *nombreTele,
        const char *nombrePreferencias, const char *nombreReporte) {

    archCanal.open(nombreCanal, ios::in);
    if (not archCanal.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreCanal << endl;
        exit(1);
    }

    archTele.open(nombreTele, ios::in);
    if (not archTele.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreTele << endl;
        exit(1);
    }

    archPrefe.open(nombrePreferencias, ios::in);
    if (not archPrefe.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombrePreferencias
                << endl;
        exit(1);
    }

    archReporte.open(nombreReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreReporte << endl;
        exit(1);
    }


}

void leerProcesarImprimirDatos(ifstream &archCanal, ifstream &archTele,
        ifstream &archPrefe, ofstream &archReporte) {

    int canal, dura_total, cant_personas, menores, jovenes, adultos;

    imprimirEncabezado(archReporte);

    while (true) {

        archCanal >> canal;
        if (archCanal.eof()) break;
        cant_personas = dura_total = menores= jovenes = adultos=0;
        imprimirInfoCanal(canal, archCanal, archReporte);

        buscarImprimirClientes(canal, archTele, archPrefe, archReporte, 
                cant_personas,dura_total,menores, jovenes, adultos);
        
        imprimirEstadisticas(dura_total, cant_personas, menores, jovenes, 
                adultos, archReporte);
    }


}

void imprimirEstadisticas(int dura_total, int cant_personas, int menores, 
        int jovenes,int adultos, ofstream &archReporte){

    int promedio = dura_total / cant_personas;
    int hh, min, seg;
    double porcentaje;
    
    hh = promedio / 3600;
    promedio %= 3600;
    min = promedio / 60;
    seg = promedio % 60;
    
    imprimirCaracter('-', archReporte);
    archReporte << "PROMEDIO DE TIEMPO QUE VEN LOS TELEVIDENTES DEL CANAL: ";
    imprimirHora(hh,min,seg,archReporte);
    archReporte << endl << "PORCENTAJES SEGUN SU EDAD" << endl;
    
    porcentaje = (double)menores / cant_personas * 100;
    
    archReporte << setprecision(2)<< fixed <<setw(10) << " " << "MENORES" << 
            setw(12) << porcentaje << "%" << endl;
    
    porcentaje = (double)jovenes / cant_personas * 100;
    
    archReporte <<setw(10) << " " << "JOVENES" << setw(12) << porcentaje << "%" 
            << endl;
    
    porcentaje = (double)adultos / cant_personas * 100;
    
    archReporte <<setw(10) << " " << "ADULTOS" << setw(12) << porcentaje << "%" 
            << endl;
    
    archReporte << "TOTAL DE PERSONAS QUE VEN EL CANAL: " << cant_personas
            << endl;
    imprimirCaracter('=', archReporte);
    imprimirCaracter('=', archReporte);
}

void buscarImprimirClientes(int canal, ifstream &archTele, ifstream &archPrefe,
        ofstream &archReporte, int &cant_personas, int &dura_total,
        int &menores, int &jovenes, int &adultos) {

    int dni, canal_prefe, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin;
    int duracion, categoria;
    char car;

    //categora 1: Menor     2: Joven    3: Adulto
    
    archPrefe.clear();
    archPrefe.seekg(0, ios::beg);
    while (true) {
        archPrefe >> dni;
        if (archPrefe.eof())break;

        while (archPrefe.get() != '\n') {
            archPrefe >> canal_prefe;
            archPrefe >> hh_ini >> car >> min_ini >> car >> seg_ini >> hh_fin >>
                    car >> min_fin >> car >> seg_fin;
            if (canal_prefe == canal) {
                //archReporte << "Buscando informacion de la perosna  ";
                buscarImprimirInfoPersona(dni, archTele, archReporte, 
                        categoria);
                calcularImprimirDuracion(hh_ini, min_ini, seg_ini, hh_fin, 
                        min_fin, seg_fin, duracion, archReporte);
                archReporte << endl;
                if(categoria == 1) menores++;
                else if (categoria == 2) jovenes++;
                else adultos++;
                dura_total += duracion;
                cant_personas++;
            }
        }

    }

}

void calcularImprimirDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &duracion, ofstream &archReporte) {

    int hh_dura, min_dura, seg_dura;
    
    int diferencia = (hh_fin * 3600 + min_fin * 60 + seg_fin) -
            (hh_ini * 3600 + min_ini * 60 + seg_ini);
    
    duracion = diferencia;
    
    hh_dura = diferencia / 3600;
    
    diferencia %= 3600;
    min_dura = diferencia / 60;
    seg_dura = diferencia % 60; 
    
    imprimirHora(hh_ini, min_ini, seg_ini, archReporte);
    archReporte << " - ";
    imprimirHora(hh_fin, min_fin, seg_fin, archReporte);
    archReporte << setw(8) << " ";
    imprimirHora(hh_dura, min_dura, seg_dura, archReporte);
    
}


void imprimirHora(int hh, int min, int seg, ofstream &archReporte){
    
    archReporte << setfill('0') << setw(2) << hh << ":" << setw(2) << min <<
            ":" << setw(2) << seg << setfill(' ');
    
}
void buscarImprimirInfoPersona(int dni, ifstream &archTele,
        ofstream &archReporte, int &categoria) {

    int dni_per, dd, mm, aa;
    char sexo, compania, car;

    archTele.clear();
    archTele.seekg(0, ios::beg);

    while (true) {
        archTele >> dni_per;
        if (archTele.eof())break;
        if (dni == dni_per) {
            archReporte << dni << setw(3) << " ";
            //archReporte << "Imprimiendo nombre de persona   ";
            leerImprimirTexto(archTele, archReporte, MAX_CAR_NOMBRE, 2);
            archTele >> dd >> car >> mm >> car >>aa >> sexo >> compania;
            archReporte << left;
            imprimirSexo(sexo, archReporte);
            if (aa > 2009) {
                archReporte << setw(14) << "Menor";
                categoria = 1;
            } else if (aa > 1998) {
                archReporte << setw(14) << "Joven";
                categoria = 2;
            } else {
                archReporte << setw(14) << "Adulto";
                categoria = 3;
            }
            imprimirCompania(compania, archReporte);
            archReporte << right;
            return;
        } 
        else while (archTele.get() != '\n');
    }

}

void imprimirCompania(char compania, ofstream& archReporte) {

    if (compania == 'A') {
        archReporte << setw(12) << "TVPUCP";
    } else if (compania == 'B') {
        archReporte << setw(12) << "CableMas";
    } else archReporte << setw(12) << "TPVision";
}

void imprimirSexo(char sexo, ofstream &archReporte) {

    if (sexo == 'F') archReporte << setw(15)<<"Femenino";
    else archReporte << setw(15) << "Masculino";

}

void imprimirInfoCanal(int canal, ifstream &archCanal, ofstream &archReporte) {

    archReporte << "CANAL: ";
    leerImprimirTexto(archCanal, archReporte, MAX_CAR_CANAL, 1);
    archReporte << "NUMERO: " << canal << endl;
    archReporte << "LISTADO DE TELEVIDENTES QUE VEN EL CANAL: " << endl;
    imprimirCaracter('-', archReporte);

    archReporte << left << setw(12) << "DNI No." << setw(40) << "NOMBRE" <<
            setw(12) << "SEXO" << setw(15) << "CATEGORIA" << setw(20) <<
            "COMPANIA" << setw(20) << "RANGO" << "DURACION" << right << endl;
    imprimirCaracter('-', archReporte);
}

void leerImprimirTexto(ifstream &archDatos, ofstream &archReporte, int n,
        int opcion) {

    //Opcion 1 leer nombre canal
    //Opcion 2 leer nombre persona

    char car;
    int cont = 0, cont_barras = 0, cont_letras = 0;

    archDatos >> ws;

    while (true) {
        car = archDatos.get();

        if (opcion == 2 and car == ' ')break;
        if (opcion == 1 and car == '/') {
            cont_barras++;
            if (cont_barras == 2) break;
            else continue;
        }

        if (car == '_') car = ' ';
        if (opcion == 2) {
            if ((cont_letras % 2) == 1 and car != ' ')
                car = car - 'A' + 'a';
            if (car != ' ')
                cont_letras++;
        }

        if (opcion == 1 and car >= 'a' and car <= 'z')
            car = car - 'a' + 'A';

        archReporte.put(car);
        cont++;
    }

    archReporte << setw(n - cont) << " ";
}

void imprimirEncabezado(ofstream &archReporte) {

    imprimirCaracter('=', archReporte);
    archReporte << setw(MAX_CAR / 2 + 19) << "EMPRESA DE OPINION DE MERCADO "
            "TP S. A." << endl;

    archReporte << setw(MAX_CAR / 2 + 18) << "AVENIDA UNIVERSITARIA 1234 "
            "San Miguel" << endl;

    archReporte << setw(MAX_CAR / 2 + 5) << "LIMA - PERU" << endl;

    imprimirCaracter('=', archReporte);
    archReporte << setw(MAX_CAR / 2 + 34) << "REGISTRO DE PREFERENCIAS DE LOS"
            " TELEVIDENTES POR CANAL DE PREFERENCIA" << endl;
    imprimirCaracter('=', archReporte);

}

void imprimirCaracter(char car, ofstream &archReporte) {

    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }
    archReporte << endl;
}