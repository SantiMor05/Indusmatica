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
public class Libreria {
    private String nombre;
    private String direccion;
    private final ArrayList<Libro> libros;
    private final ArrayList<Cliente> clientes;
    private int cantidadVendida;
    private double totalVendido;

    
    public Libreria(){
        libros = new ArrayList<>();
        clientes = new ArrayList<>();
        cantidadVendida = 0;
        totalVendido = 0;
    }
    
    
    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * @return the direccion
     */
    public String getDireccion() {
        return direccion;
    }

    /**
     * @param direccion the direccion to set
     */
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    /**
     * @return the cantidadVendida
     */
    public int getCantidadVendida() {
        return cantidadVendida;
    }

    /**
     * @param cantidadVendida the cantidadVendida to set
     */
    public void setCantidadVendida(int cantidadVendida) {
        this.cantidadVendida = cantidadVendida;
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
    
    public void leerDatos(Scanner arch){
        nombre = arch.nextLine();
        direccion = arch.nextLine();
    }
    
    public void leerLibros(Scanner arch){
        Libro libro;
        while(true){
            libro = new Libro();
            if(!libro.leerDatos(arch)) break;
            
            libros.add(libro);            
        }
        
    }
    
    public void leerClientes(Scanner arch){
        
        Cliente cliente;
        while(true){
            cliente = new Cliente();
            if(!cliente.leerDatos(arch)) break;
            clientes.add(cliente);
        }
        
    }
    
    public void leerVentas(Scanner arch){
        
        String codigo;
        int pos;
        
        while(arch.hasNext()){
            codigo = arch.next();
            pos = buscarLibro(codigo);
            if(pos != 1){
                libros.get(pos).agregarVenta(arch);
                cantidadVendida++;
                totalVendido += libros.get(pos).getPrecio();
            }
        }
        
    }
    
    public int buscarLibro(String codigo){
        int i = 0;
        for (Libro libro : libros) {
            if(libro.getCodigo().equals(codigo))
                return i;
            i++;
        }
        return -1;
    }
    
    
    public void determinarRankings(){
        for (Libro libro : libros) {
            libro.determinarRanking();
        }
    }
    
    public void emitirReporte(){
        System.out.println(nombre);
        System.out.println(direccion);
        System.out.println("RESULTADO DE LAS VENTAS REALIZADAS\n");
        
        int cont = 1;
        for (Libro libro : libros) {
            System.out.println("LIBRO NO. " + cont);
            libro.imprimirDatos(clientes);
            System.out.println("");
            cont++;
        }
    }
    
}
