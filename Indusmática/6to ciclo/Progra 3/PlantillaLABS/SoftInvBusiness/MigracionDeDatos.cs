using Business;
using Model;
using Persistance.DAO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business
{
    public class MigracionDeDatos
    {
        private VideojuegoBO videojuegoBO;
        private GeneroBO generoBO;
        private CategoriaBO categoriaBO;

        public MigracionDeDatos()
        {
            this.videojuegoBO = new VideojuegoBO();
            this.generoBO = new GeneroBO();
            this.categoriaBO = new CategoriaBO();
        }

        public int EjecutarMigracion()
        {
            IList<VideojuegoDTO> listaNormalizada = this.videojuegoBO.listaNormalizada();
            foreach(VideojuegoDTO videojuego in listaNormalizada)
            {
                // Verifica si el género ya existe
                if (generoBO.ObtenerPorId((int)videojuego.Genero.Id_genero) == null)
                {
                    Console.WriteLine("Género no encontrado: " + videojuego.Genero.Descripcion_genero);
                    // Insertar nuevo género
                    int nuevoGeneroId = this.generoBO.Insertar(videojuego.Genero.Descripcion_genero);
                    videojuego.Genero.Id_genero = nuevoGeneroId;
                }

                // Verifica si la categoría ya existe
                if (categoriaBO.ObtenerPorId((char)videojuego.Categoria.Id_categoria) == null)
                {
                    Console.WriteLine("Categoría no encontrada: " + videojuego.Categoria.Descripcion_categoria);
                    // Insertar nueva categoría
                    int nuevaCategoriaId = this.categoriaBO.Insertar((char)videojuego.Categoria.Id_categoria, videojuego.Categoria.Descripcion_categoria);
                }
                
                Console.WriteLine("Insertando videojuego: " + videojuego.Nombre_videojuego);
                // Insertar el videojuego con los IDs de género y categoría actualizados
                this.videojuegoBO.Insertar(
                    (int)videojuego.Genero.Id_genero,
                    (char)videojuego.Categoria.Id_categoria,
                    videojuego.Nombre_videojuego,
                    (DateTime)videojuego.Fecha_lanzamiento,
                    (double)videojuego.Precio_aprox_mercado,
                    (int)videojuego.Num_jugadores_mc
                );
            }
            return listaNormalizada.Count;
        }
    }
}
