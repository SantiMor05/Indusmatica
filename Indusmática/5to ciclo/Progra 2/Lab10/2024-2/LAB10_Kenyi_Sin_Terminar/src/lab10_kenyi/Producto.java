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
class Producto extends Registro {

    private String codigo;
    private ArrayList<Traduccion> nombres;
    private ArrayList<Traduccion> descripciones;
    private double precio;
    private int stock;

    public Producto() {
        nombres = new ArrayList<>();
        descripciones = new ArrayList<>();
    }

    @Override
    public void cargar(Scanner arch) {
        codigo = arch.next();
        Traduccion nombre, descripcion;
        while (!arch.hasNextDouble()) {
            nombre = new Traduccion();
            nombre.setIdioma(arch.next());
            nombre.setTexto(arch.next());
            nombres.add(nombre);
        }
        precio = arch.nextDouble();
        while (!arch.hasNextInt()) {
            descripcion = new Traduccion();
            descripcion.setIdioma(arch.next());
            descripcion.setTexto(arch.next());
            descripciones.add(descripcion);
        }
        stock = arch.nextInt();
    }

    @Override
    public void imprimir() {
        System.out.printf("%s: %s\n", codigo, obtenerNombre("ES"));
        System.out.printf("%s\n", obtenerDescripcion("ES"));
        System.out.printf("Precio: S/ %.2f\n", precio);
        if (stock > 0) {
            System.out.println("Disponible: Si");
        } else {
            System.out.println("Disponible: No");
        }
    }

    private String obtenerNombre(String idi) {
        for (Traduccion t : nombres) {
            if (t.getIdioma().equals(idi)) {
                return t.getTexto();
            }
        }
        return "";
    }

    private String obtenerDescripcion(String idi) {

        for (Traduccion t : descripciones) {
            if (t.getIdioma().equals(idi)) {
                return t.getTexto();
            }
        }
        return "";
    }

    /**
     * @return the codigo
     */
    public String getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    /**
     * @return the precio
     */
    public double getPrecio() {
        return precio;
    }

    /**
     * @param precio the precio to set
     */
    public void setPrecio(double precio) {
        this.precio = precio;
    }

    /**
     * @return the stock
     */
    public int getStock() {
        return stock;
    }

    /**
     * @param stock the stock to set
     */
    public void setStock(int stock) {
        this.stock = stock;
    }

    void imprimir(Alumno alumno, Pais pais) {
        System.out.printf("%s: %s\n", codigo, obtenerNombre(pais.getIdioma()));
        System.out.printf("%s\n", obtenerDescripcion(pais.getIdioma()));
        System.out.printf("Precio: S/ %.2f\n", alumno.calcularPrecio(this, pais.getTipoCambio()));
        if (stock > 0) {
            System.out.println("Disponible: Si");
        } else {
            System.out.println("Disponible: No");
        }
    }

}
