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
public class Pais extends Registro {

    private String nombre;
    private String moneda;
    private float tipoCambio;
    private String idioma;

    @Override
    public void cargar(Scanner arch) {
        nombre = arch.next();
        moneda = arch.next();
//        String token = arch.next();  // Lee el siguiente valor como String para inspeccionarlo
//        System.out.println("leyendo token: " + token);
//        tipoCambio = Float.parseFloat(token);
        tipoCambio = arch.nextFloat();
        idioma = arch.next();
    }

    @Override
    public void imprimir() {
        System.out.printf("%-15s %-8s %10.2f %12s\n", nombre,
                moneda, tipoCambio, idioma);
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
     * @return the moneda
     */
    public String getMoneda() {
        return moneda;
    }

    /**
     * @param moneda the moneda to set
     */
    public void setMoneda(String moneda) {
        this.moneda = moneda;
    }

    /**
     * @return the tipoCambio
     */
    public double getTipoCambio() {
        return tipoCambio;
    }

    /**
     * @param tipoCambio the tipoCambio to set
     */
    public void setTipoCambio(float tipoCambio) {
        this.tipoCambio = tipoCambio;
    }

    /**
     * @return the idioma
     */
    public String getIdioma() {
        return idioma;
    }

    /**
     * @param idioma the idioma to set
     */
    public void setIdioma(String idioma) {
        this.idioma = idioma;
    }

}
