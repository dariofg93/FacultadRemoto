package pangrama;

import java.util.ArrayList;

public class imprimir {

	static Pangrama p = new Pangrama();
	static Boolean test = "asdasdsdasd".indexOf('5')>0;
	static String frase = "abcdefghijklmnopqrstuvwxyzñ";
	static ArrayList<Character> letras;

	public static void main(String[] args) {
		System.out.println(p.abecedario());
	}

}
