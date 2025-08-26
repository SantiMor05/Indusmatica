using System;

namespace Pregunta1
{
	public class Postulante{
		
		private string paterno;
		private string materno;
		private string nombre;
		private string dni;
		
		public string Paterno{
			get{return paterno;}
			set{paterno = value;}
		}
		public string Materno{
			get{return materno;}
			set{materno = value;}
		}
		public string Nombre{
			get{return nombre;}
			set{nombre = value;}
		}
		public string Dni{
			get{return dni;}
			set{dni = value;}
		}
		
		public Postulante(){
			paterno = null;
			materno = null;
			nombre = null;
			dni = null;
		}
		
		public Postulante(string paterno, string materno, string nombre, string dni){
			this.paterno = paterno;
			this.materno = materno;
			this.nombre = nombre;
			this.dni = dni;
		}
		
		public Postulante(Postulante postulante){
			this.paterno = postulante.Paterno;
			this.materno = postulante.Materno;
			this.nombre = postulante.nombre;
			this.dni = postulante.dni;
		}
		
		public override string ToString(){
			return this.Paterno + " " + this.Materno + ", " + this.Nombre + " (" + this.dni + ").";
		}
		
	}
	
}