package contador;

public class ContadorPalabras {

	public Integer contarPalabras(String frase){
		Integer cant = 0;
		for(char c : frase.toCharArray()){
			if(c==' ')
				cant++;
		}
		return cant+1;
	}
}
