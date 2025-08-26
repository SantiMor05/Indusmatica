using System.ComponentModel;

namespace Pregunta3
{
	public class Factura : Comprobante{
		
		private string razon_social;
		private string ruc;
		
		public Factura(string ruc, string razon_social){
			this.ruc = ruc;
			this.razon_social = razon_social;
		}
		
		public override string Cabecera(){
			return "FACTURA\nCLIENTE\n" + 
			"\tRUC: " + ruc + "\n" +
			"\tRazón Social: " + razon_social + "\n";
		}
		
	}
	
}