package solicitud;

import cliente.Cliente;

public class CreditoHipotecario extends SolicitudDeCredito {
	
	private PropiedadInmobiliaria garantia;

	public CreditoHipotecario(Float unMonto, Integer cuotas, Cliente unSolicitante, PropiedadInmobiliaria unaPropiedad) {
		super(unMonto, cuotas, unSolicitante);
		this.garantia = unaPropiedad;
	}

	@Override
	public Boolean esAceptable() {
		return this.cuotaMensual()<=(this.solicitante.getIngresoMensual()*70)/100 &&
				this.monto<=(this.garantia.getValor()*70)/100 &&
				 this.solicitante.getEdad()<= 65;
	}
}
