using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;

namespace Persistance.DAO
{
    public interface GeneroDAO
    {
        int Insertar(GeneroDTO genero);
        GeneroDTO ObtenerPorId(int generoId);
        IList<GeneroDTO> ListarTodos();
        int Modificar(GeneroDTO genero);
        int Eliminar(GeneroDTO genero);
    }
}
