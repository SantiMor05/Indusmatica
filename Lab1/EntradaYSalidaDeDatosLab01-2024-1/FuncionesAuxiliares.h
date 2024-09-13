/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 6 de septiembre de 2024, 22:56
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirCabecera();
void calcularEImprimirReporte();
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, double &duracion,
        int &hh_duracion, int &min_duracion, int &seg_duracion);
void imprimirCaracter(char car, int num);
void imprimirEspecialidad(char especialidad);
void imprimirHora(int hh, int min, int seg);
void calcularEImprimirEstadisticas(double ingresos, int cantidad, int no_medicina,
            int pacientes_pediatria, int pacientes_con_gastos_mayores,
            int pacientes_cardiologia, double gastos_medicinas,
            double ingresos_medicina_dermantologia, int pacientes_derma,
            int pacientes_con_medicina);
bool verificarFecha(int dd, int mm, int aa);


#endif /* FUNCIONESAUXILIARES_H */

