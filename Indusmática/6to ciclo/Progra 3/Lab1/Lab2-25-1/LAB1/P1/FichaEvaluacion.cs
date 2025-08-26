using System;

namespace Pregunta1
{
	public class FichaEvaluacion{
		
		private Postulante candidato;
		private DateTime? fecha_hora;
		private int? evaluacion_expediente;
		private int? evaluacion_entrevista;
		private int? evaluacion_examen;
		private Estado estado_candidato;
		private static int? puntaje_minimo = 75;
		
		public Postulante Candidato{
			get{return candidato;}
			set{candidato = value;}
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
				if (evaluacion_entrevista + evaluacion_examen + evaluacion_expediente > puntaje_minimo)
					estado_candidato = Estado.ADMITIDO;
				else estado_candidato = Estado.NO_ADMITIDO;
				return estado_candidato;
			}
			set{estado_candidato = value;}
		}
		
		public FichaEvaluacion(){
			fecha_hora  = null;
			evaluacion_expediente = null;
			evaluacion_entrevista = null;
			evaluacion_examen = null;
			estado_candidato = Estado.SIN_EVALUACIÓN;
		}
		
		public FichaEvaluacion(Postulante candidato, DateTime fecha_hora, int evaluacion_expediente, int evaluacion_entrevista, 
			int evaluacion_examen, Estado estado_candidato){
			Postulante candiCopia = new Postulante(candidato);
			this.candidato = candiCopia;
			this.fecha_hora = fecha_hora;
			this.evaluacion_expediente = evaluacion_expediente;
			this.evaluacion_entrevista = evaluacion_entrevista;
			this.evaluacion_examen = evaluacion_examen;
			this.estado_candidato = estado_candidato;
		}
		
		public FichaEvaluacion(FichaEvaluacion fichaEvaluacion){
			Postulante candiCopia = new Postulante(fichaEvaluacion.Candidato);
			this.candidato = candiCopia;
			this.fecha_hora = fichaEvaluacion.Fecha_hora;
			this.evaluacion_expediente = fichaEvaluacion.evaluacion_expediente;
			this.evaluacion_entrevista = fichaEvaluacion.evaluacion_entrevista;
			this.evaluacion_examen = fichaEvaluacion.evaluacion_examen;
			this.estado_candidato = fichaEvaluacion.estado_candidato;
		}
		
	}
	
}