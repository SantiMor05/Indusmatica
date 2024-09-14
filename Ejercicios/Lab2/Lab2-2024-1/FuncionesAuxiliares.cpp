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

void leerProcesarImprimirDatos(ifstream &archDatos, ofstream &archReporte) {

    int dd, mm, aa, dni, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin,
            hh_dura, min_dura, seg_dura, duracion;
    double descuento, tarifa, monto_medicamentos, pago, duracion_horas,
            total;
    char especialidad, car, medicamentos;
    int min_duracion, max_duracion, cant_archivo, cant_procesados;

    calcularMaxMinDuracion(min_duracion, max_duracion);
    total = cant_archivo = cant_procesados = 0;
    while (true) {
        archDatos >> dd;
        if (archDatos.eof()) break;

        monto_medicamentos = 0;

        archDatos >> car >> mm >> car >> aa >> dni >> descuento >> hh_ini >>
                car >> min_ini >> car >> seg_ini >> hh_fin >> car >>
                min_fin >> car >> seg_fin >> tarifa >> especialidad >>
                medicamentos;


        if (medicamentos == 'S') {
            archDatos >> monto_medicamentos;
        }

        if (especialidad == 'P') {

            calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin,
                    hh_dura, min_dura, seg_dura, duracion, duracion_horas);

            if (duracion >= min_duracion and duracion <= max_duracion) {
                pago = tarifa * duracion_horas * (100.0 - descuento) / 100 +
                        monto_medicamentos * (100.0 - descuento / 2) / 100;

                imprimirTextoConDelimitador(dd, mm, aa, '/', archReporte, 0);
                archReporte << setw(10) << dni << setw(3) << " ";
                imprimirTextoConDelimitador(hh_ini, min_ini, seg_ini,
                        ':', archReporte, 2);
                imprimirTextoConDelimitador(hh_fin, min_fin, seg_fin,
                        ':', archReporte, 6);
                imprimirTextoConDelimitador(hh_dura, min_dura, seg_dura,
                        ':', archReporte, 0);
                archReporte << setprecision(4) << fixed << setw(16) <<
                        duracion_horas << setprecision(2) << setw(16) <<
                        descuento << "%" << setw(20) << pago << endl;

                total += pago;
                cant_procesados++;
            }

        }
        cant_archivo++;
    }

    imprimirEstadisticas(total, cant_procesados, cant_archivo, archReporte);

}

void imprimirEstadisticas(double total, int cant_procesados, int cant_archivo,
        ofstream &archReporte) {

    double porcentaje = (double) cant_procesados / cant_archivo * 100;

            imprimirCaracter('=', archReporte);
    archReporte << "Total de ingresos : " << total << endl;
    imprimirCaracter('=', archReporte);

    archReporte << "ESTADISTICAS OBTENIDAS" << endl;
    archReporte << "Cantidad de registros del archivo: " << setw(20) <<
            cant_archivo << endl;
    archReporte << "Cantidad de registros procesados: " << setw(21) <<
            cant_procesados << endl;
    archReporte << "Porcentaje de registros procesados: " << setw(18) <<
            porcentaje << "%" << endl;

}

void imprimirTextoConDelimitador(int dd, int mm, int aa, char car,
        ofstream &archReporte, int espacios_separacion) {

    archReporte << setfill('0') << setw(2) << dd << car << setw(2) << mm <<
            car << setw(2) << aa << setfill(' ') << setw(espacios_separacion)
            << " ";
}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &hh_dura, int &min_dura, int &seg_dura,
        int &duracion, double &duracion_horas) {

    int aux;

    //Todo lo pasamos a segundo y calculamos las diferencia
    duracion = (hh_fin * 3600 + min_fin * 60 + seg_fin) -
            (hh_ini * 3600 + min_ini * 60 + seg_ini);

    duracion_horas = (double) duracion / 3600;

    aux = duracion;

    hh_dura = aux / 3600;
    aux %= 3600;
    min_dura = aux / 60;
    seg_dura = aux % 60;

}

void calcularMaxMinDuracion(int &min_duracion, int &max_duracion) {

    min_duracion = 3600 + 15 * 60 + 30;
    max_duracion = 2 * 3600 + 30 * 60 + 25;

}

void imprimirEncabezado(ofstream &archReporte) {

    archReporte << setw(MAX_CAR / 2 + 11) << "EMPRESA DE SALUD S. A." << endl;

    imprimirCaracter('=', archReporte);

    archReporte << setw(5) << " " << "REGISTRO DE CITAS DE LAS CONSULTAS "
            "MEDICAS EN PEDIATRIA" << endl;
    archReporte << setw(5) << " " << "ENTRE 1 HORA CON 15 MINUTOS Y 30 SEGUNDOS "
            "Y 2 HORAS 30 MINUTOS Y 25 SEGUNDOS DE DURACION" << endl;
    imprimirCaracter('=', archReporte);

    archReporte << left << setw(13) << "Fecha" << setw(12) << "Paciente" <<
            setw(11) << "Inicio" << setw(8) << "Fin" << setw(20) <<
            "Duracion (H:M:S)" << setw(16) << "Duracion (H)" << setw(15) <<
            "% por Seguro" << "Pago (cita + medicinas)" << endl << right;

    imprimirCaracter('-', archReporte);
}

void imprimirCaracter(char car, ofstream &archReporte) {
    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }

    archReporte << endl;
}