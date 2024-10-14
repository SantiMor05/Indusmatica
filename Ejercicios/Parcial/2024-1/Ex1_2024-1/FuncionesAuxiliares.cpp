#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 120
#define MAX_CAR_NOMBRE 45
#define MAX_CAR_ESPC 20
#define MAX_CAR_MED 35

using namespace std;

void procesarDatos(const char *nombPacientes, const char *nombCitas,
        const char *nombMedicos, const char *nombMedicinas,
        const char *nombReporte) {


    ifstream archPacientes(nombPacientes, ios::in);
    if (not archPacientes.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombPacientes << endl;
        exit(1);
    }
    ifstream archCitas(nombCitas, ios::in);
    if (not archCitas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombCitas << endl;
        exit(1);
    }

    ifstream archMedicos(nombMedicos, ios::in);
    if (not archMedicos.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMedicos << endl;
        exit(1);
    }

    ifstream archMedicinas(nombMedicinas, ios::in);
    if (not archMedicinas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombMedicinas << endl;
        exit(1);
    }

    ofstream archReporte(nombReporte, ios::out);
    if (not archMedicinas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombReporte << endl;
        exit(1);
    }

    int dni, distrito, aa;
    double descuento, suma = 0;
    imprimirEncabezado(archReporte);
    archReporte << setprecision(2) << fixed;
    while (true) {
        imprimirCaracter('=', archReporte);
        archPacientes >> dni;
        if (archPacientes.eof())break;

        archReporte << "PACIENTE:" << setw(10) << dni << " - ";
        leerImprimirTexto(MAX_CAR_NOMBRE, ']', archPacientes, archReporte);
        archPacientes >> distrito >> aa >> descuento;
        archReporte << "Anho de nacimiento: " << setw(6) << aa << setw(16) <<
                "%Descuento: " << setw(6) << descuento << "%" << endl;

        imprimirCaracter('-', archReporte);
        archReporte << "CITAS: " << endl;
        imprimirCaracter('-', archReporte);
        procesarCitas(dni, descuento, suma, archCitas, archMedicinas, archMedicos,
                archReporte);
        archReporte << "PAGO TOTAL DEL PACIENTE: " << setw(10) << suma << endl;
    }
}

void procesarCitas(int dni, double descuento, double &suma, ifstream &archCitas,
        ifstream &archMedicinas, ifstream &archMedicos, ofstream &archReporte) {

    int dd, mm, aa, documento, hh_ini, min_ini, seg_ini, hh_fin, min_fin,
            seg_fin, medico, duracion, hh_dura, min_dura, seg_dura,
            medicamento, cantidad, cont;
    double tarifa, monto, pago_medicamentos;
    char car;

    archCitas.clear();
    archCitas.seekg(0, ios::beg);
    suma = 0;
    while (true) {

        archCitas >> dd;
        if (archCitas.eof())break;
        archCitas >> car >> mm >> car >> aa >> documento;
        cont = 0;
        if (documento == dni) {
            imprimirEncabezadoCita(archReporte);
            archCitas >> hh_ini >> car >> min_ini >> car >> seg_ini >>
                    hh_fin >> car >> min_fin >> car >> seg_fin >> medico;

            calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin, min_fin,
                    seg_fin, duracion, hh_dura, min_dura, seg_dura);

            imprimirFechaHora(dd, mm, aa, '/', archReporte);
            archReporte << setw(3) << " ";
            imprimirFechaHora(hh_dura, min_dura, seg_dura, ':', archReporte);
            archReporte << setw(3) << " ";

            buscarImprimirMedico(medico, tarifa, archMedicos, archReporte);
            monto = tarifa * ((double) duracion / 3600) * (100.0 - descuento) /
                    100;
            archReporte << setw(12) << monto << endl;
            pago_medicamentos = 0;
            imprimirEncabezadoMedicinas(archReporte);
            while (archCitas.get() != '\n') {

                archCitas >> medicamento >> cantidad;
                
                
                archReporte << setw(20) << " " << setfill('0') << setw(2) << 
                    cont + 1 << setfill(' ') << setw(12) << medicamento <<
                        setw(5) << " ";
                buscarImprimirMedicamento(medicamento, cantidad, descuento,
                        pago_medicamentos, archMedicinas, archReporte);  
                
                cont++;
                
            }
            imprimirEstadisticasFinalesCita(pago_medicamentos, monto, 
                    archReporte);
            
            suma += pago_medicamentos + monto;
            
        } else
            while (archCitas.get() != '\n');

    }
}


void imprimirEstadisticasFinalesCita(double pago_medicamentos, double monto, 
                    ofstream &archReporte){
    
    archReporte << endl <<"Pago total por medicinas : " << pago_medicamentos << 
            endl;
    archReporte << "Pago total:" << setw(15) << monto + pago_medicamentos << 
            endl;
    imprimirCaracter('-', archReporte);
    
}

void imprimirEncabezadoMedicinas(ofstream &archReporte){
    
    archReporte << "Medicinas recetadaas" << endl;
    archReporte << setw(20) << " " << "No." << setw(12) << "Codigo" << setw(15)
            << "Descripcion" << setw(35) << "Cantidad" << setw(13) << "Precio"
            << setw(10) << "Pago" << endl;
}

void buscarImprimirMedicamento(int medicamento, int cantidad, double descuento,
        double &pago_medicamentos, ifstream &archMedicinas, 
        ofstream &archReporte){
    
    int codigo, cont = 0;
    double pago, costo;
    archMedicinas.clear();
    archMedicinas.seekg(0,ios::beg); 
    
    while(true){
        
        archMedicinas >> codigo;
        if(archMedicinas.eof())break;
        if(codigo == medicamento){
            
            leerImprimirTexto(MAX_CAR_MED, ' ', archMedicinas, archReporte);
            archMedicinas >> costo;
            pago = cantidad * costo * (100.0 - descuento / 2) /100;
            pago_medicamentos += pago;
            archReporte << setw(6) << cantidad << setw(16) << costo << setw(12) 
                    << pago << endl;
                    
            break;
        }
        else
            while(archMedicinas.get() != '\n');
        
    }
}

void buscarImprimirMedico(int medico, double &tarifa, ifstream &archMedicos,
        ofstream &archReporte) {

    int codigo;

    archMedicos.clear();
    archMedicos.seekg(0, ios::beg);

    while (true) {

        archMedicos >> codigo;
        if (archMedicos.eof())break;
        if (medico == codigo) {
            leerImprimirTexto(MAX_CAR_NOMBRE, '/', archMedicos, archReporte);
            leerImprimirTexto(MAX_CAR_ESPC, ' ', archMedicos, archReporte);
            archMedicos >> tarifa;
            break;
        } else
            while (archMedicos.get() != '\n');


    }

}

void imprimirFechaHora(int dd, int mm, int aa, char deli,
        ofstream &archReporte) {

    archReporte << setfill('0') << setw(2) << dd << deli << setw(2) << mm <<
            deli << setw(2) << aa << setfill(' ');

}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &duracion, int &hh_dura, int &min_dura,
        int &seg_dura) {

    int aux = (hh_fin * 3600 + min_fin * 60 + seg_fin) - (hh_ini * 3600 +
            min_ini * 60 + seg_ini);
    duracion = aux;

    hh_dura = aux / 3600;
    aux %= 3600;
    min_dura = aux / 60;
    seg_dura = aux % 60;

}

void imprimirEncabezadoCita(ofstream &archReporte) {

    archReporte << "Fecha" << setw(16) << "Duracion" << setw(20) << "Medico" <<
            setw(40) << "Especialidad" << setw(24) << "Pago por cita" << endl;

}

void leerImprimirTexto(int n, char deli, ifstream &archEntrada,
        ofstream &archReporte) {

    int cont = 0;
    char car;
    archEntrada >> ws;
    car = archEntrada.get();
    if (deli == ' ')
        archReporte.put(car);
    while (true) {
        car = archEntrada.get();
        if (car == deli)break;
        if (car == '_') car = ' ';
        archReporte.put(car);
        cont++;
    }

    archReporte << setw(n - cont) << " ";

}

void imprimirEncabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 11) << "EMPRESA DE SALUD S. A." << endl;
    imprimirCaracter('=', archReporte);
    archReporte << setw(MAX_CAR / 2 + 19) << "DETALLE DE CITAS MEDICAS POR "
            "PACIENTE" << endl;

}

void imprimirCaracter(char car, ofstream &archReporte) {

    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }
    archReporte << endl;
}