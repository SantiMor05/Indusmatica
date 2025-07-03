/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10.pkg24.pkg2;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author alulab14
 */
public class Libro {
    
    private String codigo;
    private String titulo;
    private String autor;
    private double precio;
    private final ArrayList<Venta> ventas;
    private int suma;
    private int ranking;
    private double totalVendido;

    
    public Libro(){
        ventas = new ArrayList<>();
        totalVendido = 0;
        suma = 0;
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
     * @return the titulo
     */
    public String getTitulo() {
        return titulo;
    }

    /**
     * @param titulo the titulo to set
     */
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    /**
     * @return the autor
     */
    public String getAutor() {
        return autor;
    }

    /**
     * @param autor the autor to set
     */
    public void setAutor(String autor) {
        this.autor = autor;
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
     * @return the suma
     */
    public int getSuma() {
        return suma;
    }

    /**
     * @param suma the suma to set
     */
    public void setSuma(int suma) {
        this.suma = suma;
    }

    /**
     * @return the ranking
     */
    public int getRanking() {
        return ranking;
    }

    /**
     * @param ranking the ranking to set
     */
    public void setRanking(int ranking) {
        this.ranking = ranking;
    }

    /**
     * @return the totalVendido
     */
    public double getTotalVendido() {
        return totalVendido;
    }

    /**
     * @param totalVendido the totalVendido to set
     */
    public void setTotalVendido(double totalVendido) {
        this.totalVendido = totalVendido;
    }
    
    public boolean leerDatos(Scanner arch){
        
        String cod;
        cod = arch.next();
        if(cod.equals("FIN"))return false;
        
        codigo = cod;
        titulo = arch.next();
        autor = arch.next();
        precio = arch.nextDouble();
        
        return true;        
    }
    
    public void agregarVenta(Scanner arch){
        Venta venta = new Venta();
        venta.leerDatos(arch);
        suma += venta.getCalificacion();
        totalVendido += precio;
        ventas.add(venta);
    }
    
    public void determinarRanking(){
        int cantidad = ventas.size();
        double promedio;
       
        if(cantidad == 0) {
            ranking = 0;
            return;
        }
        
        promedio = suma / cantidad;
        if(promedio < 25)
            ranking = 1;
        else if(promedio < 50)
            ranking = 2;
        else if(promedio < 75)
            ranking = 3;
        else ranking = 4;
    }
    
    public void imprimirDatos(ArrayList<Cliente>clientes){
        
        int cont = 1;
        
        System.out.printf("CODIGO: %s  TITULO: %-60s AUTOR: %-30s PRECIO: %.2f\n",
                codigo, titulo, autor, precio);
        System.out.printf("LIBROS VENDIDO: %-8d RANKINGS: %d\n\n", ventas.size(), ranking);
        System.out.println("VENTAS REALIZADAS");
        
        for (Venta venta : ventas) {
            System.out.print("No. " + cont);
            for (Cliente cliente : clientes) {
                if(cliente.getDni() == venta.getDni()){
                    cliente.imprimirDatos();
                }
            }
            venta.imprimeDatos();
            cont++;
        }
        
    }
    
}
