package Java_Sandbox;

public class J011_Characters {

	public static void main(String[] args) {
		
		/* Primitive data type char */
		// Unicode for uppercase Greek omega character
		char c = '\u039A';
		System.out.println(c); 
		System.out.print("\n");
		
		/* Character Object */
		Character ch = 'a';
		System.out.println(ch); 
		System.out.print("\n");
		
		/* isLetter() */
		System.out.println(Character.isLetter('c'));
		System.out.println(Character.isLetter('5'));
		System.out.print("\n");
		
		/* isDigit() */
		System.out.println(Character.isDigit('c'));
		System.out.println(Character.isDigit('5'));
		System.out.print("\n");
		
		/* isWhitespace() */
		System.out.println(Character.isWhitespace('c'));
		System.out.println(Character.isWhitespace(' '));
		System.out.println(Character.isWhitespace('\n'));
		System.out.println(Character.isWhitespace('\t'));
		System.out.print("\n");
		
		/* isUpperCase() */
		System.out.println(Character.isUpperCase('c'));
		System.out.println(Character.isUpperCase('C'));
		System.out.print("\n");
		
		/* isLowerCase() */
		System.out.println(Character.isLowerCase('c'));
		System.out.println(Character.isLowerCase('C'));
		System.out.print("\n");
		
		/* toUpperCase() */
		System.out.println(Character.toUpperCase('c'));
		System.out.println(Character.toUpperCase('C'));
		System.out.print("\n");
		
		/* toLowerCase() */
		System.out.println(Character.toLowerCase('c'));
		System.out.println(Character.toLowerCase('C'));
		System.out.print("\n");
		
		/* toString() */
		System.out.println(Character.toString('c'));
		System.out.println(Character.toString('C'));
		System.out.print("\n");
	}
}
