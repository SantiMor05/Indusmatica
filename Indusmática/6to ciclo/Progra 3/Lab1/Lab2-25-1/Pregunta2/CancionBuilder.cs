using System.ComponentModel;


namespace Pregunta2{
	
	public class CancionBuilder{
		
		private string titulo;
		private string otroTitulo;
		private BindingList<string>interpretes;
		private BindingList<string>compositores;
		private Genero? generoMusical;
		private string album;
		private int? opus;
		private int? subOpus;
		private string dedicatoria;
		
		//Constructor sin parametro
		public CancionBuilder(){
			titulo = null;
			otroTitulo = null;
			interpretes = new BindingList<string>();
			compositores = new BindingList<string>();
			generoMusical = null;
			album = null;
			opus = null;
			subOpus = null;
			dedicatoria = null;
		}
		
		
		//Propiedades
		public string Titulo{
			get{return titulo;}
			set{titulo = value;}
		}
	public string OtroTitulo{
			get{return otroTitulo;}
			set{otroTitulo = value;}
		}
		public BindingList<string> Interpretes{
			get{return interpretes;}
			set{interpretes = value;}
		}
		public BindingList<string> Compositores{
			get{return compositores;}
			set{compositores = value;}
		}
		public Genero? GeneroMusical{
			get{return generoMusical;}
			set{generoMusical = value;}
		}
		public string Album{
			get{return album;}
			set{album = value;}
		}
		public int? Opus{
			get{return opus;}
			set{opus = value;}
		}
		public int? SubOpus{
			get{return subOpus;}
			set{subOpus = value;}
		}
		public string Dedicatoria{
			get{return dedicatoria;}
			set{dedicatoria = value;}
		}
		
		
		//Metodos
		
		public void agregarInterprete(string interprete){
			interpretes.Add(interprete);
		}
		public void agregarCompositor(string compositor){
			compositores.Add(compositor);
		}
		
		
		public CancionBuilder ConTitulo(string titulo){
			Titulo = titulo;
			return this;
		}
		public CancionBuilder TambienConocidaComo(string otroTitulo){
			OtroTitulo = otroTitulo;
			return this;
		}
		public CancionBuilder InterpretadoPor(string cadena){
			agregarInterprete(cadena);
			return this;
		}
		public CancionBuilder CompuestoPor(string cadena){
			agregarCompositor(cadena);
			return this;
		}
		public CancionBuilder DelGenero(Genero genero){
			GeneroMusical = genero;
			return this;
		}
		public CancionBuilder EnElAlbum(string cadena){
			Album = cadena;
			return this;
		}
		public CancionBuilder IdentificadoConOpus(int num){
			Opus = num;
			return this;
		}
		public CancionBuilder IdentificadoConSubOpus(int num){
			SubOpus = num;
			return this;
		}
		public CancionBuilder DedicadoA(string cadena){
			Dedicatoria = cadena;
			return this;
		}
		
		public Cancion BuildCancion(){
			
			Cancion cancion =  new Cancion();
			
			cancion.Titulo = Titulo;
			cancion.OtroTitulo = OtroTitulo;
			cancion.Interpretes = Interpretes;
			cancion.Compositores = Compositores;
			cancion.GeneroMusical = GeneroMusical;
			cancion.Album = Album;
			cancion.Opus = Opus;
			cancion.SubOpus = SubOpus;
			cancion.Dedicatoria = Dedicatoria;
			
			return cancion;
		}
		
	}
}