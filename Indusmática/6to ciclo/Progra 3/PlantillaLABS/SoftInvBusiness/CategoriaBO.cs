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
    public class CategoriaBO
    {
        private CategoriaDAO categoriaDAO;

        public CategoriaBO()
        {
            categoriaDAO = new CategoriaDAOImpl();
        }

        public int Insertar(char id_categoria, string descripcion_categoria)
        {
            CategoriaDTO categoriaDTO = new CategoriaDTO();
            categoriaDTO.Id_categoria = id_categoria;
            categoriaDTO.Descripcion_categoria = descripcion_categoria;
            return this.categoriaDAO.Insertar(categoriaDTO);
        }

        public int Modificar(char id_categoria, string descripcion_categoria)
        {
            CategoriaDTO categoriaDTO = new CategoriaDTO();
            categoriaDTO.Id_categoria = id_categoria;
            categoriaDTO.Descripcion_categoria = descripcion_categoria;
            return this.categoriaDAO.Modificar(categoriaDTO);
        }

        public int Eliminar(char id_categoria)
        {
            CategoriaDTO categoriaDTO = new CategoriaDTO();
            categoriaDTO.Id_categoria = id_categoria;
            return this.categoriaDAO.Eliminar(categoriaDTO);
        }

        public IList<CategoriaDTO> ListarTodos()
        {
            return this.categoriaDAO.ListarTodos();
        }
        public CategoriaDTO ObtenerPorId(char id_categoria)
        {
            return this.categoriaDAO.ObtenerPorId(id_categoria);
        }

    }
}
