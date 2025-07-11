//
// Created by kenyi on 25/06/2025.
//

#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include <string>
using namespace std;

class Automovil {
private:
    char *placa;

public:
    void get_placa(char * placa) const;

    void set_placa(const char *placa);

    Automovil();

    virtual ~Automovil();

    Automovil(const Automovil &);

    void operator = (const Automovil &automovil);
};


#endif //AUTOMOVIL_H
