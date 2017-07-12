package productoresYconsumidores;

public class Consumidor extends Thread{

	private final Buffer buff;
	
	public Consumidor(Buffer b) {
		this.buff = b;
	}
	
	public void run() {
		while (true) {
			Integer n = buff.consumir();
			System.out.println("Consumo el numero " + n.toString());
		}
	}
}
