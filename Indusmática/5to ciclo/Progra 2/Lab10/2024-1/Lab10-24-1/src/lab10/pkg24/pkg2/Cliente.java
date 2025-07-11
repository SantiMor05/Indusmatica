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
public class Cliente {
    
    private int dni;
    private String nombre;
    private double totalGastado;
    
    
    public Cliente(){
        totalGastado = 0;
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
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * @return the totalGastado
     */
    public double getTotalGastado() {
        return totalGastado;
    }

    /**
     * @param totalGastado the totalGastado to set
     */
    public void setTotalGastado(double totalGastado) {
        this.totalGastado = totalGastado;
    }
 
    public boolean leerDatos(Scanner arch){
        
       int documento;
       documento = arch.nextInt();
       if(documento == 0)return false;
       dni = documento;
       nombre = arch.next();
       return true;        
    }
    
    public void imprimirDatos(){
        System.out.printf("  DNI: %d  NOMBRE: %-60s", dni, nombre);
    }
    
}
