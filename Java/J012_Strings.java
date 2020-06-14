package Java_Sandbox;

/*
 * Strings are a sequence of characters. In Java programming language, strings are treated as objects.
 * The Java platform provides the String class to create and manipulate strings.
 */

public class J012_Strings {

	public static void main(String[] args) {
		
		/* Normal Constructor */
		String str = "Hello!";
		System.out.println(str); 
		System.out.print("\n");
		
		/* String(char[] value) */
		char[] helloArray = { 'H', 'e', 'l', 'l', 'o', '.' };
		String helloString = new String(helloArray);  
		System.out.println(helloString);
		System.out.print("\n");
		
		/* length() */
		String palindrome = "Dot saw I was Tod";
		int len = palindrome.length();
		System.out.println("palindrome = " + palindrome);
		System.out.println("String Length = " + len);
		System.out.print("\n");
		
		/* concat() */
		String str1 = "2020 ";
		String str2 = "Java Tutorial";
		str1 = str1.concat(str2);
		str2 = "Java Tutorial ".concat("2020");
		System.out.println("str1 = " + str1);
		System.out.println("str2 = " + str2);
		System.out.print("\n");
		
		/* + <=> concat() */
		String str3 = "saw I was ";
		System.out.println("Tod " + str3 + "Dot");
		System.out.print("\n");
		
		/* printf() */
		int i = 100;
		float f = 3.14f;
		String str4 = "2020"; 
		System.out.printf("i = %d; f = %f; str4 = %s\n", i, f, str4);
		System.out.print("\n");
		
		/* format() */
		i = -7;
		f = 2.22f;
		str4 = "2021"; 
		System.out.format("i = %d; f = %f; str4 = %s\n", i, f, str4);
		String str5 = String.format("i = %d; f = %f; str4 = %s", i, f, str4);
		System.out.printf("str5 = \"%s\"\n", str5);
		System.out.print("\n");
		
		/* charAt() */
		String str6 = "Strings are immutable";
		char index = str6.charAt(8);
		System.out.println(index);
		System.out.print("\n");
		
		/* compareTo() */
		String str7 = new String(str6);
		String str8 = new String("Integers are not immutable");
	      
		int result = str6.compareTo(str7);
		System.out.println(result);
	      
		result = str6.compareTo(str8);
		System.out.println(result);
		System.out.print("\n");
		
		/* equals() */
		System.out.println("str6.equals(str7) = " + str6.equals(str7));
		System.out.println("str6.equals(str8) = " + str6.equals(str8));
		System.out.print("\n");
		
		/* split() */
		String str9 = "Welcome to the Jungle";    
	      
		for (String tmp: str9.split(" ")) {
			System.out.println(tmp);
		}
		System.out.print("\n");
		
		/* toLowerCase() */
		System.out.println(str9.toLowerCase());
		System.out.print("\n");
		
		/* toUpperCase() */
		System.out.println(str9.toUpperCase());
		System.out.print("\n");
	}
}
