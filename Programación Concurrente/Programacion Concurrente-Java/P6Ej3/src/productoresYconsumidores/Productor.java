package productoresYconsumidores;

public class Productor extends Thread{

	private final Buffer buff;
	private final Integer[] products;
	
	public Productor(Buffer b, Integer[] ns) {
		this.buff = b;
		this.products = ns;
	}
	
	public void run() {
		for(Integer i : this.products){
			buff.producir(i);
		}
	}
}
