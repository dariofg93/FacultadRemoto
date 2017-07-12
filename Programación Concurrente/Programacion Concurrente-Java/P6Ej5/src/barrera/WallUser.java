package barrera;

public class WallUser extends Thread{

	private String frase;
	private Barrera wall;
	private Integer number;
	
	public WallUser(Barrera b, String s, Integer n){
		this.wall = b;
		this.number = n;
		this.frase = s;
	}
	
	public void run(){
		System.out.println(frase);
		try {
			this.wall.esperar();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(number);
	}
}
