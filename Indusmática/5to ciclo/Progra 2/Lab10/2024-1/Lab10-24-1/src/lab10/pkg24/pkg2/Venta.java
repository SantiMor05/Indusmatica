/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10.pkg24.pkg2;

import java.util.Scanner;

/**
 *
 * @author alulab14
 */
public class Venta {
    
    private int dni;
    private int calificacion;
    private int fecha;
    
    public Venta(){
        calificacion = 0;
        fecha = 0;
    }

    /**
     * @return the dni
     */
    public int getDni() {
        return dni;
    }

    /**
     * @param dni the dni to set
     */
    public void setDni(int dni) {
        this.dni = dni;
    }

    /**
     * @return the calificacion
     */
    public int getCalificacion() {
        return calificacion;
    }

    /**
     * @param calificacion the calificacion to set
     */
    public void setCalificacion(int calificacion) {
        this.calificacion = calificacion;
    }

    /**
     * @return the fecha
     */
    public int getFecha() {
        return fecha;
    }

    /**
     * @param fecha the fecha to set
     */
    public void setFecha(int fecha) {
        this.fecha = fecha;
    }
    
    public void leerDatos(Scanner arch){
        int dd, mm, aa;
        dni = arch.nextInt();
        dd = arch.nextInt();
        mm = arch.nextInt();
        aa = arch.nextInt();
        fecha = dd + mm * 100 + aa * 10000;
        calificacion = arch.nextInt();
    }
    
    public void imprimeDatos(){
        System.out.println("CALIFICACION: " + calificacion);
    }
    
}
