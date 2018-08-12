package solicitud;

public class PropiedadInmobiliaria {

	private String descripcion;
	private Integer direccion;
	private Float valorFiscal;

	public Float getValor() {
		return this.valorFiscal;
	}

	public String getDescripcion() {
		return descripcion;
	}

	public void setDescripcion(String descripcion) {
		this.descripcion = descripcion;
	}

	public Integer getDireccion() {
		return direccion;
	}

	public void setDireccion(Integer direccion) {
		this.direccion = direccion;
	}
}
