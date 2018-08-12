package multioperador;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;

import org.junit.Before;
import org.junit.Test;

public class MultioperadorTests {

	ArrayList<Float> numeros;
	Multioperador operador = new Multioperador();
	
	@Before
	public void setUp(){
		numeros = new ArrayList<Float>(Arrays.asList(1f,2f,8f));
	}
	
	@Test
	public void testSuma() {
		assertTrue(operador.suma(numeros)==11);
	}
	
	@Test
	public void testResta() {
		assertTrue(operador.resta(numeros)==-11);
	}

	@Test
	public void testMultiplicar() {
		assertTrue(operador.multiplicar(numeros)==16);
	}
	
	@Test
	public void testDividir() {
		assertTrue(operador.dividir(numeros)==0.0625);
	}
}
