package contadores;

public class Counter {

	private Integer n = 0;
	
	public synchronized Integer incrementar(){
		n++;
		return n;
	}
	
	public synchronized Integer decrementar(){
		n--;
		return n;
	}
}
