#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"

using namespace std;

void abrirArchivos(ifstream &archDatos, ofstream &archReporte,
        const char *nombreDatos, const char *nombreReporte) {

    archDatos.open(nombreDatos, ios::in);
    if (not archDatos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreDatos << endl;
        exit(1);
    }

    archReporte.open(nombreReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreReporte << endl;
        exit(1);
    }

}

void imprimirEmcabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 17) << "EMPRESA DE OPINON DE MERCADO S. "
            "A." << endl;
    imprimirCaracter('=', archReporte);
    archReporte << setw(5) << " " << "REGISTRO DE PREFERENCIAS DE TELEVIDENTES"
            << endl;
    imprimirCaracter('=', archReporte);

    archReporte << left << setw(12) << "DNI No." << setw(42) << "NOMBRE" <<
            setw(10) << "SEXO" << setw(12) << "CATEGORIA" << setw(13) <<
            "COMPANIA" << setw(14) << "CANAL" << setw(14) << "RANGO" <<
            "DURACION" << endl;
    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte) {

    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }
    archReporte << endl;
}

void leerProcesarImprimirDatos(ifstream &archDatos, ofstream &archReporte) {

    int dni, dd, mm, aa, canal, cant_televidentes, tiempo_total,
            cont_menores_adultos,cant_mujeres, cant_muj_tv;
    char car, sexo, compania, categoria;
    cant_televidentes = tiempo_total = cont_menores_adultos = 0;
    cant_mujeres = cant_muj_tv = 0;
    while (true) {
        archDatos >> dni;
        if (archDatos.eof()) break;
        archDatos >> sexo;
        archReporte << left << setw(10) << dni << setw(2) << " ";
        leerImprimirTexto(archDatos, archReporte);

        archDatos >> compania >> dd >> car >> mm >> car >> aa;
        imprimirSexo(sexo, archReporte);

        imprimirCategoria(aa, archReporte, categoria);
        imprimirCompania(compania, archReporte);

        procesarCanales(archDatos, archReporte,categoria, tiempo_total, 
                cont_menores_adultos);

        
        if(sexo == 'F'){
            cant_mujeres++;
                if(compania == 'A') cant_muj_tv++;
        }
        
        cant_televidentes++;
    }
    imprimirEstadisticas(cant_televidentes,cant_mujeres,cant_muj_tv,
            tiempo_total,cont_menores_adultos, archReporte);

}


void imprimirEstadisticas(int cant_televidentes,int cant_mujeres,int cant_muj_tv,
            int tiempo_total,int cont_menores_adultos, ofstream &archReporte){
    
    int hh, min, seg, promedio;
    double porcentaje = (double) cant_muj_tv / cant_mujeres * 100;
    promedio = tiempo_total / cont_menores_adultos;
    hh = promedio / 3600;
    promedio %= 3600;
    min = promedio / 60;
    seg = promedio % 60;
    
    imprimirCaracter('=', archReporte);
    archReporte << setw(8) << " " << "ESTADISTICAS OBTENIDAS" << endl;
    archReporte << setw(8) << " " << "Cantidad de televidentes registrados" <<
            setw(55) << cant_televidentes  <<endl;
    archReporte << setw(8) << " " << "Tiempo promedio que ven los menores y "
            "adultos" << setw(38) << " ";
    imprimirHora(hh, min, seg, archReporte);
    
    archReporte << endl << setw(8) << " " << "Porcentaje de mujeres que ve "
            "TVPUCP" << setprecision(2) << fixed << setw(55) << porcentaje <<
            "%" << endl; 
    
    imprimirCaracter('=', archReporte);
}

void procesarCanales(ifstream &archDatos, ofstream &archReporte, 
        char categoria,int &tiempo_total, int &cont_menores_adultos) {

    int canal, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin,
            hh_dura, min_dura, seg_dura, duracion, duracion_total, aux;
    char car;
    
    duracion_total = 0;
    while (archDatos.get() != '\n') {
        archDatos >> canal >> hh_ini >> car >> min_ini >> car >> seg_ini >>
                hh_fin >> car >> min_fin >> car >> seg_fin;


        calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin,
                hh_dura, min_dura, seg_dura, duracion);
        
        archReporte << right << setw(90) << " " << canal << setw(4) << " ";
        imprimirHora(hh_ini, min_ini, seg_ini, archReporte);
        archReporte << "-";
        imprimirHora(hh_fin, min_fin, seg_fin, archReporte);
        archReporte << setw(3) << " ";
        imprimirHora(hh_dura, min_dura, seg_dura, archReporte);
        archReporte << endl;
        
        duracion_total += duracion;
    }
    aux = duracion_total;
    hh_dura = aux / 3600;
    aux %= 3600;
    min_dura = aux / 60;
    seg_dura = aux % 60;
    archReporte << setw(117) << "TIEMPO TOTAL: ";
    imprimirHora(hh_dura, min_dura, seg_dura, archReporte); 
    archReporte << endl;
    
    if(categoria == 'M' or categoria == 'A'){
        tiempo_total += duracion_total;
        cont_menores_adultos++;
    }
}

void imprimirHora(int hh_ini, int min_ini, int seg_ini,ofstream &archReporte){
    
    archReporte << setfill('0') << setw(2) << hh_ini << ":" << setw(2) <<
            min_ini << ":" << setw(2) << seg_ini << setfill(' ');
    
}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &hh_dura, int &min_dura, int &seg_dura,
        int &duracion) {

    duracion = (hh_fin * 3600 + min_fin * 60 + seg_fin) -
            (hh_ini * 3600 + min_ini * 60 + seg_ini);

    int aux = duracion;

    hh_dura = aux / 3600;
    aux %= 3600;
    min_dura = aux / 60;
    seg_dura = aux % 60;


}

void imprimirCompania(char compania, ofstream &archReporte) {

    if (compania == 'A') archReporte << "TVPUCP" << endl;
    else if (compania == 'B') archReporte << "CableMas" << endl;
    else archReporte << "TPVision" << endl;

}

void imprimirCategoria(int aa, ofstream &archReporte, char &categoria) {
    if (aa >= 2009) {
        categoria = 'M';
        archReporte << setw(10) << "Menor";
    }
    else if (aa >= 1998) {
        categoria = 'J';
        archReporte << setw(10) << "Joven";
    } else {
        categoria = 'A';
        archReporte << setw(10) << "Adulto";
    }
}

void imprimirSexo(char sexo, ofstream &archReporte) {
    archReporte << left;
    if (sexo == 'F') {
        archReporte << setw(14) << "Femenino";
    } else archReporte << setw(14) << "Masculino";


}

void leerImprimirTexto(ifstream &archDatos, ofstream &archReporte) {

    char car;
    int cont = 0;
    archDatos >> ws;
    while (true) {
        car = archDatos.get();
        if (car == ' ') break;
        if (car == '_') car = ' ';
        archReporte.put(car);
        cont++;
    }
    archReporte << setw(MAX_CAR_NOMBRE - cont) << " ";
}
