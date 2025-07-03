/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab10.pkg24.pkg2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author alulab14
 */
public class Lab10242 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        File file = new File("VentaDeLibros.txt");
        Scanner arch = new Scanner(file);
        
        Libreria libreria = new Libreria();
        
        libreria.leerDatos(arch);
        libreria.leerLibros(arch);
        libreria.leerClientes(arch);
        libreria.leerVentas(arch);
        libreria.emitirReporte();
    }
    
}
