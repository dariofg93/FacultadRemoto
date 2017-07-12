package barrera;

public class Barrera {
	
	private Integer permisos; //La cantidad de Threads es conocida al crear la barrera.

	public Barrera(Integer n){
		this.permisos = n;
	}
	
	public synchronized void esperar() throws InterruptedException{
		while(permisos>0){
			permisos--;
			this.wait();
		}
		//Creo que no hay q restar porque nisiquiera hay 
										//que "catchear" algo... lo hago para que compile 
		this.notifyAll();
		
	}
}
