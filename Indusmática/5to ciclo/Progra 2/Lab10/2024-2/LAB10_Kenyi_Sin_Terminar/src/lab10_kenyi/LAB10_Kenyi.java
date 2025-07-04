/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab10_kenyi;

import java.io.FileNotFoundException;

/**
 *
 * @author kenyi
 */
public class LAB10_Kenyi {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        Cafeteria cafeteria = new Cafeteria("datos.txt");
        cafeteria.cargarPaises();
        cafeteria.imprimirPaises();
        cafeteria.cargarParticipantes();
//        cafeteria.imprimirParticipantes();
//
        cafeteria.cargarMenu();
//        cafeteria.imprimirMenuPredeterminado();
        cafeteria.imprimirMenusPersonalizados();
    }

}
