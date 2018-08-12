package cliente;

import java.util.ArrayList;

import banco.Banco;
import solicitud.CreditoHipotecario;
import solicitud.CreditoPersonal;
import solicitud.PropiedadInmobiliaria;
import solicitud.SolicitudDeCredito;

public class Cliente {

	private String nyAp;
	private Integer direccion;
	private Float sueldoNetoMensual;
	private Integer edad;
	private Banco banco;
	private ArrayList<SolicitudDeCredito> solicitudes;

	public Cliente(String nombre, Integer dir, Float sueldo, Integer age, Banco bank){
		this.setNyAp(nombre);
		this.setDireccion(dir);
		this.sueldoNetoMensual = sueldo;
		this.edad = age;
		this.banco = bank;
		this.solicitudes = new ArrayList<SolicitudDeCredito>();
	}

	public Float sueldoNetoAnual() {
		return this.sueldoNetoMensual * 12;
	}

	public Float getIngresoMensual() {
		return this.sueldoNetoMensual;
	}

	public Integer getEdad() {
		return this.edad;
	}
	
	public void setBanco(Banco bank){
		this.banco = bank;
	}

	public void solicitarCreditoPersonal(Float monto, Integer cuotas) {
		CreditoPersonal credito;
		credito = new CreditoPersonal(monto,cuotas,this);
				
		this.banco.agregarSolicitud(credito);
		this.solicitudes.add(credito);
	}
	
	public void solicitarCreditoHipotecario(Float monto, Integer cuotas, 
											PropiedadInmobiliaria garantia) {
		CreditoHipotecario credito;
		credito = new CreditoHipotecario(monto,cuotas,this,garantia);
				
		this.banco.agregarSolicitud(credito);
		this.solicitudes.add(credito);
	}

	public ArrayList<SolicitudDeCredito> getSolicitudes() {
		return this.solicitudes;
	}

	public String getNyAp() {
		return nyAp;
	}

	public void setNyAp(String nyAp) {
		this.nyAp = nyAp;
	}

	public Integer getDireccion() {
		return direccion;
	}

	public void setDireccion(Integer direccion) {
		this.direccion = direccion;
	}
}
