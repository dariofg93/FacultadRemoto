package contadores;

public class CONTADOR {

	public static void main(String[] args) {
		Counter count = new Counter();
		Decrementador d = new Decrementador(count);
		
		d.start();
		Incrementador i = new Incrementador(count);
		
		i.start();
	}

}
