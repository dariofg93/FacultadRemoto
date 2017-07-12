package punto;

public class Point {

	Integer ancho;
	Integer altura;
	
	public Point(){
		this.ancho = 0;
		this.altura = 0;
	}
	
	public Point(Integer x, Integer y){
		this.ancho = x;
		this.altura = y;
	}
	
	public Integer getX(){
		return this.ancho;
	}
	
	public Integer getY(){
		return this.altura;
	}
	
	public void moverPosicion(Integer x, Integer y){
		this.ancho = x;
		this.altura = y;
	}
}
