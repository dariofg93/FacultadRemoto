package pangrama;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class PangramaTests {

	Pangrama pngrma = new Pangrama();
	String frase1;
	String frase2;
	String frase3;
	
	@Before
	public void setUp(){
		frase1 = "Queda gazpacho, fibra, l�tex, jam�n, kiwi y vi�as";
		frase2 = "Alohaaaa";
		frase3 = "abcdefghijklmnopqrstuvwxyz�";
	}
	
	@Test
	public void testEsPangrama() {
		assertTrue(pngrma.esPangrama(frase1));
	}
	
	@Test
	public void testLetrasFaltantes() {
		assertTrue(pngrma.cantLetrasFaltantes(frase2)==22);
	}
	
	@Test
	public void testCantidadPalabras() {
		assertTrue(pngrma.cantPalabras(frase1)==8);
	}
}
