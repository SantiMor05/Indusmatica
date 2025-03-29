/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 5 de octubre de 2024, 11:45
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define CANT_MED 50
#define CANT_MEDICINAS 250

using namespace std;

/*
 * 
 */



int main(int argc, char** argv) {

    int cant_medicos, cant_medicinas;
    int cod_med[CANT_MED], cod_medicina[CANT_MEDICINAS];
    double tarifa[CANT_MED], precio[CANT_MEDICINAS];

    double monto_cita[CANT_MED]{}, ingreso_medicina[CANT_MED]{};
    int cant_pacientes[CANT_MED]{}, paciente_medicina[CANT_MED]{};
    int unidades[CANT_MEDICINAS]{};
    double ingreso_sin[CANT_MEDICINAS]{}, descuentos_medi[CANT_MEDICINAS]{};
    double promedio;

    leerMedicos(cant_medicos, cod_med, tarifa, "Medicos_laboratorio5.txt");

    leerMedicinas(cant_medicinas, cod_medicina, precio,
            "Medicinas_laboratorio5.txt");

    imprimirReportePrueba(cant_medicos, cant_medicinas, cod_med, cod_medicina,
            tarifa, precio, "Reporte-Prueba.txt");

    actualizarDatos(cant_medicos, cant_medicinas, cod_med, cod_medicina,
            tarifa, precio, monto_cita, cant_pacientes, paciente_medicina,
            ingreso_medicina, unidades, ingreso_sin, descuentos_medi,
            "CitasMedicas_laboratorio5.txt");

    emitirReporte(cant_medicos, cant_medicinas, cod_med, cod_medicina,
            tarifa, precio, monto_cita, cant_pacientes, paciente_medicina,
            ingreso_medicina, unidades, ingreso_sin, descuentos_medi,
            "ReporteDeIngresos.txt", promedio, 2);
    
    borrarMenoresPromedio(cant_medicos, cod_med, tarifa,monto_cita, 
            ingreso_medicina, cant_pacientes, paciente_medicina, promedio);
    
    emitirReporte(cant_medicos, cant_medicinas, cod_med, cod_medicina,
            tarifa, precio, monto_cita, cant_pacientes, paciente_medicina,
            ingreso_medicina, unidades, ingreso_sin, descuentos_medi,
            "ReporteDeMejoresMedicos.txt", promedio, 1);
    
    return 0;
}

