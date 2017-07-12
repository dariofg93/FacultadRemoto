package lectoresYescritores;

public class Database {

	private int writers=0;
	private int readers=0;
	private int waitingWriters=0;
	private int waitingReaders=0;
	
	private boolean canWrite() {
		return writers==0 && readers==0;
	}
	
	private boolean canRead() {
		return writers==0 && waitingWriters==0;
	}
	
	public synchronized void beginWrite() {
		while (!canWrite()) {
			waitingWriters++;
			try {
				this.wait();
			} catch (InterruptedException ex) {
				waitingWriters--;
				return;
			}
			waitingWriters--;
		}
		writers = 1;
	}
	
	public synchronized void endWrite() {
		writers = 0;
		if (waitingReaders > 0 || waitingWriters > 0) {
			this.notifyAll();
		}
	}
	
	public synchronized void beginRead() {
		while (!canRead()) {
			waitingReaders++;
			try {
				this.wait();
			} catch (InterruptedException ex) {
				waitingReaders--;
				return;
			}
			waitingReaders--;
		}
		readers++;
	}
	
	public synchronized void endRead() {
		readers--;
		if (waitingReaders > 0 || waitingWriters > 0) {
			this.notifyAll();
		}
	}
}
