package random;

import java.util.Random;

public class ProbandoRandom {

	static Random  rnd = new Random();
	static Integer n = (int)(rnd.nextDouble() * 500 + 1);
	
	public static void main(String[] args) {
		System.out.println("El numero que se genero es: "+n.toString());
	}
}
