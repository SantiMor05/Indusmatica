using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    public class GeneroDTO
    {
        int? id_genero;
        string descripcion_genero;

        public GeneroDTO()
        {
            this.Id_genero = null;
            this.Descripcion_genero = null;
        }

        public GeneroDTO(int id_genero, string descripcion_genero)
        {
            this.Id_genero = id_genero;
            this.Descripcion_genero = descripcion_genero;
        }
        public int? Id_genero { get => id_genero; set => id_genero = value; }
        public string Descripcion_genero { get => descripcion_genero; set => descripcion_genero = value; }
    }
}
