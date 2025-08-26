using System;

namespace Pregunta3
{
	public class ComprobanteDetalle{
		private int? nroItem;
		private string descripcion;
		private int? cantidad;
		private double? precio;
		private double? subtotal;
		private static double IGV = 18.0;
		
		public ComprobanteDetalle(){
			nroItem = null;
			descripcion = null;
			cantidad = null;
			precio = null;
			subtotal = null;
		}
		
		public int? NroItem{
			get{return nroItem;}
			set{nroItem = value;}
		}
		
		public string Descripcion{
			get{return descripcion;}
			set{descripcion = value;}
		}
		
		public int? Cantidad{
			get{return cantidad;}
			set{cantidad = value;}
		}
		
		public double? Precio{
			get{return precio;}
			set{precio = value;}
		}
		
		public double? Subtotal{
			get{return subtotal;}
			set{subtotal = value;}
		}
		
		public override string ToString(){
			return "\t" + nroItem + "  " + descripcion + "       " + cantidad + "    " + precio + "     " + IGV + "%   " + subtotal + "\n"; 
		}
	}
	
}