package shiyan8;

public interface Cast {
	public void saveMoney();

	public void takeMoney();
}

class Parent extends Thread {
	Cast cast;

	public Parent(Cast cast) {
		this.cast = cast;
	}

	@Override
	public synchronized void run() {
		super.run();
		cast.saveMoney();
	}
}

class Child extends Thread {
	Cast cast;

	public Child(Cast cast) {
		this.cast = cast;
	}

	@Override
	public synchronized void run() {
		super.run();
		cast.takeMoney();
	}
}