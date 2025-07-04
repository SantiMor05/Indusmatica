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
public class Helado extends Producto {

    private final ArrayList<String> toppings;

    public Helado() {
        toppings = new ArrayList<>();
    }

    @Override
    public void cargar(Scanner arch) {
        super.cargar(arch); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
        int cantidad = arch.nextInt();
        String top;
        for (int i = 0; i < cantidad; i++) {
            top = arch.next();
            toppings.add(top);
        }
    }

    @Override
    public void imprimir() {
        super.imprimir(); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
        System.out.println("Tipo: Helado");
    }

    @Override
    void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
        System.out.println("Tipo: Helado");
    }

}
