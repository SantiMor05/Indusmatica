/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "funcionesAux.h"
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#define MAX_LINEA 150

//Lectura de Libros
void lecturaDeLibros(const char*nombreArch,char***&libros,int**&stock){
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }

    //1.Definimos Contadores y punteros null;
    char **ptLibro;
    int numDat=0, cap=0,*ptStock;
    libros=nullptr;
    stock= nullptr;
    //2.Lectura Arch
    while (true) {
        //lectura
        ptLibro = lecturaLibro(archLee);
        if(archLee.eof()) break;
        ptStock = lecturaStock(archLee);
        //Veriifcamos el incremento;
        if(cap==numDat) aumentarEspacios(libros,stock,numDat,cap);
        
        //como hay espacio asignamos restando 1 pq en numdat tamos contando al 0
        libros[numDat-1]= ptLibro;
        stock[numDat-1]= ptStock;
        numDat++;
    }

}

void aumentarEspacios(char***&libros,int**&stock,int&numDat,int&cap){
    char***auxLibros;
    int**aucStock;
    cap+=INCREMENTO;
    if(libros==nullptr){
        //Para meter datos inicializamos por primera vez
        libros= new char**[cap]{};
        stock= new int*[cap]{};
        //El nullpt/0 debe ser contado como un dato mas
        numDat=1;
    }else{
        auxLibros= new char**[cap]{};
        aucStock= new int*[cap]{};
        // pasamos los datos al nuevo arreglo
        for (int i = 0; libros[i]; i++) {
            auxLibros[i]=libros[i];
            aucStock[i]= stock[i];
        }
        // limpiamos los datos para signar lo nuevo
        delete libros;
        delete stock;
        libros= auxLibros;
        stock= aucStock;

    }
    
}

////IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
int* lecturaStock(ifstream &archLee){
    int* dupla,stock;
    double precio;
    char c;
    archLee>>stock>>c>>precio;
    archLee.get();
    //nicializamos
    dupla= new int[2]{};
    dupla[0]= stock;
    return dupla;
}


//IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
char** lecturaLibro(ifstream &archLee){
    char** triplete,*ptLibro;
    
    ptLibro= lecturaExacta(archLee,',');
    if(archLee.eof()) return nullptr;
    
    // Como verificamos q se pueda leer inicializamos
    triplete= new char*[3]{};
    triplete[0]= ptLibro;
    triplete[1]= lecturaExacta(archLee,',');
    triplete[2]= lecturaExacta(archLee,',');
    
    return triplete;
}

char* lecturaExacta(ifstream &archLee,char delim){
    char* ptCad,buffer[200];
    int cantCad;
    archLee.getline(buffer,200,delim);
    if(archLee.eof()) return nullptr;
    cantCad = strlen(buffer);
    ptCad = new char[cantCad+1];
    strcpy(ptCad,buffer);
    return ptCad;
}

//Prueba de Lectura
void pruebaDeLecturaDeLibros(const char*nombreArch,char***libros,int**stock){
    ofstream archReport(nombreArch,ios::out);
    if (not archReport.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    char **libro;
    int* auxStock;
    archReport<<fixed<<setprecision(2);
    archReport<<left<<setw(15)<<"CODIGO"<<setw(60)<<"NOMBRE"<<setw(30)<<"AUTOR"
            <<right<<setw(15)<<"STOCK"<<setw(15)<<"CANT. NO ATEND"<<endl;
    for (int i = 0; libros[i]; i++) {
        libro= libros[i];
        auxStock= stock[i];
        archReport<<left<<setw(15)<<libro[0]<<setw(60)<<libro[1]<<setw(30)<<
                libro[2]<<right<<setw(15)<<auxStock[0]<<setw(15)<<auxStock[1]<<endl;
    }

    
    
}

//Lectura Pedidos
//000029,49516360   NEW1762    WMN3648  MLC7198
//000107,17750908
void atencionPedidos(const char*nombreArch,char***libros,int**stock,
        int**&pedidosClientes,char***&pedidosLibros,bool**&pedidosAtendidos){
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    // inicializacion contadores y le damos null a los punterros,
    int numDat=0,capClien=0,numPed,dniClien,posClien,ndPed[200]{},
            capPed[200]{},ndLib[200]{},capLib[200]{},capLibros=0;
    char c;
    pedidosClientes= nullptr;
    pedidosAtendidos= nullptr;
    pedidosLibros= nullptr;
    
    while (true) {
        archLee>>numPed;
        if(archLee.eof()) break;
        archLee>>c>>dniClien;
        // inicializamos para que haya algo q buscar;
        if(numDat==capClien) aumentarCapClien(pedidosClientes,numDat,capClien);
        
        // Buscamos Cliente
        posClien= buscamosCliente(dniClien,pedidosClientes);
        if(posClien!=NO_ENCONTRADO){
            //modificamos noma
            modificarCliente(pedidosClientes[posClien],ndPed[posClien],
                    capPed[posClien],numPed);
            
        }else{
            //agregamos
            agregarCliente(pedidosClientes[numDat-1],ndPed[numDat-1],
                    capPed[numDat-1],dniClien,numPed);
            //se aumanta pq incremento un cleinte
            numDat++;
        }
        //Primero creamos el espacio de memoria
        if(numPed>=capLibros) aumentarCapLib(pedidosAtendidos,
                pedidosLibros,capLibros,numPed);
        
        // Como ahora si existre un espacio de memoria mandamos ;
        
        asignacionLibros(archLee,pedidosAtendidos[numPed-1],
                pedidosLibros[numPed-1],ndLib[numPed-1],capLib[numPed-1],
                libros,stock);
        
        
    }

    
    
    
}

//000029,49516360   NEW1762    WMN3648  MLC7198
//000107,17750908
void asignacionLibros(ifstream &archLee,bool*& atendidos,
                char**& cadLibros,int& ndLib,int& capLib,
                char ***libros,int**stock){
    
    char cod[8],c,*ptCodLib;
    int posLib,*auxStock;

    
    
    while (true) {
        c= archLee.get();
        
        if(c=='\n') break; 
        archLee>>cod;
        ptCodLib= new char[8]{};
        strcpy(ptCodLib,cod);
        
        // ahora  como si existe el esacio tenemos que inicializarlos y chambear
        if(ndLib==capLib)
        asignamos(atendidos,cadLibros,ndLib,capLib,ptCodLib);
        
        
        posLib = buscamosLibro(libros,ptCodLib);
        //Podemos agregar el libro al arreglo
        if(posLib!=0){
            //Metemos datos;
            cadLibros[ndLib]= ptCodLib;
            auxStock= stock[posLib];
            if(auxStock[0]>0){
                atendidos[ndLib]=true;
                auxStock[0]--;
            }else{
                atendidos[ndLib]=false;
                auxStock[1]++;
            }
            
            ndLib++;
        }
        
    }

    
    
}

int buscamosLibro(char ***libros,char*ptCodLib){
    char** libro,cmp;
    
    for (int i = 0; libros[i]; i++) {
        libro= libros[i];
        cmp= strcmp(libro[0],ptCodLib);
        if(cmp==0) return i;
    }
    return NO_ENCONTRADO;
    
}
void asignamos(bool*& atendidos,char**& libros,int& ndLib,
                int& capLib,char* ptCodLib){
    bool* auxAtendidos;
    char** auxLibros;
    
    capLib+= INCREMENTO;
    
    //como ya esta inicialiaza ta en null
    if(libros==nullptr){
        atendidos= new bool[capLib]{};
        libros= new char*[capLib]{};
    }else{
        auxAtendidos= new bool[capLib]{};
        auxLibros= new char*[capLib]{};
        for (int i = 0; libros[i]; i++) {
            auxLibros[i]= libros[i];
            auxAtendidos[i]= atendidos[i];
        }
        delete atendidos;
        delete libros;
        libros= auxLibros;
        atendidos= auxAtendidos;
    }
    
    
    
}

void aumentarCapLib(bool**&pedidosAtendidos,char***&pedidosLibros,
        int&capLibros,int numPed){
    bool **auxAtendidos;
    char*** auxLibros;
    
    int capAnterior = capLibros;
    capLibros=(numPed-1)+INCREMENTO;
    if(pedidosLibros==nullptr){
        pedidosLibros= new char**[capLibros]{};
        pedidosAtendidos= new bool*[capLibros]{};
        // como no hay un numdat q guie el arreglo no aumentamos nd
    }else{
        auxLibros= new char**[capLibros]{};
        auxAtendidos= new bool*[capLibros]{};
        for (int i = 0; i < capAnterior; i++) {
            auxAtendidos[i]= pedidosAtendidos[i];
            auxLibros[i]= pedidosLibros[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        pedidosAtendidos= auxAtendidos;
        pedidosLibros= auxLibros;
    }
    
}
void modificarCliente(int*& cliente,int &ndPed,int& capPed,int numPed){
    int* auxCliente;
    
    // aca tenemos que verificar si el ndped es igual a la cap;
    
    if(ndPed==capPed){
        capPed+=INCREMENTO;
        auxCliente= new int[capPed]{};
        for (int i = 0; cliente[i]; i++) {
            auxCliente[i]=cliente[i];
        }
        delete cliente;
        cliente= auxCliente;
    }
    //asignamos pero recuerda que hay q quitarle el 0
    cliente[ndPed-1]= numPed;
    ndPed++;

}

void agregarCliente(int*& cliente,int &ndPed,
                    int& capPed,int dniClien,int numPed){
    // Como solo una vez entrará aca es como el caso de if(cliente==nullptr)
    capPed+=INCREMENTO;
    ndPed=2;
    cliente= new int[capPed]{};
    
    //guardamos
    cliente[0]= dniClien;
    cliente[1]++;
    cliente[ndPed]=numPed;
    ndPed++;
    //uno mas para tmb contar al 0 como fin
    ndPed++;
                    
}


int buscamosCliente(int dniClien,int**pedidosClientes){
    
    int*cliente;

    for (int i = 0; pedidosClientes[i] ; i++) {
        cliente= pedidosClientes[i];
        if(cliente[0]==dniClien) return i;
    }
    
    return NO_ENCONTRADO;

       
    
    
}

void aumentarCapClien(int **&pedidosClientes,int &numDat, int&capClien){
    int** auxClientes;
    
    capClien+= INCREMENTO;
    
    if(pedidosClientes==nullptr){
        // inicializamos
        pedidosClientes= new int*[capClien]{};
        //contamos al 0/null
        numDat=1;
    }else{
        auxClientes= new int*[capClien]{};
        for (int i = 0; pedidosClientes[i]; i++) {
            auxClientes[i]=pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes= auxClientes;
    }
    
}

// Ordenar
void ordenarPedidosClientes(int** pedidosClientes){
    //wasa
    
//    qSorft
    
    
    
    
}

//Reporte final
void reporteDeEntregaDePedidos(const char *nombreArch, int** pedidosClientes,
        char*** pedidosLibros, bool** pedidosAtendidos) {
    ofstream archReport(nombreArch, ios::out);
    if (not archReport.is_open()) {
        cout << "ERROR: No se ha podido abrir el archivo " << nombreArch << endl;
        exit(1);
    }
    archReport << fixed << setprecision(2);

    archReport << setw((MAX_LINEA + 30) / 2) << "REPORTE DE ATENCION CLIENTES" << endl;
    impresionLinea(archReport, MAX_LINEA, '=');

    int*dniCliente;
    for (int i = 0; pedidosClientes[i]; i++) {
        //OBTENEMOS DNI;
        dniCliente = pedidosClientes[i];
        impresionLinea(archReport, MAX_LINEA, '=');
        archReport << left << "CLIENTE:" << right << setw(15) << dniCliente[0] << endl;
        impresionLinea(archReport, MAX_LINEA, '=');

        impresionPedidos(archReport, pedidosClientes[i], pedidosAtendidos, pedidosLibros);



    }

}

void impresionPedidos(ofstream &archReport, int* pedidosCliente, bool** pedidosAtendidos,
        char***pedidosLibros) {
    char** codigosLib;
    bool* libAtendidos;
    for (int i = 2; pedidosCliente[i]; i++) {
        //encabezado
        if (i != 2) impresionLinea(archReport, MAX_LINEA, '-');
        archReport << right << setw(30) << "Pedido No" << setw(30) << "Cod. de Libro" <<
                setw(30) << "Observación" << endl;
        impresionLinea(archReport, MAX_LINEA, '-');
        archReport << right << setw(30) << pedidosCliente[i];

        codigosLib = pedidosLibros[pedidosCliente[i] - 1];
        libAtendidos = pedidosAtendidos[pedidosCliente[i] - 1];
        //buscamos el numero del pedido en pedidosLibros para imprimir lso libros;

        if(codigosLib) {
            for (int k = 0; codigosLib[k]; k++) {
                if (k != 0) archReport << setw(30 + 30 - 6 - (6 * 4)) << " ";
                    archReport << setw(30) << codigosLib[k];

                    if (libAtendidos[k]) archReport << setw(30) << "ATENDIDO";
                    else archReport << setw(30) << "NO ATENDIDO";

                archReport<< endl;
            }
        }else archReport<<endl;  

    }

}



void impresionLinea(ofstream &archReport, int cant, char car) {
    for (int i = 0; i < cant; i++) {
        archReport << car;
    }
    archReport << endl;
}