using System.ComponentModel;


namespace Pregunta2{
	
	public class Cancion{
		
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
		
		public void agregarInterprete(string interprete){
			interpretes.Add(interprete);
		}
		public void agregarCompositor(string compositor){
			compositores.Add(compositor);
		}
		
		public override string ToString(){
			string reporte = "TITULO: " + titulo + "\n";
			if(otroTitulo != null)
				reporte += "TAMBIEN CONOCIDA COMO: " + otroTitulo + "\n";
			int cont = 0;
			if(interpretes.Count != 0){
				reporte += "INTERPRETADO POR : ";
				foreach(string interprete in interpretes){
					if(cont !=0)
						reporte += ", ";
					reporte += interprete;
					cont++;
				}
				reporte += "\n";
			}
			if(compositores.Count != 0){
				reporte += "COMPUESTO POR : "; 
				cont = 0;
				foreach(string compositor in compositores){
					if(cont !=0)
						reporte += ", ";
					reporte += compositor;
					cont++;
				}
				reporte += "\n";
			}
			
			switch(generoMusical){
				
				case Genero.FOLKLORE:
					reporte += "TIPO: FOLKLORE\n";
					break;
				default:
					reporte += "TIPO: CLASICA\n";
					break;
				
			}
			if(album != null)
				reporte += "ALBUM: " + Album + "\n";
			if(opus != null){
				reporte += "OPUS: " + opus;
				if(subOpus != null)
					reporte += " SUBOPUS: " + subOpus;
				reporte += "\n";
				
			}
			if(dedicatoria != null)
				reporte += "DEDICADO A: " + dedicatoria + "\n";
				
			return reporte;	
		}
		
	}
	
	
	
}