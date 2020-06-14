package Java_Sandbox;

/*
 * Variables of a class too can have another class as its member. Writing a class within another is allowed in Java.
 * The class written within is called the nested class, and the class that holds the inner class is called the outer class.
 */

public class J019_InnerClass {
		
	public static void main(String[] args) {
		
		// Instantiating the outer class 
		OuterClass outer = new OuterClass();
	      
		// Accessing the display_Inner() method.
		outer.displayInner();
	      
        System.out.print("\n");
        
	}	
}


class OuterClass {
	int num;
	   
	// Inner Class
	private class InnerClass {
		public void print() {
			System.out.println("This is an inner class");
		}
	}
	   
	// Accessing he inner class from the method within
	void displayInner() {
		InnerClass inner = new InnerClass();
		inner.print();
	}
}