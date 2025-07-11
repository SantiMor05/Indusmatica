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
public class Menu {

    private final ArrayList<Producto> productos;

    public Menu() {
        productos = new ArrayList<>();
    }

    public void cargarProductos(Scanner archivo) {
        Producto producto;
        String tipo;
        while (archivo.hasNext()) {
            tipo = archivo.next();
            if (tipo.equals("B")) {
                producto = new Bebida();
            } else {
                producto = new Helado();
            }
            producto.cargar(archivo);
            productos.add(producto);
        }

    }

    public void imprimirMenu() {
        System.out.println("");
        System.out.println("==============Menu  del Dia ===========");
        for (Producto p : productos) {
            p.imprimir();
            System.out.println("------------------------------------");
        }
    }

    public void imprimirMenuPersonalizado(Alumno alumno, Pais pais) {
        System.out.println("");
        System.out.printf("==============Menu en " + pais.getIdioma()
                + "(" + pais.getNombre() + ") para, " + alumno.getCodigo()
                + ":" + alumno.getNombre() + "==============\n");
        for (Producto p : productos) {
            p.imprimir(alumno,pais);
            System.out.println("------------------------------------");
        }
    }
}
