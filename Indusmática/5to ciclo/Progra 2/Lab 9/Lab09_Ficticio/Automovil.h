//
// Created by kenyi on 25/06/2025.
//

#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include <string>
using namespace std;

class Automovil {
private:
    string placa;
public:
    string get_placa() const;

    void set_placa(const string &placa);
};


#endif //AUTOMOVIL_H
