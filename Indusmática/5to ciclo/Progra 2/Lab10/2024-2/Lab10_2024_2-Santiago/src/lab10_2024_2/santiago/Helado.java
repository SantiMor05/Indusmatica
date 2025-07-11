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
public class Helado extends Producto{
    private final ArrayList<String> toppings;
    
    public Helado(){
        toppings = new ArrayList<>();
    }

    @Override
    public void cargar(Scanner arch) {
        super.cargar(arch);
        int n = arch.nextInt();
        for (int i = 0; i < n; i++) {
            toppings.add(arch.next());
        }
    }

    @Override
    public void imprimir() {
        super.imprimir(); 
        String adicionales= new String();
        int i = 0;
        for (String topping : toppings) {
            if(i != 0)
                adicionales += ", ";
            adicionales += topping;
            i++;
        }
        
        System.out.println("Toppings: " + adicionales);
    }
     
    
    
    
}
