package contadores;

public class Incrementador extends Thread{

	private final Counter count;
	
	public Incrementador(Counter c) {
		this.count = c;
	}
	
	public void run() {
		while (true) {
			Integer total = count.incrementar();
			System.out.println("SUMA, el total es: " + total.toString());
		}
	}
}
