package cliente;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import banco.Banco;
import solicitud.PropiedadInmobiliaria;

public class ClienteTest {
	
	Cliente clienteTest;
	Banco bancoMock;

	@Before
	public void setUp(){
		bancoMock = mock(Banco.class);
		clienteTest = new Cliente("Dario Gutierrez",933,5000f,22,bancoMock);
	}

	@Test
	public void testSueldoNetoAnual() {
		assertTrue(clienteTest.sueldoNetoAnual().equals(60000f));
	}
	
	@Test
	public void testSolicitarCredito() {
		PropiedadInmobiliaria autito;
		autito = mock(PropiedadInmobiliaria.class);
		
		clienteTest.solicitarCreditoPersonal(15000f,10);
		clienteTest.solicitarCreditoHipotecario(15000f,10,autito);
		
		assertTrue(clienteTest.getSolicitudes().size()==2);
	}

}
