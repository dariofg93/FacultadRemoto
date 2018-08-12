package contadores;

public class ContadorImpares extends Contador {

	@Override
	public Integer contar(Integer[] numeros){
		Integer impares = 0;
		for( Integer n : numeros){
			if(n % 2 == 1)
				impares++;
		}
		return impares;
	}
}
