using Model;
using Persistance.DAO;
using Persistance.DAOImpl;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business
{
    public class GeneroBO
    {
        private GeneroDAO generoDAO;

        public GeneroBO()
        {
            generoDAO = new GeneroDAOImpl();
        }

        public int Insertar(string descripcion_genero)
        {
            GeneroDTO generoDTO = new GeneroDTO();
            generoDTO.Descripcion_genero = descripcion_genero;
            return this.generoDAO.Insertar(generoDTO);
        }

        public int modificar(int id_genero, string descripcion_genero)
        {
            GeneroDTO generoDTO = new GeneroDTO();
            generoDTO.Id_genero = id_genero;
            generoDTO.Descripcion_genero = descripcion_genero;
            return this.generoDAO.Modificar(generoDTO);
        }

        public int eliminar(int id_genero)
        {
            GeneroDTO generoDTO = new GeneroDTO();
            generoDTO.Id_genero = id_genero;
            return this.generoDAO.Eliminar(generoDTO);
        }

        public IList<GeneroDTO> ListarTodos()
        {
            return this.generoDAO.ListarTodos();
        }
        public GeneroDTO ObtenerPorId(int id_genero)
        {
            return this.generoDAO.ObtenerPorId(id_genero);
        }
    }
}
