#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "FuncionesAuxiliares.h"

using namespace std;

void operator !(struct Vector &v){ //Inicializa un vector
    for(int i = 0; i < 100; i++)
        v.arr[i] = 0;
    v.numDat = 0;
}


//void operator +(struct Vector &v, int n){//Agregar un elemento
//    v.arr[v.numDat] = n;
//    v.numDat++;
//}

//Agregar uno o varios elementos
// v + 5 + 7 + 6 + 10
struct Vector &operator + (struct Vector &v, int n){ 
    
    v.arr[v.numDat] = n;
    v.numDat++;
    return v;
}

void operator += (struct Vector &v1, const struct Vector &v2){
    
    for(int i = v1.numDat, k = 0; k < v2.numDat; k++, i++){
        v1.arr[i] = v2.arr[k];
        v1.numDat++;
    }
    
}

struct Vector operator +(const struct Vector &v1, const struct Vector &v2){
    
    struct Vector v3;
    
    !v3;
    v3 += v1;
    v3 += v2;
    
    return v3;
} 

//Para cout << vector1;
//void operator <<(ostream &out, const struct Vector &v){
//    for(int i = 0; i < v.numDat; i++)
//        out << v.arr[i] << endl;
//    out << "Numero de datos: " << v.numDat << endl << endl; 
//}


//Para cout << vector1 << vector2 << ...;
ostream & operator <<(ostream &out, const struct Vector &v){
    for(int i = 0; i < v.numDat; i++)
        out << v.arr[i] << endl;
    out << "Numero de datos: " << v.numDat << endl << endl; 
    return out;
}


//Para cin >> vector1 >> vector2 >> ...;
istream & operator >>(istream &in, struct Vector &v){
    int n = 0;
    while(1){
        in >> v.arr[n];
        if(in.eof())break;
        n++;
    }
    v.numDat = n;
    in.clear();
    return in;
}

//Para cin >> vector1;
//void operator >>(istream &in, struct Vector &v){
//    int n = 0;
//    while(1){
//        in >> v.arr[n];
//        if(in.eof())break;
//        n++;
//    }
//    v.numDat = n;
//    in.clear();
//}