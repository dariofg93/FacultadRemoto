package solicitud;

import cliente.Cliente;

public abstract class SolicitudDeCredito {

	protected Boolean aceptado;
	protected Float monto;
	protected Integer plazoEnMeses;
	protected Cliente solicitante;
	
	public SolicitudDeCredito(Float unMonto, Integer cuotas, Cliente unSolicitante) {
		this.aceptado = false;
		this.monto = unMonto;
		this.plazoEnMeses = cuotas;
		this.solicitante = unSolicitante;
	}
	
	public Float cuotaMensual() {
		return this.monto/this.plazoEnMeses;
	}
	
	public Float getMonto(){
		return this.monto;
	}
	
	public abstract Boolean esAceptable();
}
