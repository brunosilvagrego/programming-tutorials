package Java_Sandbox;

/*
 * Access Modifiers:
 * default   -> Visible to the package, no modifiers are needed.
 * public    -> Visible to the program.
 * protected -> Visible to the package and all subclasses.
 * private   -> Visible to the class only.
 * 
 * Methods declared public in a superclass also must be public in all subclasses.
 * Methods declared protected in a superclass must either be protected or public in subclasses; they cannot be private.
 * Methods declared private are not inherited.
 */

/*
 * Non-Access Modifiers:
 * static       -> Used for creating class methods and variables.
 * final        -> Used for finalizing the implementations of classes, methods, and variables.
 * abstract     -> Used for creating abstract classes and methods.
 * synchronized -> Used for threads.
 * volatile     -> Used for threads.
 */


/*
 * If a class is marked as final then no class can inherit any feature from the final class.
 */
public final class J006_ModifierTypes {
	
	/*
	 * A final variable can be explicitly initialized only once. A reference variable declared final can never be reassigned
	 * to refer to a different object.
	 */
	static final int n = 50;
	
	public static void main(String args[]) {
		
		System.out.println("Starting with " + InstanceCounter.getCount() + " instances");

		for (int i = 0; i < n; ++i) {
			new InstanceCounter();
		}
		
		System.out.println("Created " + InstanceCounter.getCount() + " instances");
		
		InstanceCounter.printCount();
		
		SubClass tmp = new SubClass();
		tmp.printHello();
	}
}


class InstanceCounter {
	
	/*
	 * The static keyword is used to create variables that will exist independently of any instances created for the class.
	 * Only one copy of the static variable exists regardless of the number of instances of the class.
	 * Static variables are also known as class variables. Local variables cannot be declared static.
	 */
	private static int numInstances = 0;

	/*
	 * The static keyword is used to create methods that will exist independently of any instances created for the class.
	 */
	protected static int getCount() {
		return numInstances;
	}

	/*
	 * Methods, variables, and constructors that are declared private can only be accessed within the declared class itself.
	 */
	private static void addInstance() {
		numInstances++;
	}

	InstanceCounter() {
		InstanceCounter.addInstance();
	}
	
	/*
	 * A final method cannot be overridden by any subclasses.
	 */
	public static final void printCount() {
		System.out.println("Instances = " + numInstances);
	}
}


/*
 * An abstract class can never be instantiated. If a class is declared as abstract then the sole purpose is for
 * the class to be extended.
 */
abstract class SuperClass {
	
	/*
	 * An abstract method is a method declared without any implementation. The methods body (implementation) is
	 * provided by the subclass. Abstract methods can never be final or strict.
	 */
	abstract void printHello();
}


class SubClass extends SuperClass {
	
	/*
	 * Any class that extends an abstract class must implement all the abstract methods of the super class,
	 * unless the subclass is also an abstract class.
	 */
	void printHello() {
		System.out.println("\nHello!");
	}
	
	/*
	 * A class, method, constructor, interface, etc. declared public can be accessed from any other class.
	 */
	public synchronized void showDetails() {
		/*
		 * The synchronized keyword used to indicate that a method can be accessed by only one thread at a time.
		 * The synchronized modifier can be applied with any of the four access level modifiers.
		 */
	}
	
	/*
	 * An instance variable is marked transient to indicate the JVM to skip the particular variable when serializing
	 * the object containing it.
	 */
	public transient int a = 55;	// will not persist
	public int b;   				// will persist
}


class MyRunnable implements Runnable {
	
	/*
	 * The volatile modifier is used to let the JVM know that a thread accessing the variable must always merge
	 * its own private copy of the variable with the master copy in the memory.
	 */
	private volatile boolean active;

	/*
	 * Usually, run() is called in one thread (the one you start using the Runnable), and stop() is called from another thread.
	 */
	public void run() {
		active = true;
		
		while (active) {	// line 1
			// Tasks
		}
	}

	public void stop() {
		active = false;   	// line 2
	}
}