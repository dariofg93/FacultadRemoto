package solicitud;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import cliente.Cliente;

public class CreditoHipotecarioTest {

	SolicitudDeCredito creditoTest;
	Cliente clienteMock;
	PropiedadInmobiliaria frizzerMock;
	
	@Before
	public void setUp(){
		frizzerMock = mock(PropiedadInmobiliaria.class);
		clienteMock = mock(Cliente.class);
		creditoTest = new CreditoHipotecario(5000f,8,clienteMock,frizzerMock);
	}

	@Test
	public void testEsAceptable() {
		when(frizzerMock.getValor()).thenReturn(10000f);
		when(clienteMock.getIngresoMensual()).thenReturn(1800.66f);
		when(clienteMock.getEdad()).thenReturn(50);
				
		assertTrue(creditoTest.esAceptable());
	}
}
