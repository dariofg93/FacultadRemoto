package secuenciador;

public class SequenceUser extends Thread{

	private SecuenciadorTernario sequence;
	
	public SequenceUser(SecuenciadorTernario st){
		this.sequence = st;
	}
	
	public void run() {
		this.sequence.secuencia();
	}
}
