using System;

namespace Pregunta1{
	
	public class FichaEvaluacion{
		
		private Postulante candidato;
		private DateTime? fecha_hora;
		private int? evaluacion_expediente;
		private int? evaluacion_entrevista;
		private int? evaluacion_examen;
		private Estado estado_candidato;
		public static int PUNTAJE_MINIMO = 75;
		
		public Postulante Candidato{
			get{return candidato;}
			set{candidato = new Postulante(value);}
			
		}
		
		public DateTime? Fecha_hora{
			get{return fecha_hora;}
			set{fecha_hora = value;}
			
		}
		
		public int? Evaluacion_expediente{
			get{return evaluacion_expediente;}
			set{evaluacion_expediente = value;}
			
		}
		
		public int? Evaluacion_entrevista{
			get{return evaluacion_entrevista;}
			set{evaluacion_entrevista = value;}
			
		}
		
		public int? Evaluacion_examen{
			get{return evaluacion_examen;}
			set{evaluacion_examen = value;}
			
		}
		
		public Estado Estado_candidato{
			get{
				int? suma = evaluacion_entrevista + evaluacion_examen + evaluacion_expediente;
				if(suma > PUNTAJE_MINIMO)
					estado_candidato = Estado.ADMITIDO;
				else
					estado_candidato = Estado.NO_ADMITIDO;
				
				return estado_candidato;
			}
			set{estado_candidato = value;}
			
		}
		//Constructor sin parametros
		public FichaEvaluacion(){
			candidato = null;
			fecha_hora = null;
			evaluacion_expediente = null;
			evaluacion_entrevista = null;
			evaluacion_examen = null;
			estado_candidato = Estado.SIN_EVALUACIÓN;
			
		}
		//Constructor con parametros
		public FichaEvaluacion(Postulante candidato, DateTime? fecha_hora, int? evaluacion_expediente, int? evaluacion_entrevista, 
			int? evaluacion_examen, Estado estado_candidato){
			this.candidato = new Postulante(candidato);
			this.fecha_hora = fecha_hora;
			this.evaluacion_expediente = evaluacion_expediente;
			this.evaluacion_entrevista = evaluacion_entrevista;
			this.evaluacion_examen = evaluacion_examen;
			this.estado_candidato = estado_candidato;
			
		}
		//Constructo copia
		public FichaEvaluacion(FichaEvaluacion ficha){
			this.candidato = new Postulante(ficha.candidato);
			this.fecha_hora = ficha.fecha_hora;
			this.evaluacion_expediente = ficha.evaluacion_expediente;
			this.evaluacion_entrevista = ficha.evaluacion_entrevista;
			this.evaluacion_examen = ficha.evaluacion_examen;
			this.estado_candidato = ficha.estado_candidato;
			
		}
		
	}
	
	
}