/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10_2024_2.santiago;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author santi
 */
public class AlumnoIntercambio extends Alumno{
    
    private String paisOrigen;
    private final ArrayList<String> idiomas;
    private int numeroDeSemestres;

    
    public AlumnoIntercambio(){
        idiomas = new ArrayList<>();
    }
    
    
    /**
     * @return the paisOrigen
     */
    @Override
    public String getPaisOrigen() {
        return paisOrigen;
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

    @Override
    public void cargar(Scanner arch) {
        super.cargar(arch);
        paisOrigen = arch.next();
        while(!arch.hasNextInt()){
            idiomas.add(arch.next());
        }
        numeroDeSemestres = arch.nextInt();
    }

    @Override
    public void imprimir() {
        super.imprimir(); 
        String idioma = "[";
        int i = 0;
        for (String idioma1 : idiomas) {
            if(i != 0)
                idioma += ", ";
            idioma += idioma1;
            i++;
        }
        idioma += "]";
        System.out.printf("%-20s %-35s %-20s %-50s Semestres(%d)\n", "N/A", "N/A",
                paisOrigen, idioma, numeroDeSemestres);
    }

    @Override
    public double calcularPrecio(Producto producto, double tipoCambio) {
        return producto.getPrecio() * tipoCambio * (95.0/100.0);
    }
    
    
    
}
