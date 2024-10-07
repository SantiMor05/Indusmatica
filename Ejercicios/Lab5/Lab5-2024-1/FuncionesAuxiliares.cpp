#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define CAR_PRUEBA 22
#define MAX_CAR 135

using namespace std;

void leerMedicos(int &cant_medicos, int *cod_med, double *tarifa,
        const char *nombMedicos) {

    char car;
    ifstream archMedicos(nombMedicos, ios::in);
    if (not archMedicos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMedicos << endl;
        exit(1);
    }
    cant_medicos = 0;
    while (true) {

        archMedicos >> cod_med[cant_medicos];
        if (archMedicos.eof()) break;
        archMedicos >> ws >> car;
        saltarTexto('/', archMedicos);
        saltarTexto(' ', archMedicos);

        archMedicos >> tarifa[cant_medicos];

        cant_medicos++;
    }


}

void leerMedicinas(int &cant_medicinas, int *cod_medicina, double *precio,
        const char * nombMedicinas) {

    ifstream archMedicinas(nombMedicinas, ios::in);
    if (not archMedicinas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMedicinas << endl;
        exit(1);
    }
    cant_medicinas = 0;
    while (true) {
        archMedicinas >> cod_medicina[cant_medicinas];
        if (archMedicinas.eof())break;
        saltarTexto(' ', archMedicinas);
        archMedicinas >> precio[cant_medicinas];

        cant_medicinas++;
    }


}

void imprimirReportePrueba(int cant_medicos, int cant_medicinas, int *cod_med,
        int *cod_medicina, double *tarifa, double *precio,
        const char *nombReporte) {

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    archReporte << setw(CAR_PRUEBA / 2 + 3) << "MEDICOS" << endl;
    archReporte << "CODIGO" << setw(14) << "TARIFA" << endl;

    imprimirCaracter('-', CAR_PRUEBA, archReporte);
    archReporte << setprecision(2) << fixed;
    for (int i = 0; i < cant_medicos; i++) {
        archReporte << cod_med[i] << setw(15) << tarifa[i] << endl;
    }

    imprimirCaracter('=', CAR_PRUEBA, archReporte);
    archReporte << setw(CAR_PRUEBA / 2 + 4) << "MEDICINAS" << endl;
    archReporte << "CODIGO" << setw(14) << "PRECIO" << endl;

    imprimirCaracter('-', CAR_PRUEBA, archReporte);

    for (int i = 0; i < cant_medicinas; i++) {
        archReporte << cod_medicina[i] << setw(15) << precio[i] << endl;
    }
}

void imprimirCaracter(char car, int n, ofstream &archReporte) {

    for (int i = 0; i < n; i++)
        archReporte.put(car);

    archReporte << endl;

}

void saltarTexto(char deli, ifstream &archMedicos) {

    archMedicos >> ws;
    while (archMedicos.get() != deli);

}

void actualizarDatos(int cant_medicos, int cant_medicinas, int *cod_med,
        int *cod_medicina, double *tarifa, double *precio, double *monto_cita,
        int *cant_pacientes, int *paciente_medicina, double *ingreso_medicina,
        int *unidades, double *ingreso_sin, double *descuentos_medi,
        const char *nombCitas) {

    int dd, dni, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin;
    int cod_medico, num_medicamentos, cod_medicamento, cant_medicamentos;
    int pos_medico, pos_medica;
    double descuento, duracion, ingresos_medi;
    char car;

    ifstream archCitas(nombCitas, ios::in);
    if (not archCitas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCitas << endl;
        exit(1);
    }

    while (true) {

        archCitas >> dd;
        if (archCitas.eof())break;
        archCitas >> car >> dd >> car >> dd >> dni;
        archCitas >> descuento >> hh_ini >> car >> min_ini >> car >> seg_ini >>
                hh_fin >> car >> min_fin >> car >> seg_fin >> cod_medico;

        duracion = calcularDuracion(hh_ini, min_ini, seg_ini,
                hh_fin, min_fin, seg_fin);

        pos_medico = buscarPos(cod_medico, cant_medicos, cod_med);
        monto_cita[pos_medico] += tarifa[pos_medico] * duracion *
                (100 - descuento) / 100;
        (cant_pacientes[pos_medico])++;

        num_medicamentos = 0;
        while (archCitas.get() != '\n') {
            archCitas >> cod_medicamento >> cant_medicamentos;
            num_medicamentos++;
            pos_medica = buscarPos(cod_medicamento, cant_medicinas,
                    cod_medicina);
            ingreso_medicina[pos_medico] += precio[pos_medica] *
                    cant_medicamentos * (100 - descuento / 2) / 100;
            unidades[pos_medica] += cant_medicamentos;
            ingresos_medi = cant_medicamentos * precio[pos_medica];
            ingreso_sin[pos_medica] += ingresos_medi;
            descuentos_medi[pos_medica] += ingresos_medi * (descuento / 2) / 100;
        }
        if (num_medicamentos != 0) {
            (paciente_medicina[pos_medico])++;
        }
    }
}

void emitirReporte(int cant_medicos, int cant_medicinas, int *cod_med,
        int *cod_medicina, double *tarifa, double *precio, double *monto_cita,
        int *cant_pacientes, int *paciente_medicina, double *ingreso_medicina,
        int *unidades, double *ingreso_sin, double *descuentos_medi,
        const char *nombReporte, double &promedio, int opcion) {

    ofstream archReporte(nombReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }
    double total, total_citas, total_med, total_ingresos;
    int pacientes_medicina, pacientes_sin_med, total_pacientes, cant;

    imprimirEncabezadoMedicos(archReporte);
    archReporte << setprecision(2) << fixed;
    pacientes_medicina = pacientes_sin_med = total_pacientes = total_citas =
            total_med = total_ingresos = 0;

    for (int i = 0; i < cant_medicos; i++) {
        total = ingreso_medicina[i] + monto_cita[i];
        cant = cant_pacientes[i] - paciente_medicina[i];

        archReporte << setfill('0') << setw(3) << i + 1 << setfill(' ') <<
                setw(8) << cod_med[i] << setw(12) << tarifa[i] << setw(13) <<
                monto_cita[i] << setw(21) << ingreso_medicina[i] << setw(15) <<
                total << setw(12) << paciente_medicina[i] << setw(23) <<
                cant << setw(21) << cant_pacientes[i] << endl;

        total_citas += monto_cita[i];
        total_med += ingreso_medicina[i];
        total_ingresos += total;
        pacientes_medicina += paciente_medicina[i];
        pacientes_sin_med += cant;
        total_pacientes += cant_pacientes[i];

    }

    imprimirCaracter('-', MAX_CAR, archReporte);
    archReporte << "Totales:" << setw(28) << total_citas << setw(21) <<
            total_med << setw(15) << total_ingresos << setw(12) <<
            pacientes_medicina << setw(23) << pacientes_sin_med << setw(21) <<
            total_pacientes << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);

    promedio = total_ingresos / cant_medicos;

    if (opcion == 2) {
        imprimirEncabezadoMedicinas(archReporte);

        int total_unidades;
        double sin_descuento, total_descuentos;

        total_ingresos = total_unidades = sin_descuento = total_descuentos = 0;

        for (int i = 0; i < cant_medicinas; i++) {
            total = ingreso_sin[i] - descuentos_medi[i];
            archReporte << setfill('0') << setw(3) << i + 1 << setfill(' ') <<
                    setw(10) << cod_medicina[i] << setw(17) << precio[i] << 
                    setw(16) << unidades[i] << setw(37) << ingreso_sin[i] << 
                    setw(19) << descuentos_medi[i] << setw(16) << total << endl;
            total_unidades += unidades[i];
            sin_descuento += ingreso_sin[i];
            total_descuentos += descuentos_medi[i];
            total_ingresos += total;
        }
        imprimirCaracter('=', MAX_CAR, archReporte);
        archReporte << "Totales:" << setw(38) << total_unidades << setw(37) <<
                sin_descuento << setw(19) << total_descuentos << setw(16) <<
                total_ingresos;
    }


}

void imprimirEncabezadoMedicinas(ofstream &archReporte) {

    archReporte << endl << endl << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);

    archReporte << setw(MAX_CAR / 2 + 11) << "EMPRESA DE SALUD S. A." << endl;
    archReporte << setw(MAX_CAR / 2 + 18) << "REGISTRO DE INGRESOS POR "
            "MEDICAMENTO" << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);

    archReporte << "No." << setw(12) << "Codigo del" << setw(15) << "Precio" <<
            setw(25) << "Cantidad de unidades" << setw(30) << "Ingresos sin" <<
            setw(20) << "Descuentos por" << setw(12) << "Total" << endl;
    archReporte << setw(16) << "Medicamento" << setw(33) << "vendidas" <<
            setw(35) << "descuentos" << setw(19) << "los seguros" << setw(16) <<
            "ingresado" << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
}

void imprimirEncabezadoMedicos(ofstream &archReporte) {

    imprimirCaracter('=', MAX_CAR, archReporte);
    archReporte << setw(MAX_CAR / 2 + 11) << "EMPRESA DE SALUD S. A." << endl;
    archReporte << setw(MAX_CAR / 2 + 15) << "REGISTRO DE INGRESOS POR "
            "MEDICAMENTO" << endl;
    imprimirCaracter('=', MAX_CAR, archReporte);

    archReporte << "No." << setw(10) << "Codigo del" << setw(10) << "Tarifa" <<
            setw(15) << "Ingresos por" << setw(20) << "Ingresos por" <<
            setw(12) << "Total" << setw(23) << "Pacientes atendidos" << setw(22)
            << "Pacientes atendidos" << setw(15) << "Total de" << endl;
    archReporte << setw(12) << "Medico" << setw(24) << "las citas" << setw(22)
            << "medicamentos" << setw(14) << "ingresado" << setw(18) <<
            "con medicinas" << setw(22) << "sin medicinas" << setw(19) <<
            "pacientes" << endl;
    imprimirCaracter('-', MAX_CAR, archReporte);
}

int buscarPos(int cod, int cant, int *codigo) {

    for (int i = 0; i < cant; i++) {
        if (codigo[i] == cod)
            return i;
    }

}

double calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin) {
    int aux = (hh_fin * 3600 + min_fin * 60 + seg_fin) -
            (hh_ini * 3600 + min_ini * 60 + seg_ini);
    double duracion = (double) aux / (3600);

    return duracion;

}


void borrarMenoresPromedio(int &cant_medicos, int *cod_med, double *tarifa,
        double *monto_cita, double *ingreso_medicina, int *cant_pacientes, 
        int *paciente_medicina, double promedio){
    
    double total_ingresos;
    
    for(int i = 0; i < cant_medicos; i++){
        total_ingresos = ingreso_medicina[i] + monto_cita[i];
        if(total_ingresos < promedio){
            for(int j= i; j < cant_medicos - 1; j++){
                cod_med[j] = cod_med[j+1];
                tarifa[j] = tarifa[j+1];
                monto_cita[j] = monto_cita[j+1];
                ingreso_medicina[j] = ingreso_medicina[j+1];
                cant_pacientes[j] = cant_pacientes[j+1];
                paciente_medicina[j] = paciente_medicina[j+1];
            }
            cant_medicos--;
            i--;
        }
    }
    
}