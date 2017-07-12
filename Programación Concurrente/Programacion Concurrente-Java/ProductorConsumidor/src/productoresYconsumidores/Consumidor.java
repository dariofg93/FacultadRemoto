package productoresYconsumidores;

public class Consumidor extends Thread{

	private final Buffer buff;
	
	public Consumidor(Buffer b) {
		this.buff = b;
	}
	
	public void run() {
		int i=0;
		while (true) {
			Object obj = buff.read();
			System.out.println("Objeto leido" + obj.toString());
		}
	}
}
