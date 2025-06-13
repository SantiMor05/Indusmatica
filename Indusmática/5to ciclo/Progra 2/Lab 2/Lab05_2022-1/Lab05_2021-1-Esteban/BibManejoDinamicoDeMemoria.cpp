#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "BibManejoDinamicoDeMemoria.h"
using namespace std;

#define INCREMENTOS 5
#define MAX_CAR_PRUEBA_FALTA 90
#define MAX_CAR_PRUEBA_MULTA 80
#define NO_ENCONTRADO -1

void cargaConductores(int *&licencia, char **&conductor) {

    ifstream arch("Conductores.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }

    licencia = nullptr;
    conductor = nullptr;
    int numDat = 0, cap = 0, lice;
    char *cad;

    while (true) {
        arch >> lice;
        if (arch.eof())break;
        arch.get();
        if (numDat == cap)
            incrementarEspacios(licencia, conductor, numDat, cap);


        cad = leerCadenaExacta(arch, '\n');

        licencia[numDat - 1] = lice;
        conductor[numDat - 1] = cad;
        numDat++;
    }

}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if (arch.eof()) return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void incrementarEspacios(int *&licencia, char **&conductor, int &numDat,
        int &cap) {

    cap += INCREMENTOS;
    if (conductor == nullptr) {
        licencia = new int [cap] {
        };
        conductor = new char *[cap] {
        };
        numDat = 1;
    } else {
        int *aux = new int [cap] {
        };
        char **auxCond = new char *[cap] {
        };
        for (int i = 0; i < numDat; i++) {
            aux[i] = licencia[i];
            auxCond[i] = conductor[i];
        }

        delete licencia;
        delete conductor;

        conductor = auxCond;
        licencia = aux;
    }
}

void reporteConductores(int *licencia, char **conductor) {

    ofstream arch("ReporteConductores.txt", ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }

    for (int i = 0; conductor[i]; i++) {
        arch << licencia[i] << setw(5) << " " << conductor[i] << endl;
    }

}

void cargaFaltas(int *licencia, char ***&placa, int **&faltas) {

    ifstream arch("RegistroDeFaltas.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }

    int numDat = contarDatos(licencia), documento, falta, aux, pos;
    int ndatos[numDat + 1]{}, posCod, *auxFalta;
    char *cod, car;
    placa = new char **[numDat + 1] {
    };
    faltas = new int *[numDat + 1] {
    };
    char **placaPersona;
    while (true) {
        arch >> documento;
        if (arch.eof())break;
        arch.get();
        cod = leerCadenaExacta(arch, ',');
        arch >> aux >> car >> aux >> car >> aux >> car >> falta;
        pos = buscarDocumento(documento, licencia);
        if (pos != NO_ENCONTRADO) {
            if (ndatos[pos] % INCREMENTOS == 0)
                incrementarEspacios(placa[pos], faltas[pos], ndatos[pos]);

            placaPersona = placa[pos];
            auxFalta = faltas[pos];
            placaPersona[ndatos[pos] - 1] = cod;
            auxFalta[ndatos[pos] - 1] = falta;

            ndatos[pos]++;
        }
    }
}

void incrementarEspacios(char **&placa, int *&falta, int &ndatos) {

    int cap = ndatos + INCREMENTOS;
    if (placa == nullptr) {
        placa = new char *[cap] {
        };
        falta = new int[cap] {
        };
        ndatos = 1;
    } else {
        char **auxPlaca = new char *[cap] {
        };
        int *auxFalta = new int[cap] {
        };
        for (int i = 0; i < ndatos; i++) {
            auxPlaca[i] = placa[i];
            auxFalta[i] = falta[i];
        }
        delete placa;
        delete falta;

        placa = auxPlaca;
        falta = auxFalta;
    }

}

int buscarDocumento(int documento, int *licencia) {

    for (int i = 0; licencia[i]; i++) {
        if (documento == licencia[i])
            return i;
    }
    return NO_ENCONTRADO;
}

int contarDatos(int *licencia) {
    int n = 0;
    for (; licencia[n]; n++);
    return n;
}

void reporteFaltas(int *licencia, char **conductor, char ***placa, int **falta) {

    ofstream arch("ReporteDeFaltas.txt", ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }

    for (int i = 0; conductor[i]; i++) {
        imprimirLinea(arch, MAX_CAR_PRUEBA_FALTA, '=');
        arch << licencia[i] << setw(5) << " " << left << setw(55) <<
                conductor[i] << right;
        if (placa[i] != nullptr)
            imprimirFaltas(placa[i], falta[i], arch);
    }

}

void imprimirLinea(ofstream &arch, int n, char car) {
    for (int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
}

void imprimirFaltas(char **placas, int *falta, ofstream &arch) {


    for (int i = 0; placas[i]; i++) {
        if (i == 0)
            arch << setw(2) << i + 1 << ")";
        else
            arch << setw(69) << " " << i + 1 << ")";
        arch << setw(10) << placas[i] << setw(8) << falta[i] << endl;
    }

}

void resumenMultas(int *licencia, int **falta, double **&multa) {
    ifstream arch("Infracciones.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }

    int numDat = contarDatos(licencia), numFalta;
    char buffer[500], tipoFalta[200];
    double monto;
    multa = new double*[numDat + 1] {
    };

    while (true) {
        arch >> numFalta;
        if (arch.eof())break;
        arch.get();
        arch.getline(buffer, 500, ',');
        arch.getline(tipoFalta, 200, ',');

        arch >> monto;

        colocarMultas(falta, multa, numFalta, tipoFalta, monto, numDat);

    }
}

void colocarMultas(int **falta, double **multa, int numFalta, char *tipoFalta,
        double monto, int numDat) {
    int *auxFaltas, pos;
    double *auxMulta;
    for (int i = 0; i < numDat; i++) {
        auxFaltas = falta[i];
        if (falta[i] != nullptr) {
            if (multa[i] == nullptr)
                darleEspacios(multa[i]);
            auxMulta = multa[i];
            for(int j = 0; auxFaltas[j];j++){
                if (auxFaltas[j] == numFalta){
                    if (strcmp(tipoFalta, "Leve") == 0)
                    pos = 0;
                    else if (strcmp(tipoFalta, "Grave") == 0)
                        pos = 1;
                    else pos = 2;
                    auxMulta[pos] += monto;
                } 
            }    
        }
    }
}

void darleEspacios(double *&multa) {

    multa = new double[3] {
    };


}

void reporteMultas(int *licencia, char **conductor, double **multa) {

    ofstream arch("ReporteDeMultas.txt", ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }
    arch << fixed << setprecision(2);
    for (int i = 0; conductor[i]; i++) {
        imprimirLinea(arch, MAX_CAR_PRUEBA_MULTA, '=');
        arch << licencia[i] << setw(5) << " " << left << setw(47) <<
                conductor[i] << right;
        if (multa[i] != nullptr)
            imprimirMultas(multa[i], arch);
        else
            arch << setw(20) << "NO TIENE MULTAS" << endl;
    }

}

void imprimirMultas(double *multa, ofstream &arch) {


    arch << "Suma De Falta:" << endl;
    arch << setw(60) << " " << "Leves: " << setw(12) << multa[0] << endl;
    arch << setw(60) << " " << "Grave: " << setw(12) << multa[1] << endl;
    arch << setw(60) << " " << "Muy Grave: " << setw(8) << multa[2] << endl;
}