package solicitud;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import cliente.Cliente;

public class CreditoPersonalTest {

	CreditoPersonal creditoTest;
	Cliente clienteMock;
	
	@Before
	public void setUp(){
		clienteMock = mock(Cliente.class);
		creditoTest = new CreditoPersonal(10000f,8,clienteMock);
	}

	@Test
	public void testEsAceptable() {
		
		when(clienteMock.sueldoNetoAnual()).thenReturn(14000f);
		
		assertFalse(creditoTest.esAceptable());
		
		when(clienteMock.sueldoNetoAnual()).thenReturn(20000f);
		when(clienteMock.getIngresoMensual()).thenReturn(1800.66f);
				
		assertTrue(creditoTest.esAceptable());
	}
}
