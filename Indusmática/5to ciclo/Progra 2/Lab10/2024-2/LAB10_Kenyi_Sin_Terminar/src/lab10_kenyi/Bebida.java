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
public class Bebida extends Producto {

    private char tipoBebida;

    @Override
    public void cargar(Scanner arch) {
        super.cargar(arch); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
        tipoBebida = arch.next().charAt(0);
    }

    @Override
    public void imprimir() {
        super.imprimir(); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
        switch (tipoBebida) {
            case 'C':
                System.out.println("Tipo: Café");
                break;
            case 'H':
                System.out.println("Tipo: Chocolate");
                break;
            case 'T':
                System.out.println("Tipo: Té");
                break;
            default:
                System.out.println("Tipo: Infusion");
                break;
        }
    }

    @Override
    void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
        switch (tipoBebida) {
            case 'C':
                System.out.println("Tipo: Café");
                break;
            case 'H':
                System.out.println("Tipo: Chocolate");
                break;
            case 'T':
                System.out.println("Tipo: Té");
                break;
            default:
                System.out.println("Tipo: Infusion");
                break;
        }
    }

}
