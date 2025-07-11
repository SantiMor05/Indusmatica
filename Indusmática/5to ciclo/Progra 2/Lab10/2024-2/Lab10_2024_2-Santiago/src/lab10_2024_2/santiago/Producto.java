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
public class Producto extends Registro{
    
    private String codigo;
    private final ArrayList<Traduccion> nombres;
    private final ArrayList<Traduccion> descripciones;
    private double precio;
    private int stock;

    
    
    public Producto(){
        nombres = new ArrayList<>();
        descripciones = new ArrayList<>();
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

    @Override
    public void cargar(Scanner arch) {
        codigo = arch.next();
        Traduccion traduccion;
        while(!arch.hasNextDouble()){
            traduccion = new Traduccion();
            traduccion.leer(arch);
            nombres.add(traduccion);
        }
        precio = arch.nextDouble();
        while(!arch.hasNextInt()){
            traduccion = new Traduccion();
            traduccion.leer(arch);
            descripciones.add(traduccion);
        }
        stock = arch.nextInt();
    }

    @Override
    public void imprimir() {
        System.out.println(codigo + ": " + obtenerNombre("ES"));
        System.out.println(obtenerDescripcion("ES"));
        System.out.printf("Precio: S/ %4.2f\n", precio);
        if(stock > 0)
            System.out.println("Disponible: Si");
        else
            System.out.println("Disponible: No");
    }
    
    public String obtenerNombre(String idioma){
        for (Traduccion nombre : nombres) {
            if(nombre.getIdioma().equals(idioma))
                return nombre.getTexto();
        }
        return "NO ENCONTRADO";
    }
    
    public String obtenerDescripcion(String idioma){
        for (Traduccion descripcion : descripciones) {
            if(descripcion.getIdioma().equals(idioma))
                return descripcion.getTexto();
        }
        return "NO ENCONTRADO";
    }
    
    
    public void imprimir(Alumno alumno, Pais pais){
        System.out.println(codigo + ": " + obtenerNombre(pais.getIdioma()));
        System.out.println(obtenerDescripcion(pais.getIdioma()));
        System.out.printf("Precio: %s %4.2f\n",pais.getMoneda(),
                alumno.calcularPrecio(this, pais.getTipoCambio()));
        if(stock > 0)
            System.out.println("Disponible: Si");
        else
            System.out.println("Disponible: No");
    }
}
