using Model;
using Persistance.DAO;
using SoftInv.DAOImpl;
using SoftInv.DAOImpl.Util;
using SoftInv.Db;
using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Persistance.DAOImpl
{
    public class VideojuegoDAOImpl : DAOImplBase, VideojuegoDAO
    {
        private VideojuegoDTO videojuego;

        public VideojuegoDAOImpl() : base("videojuego")
        {
            this.retornarLlavePrimaria = true;
            this.videojuego = null;
        }

        protected override void ConfigurarListaDeColumnas()
        {
            this.listaColumnas.Add(new Columna("id_videojuego", true, true));
            this.listaColumnas.Add(new Columna("fid_genero", false, false));
            this.listaColumnas.Add(new Columna("fid_categoria", false, false));
            this.listaColumnas.Add(new Columna("nombre_videojuego", false, false));
            this.listaColumnas.Add(new Columna("fecha_lanzamiento", false, false));
            this.listaColumnas.Add(new Columna("precio_aprox_mercado", false, false));
            this.listaColumnas.Add(new Columna("num_jugadores_mc", false, false));
        }
        protected override void IncluirValorDeParametrosParaInsercion()
        {
            AgregarParametro("@fid_genero", this.videojuego.Genero.Id_genero);
            AgregarParametro("@fid_categoria", this.videojuego.Categoria.Id_categoria);
            AgregarParametro("@nombre_videojuego", this.videojuego.Nombre_videojuego);
            AgregarParametro("@fecha_lanzamiento", this.videojuego.Fecha_lanzamiento);
            AgregarParametro("@precio_aprox_mercado", this.videojuego.Precio_aprox_mercado);
            AgregarParametro("@num_jugadores_mc", this.videojuego.Num_jugadores_mc);
        }
        protected override void IncluirValorDeParametrosParaModificacion()
        {
            AgregarParametro("@id_videojuego", this.videojuego.Id_videojuego);
            AgregarParametro("@fid_genero", this.videojuego.Genero.Id_genero);
            AgregarParametro("@fid_categoria", this.videojuego.Categoria.Id_categoria);
            AgregarParametro("@nombre_videojuego", this.videojuego.Nombre_videojuego);
            AgregarParametro("@fecha_lanzamiento", this.videojuego.Fecha_lanzamiento);
            AgregarParametro("@precio_aprox_mercado", this.videojuego.Precio_aprox_mercado);
            AgregarParametro("@num_jugadores_mc", this.videojuego.Num_jugadores_mc);
        }
        protected override void IncluirValorDeParametrosParaEliminacion()
        {
            AgregarParametro("@id_videojuego", this.videojuego.Id_videojuego);
        }

        protected override void IncluirValorDeParametrosParaObtenerPorId()
        {
            AgregarParametro("@id_videojuego", this.videojuego.Id_videojuego);
        }
        
        protected override void InstanciarObjetoDelResultSet(DbDataReader lector)
        {
            this.videojuego = new VideojuegoDTO();
            this.videojuego.Id_videojuego = this.lector.GetInt32(0);
            this.videojuego.Nombre_videojuego = this.lector.GetString(4);
            this.videojuego.Fecha_lanzamiento = this.lector.GetDateTime(5);
            this.videojuego.Precio_aprox_mercado = this.lector.GetDouble(6);
            this.videojuego.Num_jugadores_mc = this.lector.GetInt32(7);
            this.videojuego.Genero = new GeneroDTO();
            this.videojuego.Genero.Id_genero = this.lector.GetInt32(2);
            //this.videojuego.Genero.Descripcion_genero = this.lector.GetString(6);
            this.videojuego.Categoria = new CategoriaDTO();
            this.videojuego.Categoria.Id_categoria = this.lector.GetChar(3);
            //this.videojuego.Categoria.Descripcion_categoria = this.lector.GetString(8);
        }
        
        protected void InstanciarObjetoDelResultSetParaMigracion(DbDataReader lector)
        {
            this.videojuego = new VideojuegoDTO();
            this.videojuego.Id_videojuego = this.lector.GetInt32(0);
            this.videojuego.Nombre_videojuego = this.lector.GetString(1);
            this.videojuego.Fecha_lanzamiento = this.lector.GetDateTime(2);
            this.videojuego.Precio_aprox_mercado = this.lector.GetDouble(3);
            this.videojuego.Num_jugadores_mc = this.lector.GetInt32(4);
            this.videojuego.Genero = new GeneroDTO();
            this.videojuego.Genero.Id_genero = this.lector.GetInt32(5);
            this.videojuego.Genero.Descripcion_genero = this.lector.GetString(6);
            this.videojuego.Categoria = new CategoriaDTO();
            this.videojuego.Categoria.Id_categoria = this.lector.GetChar(7);
            this.videojuego.Categoria.Descripcion_categoria = this.lector.GetString(8);
        }
        protected override void LimpiarObjetoDelResultSet()
        {
            this.videojuego = null;
        }
        protected override void AgregarObjetoALaLista(IList<Object> lista, DbDataReader lector)
        {
            this.InstanciarObjetoDelResultSet(lector);
            lista.Add(this.videojuego);
        }
        public int Eliminar(VideojuegoDTO videojuego)
        {
            this.videojuego = videojuego;
            return base.Eliminar();
        }

        public int Insertar(VideojuegoDTO videojuego)
        {
            this.videojuego = videojuego;
            return base.Insertar();
        }

        public IList<VideojuegoDTO> ListarTodos()
        {
            return base.ListarTodos().Cast<VideojuegoDTO>().ToList();
        }

        public int Modificar(VideojuegoDTO videojuego)
        {
            this.videojuego = videojuego;
            return base.Modificar();
        }

        public VideojuegoDTO ObtenerPorId(int videojuegoId)
        {
            this.videojuego = new VideojuegoDTO();
            this.videojuego.Id_videojuego = videojuegoId;
            base.ObtenerPorId();
            return this.videojuego;
        }

        public IList<VideojuegoDTO> conseguirListaNoNormalizada()
        {
            IList<VideojuegoDTO> lista = new List<VideojuegoDTO>();
            string sql = "SELECT * FROM videojuego_nn";
            this.comando = DBManager.Instance.CrearComando();
            this.AbrirConexion();
            this.ColocarSQLenComando(sql);
            this.EjecutarConsultaEnBD();
            while (this.lector.Read())
            {
                this.InstanciarObjetoDelResultSetParaMigracion(this.lector);
                lista.Add(this.videojuego);
                this.LimpiarObjetoDelResultSet();
            }
            this.CerrarConexion();
            return lista;
        }

    }
}
