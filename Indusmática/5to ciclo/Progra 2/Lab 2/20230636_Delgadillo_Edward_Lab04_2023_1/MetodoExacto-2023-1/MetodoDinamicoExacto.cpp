/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "MetodoDinamicoExacto.h"

using namespace std;
#define LINEA 120

void lecturaAlumnos(const char*nombArch,int*&alumnoCodigo,char**&alumnoNombre,
        char*&alumnoModalidad,int*&alumnoPorcentaje,int*&alumnoEscala){
    
    ifstream arch(nombArch,ios::in);
    apertura(arch.is_open(),nombArch);
    
    int bufCod[100]{},bufEsca[100]{},nd=0;
    char *bufNomb[100]{},bufMod[100]{};
    int bufPorcen[100]{};
    
    while(true){
        arch>>bufCod[nd];
        if(arch.eof())break;
        arch.get();
        bufNomb[nd]=leeCadena(arch,',');
        completarBufs(arch,bufMod[nd],bufPorcen[nd],bufEsca[nd]);
        nd++;
    }
    nd++;
    pasarInfo(alumnoCodigo,alumnoNombre,alumnoModalidad,alumnoPorcentaje,
            alumnoEscala,bufCod,bufNomb,bufMod,bufPorcen,bufEsca,nd);
}

void apertura(bool abierto,const char*nombArch){
    
    if(not abierto){
        cout<<"Error en "<<nombArch; exit(1);
    }
}

char*leeCadena(ifstream &arch,char deli){
    
    char aux[100],*p;
    arch.getline(aux,100,deli);
    if(arch.eof())return nullptr;
    p=new char[strlen(aux)+1];
    strcpy(p,aux);
    return p; 
}
    //    8072,RIVERA MONTERO GLORIA OFELIA,V,3
//    8318,TOKESHI GONZALES MARTIN,S,50,1
//    5802,MINAYA AMEZQUITA RHONY JAIME,5

void completarBufs(ifstream &arch,char &modalidad,int &porcentaje,
        int &escala){
    
    char aux,c;
    porcentaje=100;
    arch>>aux;
    if(aux=='V' or aux=='S'){
        arch.get();
        modalidad=aux;
        if(aux=='S'){
            arch>>porcentaje>>c;
        }
        arch>>escala;
    }
    else{
        modalidad='P';
        escala=(int)aux-48;
    }
}

void pasarInfo(int*&alumnoCodigo,char**&alumnoNombre,
        char*&alumnoModalidad,int*&alumnoPorcentaje,int*&alumnoEscala,
        int*bufCod,char**bufNomb,char*bufMod,int*bufPorcen,int*bufEsca,
        int nd){
    
    alumnoCodigo=new int[nd]{};
    alumnoNombre=new char*[nd]{};
    alumnoModalidad=new char[nd]{};
    alumnoPorcentaje=new int[nd]{};
    alumnoEscala=new int[nd]{};
    
    for (int i = 0; i < nd; i++) {
        alumnoCodigo[i]=bufCod[i];
        alumnoNombre[i]=bufNomb[i];
        alumnoModalidad[i]=bufMod[i];
        alumnoPorcentaje[i]=bufPorcen[i];
        alumnoEscala[i]=bufEsca[i];
    }
}
        
void pruebaLecturaAlumnos(const char*nombArch,
        int*alumnoCodigo,char**alumnoNombre,
        char*alumnoModalidad,int*alumnoPorcentaje,int*alumnoEscala){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);
    arch.precision(2);
    arch<<fixed<<"Codigo  "<<left<<setw(60)<<"Nombre"<<"  Modalidad  "<<
            "Porcentaje  "<<"Escala"<<endl;
    for (int i = 0; alumnoCodigo[i]; i++) {
        arch<<right<<setw(6)<<alumnoCodigo[i]<<"  "<<left<<setw(60)<<
                alumnoNombre[i]<<"  "<<right<<setw(9)<<alumnoModalidad[i]<<"  "<<
                setw(10)<<alumnoPorcentaje[i]<<"  "<<setw(6)<<alumnoEscala[i]<<
                endl;
    }

}

void lecturaCursos(const char*nombArch,int*alumnoCodigo,int*alumnoEscala,
        char**&cursoNombre,double*&cursoCredito,int**&cursoAlumnos){
    
    ifstream arch(nombArch,ios::in);
    apertura(arch.is_open(),nombArch);
    
    char*bufCurNomb[100]{},nombCurso[80];
    double bufCurCred[100]{},credito;
    int *bufCurAl[100]{},nd=0,posAl,posCur,codigo,cantAlenCur[100]{},escala;
//    8072,Aplicaciones de las Ciencias de la Computacion,3.5
    while(true){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        posAl=buscarCodigo(alumnoCodigo,codigo);
        if(posAl!=-1){
            arch.getline(nombCurso,80,',');
            arch>>credito;
            posCur=buscarCurso(bufCurNomb,nombCurso);
            escala=alumnoEscala[posAl];
            if(posCur!=-1){
                actualizarCurAls(bufCurAl[posCur],codigo,escala,
                        cantAlenCur[posCur]++);
            }
            else{
                crearCurso(nombCurso,credito,bufCurNomb[nd],bufCurCred[nd],
                        bufCurAl[nd]);
                actualizarCurAls(bufCurAl[nd],codigo,escala,
                        cantAlenCur[nd]++);
                nd++;
            } 
        }
        else while(arch.get()!='\n');
    }
    nd++;
    hacerExacto(bufCurAl,cantAlenCur);
    pasarInfo(cursoNombre,cursoCredito,cursoAlumnos,
            bufCurNomb,bufCurCred,bufCurAl,nd);
}

void hacerExacto(int**bufCurAl,int*cantAlenCur){
    
    for (int i = 0; bufCurAl[i]; i++) {
        reducirEspacio(bufCurAl[i],cantAlenCur[i]);
    }
}

void reducirEspacio(int*&alumnos,int cant){
    
    int*aux=new int[cant*2+1]{};
    for (int i = 0; i < cant*2; i++) {
        aux[i]=alumnos[i];
    }
    delete alumnos;
    alumnos=aux;
}


void pasarInfo(char**&cursoNombre,double*&cursoCredito,int**&cursoAlumnos,
            char**bufCurNomb,double*bufCurCred,int**bufCurAl,int nd){
    
    cursoNombre=new char*[nd]{};
    cursoCredito=new double[nd]{};
    cursoAlumnos=new int*[nd]{};
    for (int i = 0; i < nd; i++) {
        cursoNombre[i]=bufCurNomb[i];
        cursoCredito[i]=bufCurCred[i];
        cursoAlumnos[i]=bufCurAl[i];
    }
}

void actualizarCurAls(int*alumnosDeCurso,int codigo,int escala,int cantAl){
    
    int pos=cantAl*2;
    alumnosDeCurso[pos]=codigo;
    alumnosDeCurso[pos+1]=escala;
}

int buscarCodigo(int*alumnoCodigo,int codigo){
    
    for (int i = 0; alumnoCodigo[i]; i++) {
        if(codigo==alumnoCodigo[i])return i;
    }
    return -1;
}

int buscarCurso(char**bufCurNomb,const char*nombCurso){
    
    for (int i = 0; bufCurNomb[i]; i++) {
        if(not strcmp(bufCurNomb[i],nombCurso))return i;
    }
    return -1;
}

void crearCurso(const char*nombreRef,double creditoRef,
        char*&nombre,double &credito,int*&alumnosDeCurso){
    
    nombre=new char[strlen(nombreRef)+1];
    strcpy(nombre,nombreRef);
    credito=creditoRef;
    alumnosDeCurso=new int[160]{};    
}
    
void pruebaDeLecturaCursos(const char*nombArch,
        char**cursoNombre,double*cursoCredito,int**cursoAlumnos){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);   
    arch.precision(2);
    
    for (int i = 0; cursoNombre[i]; i++) {
        imprimirCurso(arch,cursoNombre[i],cursoCredito[i],cursoAlumnos[i]);
    }
}

void imprimirCurso(ofstream &arch,char*nombre,double credito,int*alumnos){
    
    arch<<fixed<<left<<setw(60)<<"Nombre"<<"  "<<"Credito  "<<endl;
    arch<<setw(60)<<nombre<<"  "<<right<<setw(7)<<credito<<endl;
    arch<<"  Alumnos del curso:"<<endl;
    arch<<"    Codigo"<<"  Escala"<<endl;
    for (int i = 0; alumnos[i]; i+=2) {
        imprimirAlumno(arch,alumnos[i],alumnos[i+1]);
    }
}

void imprimirAlumno(ofstream &arch,int codigo,int escala){
    
    arch<<"    "<<right<<setw(6)<<codigo<<"  "<<setw(6)<<escala<<endl;
}

void reporteDeRecaudacionPorModalidad(const char*nombArch,
        int*alumnoCodigo,char**alumnoNombre,
        char*alumnoModalidad,int*alumnoPorcentaje,
        char**cursoNombre,double*cursoCredito,int**cursoAlumnos){
    
    ofstream arch(nombArch,ios::out);
    apertura(arch.is_open(),nombArch);
    arch.precision(2);
    arch<<fixed<<setw(LINEA/2 +5)<<"ENTIDAD EDUCATIVA LP1"<<endl;
    arch<<fixed<<setw(LINEA/2 +3)<<"LISTADOS DE CLASE"<<endl;
    double totalPrese=0,totalSemi=0,totalVirtu=0;
    for (int i = 0; cursoNombre[i]; i++) {
        imprimeLinea(arch,LINEA,'=');
        arch<<setfill('0')<<right<<setw(2)<<i+1<<setfill(' ')<<
                ")  Curso: "<<left<<setw(60)
                <<cursoNombre[i]<<"  Creditos: "<<right<<setw(6)<<
                cursoCredito[i]<<endl;
        imprimeLinea(arch,LINEA,'-');
        arch<<"ALUMNOS Matriculados"<<endl;
        imprimeLinea(arch,LINEA,'-');
        imprimirCabecera(arch);
        imprimeLinea(arch,LINEA,'-');
        imprimirInfoCurso(arch,cursoAlumnos[i],cursoCredito[i],
                alumnoCodigo,alumnoNombre,alumnoModalidad,alumnoPorcentaje,
                totalPrese,totalSemi,totalVirtu);
    }
    imprimeLinea(arch,LINEA,'=');
    arch<<"RECAUDACION TOTAL POR MODALIDAD DE ESTUDIO: "<<totalPrese<<"  "<<
            totalSemi<<"  "<<totalVirtu<<endl;
    imprimeLinea(arch,LINEA,'-');
    arch<<"TOTAL GENERAL"<<totalPrese+totalSemi+totalVirtu<<endl;
}

void imprimirCabecera(ofstream &arch){
    
    arch<<right<<setw(108)<<"PAGOS"<<endl;
    arch<<"   CODIGO  "<<left<<setw(60)<<"NOMBRE"<<"  ESCALA  "<<
            "PRESENCIAL  "<<"SEMI PRESENCIAL  "<<"VIRTUAL"<<endl;
}

void imprimeLinea(ofstream &arch,int n,char c){
    
    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}
     
void imprimirInfoCurso(ofstream &arch,int*alumnos,double creditos,
        int*alumnoCodigo,char**alumnoNombre,char*alumnoModalidad,
        int*alumnoPorcentaje,
        double &totalPrese,double &totalSemi,double &totalVirtu){
    
//      arch<<right<<setw(108)<<"PAGOS"<<endl;
//    arch<<"   CODIGO  "<<left<<setw(60)<<"NOMBRE"<<"  ESCALA  "<<
//            "PRESENCIAL  "<<"SEMI PRESENCIAL  "<<"VIRTUAL"<<endl;
    
    int codigo,escala,pos,j=0;
    double valorEscala,gasto,porcentaje,parcialPre=0,parcialSemi=0,
            parcialVirtu=0;
    for (int i = 0; alumnos[i]; i+=2){
        codigo=alumnos[i];
        escala=alumnos[i+1];
        valorEscala=hallarValor(escala);
        pos=buscarCodigo(alumnoCodigo,codigo);
        if(pos!=-1){
            j++;
            porcentaje=alumnoPorcentaje[pos];
            arch<<setfill('0')<<right<<setw(2)<<j<<")"<<setfill(' ')<<
                setw(6)<<alumnoCodigo[pos]<<"  "<<left<<setw(60)<<
                alumnoNombre[pos]<<"  "<<right<<setw(6)<<escala<<"  ";
            gasto=valorEscala*creditos*((double)porcentaje/100);
            
            if(alumnoModalidad[pos]=='P'){
                parcialPre+=gasto;
                imprimirGasto(arch,gasto,10);
            }
                
            if(alumnoModalidad[pos]=='S'){
                parcialSemi+=gasto;
                imprimirGasto(arch,gasto,27);
            }                
            if(alumnoModalidad[pos]=='V'){
                parcialVirtu+=gasto;
                imprimirGasto(arch,gasto,36);
            } 
        }
    }
    totalPrese+=parcialPre;
    totalSemi+=parcialSemi;
    totalVirtu+=parcialVirtu;
    imprimeLinea(arch,LINEA,'=');
    arch<<"RECAUDACION POR MODALIDAD DE ESTUDIO: "<<parcialPre<<"  "<<
            parcialSemi<<"  "<<parcialVirtu<<endl;
    imprimeLinea(arch,LINEA,'-');
    arch<<"TOTAL RECAUDADO: "<<parcialPre+parcialSemi+parcialVirtu<<endl;
}

double hallarValor(int escala){
    
    double valor;
    switch(escala){
        case 1:valor=282.3;break;
        case 2:valor=362;break;
        case 3:valor=454.2;break;
        case 4:valor=556.7;break;
        case 5:valor=666.9;break;
        default: valor=-1;
    }
    return valor;
}

void imprimirGasto(ofstream &arch,double gasto,int n){
    
    arch<<right<<setw(n)<<gasto<<endl;
}