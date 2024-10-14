#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_PRUEBA 100
#define MAX_CAR 120

using namespace std;

void leerPacientes(int &cant_pacientes, int *dni, int *distrito,
        char *clasificacion, double *descuento, const char *nombPacientes) {

    int aa;

    ifstream archPacientes(nombPacientes, ios::in);
    if (not archPacientes.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombPacientes << endl;
        exit(1);
    }
    cant_pacientes = 0;


    while (true) {

        archPacientes >> dni[cant_pacientes];
        if (archPacientes.eof())break;
        saltarTexto(']', archPacientes);
        archPacientes >> distrito[cant_pacientes] >> aa >>
                descuento[cant_pacientes];

        clasificacion[cant_pacientes] = clasificar(aa);

        cant_pacientes++;
    }

}

void leerMedicinas(int &cant_medicinas, int *medicina, double *costo,
        const char *nombMedicinas) {

    ifstream archMedicinas(nombMedicinas, ios::in);
    if (not archMedicinas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMedicinas << endl;
        exit(1);
    }

    cant_medicinas = 0;
    while (true) {

        archMedicinas >> medicina[cant_medicinas];
        if (archMedicinas.eof())break;
        saltarTexto(' ', archMedicinas);
        archMedicinas >> costo[cant_medicinas];
        cant_medicinas++;
    }

}

void emitiirPrueba(int cant_pacientes, int *dni, int *distrito,
        char *clasificacion, double *descuento, int cant_medicinas,
        int *medicina, double *costo, const char *nombPrueba) {

    ofstream archPrueba(nombPrueba, ios::out);
    if (not archPrueba.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombPrueba << endl;
        exit(1);
    }

    archPrueba << "Dni" << setw(12) << "Distrito" << setw(15) <<
            "Clasificiacion" << setw(12) << "Descuento" << endl;
    imprimirCaracter('=', MAX_CAR_PRUEBA, archPrueba);
    archPrueba << setprecision(2) << fixed;
    for (int i = 0; i < cant_pacientes; i++) {
        archPrueba << dni[i] << setw(12) << distrito[i] << setw(12) <<
                clasificacion[i] << setw(12) << descuento[i] << endl;
    }
    imprimirCaracter('=', MAX_CAR_PRUEBA, archPrueba);
    archPrueba << "Medicina" << setw(12) << "Costo" << endl;
    imprimirCaracter('=', MAX_CAR_PRUEBA, archPrueba);
    for (int i = 0; i < cant_medicinas; i++) {
        archPrueba << medicina[i] << setw(12) << costo[i] << endl;
    }

}

void actualizarDatos(int cant_pacientes, int *dni, int *distrito,
        char *clasificacion, double *descuento, int *cant_citas,
        int *num_medicinas, double *pago, int cant_medicinas,
        int *medicina, double *costo, const char *nombCitas) {

    int documento, dd, medico, pos_paciente, pos_med, cod_medicina, cantidad;
    double monto;
    char car;
    ifstream archCitas(nombCitas, ios::in);
    if (not archCitas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCitas << endl;
        exit(1);
    }

    while (true) {

        archCitas >> dd;
        if (archCitas.eof())break;
        saltarTexto(' ', archCitas);
        archCitas >> documento;
        pos_paciente = buscarPos(documento, cant_pacientes, dni);
        saltarTexto(' ', archCitas);
        saltarTexto(' ', archCitas);
        archCitas >> medico;

        (cant_citas[pos_paciente])++;
        while (archCitas.get() != '\n') {
            archCitas >> cod_medicina >> cantidad;
            pos_med = buscarPos(cod_medicina, cant_medicinas, medicina);
            monto = costo[pos_med] * cantidad *
                    (100.0 - descuento[pos_paciente]) / 100;
            pago[pos_paciente] += monto;
            (num_medicinas[pos_paciente])++;
        }
    }

}

void ordenarArreglos(int cant_pacientes, int *dni, int *distrito,
        char *clasificacion, double *descuento, int *cant_citas,
        int *num_medicinas, double *pago) {


    for (int i = 0; i < cant_pacientes; i++) {
        for (int j = i + 1; j < cant_pacientes; j++) {
            if (clasificacion[j] < clasificacion[i] or
                    (clasificacion[j] == clasificacion[i] and
                    distrito[j] > distrito[i])) {

                intercabiarInt(i, j, dni);
                intercabiarInt(i, j, distrito);
                intercabiarInt(i, j, num_medicinas);
                intercabiarInt(i, j, cant_citas);
                intercabiarChar(i, j, clasificacion);
                intercabiarDouble(i, j, descuento);
                intercabiarDouble(i, j, pago);

            }
        }
    }

}

void imprimirReporte(int cant_pacientes, int *dni, int *distrito,
        char *clasificacion, double *descuento, int *cant_citas,
        int *num_medicinas, double *pago, const char *nombReporte) {

    double total = 0;
    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    imprimirEncabezado(archReporte);
    archReporte << setprecision(2) << fixed;
    for (int i = 0; i < cant_pacientes; i++) {
        archReporte << setw(7) << clasificacion[i] << setw(16) << distrito[i] <<
                setw(18) << dni[i] << setw(15) << descuento[i] << "%" << setw(10)
                << cant_citas[i] << setw(18) << num_medicinas[i] << setw(24) <<
                pago[i] << endl;
        total += pago[i];
    }
    imprimirCaracter('-', MAX_CAR, archReporte);
    archReporte << "RESUMEN" << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
    archReporte << "PAGO TOTAL POR MEDICINAS: " << total << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);
}

void imprimirEncabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 11) << "EMPRESA DE SALUD S. A." << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);
    archReporte << setw(MAX_CAR / 2 + 18) << "CONSOLIDADO DE ATENCION POR "
            "PACIENTE" << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);

    archReporte << "CLASIFICACION" << setw(12) << "DISTRITO" << setw(18) <<
            "DNI PACIENTE" << setw(16) << "%DESCUENTO" << setw(13) <<
            "CANT.CITAS" << setw(20) << "CANT.MEDICINAS" << setw(20) <<
            "PAGO.MEDICINAS" << endl;
}

void intercabiarDouble(int i, int j, double *arr) {

    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;

}

void intercabiarChar(int i, int j, char *arr) {

    char aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;

}

void intercabiarInt(int i, int j, int *arr) {

    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;

}

int buscarPos(int codigo, int cant, int *arr) {

    for (int i = 0; i < cant; i++) {
        if (codigo == arr[i]) return i;
    }
    return -1;
}

void imprimirCaracter(char car, int n, ofstream &archSalida) {

    for (int i = 0; i < n; i++)
        archSalida.put(car);
    archSalida << endl;
}

char clasificar(int aa) {

    if (aa >= 2019) return 'A';
    else if (aa >= 2013) return 'B';
    else if (aa >= 2006) return 'C';
    else if (aa >= 1998) return 'D';
    else if (aa >= 1965) return 'E';
    else return 'F';

}

void saltarTexto(char deli, ifstream &archPacientes) {

    char car;
    archPacientes >> ws;
    while (true) {
        car = archPacientes.get();
        if (car == deli)
            break;
    }

}