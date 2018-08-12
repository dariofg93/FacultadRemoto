package solicitud;

import cliente.Cliente;

public class CreditoPersonal extends SolicitudDeCredito {

	public CreditoPersonal(Float unMonto, Integer cuotas, Cliente unSolicitante) {
		super(unMonto, cuotas, unSolicitante);
	}

	@Override
	public Boolean esAceptable() {
		return (this.solicitante.sueldoNetoAnual() >= 15000f) &&
				this.cuotaMensual()<=(this.solicitante.getIngresoMensual()*70)/100;
	}
}
