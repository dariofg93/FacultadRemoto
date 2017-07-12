package semaforos;

public class SEMAFORO {

	public static void main(String[] args) {
		Semaphore s = new Semaphore();
		DaPermiso release = new DaPermiso(s);
		
		release.start();
		TomaPermiso acquire = new TomaPermiso(s);
		
		acquire.start();
	}

}
