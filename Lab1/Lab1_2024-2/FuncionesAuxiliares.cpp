#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "FuncionesAuxiliares.h"
#define PI 3.14159


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
    }

}

void imprimirEncabezado(ifstream &archDatos, ofstream &archReporte) {
    int dd, mm, aa;
    char car;
    archDatos >> dd >> car >> mm >> car >> aa;

    archReporte << setw(MAX_CAR / 2 + 16) << "EMPRESA DE REPARTOS A DOMICILIO "
            "TP S. A." << endl;
    archReporte << setw(MAX_CAR / 2 + 4) << "FECHA DE LOS REPARTOS: " <<
            setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" <<
            setw(2) << aa << endl << setfill(' ');


}

void imprimirCaracter(int n, char car, ofstream &archReporte) {
    for (int i = 0; i < n; i++) {
        archReporte.put(car);
    }

    archReporte << endl;
}

void leerProcesarImprimirReporte(ifstream &archDatos, ofstream &archReporte) {

    int dni, hh_part, min_part, seg_part, hh_llega, min_llega, seg_llega;
    double velocidad, pago, pago_acumulado, distancia, dist_acumulado,
            x1, x2, y1, y2, dist_mayor, dist_menor;
    int grados, min_grados, seg_grados, dni_menor, dni_mayor, cont = 0;
    char car;
    archReporte << setprecision(2) << fixed;
    while (true) {
        archDatos >> dni;
        if (archDatos.eof()) break;
        imprimirCaracter(MAX_CAR, '=', archReporte);
        imprimirDatosRepartidor(archDatos, archReporte, dni);
        imprimirEncabezadoDatos(archReporte);
        archDatos >> hh_part >> car >> min_part >> car >> seg_part;
        dist_acumulado = pago_acumulado = 0;
        x1 = x2 = y1 = y2 = 0;
        for (int i = 0; i < 3; i++) {
            archDatos >> velocidad >> hh_llega >> car >> min_llega >> car >>
                    seg_llega;
            archDatos >> grados >> car >> min_grados >> car >> seg_grados >>
                    car;

            calcularDistancia(distancia, dist_acumulado, hh_part, min_part,
                    seg_part, hh_llega, min_llega, seg_llega, velocidad);

            calcularPuntos(x1, y1, x2, y2, distancia, grados, min_grados,
                    seg_grados);

            calcularPago(distancia, pago, pago_acumulado);


            imprimirTramo(i, hh_part, min_part, seg_part, hh_llega, min_llega,
                    seg_llega, velocidad, distancia, x1, y1, x2, y2,
                    dist_acumulado, pago, archReporte);


            hh_part = hh_llega;
            min_part = min_llega;
            seg_part = seg_llega;
            x1 = x2;
            y1 = y2;
        }
        
        calcularRetorno(distancia, x1, y1, dist_acumulado, velocidad,
                hh_part, min_part, seg_part, hh_llega, min_llega, seg_llega);
        imprimirTramo(4, hh_part, min_part, seg_part, hh_llega, min_llega,
                seg_llega, velocidad, distancia, x1, y1, 0, 0,
                dist_acumulado, 0, archReporte);
        imprimirCaracter(MAX_CAR, '=', archReporte);
        archReporte << "PAGO TOTAL AL REPARTIDOR: " << pago_acumulado << endl;
        
        calcularMenorMayor(dni_menor, dni_mayor, dist_mayor, dist_menor, 
                dist_acumulado, dni, cont);
        
        cont++;
    }

    imprimirResumen(dni_mayor, dist_mayor, dist_menor, dni_menor, archReporte);

}


void imprimirResumen(int dni_mayor, double dist_mayor, double dist_menor, 
        int dni_menor, ofstream &archReporte){
    
    imprimirCaracter(MAX_CAR, '/', archReporte);
    archReporte << "REPARTIDOR CON MAYOR RECORRIDO" << endl;
    archReporte << "DNI: " << dni_mayor << endl;
    archReporte << "Distancia: " << dist_mayor << " km." << endl;
    
    archReporte << "REPARTIDOR CON MENOR RECORRIDO" << endl;
    archReporte << "DNI: " << dni_menor<< endl;
    archReporte << "Distancia: " << dist_menor << " km." << endl;
    
}

void calcularMenorMayor(int &dni_menor, int &dni_mayor, double &dist_mayor, 
        double &dist_menor, double dist_acumulado, int dni, int cont ){
    
    if(cont == 0){
        dni_menor = dni;
        dni_mayor = dni;
        dist_mayor = dist_acumulado;
        dist_menor = dist_acumulado;
    }
    else if(dist_mayor < dist_acumulado){
        dist_mayor = dist_acumulado;
        dni_mayor = dni;
    }
    else if(dist_menor > dist_acumulado){
        dni_menor = dni;
        dist_menor = dist_acumulado;
    }
    
}

void imprimirTramo(int i, int hh_part, int min_part, int seg_part, int hh_llega,
        int min_llega, int seg_llega, double velocidad, double distancia,
        double x1, double y1, double x2, double y2, double dist_acumulado,
        double pago, ofstream &archReporte) {

    if (i < 4) {
        archReporte << "Tramo " << i << ":" << setw(3) << " ";
    } else {
        archReporte << "Retorno: " << setw(2) << " ";
    }

    archReporte << setfill('0') << setw(2) << hh_part << ":" << setw(2)
            << min_part << ":" << setw(2) << seg_part << setfill(' ') << 
            setw(3) <<  " " << setw(2) << setfill('0') <<hh_llega << ":" 
            << setw(2)<< min_llega << ":" << setw(2) << seg_llega << 
            setfill(' ') <<setw(3) << " " << setw(8) << velocidad << 
            setw(12) << distancia << setw(14) << x1 << " - " << setw(6) << y1 << 
            setw(16) << x2 << " - " << setw(6) << y2 << setw(19) <<
            dist_acumulado << setw(18) << pago << endl;

}

void calcularRetorno(double &distancia, double x1, double y1,
        double &dist_acumulado, double velocidad, int &hh_part, int &min_part,
        int &seg_part, int &hh_llega, int &min_llega, int &seg_llega) {

    distancia = sqrt(pow(x1, 2) + pow(y1, 2));
    dist_acumulado += distancia;

    hh_part = hh_llega;
    min_part = min_llega;
    seg_part = seg_llega;

    int tiempo = (distancia * 1000) / (velocidad * 1000 / 3600);

    int hora = hh_part * 3600 + min_part * 60 + seg_part;
    hora += tiempo;

    
    
    hh_llega = hora / 3600;
    if(hh_llega >= 24) hh_llega -= 24;
    hora %= 3600;
    min_llega = hora / 60;
    seg_llega = hora % 60;



}

void imprimirEncabezadoDatos(ofstream &archReporte) {
    archReporte << "DATOS DE LA RUTA: " << endl;
    archReporte << left << setw(11) << " " << setw(11) << "HORA INI" <<
            setw(12) << "HORA FIN" << setw(12) << "VELOCIDAD" << setw(12) <<
            "DISTANCIA" << setw(24) << "PUNTO DE PARTIDA (X,Y)" <<
            setw(24) << "PUNTO DE LLEGADA (X,Y)" << setw(22) <<
            "DISTANCIA ACUMULADA" << "PAGO POR ENVIO" << endl << right;
}

void calcularPuntos(double x1, double y1, double &x2, double &y2,
        double distancia, int grados, int min_grados, int seg_grados) {

    double angulo = grados + (double) min_grados / 60 +
            (double) seg_grados / 3600;

    angulo = PI * angulo / 180;
    
    x2 = x1 + distancia * cos(angulo);
    y2 = y1 + distancia * sin(angulo);


}

void calcularPago(double distancia, double &pago, double &pago_acumulado) {
    if (distancia < 10.5) pago = 8.5;
    else if (distancia < 20.5) pago = 17.75;
    else if (distancia < 35.5) pago = 29.85;
    else pago = 45.69;

    pago_acumulado += pago;
}

void imprimirDatosRepartidor(ifstream &archDatos, ofstream &archReporte,
        int dni) {
    archReporte << "Repartidor:" << endl << "Nombre: ";
    leerImprimirTexto(archDatos, archReporte);
    archReporte << "DNI: " << dni << endl;
    imprimirCaracter(MAX_CAR, '-', archReporte);
}

void leerImprimirTexto(ifstream &archDatos, ofstream &archReporte) {
    char car;
    int cont = 0;
    archDatos >> ws;
    while (true) {
        car = archDatos.get();
        if (car == ' ') break;
        archReporte.put(car);
        cont++;
    }

    cout << setw(MAX_CAR_NOMBRE - cont) << " ";

}

void calcularDistancia(double &distancia, double &dist_acumulado, int hh_part,
        int min_part, int seg_part, int hh_llega, int min_llega, int seg_llega,
        double velocidad) {

    int diferencia = (hh_llega * 3600 + min_llega * 60 + seg_llega) -
            (hh_part * 3600 + min_part * 60 + seg_part);

    velocidad = velocidad * 1000 / 3600;

    distancia = velocidad * diferencia / 1000;

    dist_acumulado += distancia;

}