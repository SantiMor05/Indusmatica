#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 155
#define MAX_CAR_NOMB 40
#define MAX_CAR_ESPECIALIDAD 20

using namespace std;

void abrirArchivos(ifstream &archCitas, ifstream &archMed,
        ofstream &archReporte, const char *nombreCitas,
        const char *nombreMedicos, const char *nombreReporte) {


    archCitas.open(nombreCitas, ios::in);
    if (not archCitas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreCitas << endl;
        exit(1);
    }


    archMed.open(nombreMedicos, ios::in);
    if (not archMed.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreMedicos
                << endl;
        exit(1);
    }


    archReporte.open(nombreReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombreReporte
                << endl;
        exit(1);
    }
}

void leerProcesarImpirmirDatos(ifstream &archCitas, ifstream &archMed,
        ofstream &archReporte) {

    int dd, mm, aa, dni, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin,
            cod_med, hh_dura, min_dura, seg_dura, dni_mayor;
    char medicamentos, car;
    double porcentaje, costo_medicamentos, tarifa, pago, duracion, total,
            pago_mayor;

    imprimirEncabezado(archReporte);
    total = pago_mayor = 0;
    while (true) {
        archCitas >> dd;
        if (archCitas.eof())break;
        archCitas >> car >> mm >> car >> aa >> dni >> porcentaje >> hh_ini >>
                car >> min_ini >> car >> seg_ini >> hh_fin >> car >>
                min_fin >> car >> seg_fin >> cod_med;
        
        calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin,
                min_fin, seg_fin, duracion, hh_dura, min_dura, seg_dura);
        
        imprimirFechaHora(dd, mm, aa, '/', archReporte);
        archReporte << setw(10) << dni << setw(3) << " ";
        imprimirFechaHora(hh_ini, min_ini, seg_ini, ':', archReporte);
        archReporte << setw(3) << " ";
        imprimirFechaHora(hh_fin, min_fin, seg_fin, ':', archReporte);
        archReporte << setw(5) << " ";
        imprimirFechaHora(hh_dura, min_dura, seg_dura, ':', archReporte);
        archReporte << setw(12) << porcentaje << "%" << setw(9) << " ";

        buscarMedico(cod_med, archMed, archReporte, tarifa);

        archCitas >> medicamentos;
        if (medicamentos == 'S')
            archCitas >> costo_medicamentos;
        else costo_medicamentos = 0;

        

        pago = (tarifa * duracion) * (100 - porcentaje) / 100 +
                costo_medicamentos * (100 - porcentaje / 2) / 100;
        archReporte << setprecision(2) << fixed << setw(10) <<pago << endl;
        
        total += pago;
        if(pago > pago_mayor){
            pago_mayor = pago;
            dni_mayor =dni;
        }
    }
    imprimirEstadisticas(dni_mayor, pago_mayor, total, archReporte);
}

void imprimirEstadisticas(int dni_mayor, double pago_mayor, double total, 
        ofstream &archReporte){
    
    imprimirCaracter('=', archReporte);
    archReporte << "Total de ingresos: " << total << endl;
    imprimirCaracter('=', archReporte);
    archReporte << "Paciente que mas gasto en una cita medica: " << dni_mayor 
            << endl;
    archReporte << "Monto gastado: " << setw(25) << pago_mayor << endl;
    imprimirCaracter('=', archReporte);
}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, double &duracion, int &hh_dura,
        int &min_dura, int &seg_dura){

    int diferencia = (hh_fin * 3600 + min_fin * 60 + seg_fin) -
            (hh_ini * 3600 + min_ini * 60 + seg_ini);

    duracion = (double) diferencia / 3600;
    
    hh_dura = diferencia / 3600;
    diferencia %= 3600;
    min_dura = diferencia / 60;
    seg_dura = diferencia % 60;

}

void buscarMedico(int cod_med, ifstream &archMed, ofstream &archReporte,
        double &tarifa) {

    int codigo;

    archMed.clear();
    archMed.seekg(0, ios::beg);

    while (true) {
        archMed >> codigo;
        if (archMed.eof()) return;
        if (cod_med == codigo) {
            leerImprimirNombre(archMed, archReporte, 1);
            leerImprimirNombre(archMed, archReporte, 2);
            archMed >> tarifa;
        } else {
            while (archMed.get() != '\n');
        }
    }

}

void leerImprimirNombre(ifstream &archMed, ofstream &archReporte, int opcion) {

    //Opcion 1 pasar de mayusculas a tipo oración
    //Opcion 2 pasar todo a mayusculas

    char car;
    char anterior = ' ';
    int cont = 0, cant;
    archMed >> ws;

    if (opcion == 1) cant = MAX_CAR_NOMB;
    else cant = MAX_CAR_ESPECIALIDAD;

    while (true) {
        car = archMed.get();
        if (car == ' ')break;
        if (car == '_') car = ' ';
        if (opcion == 1 and car >= 'A' and car <= 'Z' and
                 anterior != ' ' and anterior != '_')
            car = car - 'A' + 'a';
        if (opcion == 2 and (anterior != ' ' and anterior != '_'))
            car = car - 'a' + 'A';
        archReporte.put(car);
        anterior = car;
        cont++;
    }

    archReporte << setw(cant - cont) << " ";

}

void imprimirFechaHora(int dd, int mm, int aa, char deli, ofstream &archReporte) {

    archReporte << setfill('0') << setw(2) << dd << deli << setw(2) <<
            mm << deli << setw(2) << aa << setfill(' ');
}

void imprimirEncabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 11) << "EMPRESA DE SALUD S. A." << endl;
    imprimirCaracter('=', archReporte);

    archReporte << setw(MAX_CAR / 2 + 12) << "REGISTRO DE CITAS MEDICAS" <<
            endl;
    imprimirCaracter('=', archReporte);

    archReporte << left << setw(12) << "Fecha" << setw(12) << "Paciente" <<
            setw(12) << "Inicio" << setw(11) << "Fin" << setw(13) <<
            "Duracion" << setw(17) << "% por Seguro" << setw(35) <<
            "Medico" << setw(22) << "Especialidad" << "Pago (cita+medicinas)" <<
            endl << right;
    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte) {

    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }
    archReporte << endl;

}