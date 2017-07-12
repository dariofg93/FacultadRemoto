package semaforos;

public class TomaPermiso extends Thread{

private final Semaphore semaforo;
	
	public TomaPermiso(Semaphore s){
		this.semaforo = s;
	}
	
	public void run(){
		semaforo.release();
		System.out.println("Tomar Permiso");
	}
}
