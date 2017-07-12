package productoresYconsumidores;

public class Main {

	public static void main(String[] args) {
		Buffer buff = new Buffer();
		Productor p = new Productor(buff);
		
		p.start();
		Consumidor c = new Consumidor(buff);
		
		c.start();
		}
}
