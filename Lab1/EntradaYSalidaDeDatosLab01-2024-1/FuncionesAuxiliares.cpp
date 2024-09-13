#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define N 130
#define DD 15
#define MM 01
#define AA 2024

using namespace std;

void imprimirCaracter(char car, int num) {
    for (int i = 0; i < num; i++)
        cout.put(car);
    cout << endl;
}

void imprimirCabecera() {
    cout << setw(N / 2 + 10) << "EMPRESA DE SALUD S. A." << endl;
    imprimirCaracter('=', N);
    cout << setw(55) << "REGISTRO DE CITAS DE LAS CONSULTAS MEDICAS" << endl;
    imprimirCaracter('=', N);

    cout << "Fecha" << setw(17) << "Paciente" << setw(10) << "Inicio" <<
            setw(11) << "Fin" << setw(23) << "Duracion (H:M:S)" <<
            setw(17) << "Duracion (H)" << setw(17) << "Especialidad" <<
            setw(23) << "Pago (cita+medicina)" << endl;

    imprimirCaracter('-', N);

}

void calcularEImprimirReporte() {

    int cantidad;
    int dd, mm, aa, dni;
    int hh_ini, min_ini, seg_ini, hh_fin, min_fin, seg_fin;
    int hh_duracion, min_duracion, seg_duracion;
    double tarifa_hora, monto_medicamentos, monto_total, duracion;
    char car, especialidad, medicamentos;
    
    int pacientes_con_medicina, pacientes_derma;

    double gastos_medicinas, ingresos_medicina_dermantologia;
    int no_medicina, pacientes_pediatria, pacientes_con_gastos_mayores;
    int pacientes_cardiologia;
    double ingresos;

    //Inicializamos los contadores
    cantidad = ingresos = no_medicina = pacientes_pediatria = 0;
    pacientes_con_gastos_mayores = pacientes_pediatria = 0;
    pacientes_cardiologia = 0;
    ingresos_medicina_dermantologia = gastos_medicinas = 0.0;
    pacientes_con_medicina = pacientes_derma= 0;

    while (true) {
        cin >> dd;
        if (cin.eof()) break;
        cin >> car >> mm >> car >> aa;
        cin >> dni;
        //Leemos la hora de inicio y fin
        cin >> hh_ini >> car >> min_ini >> car >> seg_ini;
        cin >> hh_fin >> car >> min_fin >> car >> seg_fin;

        cin >> tarifa_hora >> especialidad >> medicamentos;

        //Calculamos las duraciones
        calcularDuracion(hh_ini, min_ini, seg_ini, hh_fin,
                min_fin, seg_fin, duracion, hh_duracion, min_duracion,
                seg_duracion);


        monto_total = tarifa_hora * duracion;
        //Si le recetaron medicina
        if (medicamentos == 'S') {
            cin >> monto_medicamentos;
            monto_total += monto_medicamentos;
            gastos_medicinas += monto_medicamentos;
            pacientes_con_medicina++;
            //Verificar si fue a dermatologia
            if (especialidad == 'D') {
                ingresos_medicina_dermantologia += monto_medicamentos;
                pacientes_derma++;
            }
        } else {
            no_medicina++;
            if (monto_total > 350.00) {
                pacientes_con_gastos_mayores++;
            }
        }

        //Si va a pediatria
        if (especialidad == 'P') pacientes_pediatria++;
        if (especialidad == 'C') {
            if (verificarFecha(dd, mm, aa)) pacientes_cardiologia++;
        }

        //Impresion de informacion

        cout << setfill('0') << setw(2) << dd << "/" << setw(2) << mm <<
                "/" << setw(4) << aa;
        //Reiniciamos el setfill
        cout << setfill(' ') << setw(2) << " ";
        cout << setw(10) << dni << setw(3) << " ";

        imprimirHora(hh_ini, min_ini, seg_ini);
        cout << setw(5) << " ";
        imprimirHora(hh_fin, min_fin, seg_fin);
        cout << setw(8) << " ";
        imprimirHora(hh_duracion, min_duracion, seg_duracion);

        cout << setw(6) << " ";
        cout.precision(4);
        cout << fixed;
        cout << setw(12) << duracion << setw(8) << " ";

        imprimirEspecialidad(especialidad);

        cout.precision(2);
        cout << setw(13) << monto_total << endl;

        ingresos += monto_total;
        cantidad++;
    }

    calcularEImprimirEstadisticas(ingresos,cantidad, no_medicina,
             pacientes_pediatria,  pacientes_con_gastos_mayores,
             pacientes_cardiologia,  gastos_medicinas,
             ingresos_medicina_dermantologia, pacientes_derma,
            pacientes_con_medicina);


}

void calcularEImprimirEstadisticas(double ingresos, int cantidad, int no_medicina,
            int pacientes_pediatria, int pacientes_con_gastos_mayores,
            int pacientes_cardiologia, double gastos_medicinas,
            double ingresos_medicina_dermantologia, int pacientes_derma,
            int pacientes_con_medicina){
    
    
    double promedio, porcentaje;
    
    imprimirCaracter('=', N);
    cout << "Total de ingresos : " << ingresos << endl;
    imprimirCaracter('=', N);
    
    cout << setw(7) << " " << left << "ESTADISTICAS OBTENIDAS: " << endl;
    
    promedio = gastos_medicinas / pacientes_con_medicina;
    
    
    cout << setw(7) << " " << setw(100) << "Promedio de gastos por " 
            "medicina de los pacientes que le recetaron medicinas" 
            << setw(9) << promedio << endl;
    
    promedio = ingresos_medicina_dermantologia / pacientes_derma;
    
    cout << setw(7) << " " << setw(101) << "Promedio de gastos por " 
            "medicina de los pacientes que se antendieron en "  
            "dermatología" << setw(9) << promedio <<endl;
    
    porcentaje = (double) no_medicina / cantidad * 100;
    
    cout << setw(7) << " " << setw(100) << "Porcentaje de pacientes "
            "que no le recetaron medicinas" << "%" << 
           setw(9) << porcentaje << endl;
    
    porcentaje = (double)pacientes_pediatria / cantidad * 100;
    
    cout << setw(7) << " " << setw(100) << "Porcentaje de pacientes"
            " que se atendieron en pediatria" << "%" << setw(9) << 
            porcentaje << endl;
    
    cout << setw(7) << " " << setw(100) << "Cantidad de pacientes "
            "que se atendieron en cardiologia despues del "
            "15/01/2024" << setw(9) << pacientes_cardiologia <<endl;
    
    porcentaje = (double) pacientes_con_gastos_mayores / cantidad * 100;
    
    cout << setw(7) << " " << setw(100) << "Porcentaje de pacientes "
            "que no le recetaron medicinas y que gasto mas de "
            "350.00" << "%" << setw(9) << porcentaje << endl;
}


bool verificarFecha(int dd, int mm, int aa) {

    if (aa > 2024)return true;
    else if (aa == 2024 and mm > 01) return true;
    else if (aa == 2024 and mm == 01 && dd > 15) return true;

    return false;
}

void imprimirHora(int hh, int min, int seg) {
    cout << setfill('0') << setw(2) << hh << ":" << setw(2) <<
            min << ":" << setw(2) << seg;
    cout << setfill(' ');
}

void imprimirEspecialidad(char especialidad) {
    switch (especialidad) {
        case 'C':
            cout << left << setw(15) << "Cardiologia";
            break;
        case 'D':
            cout << left << setw(15) << "Dermatologia";
            break;
        case 'P':
            cout << left << setw(15) << "Pediatria";
            break;
    }

    cout << right;

}

void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, double &duracion,
        int &hh_duracion, int &min_duracion, int &seg_duracion) {

    int segundos_total_ini, segundos_total_fin;
    int duracion_segundos;

    //Pasamos las horas de inicio y fin a segundos

    segundos_total_ini = hh_ini * 3600 + min_ini * 60 + seg_ini;
    segundos_total_fin = hh_fin * 3600 + min_fin * 60 + seg_fin;

    duracion_segundos = segundos_total_fin - segundos_total_ini;

    duracion = (double) (duracion_segundos) / 3600;

    hh_duracion = duracion_segundos / 3600;
    duracion_segundos = duracion_segundos - hh_duracion * 3600;

    min_duracion = duracion_segundos / 60;
    duracion_segundos = duracion_segundos - min_duracion * 60;

    seg_duracion = duracion_segundos;
}