using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    public class CategoriaDTO
    {
        char? id_categoria;
        string descripcion_categoria;
        public CategoriaDTO()
        {
            this.Id_categoria = null;
            this.Descripcion_categoria = null;
        }
        public CategoriaDTO(char id_categoria, string descripcion_categoria)
        {
            this.Id_categoria = id_categoria;
            this.Descripcion_categoria = descripcion_categoria;
        }
        public char? Id_categoria { get => id_categoria; set => id_categoria = value; }
        public string Descripcion_categoria { get => descripcion_categoria; set => descripcion_categoria = value; }
    }
}
