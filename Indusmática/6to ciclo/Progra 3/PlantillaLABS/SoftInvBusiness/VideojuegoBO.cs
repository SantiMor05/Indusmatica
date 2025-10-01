using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;
using Persistance.DAO;
using Persistance.DAOImpl;

namespace Business
{
    public class VideojuegoBO
    {
        private VideojuegoDAO videojuegoDAO;
        public VideojuegoBO()
        {
            videojuegoDAO = new VideojuegoDAOImpl();
        }

        public int Insertar(int fid_genero, char fid_categoria, string nombre_videojuego, DateTime fecha_lanzamiento, double precio_aprox_mercado, int num_jugadores_mc)
        {
            VideojuegoDTO videojuegoDTO = new VideojuegoDTO();
            videojuegoDTO.Genero = new GeneroDTO() { Id_genero = fid_genero };
            videojuegoDTO.Categoria = new CategoriaDTO() { Id_categoria = fid_categoria };
            videojuegoDTO.Nombre_videojuego = nombre_videojuego;
            videojuegoDTO.Fecha_lanzamiento = fecha_lanzamiento;
            videojuegoDTO.Precio_aprox_mercado = precio_aprox_mercado;
            videojuegoDTO.Num_jugadores_mc = num_jugadores_mc;
            return this.videojuegoDAO.Insertar(videojuegoDTO);
        }

        public int Modificar(int id_videojuego, int fid_genero, char fid_categoria, string nombre_videojuego, DateTime fecha_lanzamiento, double precio_aprox_mercado, int num_jugadores_mc)
        {
            VideojuegoDTO videojuegoDTO = new VideojuegoDTO();
            videojuegoDTO.Id_videojuego = id_videojuego;
            videojuegoDTO.Genero = new GeneroDTO() { Id_genero = fid_genero };
            videojuegoDTO.Categoria = new CategoriaDTO() { Id_categoria = fid_categoria };
            videojuegoDTO.Nombre_videojuego = nombre_videojuego;
            videojuegoDTO.Fecha_lanzamiento = fecha_lanzamiento;
            videojuegoDTO.Precio_aprox_mercado = precio_aprox_mercado;
            videojuegoDTO.Num_jugadores_mc = num_jugadores_mc;
            return this.videojuegoDAO.Modificar(videojuegoDTO);
        }

        public int Eliminar(int id_videojuego)
        {
            VideojuegoDTO videojuegoDTO = new VideojuegoDTO();
            videojuegoDTO.Id_videojuego = id_videojuego;
            return this.videojuegoDAO.Eliminar(videojuegoDTO);
        }

        public IList<VideojuegoDTO> ListarTodos()
        {
            return this.videojuegoDAO.ListarTodos();
        }
        public VideojuegoDTO ObtenerPorId(int id_videojuego)
        {
            return this.videojuegoDAO.ObtenerPorId(id_videojuego);
        }

        public IList<VideojuegoDTO> listaNormalizada()
        {
            return this.videojuegoDAO.conseguirListaNoNormalizada();
        }
    }
}
