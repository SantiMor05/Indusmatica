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
public class Menu {
    private final ArrayList<Producto> productos;
    private final int MAX_CAR = 120;
    
    public Menu(){
        productos = new ArrayList<>();
    }
    
    public void cargaProductos(Scanner arch){
        //String tipo;
        Producto producto;
        while(arch.hasNext()){
            
            if(arch.next().equals("B"))
                producto = new Bebida();
            else
                producto = new Helado();
            
            producto.cargar(arch);
            productos.add(producto);
        }
    }
    
    
    public void imprimirMenu(){
        
        boolean imprime = false;
        
        System.out.println("==================== Menu del dia ====================");
        for (Producto producto : productos) {
            if(imprime)
                imprimeLinea('-');
            producto.imprimir();
            imprime = true;
        }
    }
    
    public void imprimirMenuPersonalizado(Alumno alumno, Pais pais){
        System.out.printf("\n======== Menu en %s(%s) para, %d:%s ========\n",pais.getIdioma(),
                pais.getNombre(), alumno.getCodigo(), alumno.getNombre());
        boolean imprime = false;
        for (Producto producto : productos) {
            if(imprime)
                imprimeLinea('-');
            producto.imprimir(alumno, pais);
            
            imprime = true;
        }
        System.out.println();
        
    }
    
    public void imprimeLinea(char car){
        for (int i = 0; i < MAX_CAR; i++) {
            System.out.print(car);
        }
        System.out.println();
    }
    
}
