/**
 * 
 */
package intro_algoritmos;

/**
 * @author Gabriel May
 *
 */
public class VariablesInJava {

	
	public static void main(String[] args) {
		
		int number= 10;
		String nome = "Gabriel May";//string aspas duplas (e com S maísculo)
		char letra = 'G';//char, aspas unicas
		float decimal= 1.5f;// f no final para indicar float 
		boolean bool = true;// bool é boolean em Java ( nome mais completo )
		
		
		//print funciona basicamente igual ao Python, porém com:   System.out.println
		System.out.println(number +  "\n" + nome + "\n" + letra + "\n" + decimal + "\n" + bool);
		
		/*
		 *  byte (number, 1 byte)
			short (number, 2 bytes)
			int (number, 4 bytes)
			long (number, 8 bytes)
			
			float (float number, 4 bytes)
			double (float number, 8 bytes)
			
			char (a character, 2 bytes)
			
			boolean (true or false, 1 byte)
			
					 */
		
	}

}