using System;


namespace Pregunta3{
	
	class ComprobanteDetalle{
		private int numeroItem;
		private string descripcion;
		private int cantidad;
		private double precio;
		private double subtotal;
		private static double IGV = 18;
		
		public int NumeroItem{
			get{return numeroItem;}
			set{numeroItem = value;}
		}
		public string Descripcion{
			get{return descripcion;}
			set{descripcion = value;}
		}
		public int Cantidad{
			get{return cantidad;}
			set{cantidad = value;}
		}
		public double Precio{
			get{return precio;}
			set{precio = value;}
		}
		public double Subtotal{
			get{return subtotal;}
			set{subtotal = value;}
		}
		
		public ComprobanteDetalle(int numeroItem, string descripcion, int cantidad, double precio){
		
			this.descripcion = descripcion;
			this.cantidad = cantidad;
			this.precio = precio;
			this.subtotal = precio * cantidad * (100 + IGV) / 100;
			this.numeroItem = numeroItem;		
			
		}
		 
		public override string ToString(){
			
			string reporte = "\t" + numeroItem.ToString("D2") + " " + descripcion.PadRight(20);
			reporte += cantidad.ToString("D2") + precio.ToString("F2").PadLeft(8) + "  18,0 %";
			reporte += subtotal.ToString("F2").PadLeft(8) + "\n";
			return reporte;
		}
		
	}
	
}