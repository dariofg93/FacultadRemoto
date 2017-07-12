package productoresYconsumidores;

public class Buffer {

	private Object[] data = new Object[10];
	private int begin=0;
	private int end=0;
	
	private boolean isEmpty() {
		return begin==end;
	}
	
		private boolean isFull() {
		return (begin+1%10)==end;
	}
		
	public synchronized void write(Object o) {
		while (isFull()) {
			try {
				this.wait();
			} 	catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				}
		}
		
		data[begin]=o;
		begin = begin+1 % 10;
		
		this.notifyAll();
	}
	
	public synchronized Object read() {
		while (isEmpty()) {
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		Object result = data[end];
		end = end+1%10;
		this.notifyAll();
		
		return result;
	}
}
