#include <iostream>
#include<iomanip>

//Fabricio Flores 20230360

using namespace std;


int numSolu = -1;
int soluciones[100][3]{};

void agregarSoluArreglo(int x, int y, int z) {
    soluciones[numSolu][0] = x;
    soluciones[numSolu][1] = y;
    soluciones[numSolu][2] = z;
}

int noRepetido(int x, int y, int z, int cont) {

    if (cont >= numSolu)return 1;

    if (x == soluciones[cont][0] and y == soluciones[cont][1] and z == soluciones[cont][2]) return 0;
    return noRepetido(x, y, z, cont + 1);

}

int resolverContrasenha(int x, int y, int z, int factor) {
    if (x + y + z > factor or (x > 9 or y > 9 or z > 9) or (x == 0 or y == 0 or z == 0))
        return 0;

    if (x + y + z == factor and x != y and y != z and z != x) {
        numSolu++;
        if (noRepetido(x, y, z, 0)) {
            cout << x << ' ' << y << ' ' << z << endl;
            agregarSoluArreglo(x, y, z);
        }

        return 1;
    }

    int nx = x + 1;
    int ny = y + 1;
    int nz = z + 1;

    resolverContrasenha(nx, y, z, factor);
    resolverContrasenha(x, ny, z, factor);
    resolverContrasenha(x, y, nz, factor);
    return 0;
}

int main() {
    int factor = 8;

    resolverContrasenha(1, 1, 1, factor);


    return 0;
}
