package Java_Sandbox;

public class J007_BasicTypes {

	public static void main(String[] args) {
		
		/* Arithmetic Operators */
		int a = 10;
		int b = 20;
		int c = 25;
		int d = 25;
		
		System.out.println("\nArithmetic Operators:");
		System.out.println("a + b = " + (a + b));
		System.out.println("a - b = " + (a - b));
		System.out.println("a * b = " + (a * b));
		System.out.println("b / a = " + (b / a));
		System.out.println("b % a = " + (b % a));
		System.out.println("c % a = " + (c % a));
		System.out.println("++a   = " + (++a));
		System.out.println("--b   = " + (--b));
		System.out.println("d++   = " + (d++));
		System.out.println("++d   = " + (++d));
		
		/* Relational Operators */
		System.out.println("\nRelational Operators:");
		System.out.println("a == b = " + (a == b));
		System.out.println("a != b = " + (a != b));
		System.out.println("a > b  = " + (a > b));
		System.out.println("a < b  = " + (a < b));
		System.out.println("b >= a = " + (b >= a));
		System.out.println("b <= a = " + (b <= a));
		
	    /* Bitwise Operators */
		a = 60;	/* 60 = 0011 1100 */
	    b = 13;	/* 13 = 0000 1101 */
	    c = 0;
	    
		System.out.println("\nBitwise Operators:");

		c = a & b;        /* 12 = 0000 1100 */
		System.out.println("a & b   = " + c );

		c = a | b;        /* 61 = 0011 1101 */
		System.out.println("a | b   = " + c );

		c = a ^ b;        /* 49 = 0011 0001 */
		System.out.println("a ^ b   = " + c );

		c = ~a;           /*-61 = 1100 0011 */
		System.out.println("~a      = " + c );

		c = a << 2;       /* 240 = 1111 0000 */
		System.out.println("a << 2  = " + c );

		c = a >> 2;       /* 15 = 1111 */
		System.out.println("a >> 2  = " + c );

		// Zero fill right shift
		c = a >>> 2;      /* 15 = 0000 1111 */
		System.out.println("a >>> 2 = " + c );
		
		/* Logical Operators */
		boolean x = true;
		boolean y = false;
		
		System.out.println("\nLogical Operators:");
		System.out.println("x && y    = " + (x && y));
		System.out.println("x || y    = " + (x || y) );
		System.out.println("!(x && y) = " + !(x && y));
		
		/* Assignment Operators */
		System.out.println("\nAssignment Operators:");
		
		a = 10;
	    b = 20;
	    c = 0;

	    c += a ;
	    System.out.println("c += a  = " + c );

	    c -= a ;
	    System.out.println("c -= a  = " + c );

	    c *= a ;
	    System.out.println("c *= a  = " + c );

	    a = 10;
	    c = 15;
	    c /= a ;
	    System.out.println("c /= a  = " + c );

	    a = 10;
	    c = 15;
	    c %= a ;
	    System.out.println("c %= a  = " + c );

	    c <<= 2 ;
	    System.out.println("c <<= 2 = " + c );

	    c >>= 2 ;
	    System.out.println("c >>= 2 = " + c );
      
	    c >>= 2 ;
	    System.out.println("c >>= 2 = " + c );

	    c &= a ;
	    System.out.println("c &= a  = " + c );

	    c ^= a ;
	    System.out.println("c ^= a  = " + c );

	    c |= a ;
	    System.out.println("c |= a  = " + c );
	    
	    /* Conditional Operator */
		System.out.println("\nConditional Operator:");
		
	    a = 10;
	    b = (a == 1) ? 20: 30;
	    System.out.println( "b = " +  b );

	    b = (a == 10) ? 20: 30;
	    System.out.println( "b = " +  b );
	    
	    /* instanceof Operator */
		System.out.println("\ninstanceof Operator:");

		String name = "James";
		boolean result = name instanceof String;
		System.out.println(result);
	}
}
