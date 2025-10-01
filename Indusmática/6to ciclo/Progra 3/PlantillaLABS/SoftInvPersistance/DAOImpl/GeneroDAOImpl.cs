using Model;
using SoftInv.DAOImpl;
using SoftInv.DAOImpl.Util;
using Model;
using Persistance.DAO;
using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Persistance.DAOImpl
{
    public class GeneroDAOImpl : DAOImplBase, GeneroDAO
    {

        private GeneroDTO genero;
        public GeneroDAOImpl() : base("genero")
        {
            genero = null;
            this.retornarLlavePrimaria = true;
        }

        protected override void ConfigurarListaDeColumnas()
        {
            this.listaColumnas.Add(new Columna("id_genero", true, true));
            this.listaColumnas.Add(new Columna("descripcion_genero", false, false));
        }

        protected override void IncluirValorDeParametrosParaInsercion()
        {
            AgregarParametro("@descripcion_genero", this.genero.Descripcion_genero);
        }
        protected override void IncluirValorDeParametrosParaModificacion()
        {
            AgregarParametro("@id_genero", this.genero.Id_genero);
            AgregarParametro("@descripcion_genero", this.genero.Descripcion_genero);
        }
        protected override void IncluirValorDeParametrosParaEliminacion()
        {
            AgregarParametro("@id_genero", this.genero.Id_genero);
        }

        protected override void IncluirValorDeParametrosParaObtenerPorId()
        {
            AgregarParametro("@id_genero", this.genero.Id_genero);
        }
        
        protected override void InstanciarObjetoDelResultSet(DbDataReader lector)
        {
            this.genero = new GeneroDTO();
            this.genero.Id_genero = this.lector.GetInt32(0);
            this.genero.Descripcion_genero = this.lector.GetString(1);
        }
        
        protected void InstanciarObjetoDelResultSetParaMigracion(DbDataReader lector)
        {
            this.genero = new GeneroDTO();
            this.genero.Id_genero = this.lector.GetInt32(5);
            this.genero.Descripcion_genero = this.lector.GetString(6);
        }
        protected override void LimpiarObjetoDelResultSet()
        {
            this.genero = null;
        }
        protected override void AgregarObjetoALaLista(IList<Object> lista, DbDataReader lector)
        {
            this.InstanciarObjetoDelResultSet(lector);
            lista.Add(this.genero);
        }
        public int Eliminar(GeneroDTO genero)
        {
            this.genero = genero;
            return base.Eliminar();
        }

        public int Insertar(GeneroDTO genero)
        {
            this.genero = genero;
            return base.Insertar();
        }

        public IList<GeneroDTO> ListarTodos()
        {
            return base.ListarTodos().Cast<GeneroDTO>().ToList();
        }

        public int Modificar(GeneroDTO genero)
        {
            this.genero = genero;
            return base.Modificar();
        }

        public GeneroDTO ObtenerPorId(int generoId)
        {
            this.genero = new GeneroDTO();
            this.genero.Id_genero = generoId;
            base.ObtenerPorId();
            return this.genero;
        }

        
    }
}
