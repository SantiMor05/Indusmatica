using System.ComponentModel;

namespace Pregunta3
{
	public class Comprobante{
		private BindingList<ComprobanteDetalle>listaComprobantes;
		private static double IGV = 18.0;
		
		public void agregarDetalle(string descripcion, int cantidad, double precio){
			ComprobanteDetalle detalle = new ComprobanteDetalle();
			detalle.NroItem = listaComprobantes.Count + 1;
			detalle.Descripcion = descripcion;
			detalle.Cantidad = cantidad;
			detalle.Precio = precio;
			detalle.Subtotal = cantidad*precio*(1+IGV/100);
			listaComprobantes.Add(detalle);
		}
		
		public Comprobante(){
			listaComprobantes = new BindingList<ComprobanteDetalle>();
		}
		
		public virtual string Cabecera(){
			return "BOLETA DE PAGO\n";
		}
		
		public override string ToString(){
			string reporte = Cabecera();
			reporte += "\tNo. Desc.        Cant.   Precio   IGV   subTotal\n";
			double? total = 0;
			for(int i=0; i<listaComprobantes.Count; i++){
				reporte += listaComprobantes[i];
				total += listaComprobantes[i].Subtotal;
			}
			reporte += "TOTAL: " + total + ", 7%";
			return reporte;
		}
		
		
		
	}	
	
}