using System.ComponentModel;

namespace Pregunta2
{
    public class CancionBuilder{
		
		private string titulo;
		private string otroTitulo;
		private BindingList<string> interpretes;
		private BindingList<string> compositores;
		private Genero? generoMusical;
		private string album;
		private int? opus;
		private int? subOpus;
		private string dedicatoria;
		
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
		
		public string Titulo{
			get{return titulo;}
			set{titulo = value;}
		}
		
		public string OtroTitulo{
			get{return otroTitulo;}
			set{otroTitulo = value;}
		}
		
		public void agregarInterprete(string interprete){
			this.interpretes.Add(interprete);
		}
		
		public void agregarCompositor(string compositor){
			this.compositores.Add(compositor);
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
		
		public CancionBuilder ConTitulo(string titulo){
			this.titulo = titulo;
			return this;
		}
		
		public CancionBuilder TambienConocidaComo(string otroTitulo){
			this.otroTitulo = otroTitulo;
			return this;
		}
		
		public CancionBuilder InterpretadoPor(string interprete){
			this.agregarInterprete(interprete);
			return this;
		}
		
		public CancionBuilder CompuestoPor(string compositor){
			this.agregarCompositor(compositor);
			return this;
		}
		
		public CancionBuilder DelGenero(Genero generoMusical){
			this.generoMusical = generoMusical;
			return this;
		}
		
		public CancionBuilder EnElAlbum(string album){
			this.album = album;
			return this;
		}
		
		public CancionBuilder IdentificadoConOpus(int opus){
			this.opus = opus;
			return this;
		}
		
		public CancionBuilder IdentificadoConSubOpus(int subOpus){
			this.subOpus = subOpus;
			return this;
		}
		
		public CancionBuilder DedicadoA(string dedicatoria){
			this.dedicatoria = dedicatoria;
			return this;
		}
		
		public Cancion BuildCancion(){
			Cancion cancion = new Cancion();
			cancion.Titulo = this.titulo;
			cancion.OtroTitulo = this.otroTitulo;
			foreach(string interprete in interpretes){
				cancion.agregarInterprete(interprete);
			}
			foreach(string compositor in compositores){
				cancion.agregarCompositor(compositor);
			}
			cancion.GeneroMusical = this.generoMusical;
			cancion.Album = this.album;
			cancion.Opus = this.opus;
			cancion.SubOpus = this.subOpus;
			cancion.Dedicatoria = this.dedicatoria;
			return cancion;
		}
		
	}
}
