#include <iostream>
#include <iomanip>
#include "FuncionesAuxliares.h"

#define MAX_CARACTER 120

using namespace std;

void imprimirCaracter(char car, int n) {
    for (int i = 0; i < n; i++) {
        cout.put(car);
    }
    cout << endl;
}

void imprimirEncabezado() {
    cout << setw(MAX_CARACTER / 2 + 17) << "EMPRESA DE OPINION DE "
            "MERCADO S. A." << endl;

    imprimirCaracter('=', MAX_CARACTER);
    cout << setw(45) << "REGISTRO DE PREFERENCIAS DE LOS CLIENTES" << endl;
    imprimirCaracter('=', MAX_CARACTER);

    cout << left << setw(12) << "DNI No." << setw(9) << "Sexo" <<
            setw(13) << "Categoria" << setw(11) << "Hora (P)" <<
            setw(12) << "Hora (A)" << setw(19) << "Duracion (H:M:S)" <<
            setw(17) << "Duracion (H)" << setw(13) << "Canales" <<
            "Compañia" << endl;
    cout << right;
    imprimirCaracter('-', MAX_CARACTER);
}

char verificarCategoria(int aa) {
    if (aa >= 2009) return 'M'; //menor
    if (aa >= 1998) return 'J'; //joven
    return 'A'; //adulto
}

void procesarEImprimirReporte() {

    int dni, dd, mm, aa, hh_pren, min_pren, seg_pren;
    int hh_apag, min_apag, seg_apag, canal1, canal2, canal3;
    char sexo, compania, car, categoria;
    int duracion_segs, hh_dur, min_dur, seg_dur;
    double dura_horas;

    //Variables para las estadisticas
    int canales, televidentes, cant_menores, cant_muj_adult;
    int cant_hom_jov_mas3horas, cant_per_canales, cant_menoresYadultos;
    int tiempo_menor_adultos, cant_mujeres, cant_hombre_jovenes;
    int cant_hjovenes_TPvision, cant_adultos, cantMujeresTVPUCP;
    int validar;

    televidentes = cant_muj_adult = cant_menores = 0;
    cant_hom_jov_mas3horas = cant_per_canales = cant_menoresYadultos = 0;
    tiempo_menor_adultos = cant_mujeres = cant_hombre_jovenes = 0;
    cant_hjovenes_TPvision = cant_adultos = cantMujeresTVPUCP = 0;

    //Lectura de datos
    while (true) {

        cin >> dni;
        if (cin.eof())break;
        cin >> sexo;
        cin >> dd >> car >> mm >> car >> aa;
        cin >> hh_pren >> car >> min_pren >> car >> seg_pren;
        cin >> hh_apag >> car >> min_apag >> car >> seg_apag;
        cin >> canal1 >> canal2 >> canal3;
        cin >> compania;

        //Cálculos y verificaciones
        categoria = verificarCategoria(aa);
        calcularDuracion(hh_pren, min_pren, seg_pren, hh_apag, min_apag,
                seg_apag, duracion_segs, hh_dur, min_dur, seg_dur);

        dura_horas = (double) duracion_segs / 3600;

        //Impresion del reporte
        cout << left << setw(10) << dni;
        if (sexo == 'F') {
            cout << setw(12) << "Femenino";
            if (compania == 'A') {
                cantMujeresTVPUCP++;
            }
            cant_mujeres++;
        } else {
            cout << setw(12) << "Masculino";
        }

        cout << setw(12);
        if (categoria == 'A') {
            cout << "Adulto";
            if (sexo == 'F') {
                validar = (hh_apag <= 9 and min_apag < 30) or
                        (hh_pren >= 12 and min_pren > 45);
                if (validar) {
                    cant_muj_adult++;
                }
            }

            cant_menoresYadultos++;
            tiempo_menor_adultos += duracion_segs;
            cant_adultos++;

        }
        else if (categoria == 'J') {
            cout << "Joven";
            if (sexo == 'M') {
                validar = (hh_dur >= 3 and min_dur >= 30);
                if (validar) {
                    cant_hom_jov_mas3horas++;
                }
                if (compania == 'C') {
                    cant_hjovenes_TPvision++;
                }
                cant_hombre_jovenes++;
            }
        } else {
            cout << "Menor";
            if ((hh_pren >= 14 and hh_pren <= 19) or
                    (hh_apag >= 14 and hh_apag <= 19) or
                    (hh_pren < 14 and hh_apag > 19)) {
                cant_menores++;
            }
            cant_menoresYadultos++;
            tiempo_menor_adultos += duracion_segs;
        }

        //Verificamos los canales
        validar = (canal1 != 314 and canal2 != 314 and canal2 != 314) and
                (canal1 != 555 and canal2 != 555 and canal2 != 555) and
                ((canal1 == 770 and canal2 == 770 and canal2 == 770) or
                (canal1 == 312 and canal2 == 312 and canal2 == 312) or
                (canal1 == 577 and canal2 == 577 and canal2 == 577));
        if (validar) {
            cant_per_canales++;
        }

        //Imprimimos horarios
        cout << right;
        imprimirHora(hh_pren, min_pren, seg_pren);
        cout << setw(3) << " ";
        imprimirHora(hh_apag, min_apag, seg_apag);
        cout << setw(7) << " ";
        imprimirHora(hh_dur, min_dur, seg_dur);

        cout.precision(4);
        cout << fixed;
        cout << setw(16) << dura_horas;

        canales += imprimirYCalcularCanales(canal1, canal2, canal3);

        if (compania == 'A') {
            cout << "TVPUCP" << endl;
        } else if (compania == 'B') {
            cout << "CableMas" << endl;
        } else {
            cout << "TPVision" << endl;
        }

        televidentes++;
    }

    imprimirEstadisticas(canales, televidentes, cant_menores, cant_muj_adult,
            cant_hom_jov_mas3horas, cant_per_canales, cant_menoresYadultos,
            tiempo_menor_adultos, cant_mujeres, cant_hombre_jovenes,
            cant_hjovenes_TPvision, cant_adultos, cantMujeresTVPUCP);
}

void imprimirEstadisticas(int canales, int televidentes, int cant_menores, int
        cant_muj_adult, int cant_hom_jov_mas3horas, int cant_per_canales,
        int cant_menoresYadultos, int tiempo_menor_adultos, int cant_mujeres,
        int cant_hombre_jovenes, int cant_hjovenes_TPvision,
        int cant_adultos, int cantMujeresTVPUCP) {
    
    double promedio, porcentaje;
    
    imprimirCaracter('=', MAX_CARACTER);
    cout.precision(2);
    cout << left << setw(8) << " " << "ESTADISTICAS OBTENIDAS: " << endl;

    cout << setw(8) << " " << setw(90) << "Cantidad de televidentes "
            "regitrasdos" << televidentes << endl;
    
    cout << setw(8) << " " << setw(90) << "Cantidad de menores que ven"
            " entre  las 14:00 y las 19:00" << cant_menores << endl;
    
    cout << setw(8) << " " << setw(90) << "Cantidad de mujeres adultas"
            " que NO ven television entre las 9:30:00 y las 12:45" <<
            cant_muj_adult << endl;
    
    cout << setw(8) << " " << setw(90) << "Cantidad de hombres jovenes "
            "que ve mas de 3 horas y media" << cant_hom_jov_mas3horas <<
            endl;
    
    cout << setw(8) << " " << setw(90) << "Cantidad de personas que"
            " ven los canales 770,312 o 577 pero no 314 ni 555" <<
            cant_per_canales << endl;
    
    promedio = (double)tiempo_menor_adultos / cant_menoresYadultos;
    
    cout << setw(8) << " " << setw(90) << "Tiempo promedio que ven los"
            " menores y adultos" << promedio << endl;
    
    porcentaje = (double) cantMujeresTVPUCP / cant_mujeres * 100;
    
    cout << setw(8) << " " << setw(90) << "Porcentaje de mujeres que"
            " ven TVPUCP" << porcentaje << "%" << endl;
    
    porcentaje = (double)cant_hjovenes_TPvision / cant_hombre_jovenes  * 100;
    
    cout << setw(8) << " " << setw(90) << "Porcentaje de hombres jovenes"
            " que ve TPVision" << porcentaje << "%" << endl;
    
    porcentaje = (double)cant_adultos / televidentes * 100;
    
    cout << setw(8) << " " << setw(90) << "Porcentaje de adultos "
            "registrados" << porcentaje << "%" << endl;
    
    promedio = (double)canales / televidentes;
    
    cout << setw(8) << " " << setw(90) << "Promedio de canales que ven los"
            " televidentes" << promedio << endl;


}

int imprimirYCalcularCanales(int canal1, int canal2, int canal3) {
    int canales = 0;
    int numeroCar = 13;

    cout << setw(12) << canal1;
    canales++;
    numeroCar -= 3;
    if (canal2 != 0) {
        cout << "/" << canal2;
        canales++;
        numeroCar -= 4;
    }
    if (canal3 != 0) {
        cout << "/" << canal3;
        canales++;
        numeroCar -= 4;
    }

    cout << setw(numeroCar) << " ";

    return canales;
}

void imprimirHora(int hh, int min, int seg) {
    cout << setfill('0') << setw(2) << hh << ":" <<
            setw(2) << min << ":" << setw(2) << seg << setfill(' ');
}

void calcularDuracion(int hh_pren, int min_pren, int seg_pren, int hh_apag,
        int min_apag, int seg_apag, int &duracion, int &hh_dur,
        int &min_dur, int &seg_dur) {

    int segs_prendido, segs_apagado, aux;

    //Pasamos todo a segundos
    segs_prendido = hh_pren * 3600 + min_pren * 60 + seg_pren;
    segs_apagado = hh_apag * 3600 + min_apag * 60 + seg_apag;

    duracion = segs_apagado - segs_prendido; //en segundos

    hh_dur = duracion / 3600;
    aux = duracion % 3600;

    min_dur = aux / 60;
    aux = aux % 60;

    seg_dur = aux;
}