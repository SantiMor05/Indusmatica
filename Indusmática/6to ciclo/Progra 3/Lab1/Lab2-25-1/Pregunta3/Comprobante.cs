using System.ComponentModel;

namespace Pregunta3{
	
	class Comprobante{
		
		private BindingList<ComprobanteDetalle>comprobantes;
		
		public Comprobante(){
			comprobantes = new BindingList<ComprobanteDetalle>();			
		}
		
		public void agregarDetalle(string descripcion, int cantidad, double precio){
			int numero;
			
			if(comprobantes.Count == 0) numero = 1;
			else 
				numero = comprobantes[comprobantes.Count - 1].NumeroItem;
			
			ComprobanteDetalle comprobante = new ComprobanteDetalle(numero, descripcion, cantidad, precio);
			comprobantes.Add(comprobante);
			
		}
		
		public override string ToString(){
		string reporte = null;
			if(this.GetType() == typeof(Comprobante))
				reporte = "BOLETA DE PAGO\n";
			
			reporte += "DETALLE:\n";
			reporte += "\tNo Desc." + "Cant.".PadLeft(18) + "Precio".PadLeft(8) + "IGV".PadLeft(6) + "Subtotal".PadLeft(12) + "\n";
			
			foreach(var detalle in comprobantes){
				
				reporte += detalle;
			}
			return reporte;
		}
		
	}
	
}