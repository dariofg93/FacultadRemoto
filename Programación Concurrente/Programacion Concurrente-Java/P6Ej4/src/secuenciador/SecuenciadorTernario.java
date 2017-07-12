package secuenciador;

public class SecuenciadorTernario {
	
	private Integer current = 0;

	private  void primero(){
		System.out.println("Hola soy Primero");
	}
	private  void segundo(){
		System.out.println("Hola soy Segundo");
	}
	private  void tercero(){
		System.out.println("Hola soy Tercero");
	}
	
	public void secuencia(){
		 switch (current) {
         	case 0: this.primero();
			 		current = (current + 1) % 3;
			 		break;
         	case 1: this.segundo();
			 		current = (current + 1) % 3;
			 		break;
         	case 2: this.tercero();
         			current = (current + 1) % 3;
	 		 		break;
		 }
	}
}
