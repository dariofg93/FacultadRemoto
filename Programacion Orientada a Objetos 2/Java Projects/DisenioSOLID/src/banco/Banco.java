package banco;

import java.util.ArrayList;

import cliente.Cliente;
import solicitud.SolicitudDeCredito;

public class Banco {
	
	private ArrayList<Cliente> clientes;
	private ArrayList<SolicitudDeCredito> prestamos;

	public Banco(){
		this.clientes = new ArrayList<Cliente>();
		this.prestamos = new ArrayList<SolicitudDeCredito>(); 
	}

	public void agregarCliente(Cliente unCliente) {
		this.clientes.add(unCliente);
		unCliente.setBanco(this);
	}

	public ArrayList<Cliente> getClientes() {
		return this.clientes;
	}

	public void agregarSolicitud(SolicitudDeCredito credito) {
		this.prestamos.add(credito);
	}

	public Float totalADesembolsar() {
		
		Float total = 0f;
		
		for(SolicitudDeCredito solicitud: this.prestamos)
			total += solicitud.getMonto();
		
		return total;
	}
}
