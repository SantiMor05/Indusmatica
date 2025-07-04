/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10_kenyi;

import java.util.Scanner;

/**
 *
 * @author kenyi
 */
public abstract class Alumno extends Registro{
    private String nombre;
    private int codigo;

    @Override
    public void cargar(Scanner arch) {
        codigo = arch.nextInt();
        nombre = arch.next();
    }

    @Override
    public void imprimir() {
        System.out.printf("%-12d %-60s",codigo,nombre);
    }
    
    public abstract double calcularPrecio(Producto produc,double tipoCambio);
    public abstract String getPaisOrigen();
//    public abstract double calcularPrecio()();
    
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
     * @return the codigo
     */
    public int getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }
    
    
}
