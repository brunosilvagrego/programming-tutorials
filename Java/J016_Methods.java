package Java_Sandbox;


/*
 * A Java method is a collection of statements that are grouped together to perform an operation.
 */

public class J016_Methods {
	
	// Passing parameters by value; returns int.
	public static int min (int n1, int n2) {
		
		int min;
		   
		if (n1 > n2) {
			min = n2;
		}
		else {
			min = n1;
		}

		return min;
	}
	
	/* Method Overloading */
	// Passing parameters by value; returns double.
	public static double min (double n1, double n2) {
		
		double min;
		   
		if (n1 > n2) {
			min = n2;
		}
		else {
			min = n1;
		}

		return min;
	}
	
	// Passing parameter by value; returns void. 
	public static void RankPoints (double points) {
		if (points >= 202.5) {
			System.out.println("Rank: A1");
		}
		else if (points >= 122.4) {
			System.out.println("Rank: A2");
		}
		else {
			System.out.println("Rank: A3");
		}
	}
	
	/*
	 * Java is pass by value and it is not possible to pass integer by reference in Java directly.
	 * This can be achieved indirectly by creating a Wrapper Class or by wrapping the variable using an array of length one. 
	 */
	
	// Passing parameter by reference; returns void.
	public static void increment (int[] array) 
    { 
        // increment in the actual value 
        array[0]++; 
    }
	
	/*
	 * Variable Arguments:
	 * JDK 1.5 enables you to pass a variable number of arguments of the same type to a method.
	 * In the method declaration, you specify the type followed by an ellipsis (...).
	 * Only one variable-length parameter may be specified in a method, and this parameter must be the last parameter.
	 * Any regular parameters must precede it.
	 */
	
	// Passing parameters by value; returns void.
	public static void printMax (double... numbers) {
		
		if (numbers.length == 0) {
			System.out.println("No arguments passed");
			return;
		}

		double result = numbers[0];

		for (int i = 1; i <  numbers.length; i++) {
			if (numbers[i] >  result) {
				result = numbers[i];
			}
		}
		
		System.out.println("Max value = " + result);
	}
	
	
	public static void main(String[] args) {
		
		/* min() */
		int a = 11;
		int b = 6;
		System.out.printf("min(%d, %d) = %d\n", a, b, min(a, b));
		System.out.print("\n");
		
		double c = 3.1415;
		double d = 0.9198;
		System.out.printf("min(%.4f; %.4f) = %.4f\n", c, d, min(c, d));
		System.out.print("\n");
		
		/* RankPoints() */
		RankPoints(255.7);
		System.out.print("\n");
		
		/* increment() */
		// Original variable
		int k = 100;
		
		// Wrapping is done by using an array of length one 
        int[] array = {k}; 
  
        // Reference is passed 
        increment(array);
  
        // Incremented value printed
        System.out.println("k   = " + k);
        System.out.println("k++ = " + array[0]);
		System.out.print("\n");
		
		/* Using Command-Line Arguments */
		for (int i = 0; i < args.length; i++) {
			System.out.println("args[" + i + "]: " +  args[i]);
		}
		
		System.out.print("\n");
		
		/* Class Student */
		Student st = new Student(20);
		System.out.println("Student age: " + st.getAge());
		System.out.print("\n");
		
		/* printMax() */
		printMax(34, 3, 4.5, 2, 56.5);
		System.out.print("\n");
	}
}


class Student {
	
	int age;   
	
	/*
	 * 'this' is a keyword in Java which is used as a reference to the object of the current class, with in an instance
	 * method or a constructor. 'this' can refer the members of a class such as constructors, variables and methods. 
	 */
	
	Student(int age) {
		this.age = age;	
	}
	
	public int getAge() {
		return this.age;
	}
	
	/*
	 * It is possible to define a method that will be called just before an object's final destruction by the garbage collector.
	 * This method is called finalize(), and it can be used to ensure that an object terminates cleanly.
	 * For example, you might use finalize() to make sure that an open file owned by that object is closed.
	 * You cannot know when or even if finalize() will be executed. If your program ends before garbage collection occurs,
	 * finalize() will not execute.
	 */
	
	protected void finalize( ) {
		// finalization code here
	}
}