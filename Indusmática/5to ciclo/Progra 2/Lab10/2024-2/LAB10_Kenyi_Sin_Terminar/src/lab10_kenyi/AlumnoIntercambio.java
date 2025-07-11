/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10_kenyi;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author kenyi
 */
public class AlumnoIntercambio extends Alumno {

    private String paisOrigen;
    private final ArrayList<String> idiomas;
    private int numeroDeSemestres;

    @Override
    public double calcularPrecio(Producto produc, double tipoCambio) {
        return produc.getPrecio() * tipoCambio *(1 - 5 / 100.0);
    }

    @Override
    public String getPaisOrigen() {
        return paisOrigen;
    }

    public AlumnoIntercambio() {
        idiomas = new ArrayList<>();
    }

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        setPaisOrigen(archivo.next());
        String idioma;
        while (!archivo.hasNextInt()) {
            idioma = archivo.next();
            idiomas.add(idioma);
        }
        setNumeroDeSemestres(archivo.nextInt());
    }

    @Override
    public void imprimir() {
        super.imprimir();
        String idioma = "[";
        int i = 0;
        for (String idioma1 : idiomas) {
            if (i != 0) {
                idioma += ", ";
            }
            idioma += idioma1;
            i++;
        }
        idioma += "]";
        System.out.printf("%-20s %-35s %-20s %-50s Semestres(%d)\n", "N/A", "N/A",
                paisOrigen, idioma, numeroDeSemestres);
    }

    /**
     * @param paisOrigen the paisOrigen to set
     */
    public void setPaisOrigen(String paisOrigen) {
        this.paisOrigen = paisOrigen;
    }

    /**
     * @return the numeroDeSemestres
     */
    public int getNumeroDeSemestres() {
        return numeroDeSemestres;
    }

    /**
     * @param numeroDeSemestres the numeroDeSemestres to set
     */
    public void setNumeroDeSemestres(int numeroDeSemestres) {
        this.numeroDeSemestres = numeroDeSemestres;
    }

}
