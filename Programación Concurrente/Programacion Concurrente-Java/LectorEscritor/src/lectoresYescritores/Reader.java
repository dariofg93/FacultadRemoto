package lectoresYescritores;

public class Reader extends Thread{

	private final Database db;
	
	public Reader(Database db) {
		this.db = db;
	}
	
	public void run() {
		while (true) {
			db.beginRead();
			System.out.println("Vamo a leeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee xP");
			db.endRead();
		}
	}
}
