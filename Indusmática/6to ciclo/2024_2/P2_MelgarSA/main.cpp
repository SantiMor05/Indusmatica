#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Producto {
    string nombre;
    int requetimiento;
    int longit;
    int altura;
};

struct Lamina {
    int longit;
    int altura;
};

struct Respuesta {
    int cantidad;
    double porcent;
};

bool operator<(const Producto &p1, const Producto &p2) {
    if (max(p1.longit, p1.altura)== max(p2.longit, p2.altura)) {
        return p1.longit*p1.altura > p2.longit*p2.altura;
    }else {
        return max(p1.longit, p1.altura) > max(p2.longit, p2.altura);
    }

}

Respuesta calcularLaminas(Producto* prod, Lamina lamin, int n) {
    Respuesta respuesta{0, 0.0};
    sort(prod, prod + n);
    int demanda = 0;
    for (int i = 0; i < n; ++i) demanda += prod[i].requetimiento;
    if (demanda == 0) return respuesta; // 0 láminas, 0%
    respuesta.cantidad = 1;
    int desperdicio = 0;

    int altura_restante = lamin.altura;
    int ancho_libre     = lamin.longit;
    int altura_lamina   = 0;

    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < prod[i].requetimiento) {
            if (altura_lamina == 0) altura_lamina = prod[i].altura;
            if (prod[i].longit <= ancho_libre && prod[i].altura <= altura_lamina) {
                ancho_libre -= prod[i].longit;
                ++j;
            }else if (altura_restante >= altura_lamina + prod[i].altura) {
                desperdicio += ancho_libre * altura_lamina;
                altura_restante -= altura_lamina;
                ancho_libre = lamin.longit;
                altura_lamina = 0;
            }else{
                if (altura_lamina > 0) {
                    desperdicio += ancho_libre * altura_lamina;
                    altura_restante -= altura_lamina;
                }
                if (altura_restante<0) altura_restante=0;
                desperdicio += lamin.longit * altura_restante;

                respuesta.cantidad++;
                altura_restante = lamin.altura;
                ancho_libre     = lamin.longit;
                altura_lamina   = 0;
            }
        }
    }

    if (respuesta.cantidad > 0) {
        if (altura_lamina > 0) {
            desperdicio += ancho_libre * altura_lamina;
            altura_restante -= altura_lamina;
        }
        desperdicio += lamin.longit * max(0, altura_restante);
    }

    long long area_total = respuesta.cantidad * lamin.longit * lamin.altura;
    respuesta.porcent = (area_total > 0) ? (100.0 * desperdicio / area_total) : 0.0;

    return respuesta;
}

int main() {
    Lamina lamina{50,50};
    Producto productos[]{
        {"Mentolato",5,2,3},
        {"Crema Nivea",10,9,3},
        {"Atun",15,14,7},
        {"Conserva",20,15,20},
        {"Aceite Industrial",20,22,18},
    };
    Respuesta respuesta;
    int n = sizeof(productos)/sizeof(productos[0]);
    respuesta=calcularLaminas(productos,lamina,n);

    cout<<respuesta.cantidad<<endl<<respuesta.porcent;
    return 0;
}