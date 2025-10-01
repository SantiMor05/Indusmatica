using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;

namespace Persistance.DAO
{
    public interface VideojuegoDAO
    {
        int Insertar(VideojuegoDTO videojuego);

        VideojuegoDTO ObtenerPorId(int videojuegoId);

        IList<VideojuegoDTO> ListarTodos();

        int Modificar(VideojuegoDTO videojuego);

        int Eliminar(VideojuegoDTO videojuego);
        IList<VideojuegoDTO> conseguirListaNoNormalizada();
    }
}
