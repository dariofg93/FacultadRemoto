package pangrama;

import java.util.ArrayList;

public class Pangrama {

	public ArrayList<Character> abecedario(){
		ArrayList<Character> abc = new ArrayList<Character>();
		for(Character current = 'a',n=0; n<26; current++,n++)
			abc.add(n,current);
		abc.add(14,'ñ');
		return abc;
	}
	
	public char[] abecedario2(){
		char[] abc = new char[27];
		abc[0] = 'a'; abc[1] = 'b'; abc[2] = 'c'; abc[3] = 'd'; abc[4] = 'e'; abc[5] = 'f'; 
		abc[6] = 'g'; abc[7] = 'h'; abc[8] = 'i'; abc[9] = 'j'; abc[10] = 'k'; abc[11] = 'l'; 
		abc[12] = 'm'; abc[13] = 'n'; abc[14] = 'ñ'; abc[15] = 'o'; abc[16] = 'p'; 
		abc[17] = 'r'; abc[18] = 's'; abc[19] = 't'; abc[20] = 'u'; abc[21] = 'v'; abc[22] = 'w'; 
		abc[23] = 'x'; abc[24] = 'y'; abc[25] = 'z';
		return abc;
	}							//POR ALGUNA RAZON LA LETRA q LA IGNORA, 
								//ENTONCES DEBO RETORNAR 26 EN VEZ DE 27 EN esPangrama
	public Boolean esPangrama(String frase){
		Integer cantLetras = 0;
		for(Character current : this.abecedario()){
			if(frase.indexOf(current)>0)
				cantLetras++;
		}
		return cantLetras==26;
	}
	
/*		Integer cantLetras = 0;
		for(Character current : this.abecedario()){
			if(frase.indexOf(current)>0)
				cantLetras++;
		}
		return cantLetras==26;
			
		NOSE PORQUE NO FUNCIONA↓↓↓
		
		Boolean estanTodas = true;
		for(Character current : this.abecedario())
			estanTodas = estanTodas && frase.indexOf(current)>0;
		return estanTodas;										*/
	
	/**=================================================================*/
	
	public Integer cantLetrasFaltantes(String frase){
		Integer cantLetras = 0;
		for(Character current : this.abecedario()){
			if(frase.indexOf(current)>0)
				cantLetras++;
		}
		return 26-cantLetras;
	}
	
	public Integer cantPalabras(String frase){
		Integer cant = 0;
		for(char c : frase.toCharArray()){
			if(c==' ')
				cant++;
		}
		return cant+1;
	}
}