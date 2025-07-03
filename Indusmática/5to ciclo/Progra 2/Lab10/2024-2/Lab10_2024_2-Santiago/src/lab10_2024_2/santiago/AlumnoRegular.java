/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10_2024_2.santiago;

import java.util.Scanner;

/**
 *
 * @author santi
 */
public class AlumnoRegular extends Alumno{
    
    private String especialidad;
    private String facultad;

    /**
     * @return the especialidad
     */
    public String getEspecialidad() {
        return especialidad;
    }

    /**
     * @param especialidad the especialidad to set
     */
    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    /**
     * @return the facultad
     */
    public String getFacultad() {
        return facultad;
    }

    /**
     * @param facultad the facultad to set
     */
    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }

    @Override
    public String getPaisOrigen() {
         return "Perú";
    }

    @Override
    public void cargar(Scanner arch) {
        super.cargar(arch); 
        especialidad = arch.next();
        facultad = arch.next();
    }

    @Override
    public void imprimir() {
        super.imprimir(); // 
        System.out.printf("%-20s %-35s %-20s %-50s N/A\n", facultad, especialidad,
                "N/A", "N/A");
    }

    @Override
    public double calcularPrecio(Producto producto, double tipoCambio) {
        return producto.getPrecio() * tipoCambio * 97/100;
    }
    
    
     
    
}
