package secuenciador;

public class SECUENCIADOR {

	public static void main(String[] args) {
		SecuenciadorTernario secuencia = new SecuenciadorTernario();
		
		for(int i = 0 ; i<20 ; i++){
			SequenceUser thread = new SequenceUser(secuencia);
			thread.start();
		}
	}

}
