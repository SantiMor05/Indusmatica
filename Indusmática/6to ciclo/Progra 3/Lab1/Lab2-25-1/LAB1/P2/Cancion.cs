using System.ComponentModel;

namespace Pregunta2
{
    public class Cancion{
		
		private string titulo;
		private string otroTitulo;
		private BindingList<string> interpretes;
		private BindingList<string> compositores;
		private Genero? generoMusical;
		private string album;
		private int? opus;
		private int? subOpus;
		private string dedicatoria;
		
		public Cancion(){
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
		
		public override string ToString(){
			string Song = "TÍTULO: " + this.titulo + "\n";
			if (otroTitulo != null)
				Song += "TAMBIÉN CONOCIDA COMO: " + otroTitulo + "\n";
			if (interpretes.Count > 0){
				Song += "INTERPRETADO POR: ";
				for(int i=0; i<interpretes.Count; i++){
					if (i>0) Song += ", ";
					Song += interpretes[i];
				}
				Song += "\n";
			}
			if (compositores.Count > 0){
				Song += "COMPUESTO POR: ";
				for(int i=0; i<compositores.Count; i++){
					if (i>0) Song += ", ";
					Song += compositores[i];
				}
				Song += "\n";
			}
			Song += "TIPO: " + generoMusical + "\n";
			if (album != null) Song += "ALBUM: " + album + "\n";
			if (opus != null){
				Song += "OPUS: " + opus;
				if (subOpus != null)
					Song += " SUBOPUS: " + subOpus;
				Song += "\n";
			}
			if (dedicatoria != null)
				Song += "DEDICADO A: " + dedicatoria;
			Song += "\n";
			return Song;
		}
		
	}
}
