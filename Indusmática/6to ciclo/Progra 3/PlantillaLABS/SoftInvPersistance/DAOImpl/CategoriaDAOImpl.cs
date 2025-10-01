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
    public class CategoriaDAOImpl : DAOImplBase, CategoriaDAO
    {

        private CategoriaDTO categoria;

        public CategoriaDAOImpl() : base("categoria")
        {
            this.retornarLlavePrimaria = true;
            this.categoria = null;
        }
        protected override void ConfigurarListaDeColumnas()
        {
            this.listaColumnas.Add(new Columna("id_categoria", true, false));
            this.listaColumnas.Add(new Columna("descripcion_categoria", false, false));
        }

        protected override void IncluirValorDeParametrosParaInsercion()
        {
            AgregarParametro("@id_categoria", this.categoria.Id_categoria);
            AgregarParametro("@descripcion_categoria", this.categoria.Descripcion_categoria);
        }
        protected override void IncluirValorDeParametrosParaModificacion()
        {
            AgregarParametro("@id_categoria", this.categoria.Id_categoria);
            AgregarParametro("@descripcion_categoria", this.categoria.Descripcion_categoria);
        }
        protected override void IncluirValorDeParametrosParaEliminacion()
        {
            AgregarParametro("@id_categoria", this.categoria.Id_categoria);
        }

        protected override void IncluirValorDeParametrosParaObtenerPorId()
        {
            AgregarParametro("@id_categoria", this.categoria.Id_categoria);
        }

        protected void InstanciarObjetoDelResultSetParaMigracion(DbDataReader lector)
        {
            this.categoria = new CategoriaDTO();
            this.categoria.Id_categoria = this.lector.GetChar(7);
            this.categoria.Descripcion_categoria = this.lector.GetString(8);
        }
        
        protected override void InstanciarObjetoDelResultSet(DbDataReader lector)
        {
            this.categoria = new CategoriaDTO();
            this.categoria.Id_categoria = this.lector.GetChar(0);
            this.categoria.Descripcion_categoria = this.lector.GetString(1);
        }
        
        protected override void LimpiarObjetoDelResultSet()
        {
            this.categoria = null;
        }
        protected override void AgregarObjetoALaLista(IList<Object> lista, DbDataReader lector)
        {
            this.InstanciarObjetoDelResultSet(lector);
            lista.Add(this.categoria);
        }
        public int Eliminar(CategoriaDTO categoria)
        {
            this.categoria = categoria;
            return base.Eliminar();
        }

        public int Insertar(CategoriaDTO categoria)
        {
            this.categoria= categoria;
            return base.Insertar();
        }

        public IList<CategoriaDTO> ListarTodos()
        {
            return base.ListarTodos().Cast<CategoriaDTO>().ToList();
        }

        public int Modificar(CategoriaDTO categoria)
        {
            this.categoria = categoria;
            return base.Modificar();
        }

        public CategoriaDTO ObtenerPorId(char categoriaId)
        {
            this.categoria = new CategoriaDTO();
            this.categoria.Id_categoria = categoriaId;
            base.ObtenerPorId();
            return this.categoria;
        }

        
    }
}
