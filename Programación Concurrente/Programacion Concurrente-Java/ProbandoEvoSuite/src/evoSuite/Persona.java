package evoSuite;

public class Persona {

	String name;
	Integer edad;
	Boolean esCasado;
	Float sueldo;
	
	public Persona(String aName, Integer age, Boolean estadoCivil, Float unSueldo){
		this.name = aName;
		this.edad = age;
		this.esCasado = estadoCivil;
		this.sueldo = unSueldo;
	}
	
	public Float sueldoAnual(){
		return this.sueldo * 12;
	}
}
