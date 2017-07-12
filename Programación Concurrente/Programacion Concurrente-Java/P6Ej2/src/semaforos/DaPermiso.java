package semaforos;

public class DaPermiso extends Thread{
	
	private final Semaphore semaforo;
	
	public DaPermiso(Semaphore s){
		this.semaforo = s;
	}
	
	public void run(){
		semaforo.release();
		System.out.println("Dar Permiso");
	}
}
