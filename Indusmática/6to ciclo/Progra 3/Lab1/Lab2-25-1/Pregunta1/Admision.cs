using System.ComponentModel;

namespace Pregunta1{
	
	public class Admision{
		private BindingList<FichaEvaluacion> listaFichas;
		private int cantidad_admitidos;
		private int cantidad_postulantes;
	
	
		public BindingList<FichaEvaluacion>ListaFichas{
			
			get{return listaFichas;}
			set{listaFichas = value;}
		
		}
		
		public int Cantidad_admitidos{
			get{return cantidad_admitidos;}
			set{cantidad_admitidos = value;}
		}
		
		public int Cantidad_postulantes{
			get{return cantidad_postulantes;}
			set{cantidad_postulantes = value;}
		}
	
		public Admision(){
			listaFichas = new BindingList<FichaEvaluacion>();
			cantidad_admitidos = 0;
			cantidad_postulantes = 0;
		}
	
	
		public void agregarFichaDeEvaluacion(FichaEvaluacion ficha){
			
			listaFichas.Add(new FichaEvaluacion(ficha));
			cantidad_postulantes++;
			
			if(ficha.Estado_candidato == Estado.ADMITIDO)
				cantidad_admitidos++;
			
		}
		
		public override string ToString(){
			
			string reporte = "PROCESO DE ADMISION: " + cantidad_postulantes + " postulantes, ";
			reporte += cantidad_admitidos + " admitidos\n";
			
			reporte += "\tLISTA DE ADMITIDOS:\n";
			foreach(FichaEvaluacion ficha in listaFichas){
				if(ficha.Estado_candidato == Estado.ADMITIDO)
					reporte += "\t\t" + ficha.Candidato + "\n";
				
			}
			return reporte;
		}
	
	}
}