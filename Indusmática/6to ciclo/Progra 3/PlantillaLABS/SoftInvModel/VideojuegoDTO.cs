using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    public class VideojuegoDTO
    {
        int? id_videojuego;
        GeneroDTO genero;
        CategoriaDTO categoria;
        string nombre_videojuego;
        DateTime? fecha_lanzamiento;
        double? precio_aprox_mercado;
        int? num_jugadores_mc;

        public VideojuegoDTO()
        {
            this.Id_videojuego = null;
            this.Genero = null;
            this.Categoria = null;
            this.Nombre_videojuego = null;
            this.Fecha_lanzamiento = null;
            this.Precio_aprox_mercado = null;
            this.Num_jugadores_mc = null;
        }

        public VideojuegoDTO(int id_videojuego, GeneroDTO genero, CategoriaDTO categoria, string nombre_videojuego, DateTime fecha_lanzamiento, double precio_aprox_mercado, int num_jugadores_mc)
        {
            this.Id_videojuego = id_videojuego;
            this.genero = genero;
            this.categoria = categoria;
            this.Nombre_videojuego = nombre_videojuego;
            this.Fecha_lanzamiento = fecha_lanzamiento;
            this.Precio_aprox_mercado = precio_aprox_mercado;
            this.Num_jugadores_mc = num_jugadores_mc;
        }

        public int? Id_videojuego { get => id_videojuego; set => id_videojuego = value; }
        public string Nombre_videojuego { get => nombre_videojuego; set => nombre_videojuego = value; }
        public DateTime? Fecha_lanzamiento { get => fecha_lanzamiento; set => fecha_lanzamiento = value; }
        public double? Precio_aprox_mercado { get => precio_aprox_mercado; set => precio_aprox_mercado = value; }
        public int? Num_jugadores_mc { get => num_jugadores_mc; set => num_jugadores_mc = value; }
        public GeneroDTO Genero { get => genero; set => genero = value; }
        public CategoriaDTO Categoria { get => categoria; set => categoria = value; }
    }
}
