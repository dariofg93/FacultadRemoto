package contadores;

public class ContadorMultiplos extends Contador {

	@Override
	public Integer contar(Integer[] numeros) {
		return null;
	}
	
	public Integer contarMultiplosDe(Integer n, Integer[] numeros){
		Integer multiplos = 0;
		for( Integer m : numeros){
			if(m % n == 0)
				multiplos++;
		}
		return multiplos;
	}

}
