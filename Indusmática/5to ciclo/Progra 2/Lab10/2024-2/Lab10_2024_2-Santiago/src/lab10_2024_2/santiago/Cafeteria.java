/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10_2024_2.santiago;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author santi
 */
public class Cafeteria {
    private final ArrayList<Pais> paises;
    private final ArrayList<Alumno> participantes;
    private final int MAX_CAR = 120;
    Menu menu;
    Scanner archivo;

    public Cafeteria(String nombArch) throws FileNotFoundException {
        this.participantes = new ArrayList<>();
        this.paises = new ArrayList<>();
        File file = new File(nombArch);
        archivo = new Scanner(file);
        menu = new Menu();
    }
    
    
    private void imprimeLinea(char car, int n){
        for (int i = 0; i < n; i++)
            System.out.print(car);
        //System.out.println();
    }
    
    public void cargarPaises(){
        Pais pais;
        while(true){
            
            if(archivo.next().equals("FIN")) break;
            pais = new Pais();
            pais.cargar(archivo);
            paises.add(pais);
        }
    }
    
    public void imprimirPaises(){
        System.out.printf("NOMBRE %15s  %15s %10s\n", "Moneda", "Tipo de cambio",
                "Idioma");
        imprimeLinea('=',120);
        System.out.println();
        for (Pais pais : paises) {
            pais.imprimir();
        }
        System.out.println("\n");
    }
    
    public void cargarParticipantes(){
        Alumno alumno;
        String tipo;
        OUTER:
        while (true) {
            tipo = archivo.next();
            switch (tipo) {
                case "FIN":
                    break OUTER;
                case "R":
                    alumno = new AlumnoRegular();
                    break;
                default:
                    alumno = new AlumnoIntercambio();
                    break;
            }
            alumno.cargar(archivo);
            participantes.add(alumno);
        }
    }
    
    public void imprimirParticipantes(){
        imprimeLinea('=', 50);
        System.out.print(" LISTADO DE PARTICIPANTES ");
        imprimeLinea('=', 50);
        System.out.println();
        imprimeLinea('-', MAX_CAR);
        System.out.printf("\nCODIGO %12s %50s %25s %25s %26s %48s\n","NOMBRE", "FACULTAD",
                "ESPECIALIDAD", "PAIS", "IDIOMAS", "DURACION");
        imprimeLinea('-', MAX_CAR);
        System.out.println();
        for (Alumno participante : participantes) {
            participante.imprimir();
        }
        
        System.out.println("\n");
    }
    
    public void cargaMenu(){
        menu.cargaProductos(archivo);
    }
    
    public void imprimirMenuPredeterminado(){
        menu.imprimirMenu();
    }
    
    public void imprimirMenusPersonalizados(){
        for (Alumno alumno : participantes) {
            if(!alumno.getPaisOrigen().equals("Perú")){
                for (Pais pais : paises) {
                    if(pais.getNombre().equals(alumno.getPaisOrigen())){
                        menu.imprimirMenuPersonalizado(alumno, pais);
                    }
                }
            }
        }
    }
    
}
