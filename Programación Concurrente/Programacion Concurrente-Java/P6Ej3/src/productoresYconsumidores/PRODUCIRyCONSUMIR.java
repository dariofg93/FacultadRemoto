package productoresYconsumidores;

public class PRODUCIRyCONSUMIR {

	public static void main(String[] args) {
		Buffer buff = new Buffer(2);
		
		Productor p = new Productor(buff,new Integer[]{1,6,3,9,23,7,4,4,6,4});
		p.start();
		
		Consumidor c = new Consumidor(buff);
		c.start();
		}
}			//PREGUNTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR!!!
	//(Como hacer que el productor pueda hacer todas sus producciones
//				y no limitarse por el tamaño del Buffer???)
