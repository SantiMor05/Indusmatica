#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define N 80
#define MAX_CAR_NOMBRE 30


using namespace std;

void lecturaEImpresionDatosUsuario(int &distrito1, int &distrito2, int &hh,
        int &min, int &seg, int &duracion, char &alimentos) {

    char car;
    int hhU_dura, minU_dura,segU_dura;

    cin >> distrito1 >> distrito2;
    cin >> hh >> car >> min >> car >> seg;
    cin >> hhU_dura >> car >> minU_dura >> car >> segU_dura;
    cin >> alimentos;

    cout << "Datos Ingresados:" << endl;
    cout << "Distritos: " << distrito1 << " y " << distrito2 << endl;
    cout << "Disponibilidad a partir de las " << hh << ":" <<
            min << ":" << seg << endl;
    cout << "Duracion maxima: " << hhU_dura << ":" << minU_dura << ":" <<
            segU_dura<< endl;
    
    if(alimentos == 'S') cout << "El cliente llevara alimentos" << endl;
    else cout << "El cliente no llevara alimentos" << endl;
    
    duracion = hhU_dura * 3600 + minU_dura * 60 + segU_dura;

    imprimirCaracter('=', N);
}

void imprimirCaracter(char car, int n){
    for(int i = 0; i < n; i++){
        cout.put(car);
    }
    cout << endl;
}

void leerImprimirTexto(int n){
    int cont = 0;
    int car;
    cin >> ws;
    while(true){
        car = cin.get();
        if(car == ' ' or car == '\n') {
            if(car =='\n') cin.unget();
            break;
        }
        cout.put(car);
        cont++;
    }
    cout << setw(n - cont) << " ";
}

void leerYProcesarDatosArchivo(int distrito1, int distrito2, int hh, 
        int min, int seg, int duracion, char alimentos){
    
    int distrito, sala, hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin;
    int cant_pelis, cant_opciones = 0;
    int dura_hh, dura_min, dura_seg,dura, num_distrito = 1;
    double costo;
    char comida, car;
    
    cout << setw(N/2 + 16) << "LISTA DE PELICULAS A LAS QUE PUEDE ASISTIR" <<
            endl;
    
    while(true){
        cin >> distrito;
        if(cin.eof()) break;
        if(distrito == distrito1 || distrito == distrito2){
            cant_pelis = 0;
            cout << setw(4) << " " << "DISTRITO: " << setw(6) << distrito <<
                    "  - ";
            leerImprimirTexto(20);
            cout << endl << endl;
            cout << setw(4) << " " << left << setw(8) << "SALA" <<
                    setw(30) << "PELICULA" << setw(8) << "COSTO" <<
                    setw(11) << "INICIA" << setw(11) << "TERMINA" << 
                    "DURACION" << endl;
            
            while(cin.get() != '\n'){
                cin >> sala >> costo >> comida;
                cin >> hh_ini >> car >> min_ini >> car >> seg_ini;
                cin >> hh_fin >> car >> min_fin >> car >> seg_fin;
                
                
                calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin, min_fin, 
                        seg_fin,dura,dura_hh, dura_min, dura_seg);
                if(dura <= duracion and !(comida == 'N' and alimentos == 'S')){
                    cout << left;
                    cout << setw(4) << " " << setw(8) << sala;
                    leerImprimirTexto(MAX_CAR_NOMBRE);
                    cout.precision(2);
                    cout << fixed << setw(8) << costo;
                    cout << right;
                    imprimirHora(hh_ini,min_ini, seg_ini);
                    cout << setw(3) << " ";
                    imprimirHora(hh_fin,min_fin, seg_fin);
                    cout << setw(3) << " ";
                    imprimirHora(dura_hh,dura_min, dura_seg);
                    cout << endl;
                    cant_pelis++;
                }
                else {
                    cin >> ws;
                    car = cin.get();
                    while(car != ' ' and car != '\n'){
                        car = cin.get();
                    }
                        //Obviamos el texto
                    if(car == '\n') cin.unget();
                }
                
            }
            
            imprimirCaracter('-', N);
            if(cant_pelis > 0){
                cout << "CANTIDAD DE PELICULAS: " << cant_pelis << endl <<endl;
            }
            else cout << "NO HAY PELICULAS PARA ESAS OPCIONES" << endl;
            cant_opciones += cant_pelis;
            if(num_distrito == 1) imprimirCaracter('-', N);
            num_distrito++;
        }
        else {
            while(cin.get() != '\n');
        }
    }
    
    imprimirCaracter('=', N);
    cout << "Tienes " << cant_opciones <<" opciones de peliculas con los "
            "datos que ha ingresado" << endl;
    
}

void imprimirHora(int hh,int min, int seg){
    cout << setfill('0') << setw(2) << hh << ":" << setw(2) << min <<
            ":" << setw(2) << seg;
    cout << setfill(' ');
}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin, 
        int min_fin, int seg_fin, int &dura, int &dura_hh, int &dura_min, 
        int &dura_seg){
    
    int dura_ini, dura_fin,aux;
    
    dura_ini = hh_ini * 3600 + min_ini * 60 + seg_ini;
    dura_fin = hh_fin * 3600 + min_fin * 60 + seg_fin;
    
    dura = dura_fin - dura_ini;
    
    dura_hh = dura / 3600;
    aux = dura % 3600;
    
    dura_min = aux / 60;
    
    dura_seg = aux % 60;
     
}