package Java_Sandbox;


public class J002_ClassDog {

	public static void main(String args[]) {	
		
		/* Object creation */
		Dog Dog1 = new Dog("Spark", 2);

		/* Call class method to get Dog's name */
		System.out.println("Dog name: " + Dog1.getName());
		
		/* Call class method to get Dog's age */
		System.out.println("Dog age:  " + Dog1.getAge() + "\n");
		
		/* Object creation */
		Dog Dog2 = new Dog();
		
		Dog2.setName("Thunder");
		Dog2.setAge(3);

		/* Call class method to get Dog's name */
		System.out.println("Dog name: " + Dog2.getName());
		
		/* Call class method to get Dog's age */
		System.out.println("Dog age:  " + Dog2.getAge());
	}
}


class Dog {
	
	private String dogName; 
	private int dogAge;

	/*
	 * All classes have constructors, whether you define one or not, because Java automatically provides a default constructor
	 * that initializes all member variables to zero. However, once you define your own constructor, the default constructor
	 * is no longer used.
	 */
	
	// No argument Constructor
	public Dog () {
		System.out.println("Dog object was created");
	}
	
	// Parameterized Constructor
	public Dog (String name, int age) {
		dogName = name;
		dogAge = age;
		System.out.println("Dog object was created");
	}

	public String getName() {
		return dogName;
	}
	
	public int getAge() {
		return dogAge;
	}
	
	public void setAge(int age) {
		dogAge = age;
	}
	
	public void setName(String name) {
		dogName = name;
	}
}