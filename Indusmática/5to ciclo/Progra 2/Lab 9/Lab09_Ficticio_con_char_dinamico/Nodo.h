//
// Created by kenyi on 25/06/2025.
//

#ifndef NODO_H
#define NODO_H
#include "Conductor.h"


class Nodo {
private:
    Nodo *siguiente;
    Conductor datoConductor;

public:
    Nodo();

    friend class Cola;
};


#endif //NODO_H
