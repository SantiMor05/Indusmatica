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
public class Bebida extends Producto{
    
    private char tipoBebida;

    /**
     * @return the tipoBebida
     */
    public char getTipoBebida() {
        return tipoBebida;
    }

    /**
     * @param tipoBebida the tipoBebida to set
     */
    public void setTipoBebida(char tipoBebida) {
        this.tipoBebida = tipoBebida;
    }

    @Override
    public void cargar(Scanner arch) {
        super.cargar(arch);
        tipoBebida = arch.next().charAt(0);
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Tipo: " + tipoBebida);
    }
}
