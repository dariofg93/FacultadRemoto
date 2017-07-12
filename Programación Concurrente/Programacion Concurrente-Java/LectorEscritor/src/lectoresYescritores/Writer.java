package lectoresYescritores;

public class Writer extends Thread{

	private final Database db;
	
	public Writer(Database db) {
		this.db = db;
	}
	
	public void run() {
		while (true) {
			db.beginWrite();
			System.out.println("Vamo a escribiiii :D");
			db.endWrite();
		}
	}
}
