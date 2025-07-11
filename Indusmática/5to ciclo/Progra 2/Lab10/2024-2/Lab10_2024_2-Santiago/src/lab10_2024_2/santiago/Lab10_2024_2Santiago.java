/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab10_2024_2.santiago;

import java.io.FileNotFoundException;

/**
 *
 * @author santi
 */
public class Lab10_2024_2Santiago {

    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException {
        
        Cafeteria cafeteria = new Cafeteria("datos.txt");
        
        cafeteria.cargarPaises();
        cafeteria.imprimirPaises();
        cafeteria.cargarParticipantes();
        cafeteria.imprimirParticipantes();
        
        cafeteria.cargaMenu();
        cafeteria.imprimirMenuPredeterminado();
        cafeteria.imprimirMenusPersonalizados();
    }
    //Me quede en 45 min
}
