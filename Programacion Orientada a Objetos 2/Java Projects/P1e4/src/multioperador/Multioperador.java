package multioperador;

import java.util.ArrayList;

public class Multioperador {

	public Float suma(ArrayList<Float> array){
		Float total = 0f;
		for(Float n : array)
			total+=n;
		return total;
	}
	
	public Float resta(ArrayList<Float> array){
		Float total = 0f;
		for(Float n : array)
			total-=n;
		return total;
	}
	
	public Float multiplicar(ArrayList<Float> array){
		Float total = 1f;
		for(Float n : array)
			total*=n;
		return total;
	}
	
	public Float dividir(ArrayList<Float> array){
		Float total = 1f;
		for(Float n : array)
			total/=n;
		return total;
	}
}
