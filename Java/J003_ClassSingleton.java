package Java_Sandbox;


public class TestClass {

	public static void main(String args[]) {	
		Singleton tmp = Singleton.getInstance();
		tmp.demoMethod();
	}
}

/*
 * The Singleton's purpose is to control object creation, limiting the number of objects to only one. Since there is only
 * one Singleton instance, any instance fields of a Singleton will occur only once per class, like static fields.
 * 
 * Singletons often control access to resources, such as database connections or sockets. For example, if you have a license
 * for only one connection for your database or your JDBC driver has trouble with multithreading, the Singleton makes sure
 * that only one connection is made or that only one thread can access the connection at a time.
 */

class Singleton {

	private static Singleton instance = null;
	private Singleton() {
		// Exists only to defeat instantiation.
	}

	public static Singleton getInstance() {
		if(instance == null) {
			instance = new Singleton();
		}
		
		return instance;
	}
	
	/* Other methods protected by singleton-ness */
	protected void demoMethod() {
		System.out.println("Hello Singleton");
	}
}