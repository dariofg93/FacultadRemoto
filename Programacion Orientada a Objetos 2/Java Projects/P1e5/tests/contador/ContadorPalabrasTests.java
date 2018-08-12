package contador;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class ContadorPalabrasTests {
	
	String frase;
	ContadorPalabras contador = new ContadorPalabras();
	
	@Before
	public void setUp(){
		frase = "Hola, me llamo eclipse Mars 5.2.";
	}

	@Test
	public void testContarPalabras() {
		assertTrue(contador.contarPalabras(frase)==6);
	}
}