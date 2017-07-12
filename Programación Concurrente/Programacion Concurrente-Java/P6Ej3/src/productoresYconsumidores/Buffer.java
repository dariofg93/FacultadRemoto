package productoresYconsumidores;

public class Buffer {

	private Integer[] slots;
	private int begin=0;
	private int end=0;
	
	public Buffer(Integer n){
		this.slots = new Integer[n];
	}
	
	private boolean isEmpty() {
		return begin==end;
	}
	
		private boolean isFull() {
		return (begin+1%10)==end;
	}
		
	public synchronized void producir(Integer i){
		while (isFull())
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
		slots[begin]=i;
		begin = begin+1 % this.slots.length;
		
		this.notifyAll();
	}
	
	public synchronized Integer consumir() {
		while (isEmpty())
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
		Integer result = slots[end];
		end = end+1 % this.slots.length;
		
		this.notifyAll();
		
		return result;
	}
}
