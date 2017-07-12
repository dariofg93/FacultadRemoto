package contadores;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class ContadoresTests {

	Integer[] numeros;
	Contador contPares = new ContadorPares();
	Contador contImpares = new ContadorImpares();
	ContadorMultiplos contMult = new ContadorMultiplos();
	
	@Before
	public void setUp(){
		numeros = new Integer[] {1,2,3,4,5,6,7,8,9,10,11};
	}
	
	@Test
	public void testPares() {
		assertTrue(contPares.contar(numeros)==5);
	}

	@Test
	public void testImpares() {
		assertTrue(contImpares.contar(numeros)==6);
	}
	
	@Test
	public void testMultiplos() {
		assertTrue(contMult.contarMultiplosDe(2,numeros)==5);
	}
}
