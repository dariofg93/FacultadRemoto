package solicitud;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import cliente.Cliente;

public class SolicitudDeCreditoTest {

	SolicitudDeCredito creditoTest;
	Cliente clienteMock;
	
	@Before
	public void setUp(){
		clienteMock = mock(Cliente.class);
		creditoTest = new CreditoPersonal(10000f,8,clienteMock);
	}

	@Test
	public void testCuotaMensual() {
		assertTrue(creditoTest.cuotaMensual().equals(1250f));
	}
}
