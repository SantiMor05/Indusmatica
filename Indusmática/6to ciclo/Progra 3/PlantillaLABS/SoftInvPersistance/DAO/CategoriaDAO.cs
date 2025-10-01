using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;

namespace Persistance.DAO
{
    public interface CategoriaDAO
    {
        int Insertar(CategoriaDTO categoria);
        CategoriaDTO ObtenerPorId(char categoriaId);
        IList<CategoriaDTO> ListarTodos();
        int Modificar(CategoriaDTO categoria);
        int Eliminar(CategoriaDTO categoria);
    }
}
