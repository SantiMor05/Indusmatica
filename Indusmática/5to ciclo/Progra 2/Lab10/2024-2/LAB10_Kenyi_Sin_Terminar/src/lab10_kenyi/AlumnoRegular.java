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
public class AlumnoRegular extends Alumno {

    private String especialidad;
    private String facultad;

    @Override
    public double calcularPrecio(Producto produc, double tipoCambio) {
        return produc.getPrecio() * tipoCambio * (1 - 3 / 100.0);
    }

    @Override
    public String getPaisOrigen() {
        return "Peru";
    }

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        especialidad = archivo.next();
        facultad = archivo.next();
    }

    @Override
    public void imprimir() {
        super.imprimir(); // 
        System.out.printf("%-20s %-35s %-20s %-50s N/A\n", facultad, especialidad,
                "N/A", "N/A");
    }

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

}
