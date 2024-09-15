#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "FuncionesAuxiliares.h"

using namespace std;

void abrirArchivos(ifstream &archDatos, ofstream &archReporte,
        const char * nombreDatos, const char *nombreReporte) {


    archDatos.open(nombreDatos, ios::in);
    if (not archDatos.is_open()) {
        cout << "ERRROR: No se pudo abrir el archivo " << nombreDatos << endl;
        exit(1);
    }

    archReporte.open(nombreReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERRROR: No se pudo abrir el archivo " << nombreReporte << endl;
        exit(1);
    }

}

void leerProcesarImprimirDatos(ifstream &archDatos, ofstream &archReporte) {

    int dd_doce, mm_doce, aa_doce, dd_alum, mm_alum, aa_alum, carne,
            codigo, dd_libro, mm_libro, aa_libro, fecha_alum, fecha_doce, fecha,
            cant_libros, carne_estudiante, carne_docente, primer_docente,
            primer_estudiante;
    char car, usuario, calificacion;
    double valor, porcentaje, multa, multa_total, mayor_deuda_docente,
            mayor_deuda_estudiante;
    bool retrasado, entro;

    archDatos >> dd_doce >> car >> mm_doce >> car >> aa_doce >> dd_alum >>
            car >> mm_alum >> car >> aa_alum;

    fecha_doce = calcularFecha(dd_doce, mm_doce, aa_doce);
    fecha_alum = calcularFecha(dd_alum, mm_alum, aa_alum);

    imprimirEncabezado(dd_doce, mm_doce, aa_doce, dd_alum, mm_alum, aa_alum,
            archReporte);

    archReporte << setprecision(2) << fixed;
    primer_docente = primer_estudiante = 0;
    while (true) {

        archDatos >> carne;
        if (archDatos.eof())break;
        archDatos >> usuario >> calificacion;
        entro = false;

        multa_total = cant_libros = 0;

        while (archDatos.get() != '\n') {
            retrasado = false;
            archDatos >> codigo >> dd_libro >> car >> mm_libro >> car >>
                    aa_libro >> valor;
            fecha = calcularFecha(dd_libro, mm_libro, aa_libro);

            if (fecha < fecha_alum && usuario == 'E') {
                if (calificacion == 'R') porcentaje = 0.03;
                else porcentaje = 0.01;
                retrasado = true;
            } else if (fecha < fecha_doce && usuario == 'D') {
                if (calificacion == 'R') porcentaje = 0.0725;
                else porcentaje = 0.0225;
                retrasado = true;
            }

            if (retrasado) {

                if (cant_libros == 0) {
                    imprimirDatosUsuario(carne, usuario,
                            calificacion, archReporte);
                    entro = true;
                }
                multa = valor * porcentaje;
                imprimirDatosLibro(codigo, dd_libro, mm_libro, aa_libro, multa,
                        archReporte);
                multa_total += multa;
                cant_libros++;
            }

        }
        if (entro) {
            imprimirCaracter('=', archReporte);
            archReporte << setw(5) << " " << "Cantidad de libros adeudados:" <<
                    setw(10) << cant_libros << endl;
            archReporte << setw(5) << " " << "Total de deudas por multa:" <<
                    setw(15) << multa_total << endl;
            imprimirCaracter('=', archReporte);
            hallarMayorDeuda(mayor_deuda_docente, mayor_deuda_estudiante,
                    carne_estudiante, carne_docente, carne, multa_total,
                    usuario, primer_estudiante, primer_docente);
        }
    }

    imprimirResumen(mayor_deuda_docente, mayor_deuda_estudiante,
            carne_estudiante, carne_docente, archReporte);

}

void imprimirResumen(double mayor_deuda_docente, double mayor_deuda_estudiante,
        int carne_estudiante, int carne_docente,
        ofstream &archReporte) {

    archReporte << "Resumen:" << endl;
    archReporte << "Reincidente con mayor deuda:" << setw(18) << "Docente: " <<
            carne_docente << "  Deuda S/. " << setw(5) << mayor_deuda_docente <<
            setw(13) << "Estudiante: " << carne_estudiante << "  Deuda S/. " <<
            setw(5) << mayor_deuda_estudiante;
    

}

void hallarMayorDeuda(double &mayor_deuda_docente, double &mayor_deuda_estudiante,
        int &carne_estudiante, int &carne_docente, int carne,
        double multa_total, char usuario, int &primer_estudiante, 
        int &primer_docente){

    if (usuario == 'E') {
        if ((primer_estudiante == 0) or
                (multa_total > mayor_deuda_estudiante)) {
            mayor_deuda_estudiante = multa_total;
            carne_estudiante = carne;
            primer_estudiante = 1;
        }
    } else {
        if ((primer_docente == 0) or 
                (multa_total > mayor_deuda_docente)) {
            mayor_deuda_docente = multa_total;
            carne_docente = carne;
            primer_docente = 1;
        }
    }

}

void imprimirDatosLibro(int codigo, int dd, int mm, int aa,
        double multa, ofstream & archReporte) {

    archReporte << setw(15) << codigo << setw(9) << " ";
    imprimirFecha(dd, mm, aa, archReporte);
    archReporte << setw(19) << multa << endl;


}

void imprimirDatosUsuario(int carne, char usuario, char calificacion,
        ofstream & archReporte) {

    archReporte << setw(5) << " " << "Carne No.:" << setw(12) << carne <<
            setw(12) << "Tipo";
    if (usuario == 'E') {
        archReporte << setw(12) << "Estudiante";
    } else {
        archReporte << setw(10) << "Docente";
    }

    if (calificacion == 'R') {
        archReporte << " - " << "Reincidente";
    }
    archReporte << endl;
    imprimirCaracter('-', archReporte);
    archReporte << setw(5) << " " << "Libros en su poder, retrasados en su "
            "entrega:" << endl;
    archReporte << setw(15) << "Codigo" << setw(20) << "F. de retiro" <<
            setw(19) << "Multa" << endl;
}

int calcularFecha(int dd, int mm, int aa) {

    return aa * 10000 + mm * 100 + dd;

}

void imprimirEncabezado(int dd_doce, int mm_doce, int aa_doce, int dd_alum,
        int mm_alum, int aa_alum, ofstream & archReporte) {

    archReporte << setw(MAX_CAR / 2 + 18) << "BIBLIOTECA GENERAL DE LA "
            "UNIVERSIDAD" << endl;

    imprimirCaracter('=', archReporte);

    archReporte << setw(5) << "Fecha limite de devolucion:" << endl;
    archReporte << setw(40) << " " << "Docentes" << setw(10) << " ";
    imprimirFecha(dd_doce, mm_doce, aa_doce, archReporte);
    archReporte << endl;
    archReporte << setw(40) << " " << "Estudiantes" << setw(7) << " ";
    imprimirFecha(dd_alum, mm_alum, aa_alum, archReporte);
    archReporte << endl;
    imprimirCaracter('-', archReporte);
    archReporte << setw(MAX_CAR / 2 + 22) << "RELACION DE USUARIO RETRASADOS"
            "EN SU ENTREGA" << endl;
    imprimirCaracter('=', archReporte);
}

void imprimirFecha(int dd, int mm, int aa, ofstream & archReporte) {
    archReporte << setfill('0') << setw(2) << dd << "/" << setw(2) << mm <<
            "/" << setw(4) << aa << setfill(' ');

}

void imprimirCaracter(char car, ofstream & archReporte) {

    for (int i = 0; i < MAX_CAR; i++) {
        archReporte.put(car);
    }
    archReporte << endl;
}