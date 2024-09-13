

/* 
 * File:   FuncionesAuxliares.h
 * Author: santi
 *
 * Created on 7 de septiembre de 2024, 17:46
 */

#ifndef FUNCIONESAUXLIARES_H
#define FUNCIONESAUXLIARES_H

void imprimirEncabezado();
void procesarEImprimirReporte();
void imprimirCaracter(char car, int n);
char verificarCategoria(int aa);
void imprimirCanales(int canal1, int canal2, int canal3);
void imprimirHora(int hh, int min, int seg);
void calcularDuracion(int hh_pren, int min_pren, int seg_pren, int hh_apag,
        int min_apag, int seg_apag, int &duracion, int &hh_dur,
        int &min_dur, int &seg_dur);
void imprimirEstadisticas(int canales, int televidentes, int cant_menores, int
        cant_muj_adult, int cant_hom_jov_mas3horas, int cant_per_canales,
        int cant_menoresYadultos, int tiempo_menor_adultos, int cant_mujeres,
        int cant_hombre_jovenes, int cant_hjovenes_TPvision,
        int cant_adultos, int cantMujeresTVPUCP);

int imprimirYCalcularCanales(int canal1, int canal2, int canal3);

#endif /* FUNCIONESAUXLIARES_H */

