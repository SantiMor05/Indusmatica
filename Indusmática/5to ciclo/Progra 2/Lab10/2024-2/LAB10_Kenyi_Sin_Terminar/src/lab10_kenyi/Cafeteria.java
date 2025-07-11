/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10_kenyi;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author kenyi
 */
public class Cafeteria {

    private final ArrayList<Pais> paises;
    private final ArrayList<Alumno> participantes;
    private Menu menu;
    private final int MAX_CAR = 200;
    private final Scanner archivo;

    public Cafeteria(String nombArch) throws FileNotFoundException {
        participantes = new ArrayList<>();
        paises = new ArrayList<>();
        File file = new File(nombArch);
        archivo = new Scanner(file);
        menu = new Menu();
    }

    public void cargarPaises() {
        Pais pais;
        while (!archivo.next().equals("FIN")) {
            pais = new Pais();
            pais.cargar(archivo);
            paises.add(pais);
        }
    }

    public void imprimirPaises() {
        System.out.printf("NOMBRE %15s  %15s %10s\n", "Moneda", "Tipo de cambio",
                "Idioma");
        imprimeLinea('=', 120);
        System.out.println();
        for (Pais pais : paises) {
            pais.imprimir();
        }
        System.out.println("\n");
    }

    private void imprimeLinea(char car, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(car);
        }
    }

    public void cargarParticipantes() {
        Alumno alumno;
        String tipo;
        while (true) {
            tipo = archivo.next();
            if (tipo.equals("R")) {
                alumno = new AlumnoRegular();
            } else if (tipo.equals("I")) {
                alumno = new AlumnoIntercambio();
            } else {
                break;
            }
            alumno.cargar(archivo);
            participantes.add(alumno);
        }
    }

    public void imprimirParticipantes() {
        imprimeLinea('=', 50);
        System.out.print(" LISTADO DE PARTICIPANTES ");
        imprimeLinea('=', 50);
        System.out.println();

        imprimeLinea('-', MAX_CAR);
        System.out.printf("\nCODIGO %12s %60s %25s %25s %26s %48s\n", "NOMBRE", "FACULTAD",
                "ESPECIALIDAD", "PAIS", "IDIOMAS", "DURACION");
        imprimeLinea('-', MAX_CAR);
        System.out.println();
        for (Alumno participante : participantes) {
            participante.imprimir();
        }

        System.out.println("\n");
    }

    public void cargarMenu() {
        menu.cargarProductos(archivo);

    }

    public void imprimirMenuPredeterminado() {
        menu.imprimirMenu();
    }

    public void imprimirMenusPersonalizados() {
        for (Alumno a : participantes) {
            if (!a.getPaisOrigen().equals("Peru")) {
                menu.imprimirMenuPersonalizado(a, buscarPais(a.getPaisOrigen()));
            }
        }
    }

    public Pais buscarPais(String pais) {
        for (Pais p : paises) {
            if (p.getNombre().equals(pais)) {
                return p;
            }
        }
        return null;
    }

}
