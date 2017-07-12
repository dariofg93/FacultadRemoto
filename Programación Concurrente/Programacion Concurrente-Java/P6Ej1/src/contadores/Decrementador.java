package contadores;

public class Decrementador extends Thread{

	private final Counter count;
	
	public Decrementador(Counter c) {
		this.count = c;
	}
	
	public void run() {
		while (true) {
			Integer total = count.decrementar();
			System.out.println("RESTA, el total es: " + total.toString());
		}
	}
}
