#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "FuncionesParte02EX1.h"

using namespace std;

#define INCREMENTO 5
#define MAX_CAR_CONDUCTORES 80
#define MAX_CAR_INFRACCIONES 85
#define MAX_CAR_MULTAS 50
#define NO_ENCONTRADO -1

void leerConductores(int *&dni, char **&conductor, char ***&placas){
    
    char archNomb[] = "Conductores.csv";
    ifstream arch(archNomb, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << archNomb << endl;
        exit(1);
    }
    
    int *auxDni = nullptr, documento , cap = 0;
    char **auxConductores = nullptr, ***auxPlacas = nullptr, car;
    int numDat = 0;
    
    while(true){
        arch >> documento; 
        if(arch.eof()) break;
        if(numDat == cap)
            incrementarEspacios(numDat, cap, auxDni, auxConductores, auxPlacas);
        auxDni[numDat - 1] = documento;
        arch.get(); //Leemos la coma
        auxConductores[numDat - 1] = leerCadenaExacta(arch, ',');
        arch >> documento;//Leemos el telefono y la coma (no sirve)
        auxPlacas[numDat - 1] = leerPlacas(arch);
        numDat++;
    }
    
    dni = auxDni;
    conductor = auxConductores;
    placas = auxPlacas;    
}

void incrementarEspacios(int &numDat, int &cap, int *&dni, char **&conductor, 
        char ***&placas){
    
    cap += INCREMENTO;
    if(dni == nullptr){
        dni = new int [cap]{};
        conductor = new char *[cap]{};
        placas = new char **[cap]{};
        numDat = 1;
    }
    else{
        int *auxDni;
        char **auxConductor;
        char ***auxPlacas;
        
        auxDni = new int [cap]{};
        auxConductor = new char *[cap]{};
        auxPlacas = new char **[cap]{};
        
        for(int i = 0; i < numDat; i++){
            auxDni[i] = dni[i]; 
            auxConductor[i] = conductor[i]; 
            auxPlacas[i] = placas[i]; 
        }
        delete dni;
        delete conductor;
        delete placas;
        
        dni = auxDni;
        conductor = auxConductor;
        placas = auxPlacas;
    }
}

char **leerPlacas(ifstream &arch){
    
    char **auxPlacas = nullptr, **placas, *cad;
    int numDat = 0, cap = 0;
    
    while(arch.get() != '\n'){
          
        cad = leerCadenaExactaGet(arch, 8);
        if(cad == nullptr) break;
        
        if(numDat == cap)
            incrementarEspacios(numDat, cap, auxPlacas);
        auxPlacas[numDat - 1] = cad;
        numDat++;
    }
    placas = auxPlacas;
    return placas;
}


void incrementarEspacios(int &numDat, int &cap, char **&placas){
    
    cap += INCREMENTO;
    if(placas == nullptr){
        placas = new char *[cap]{};
        numDat = 1;
    }
    else{
        char **auxPlacas;
        auxPlacas = new char *[cap]{};
        for(int i = 0; i < numDat; i++){
            auxPlacas[i] = placas[i]; 
        }
        delete placas;
        placas = auxPlacas;
    }
    
}

char *leerCadenaExactaGet(ifstream &arch, int espacios){
    
    char buffer[200], *cad;
    arch.get(buffer, espacios);
    if(arch.eof()) return nullptr;
    cad = new char [strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}


char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof()) return nullptr;
    cad = new char [strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}

void imprimirConductores(int *dni, char **conductor, char ***placas){
    
    char archNomb[] = "ReporteConductores.txt";
    ofstream arch(archNomb, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << archNomb << endl;
        exit(1);
    }
    
    arch << "REGISTRO DE CONDUCTORES" << endl;
    imprimirCaracter(arch, MAX_CAR_CONDUCTORES, '=');
    arch << setw(9) << "DNI" << setw(16) << "CONDUCTOR" << setw(45) <<
            "AUTOS"  << endl;
    imprimirCaracter(arch, MAX_CAR_CONDUCTORES, '=');
    
    for(int i = 0; conductor[i]; i++){
        arch <<setw(3) << i + 1 << ")" << setw(10) << dni[i] << setw(2) << " "
                << left << setw(45) << conductor[i] << right;
        imprimirPlacas(arch, placas[i]);
    }
}

void imprimirPlacas(ofstream &arch, char **placas){
    
    for(int i = 0; placas[i]; i++){
        if(i == 0){
            arch << setw(5) << i + 1 << ")" << placas[i] << endl;
        }
        else
            arch << setw(66) << i + 1 << ")" << placas[i] << endl;
    }
    imprimirCaracter(arch, MAX_CAR_CONDUCTORES, '-');
}

void imprimirCaracter(ofstream &arch, int n, char car){
    for(int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
}

void leerMultas(double *&multas){
    char archNomb[] = "Infracciones.csv";
    ifstream arch(archNomb, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << archNomb << endl;
        exit(1);
    }
    double buffMultas[300];
    for(int i = 0; i < 300;i++) buffMultas[i] = -1;
    int cod,mayorCod;
    char buffer[300];
    
    while(true){
        arch >>cod;
        if(arch.eof())break;
        arch.get();
        arch.getline(buffer, 300, ',');
        arch.getline(buffer, 300, ',');
        arch >> buffMultas[cod - 101];
        mayorCod = cod;
    }
    
    multas = new double [mayorCod + 10 - 101]{};
    for (int i = 0; i < mayorCod + 10 - 101; i++)
        multas[i] = buffMultas[i];
    
    multas[mayorCod + 10 - 102] = -10000;  
}

void imprimirMultas(double *multas){
    
    char archNomb[] = "ReporteMultas.txt";
    ofstream arch(archNomb, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << archNomb << endl;
        exit(1);
    }
    
    
    arch << setprecision(2) << fixed;
    
    arch << "MULTAS POR INFRACCIONES DE TRANSITO" << endl;
    imprimirCaracter(arch, MAX_CAR_MULTAS, '=');    
    arch << setw(10) << "CODIGO" << setw(10) << "MULTA" << endl;
    imprimirCaracter(arch, MAX_CAR_MULTAS, '-'); 
    int cont = 1;
    for(int i = 0; multas[i] > -100; i++){
        if(multas[i] > 0){
            arch << setw(3) << cont << ")" << setw(5) << i + 101 << setw(12) <<
                    multas[i] << endl;
            cont++;
        }
    }
}

void leerInfraccionesCometidas(int *dni, char ***placas,double *multas,
        double ***&montoXMultas){
    
    char archNomb[] = "Registro_de_Faltas.csv";
    ifstream arch(archNomb, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << archNomb << endl;
        exit(1);
    }
    
    int documento, multa, pos;
    char codigo[10], car;
    double monto;
    int cant = calcularCantidadPersonas(dni);
    
    montoXMultas = new double **[cant + 1]{};
    
    while(true){
        arch >> documento;
        if(arch.eof())break;
        arch.get();
        arch.getline(codigo, 10,',');
        arch >> multa;
        
        pos = buscarDni(documento, dni);
        if(pos != NO_ENCONTRADO){
            if(montoXMultas[pos] == nullptr)
                destinarEspacios(montoXMultas[pos], placas[pos]);
            monto = multas[multa - 101];
            agregarMulta(montoXMultas[pos], placas[pos], codigo, monto);
        }
    }
}

void agregarMulta(double **montoXMultas, char **placas, char *codigo, double monto){
    
    int pos = -1;
    for(int i = 0; placas[i]; i++){
        if(strcmp(placas[i], codigo) == 0){
            pos = i;
            break;
        }
    }   
    if(pos != -1){
        double *aux = montoXMultas[0];
        aux[pos] += monto;
        aux = montoXMultas[1];
        (*aux) += monto;
    }
    
}

void destinarEspacios(double **&montoXMultas, char **placas){
    
    
    montoXMultas = new double*[2]{};
    double *aux;
    int n;
    for(n = 0; placas[n]; n++);
    
    aux = montoXMultas[0];
    aux = new double[n];
    montoXMultas[0] = aux; 
    aux = montoXMultas[1];
    aux = new double{};
    montoXMultas[1] = aux;
}

int buscarDni(int documento, int *dni){
    
    for(int i = 0; dni[i]; i++)
        if(documento == dni[i])
            return i;
    
    return NO_ENCONTRADO;
    
}

int calcularCantidadPersonas(int *dni){
    
    int n = 0;
    for(; dni[n]; n++);
    return n;
    
}

void imprimirInfraccionesCometidas(int *dni, char **conductor,char ***placas,
        double ***montoXMultas){
    
    char archNomb[] = "ReporteInfracciones.txt";
    ofstream arch(archNomb, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << archNomb << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
    arch << "REGISTRO DE CONDUCTORES" << endl;
    imprimirCaracter(arch, MAX_CAR_INFRACCIONES, '=');
    arch << setw(9) << "DNI" << setw(16) << "CONDUCTOR" << setw(45) <<
            "AUTOS"  << setw(13) << "Multas" << endl;
    imprimirCaracter(arch, MAX_CAR_INFRACCIONES, '=');
    
    for(int i = 0; conductor[i]; i++){
        arch <<setw(3) << i + 1 << ")" << setw(10) << dni[i] << setw(2) << " "
                << left << setw(45) << conductor[i] << right;
        imprimirPlacas(arch, placas[i], montoXMultas[i]);
    }
    
}

void imprimirPlacas(ofstream &arch, char **placas, double **montXMultas){
    
    double *monto;
    for(int i = 0; placas[i]; i++){
        if(i == 0){
            arch << setw(5) << i + 1 << ")" << placas[i];
        }
        else
            arch << setw(66) << i + 1 << ")" << placas[i];
        
        if(montXMultas != nullptr){
            monto = montXMultas[0];
            arch << setw(11) << monto[i]<< endl;
        }
        else{
            arch << setw(11) << 0 << endl;
        }
    }
    arch << setw(73) << "Total:" << setw(12);
    if(montXMultas != nullptr)
        arch << (*montXMultas[1]) << endl;
    else
        arch << 0 << endl;
    imprimirCaracter(arch, MAX_CAR_INFRACCIONES, '-');
}
