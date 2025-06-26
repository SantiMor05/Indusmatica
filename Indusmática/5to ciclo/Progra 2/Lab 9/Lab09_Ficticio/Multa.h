//
// Created by kenyi on 26/06/2025.
//

#ifndef MULTA_H
#define MULTA_H
#include <string>
using namespace std;

class Multa {
private:
    int numMulta;
    string descripcion;
    double multa;
    string tipo;

public:
    string get_tipo() const;

    void set_tipo(const string &tipo);

    int get_num_multa() const;

    void set_num_multa(int num_multa);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    double get_multa() const;

    void set_multa(double multa);
};


#endif //MULTA_H
