using System.ComponentModel;

namespace Pregunta1
{
	public class Admision{
		
		private BindingList<FichaEvaluacion>listaFichas;
		private int cantidad_admitidos;
		private int cantidad_postulantes;
		
	
		public Admision(){
			listaFichas = new BindingList<FichaEvaluacion>();
			cantidad_admitidos = 0;
			cantidad_postulantes = 0;
		}
	
		public void agregarFichaDeEvaluacion(FichaEvaluacion fichaEvaluacion){
			FichaEvaluacion ficha = new FichaEvaluacion(fichaEvaluacion);
			listaFichas.Add(ficha);
			cantidad_postulantes++;
			if (fichaEvaluacion.Estado_candidato == Estado.ADMITIDO)
				cantidad_admitidos++;
		}
	
		public override string ToString(){
			string reporte = "PROCESOD DE ADMISION: " + cantidad_postulantes + " postulantes, " + cantidad_admitidos + " admitidos\n";
			reporte += "\tLISTA DE ADMITIDOS:\n";
			foreach(FichaEvaluacion fichaEvaluacion in listaFichas){
				if (fichaEvaluacion.Estado_candidato == Estado.ADMITIDO){
					reporte += "\t\t" + fichaEvaluacion.Candidato + "\n";
				}
			}
			return reporte;
		}
	
	}
	
}