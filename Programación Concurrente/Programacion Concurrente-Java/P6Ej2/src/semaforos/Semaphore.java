package semaforos;

public class Semaphore {

	public synchronized void acquire() throws InterruptedException{
		this.wait();
	}
	
	public synchronized void release(){
		this.notify();
	}
}
