package lectoresYescritores;

public class Main {

	public static void main(String[] arg) {
		Database db = new Database();
		Writer w0 = new Writer(db);
		
		w0.start();
		Writer w1 = new Writer(db);
		w1.start();
		
		for (int i =0 ; i<100; i++) {
			Reader r = new Reader(db);
			r.start();
		}
	}
}
