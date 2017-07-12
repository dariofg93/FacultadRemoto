package productoresYconsumidores;

public class Productor extends Thread{

	private final Buffer buff;
	
	public Productor(Buffer b) {
		this.buff = b;
	}
	
	public void run() {
		int i=0;
		while (true) {
			buff.write(new Integer(i));
			i++;
		}
	}
}
