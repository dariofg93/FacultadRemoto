package barrera;

public class WALL {

	public static void main(String[] args) {
		Barrera b = new Barrera(9);
		
		for(Integer i = 0; i<10; i++){
			WallUser user;
			user = new WallUser(b,"Entra el Thread N: "+i.toString()+" y choca",i);
			user.start();
		}
	}
}
