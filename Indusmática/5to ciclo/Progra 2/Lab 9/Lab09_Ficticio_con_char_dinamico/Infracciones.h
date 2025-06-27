//
// Created by kenyi on 25/06/2025.
//

#ifndef INFRACCIONES_H
#define INFRACCIONES_H
#include "string"
#include "fstream"
using namespace std;


class Infracciones {
private:
    string placa;
    int fecha;
    int num;

public:
    string get_placa() const;

    void set_placa(const string &placa);

    int get_fecha() const;

    void set_fecha(int fecha);

    int get_num() const;

    void set_num(int num);

    void leer(ifstream & arch);

    void imprime( ofstream & out) const;
};



#endif //INFRACCIONES_H
