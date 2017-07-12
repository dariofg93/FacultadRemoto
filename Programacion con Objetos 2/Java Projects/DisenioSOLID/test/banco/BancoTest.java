package banco;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import cliente.Cliente;
import solicitud.CreditoHipotecario;
import solicitud.CreditoPersonal;

public class BancoTest {
	
	Banco miBanco;
	Cliente clienteMock;
	CreditoPersonal credito1;
	CreditoHipotecario credito2;

	@Before
	public void setUp(){
		this.miBanco = new Banco();
		this.clienteMock = mock(Cliente.class);
		this.credito1 = mock(CreditoPersonal.class);
		this.credito2 = mock(CreditoHipotecario.class);
	}

	@Test
	public void testAgregarCliente() {
		miBanco.agregarCliente(clienteMock);
		miBanco.agregarCliente(clienteMock);
		
		assertTrue(miBanco.getClientes().size()==2);
	}
	
	@Test
	public void testTotalADesembolsar() {

		miBanco.agregarSolicitud(credito1);
		miBanco.agregarSolicitud(credito2);

		when(credito1.getMonto()).thenReturn(100f);
		when(credito2.getMonto()).thenReturn(400f);
		
		assertTrue(miBanco.totalADesembolsar()==500f);
	}
}
