package contadores;

public class ContadorPares extends Contador{

	@Override
	public Integer contar(Integer[] numeros){
		Integer pares = 0;
		for( Integer n : numeros){
			if(n % 2 == 0)
				pares++;
		}
		return pares;
	}
}