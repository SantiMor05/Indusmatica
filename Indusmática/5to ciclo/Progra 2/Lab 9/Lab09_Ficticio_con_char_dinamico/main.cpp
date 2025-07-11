#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "Cola.h"

using namespace std;
#include "Persona.h"
#include "Conductor.h"


int main() {
    Cola cola;
    cola.cargarMultas("infracciones.csv");
    cola.cargarConductores("Conductores.csv");
    cola.imprimirConductores("Reporte.txt");
    return 0;
}
