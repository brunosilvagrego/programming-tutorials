package Java_Sandbox;


public class J005_VariableTypes {

	public static void main(String args[]) {
		
		/*
		 * Local variables are created when the method, constructor or block is entered and the variable will be
		 * destroyed once it exits the method, constructor, or block.
		 */
		
		// emp1 is a local variable 
		Employee emp1 = new Employee("Bruno");
		
		emp1.setSalary(1000);
		
		emp1.printEmp();
	}
}


class Employee {
	
	// This instance variable is visible for any child class
	public String name;

	// This instance variable is visible in Employee class only
	private double salary;
	
	/*
	 * Class variables, also known as static variables are declared with the static keyword in a class, but outside a
	 * method, constructor or a block.
	 * 
	 * There is only one copy of each class variable per class, regardless of how many objects are created from it.
	 * 
	 * Static variables are rarely used other than being declared as constants. Constants are variables that are declared
	 * as public/private, final, and static. Constant variables never change from their initial value.
	 * 
	 * Static variables are stored in the static memory. It is rare to use static variables other than declared final and
	 * used as either public or private constants.
	 */
	
	// DEPARTMENT is a constant public static variable
	public static final String DEPARTMENT = "Development";

	// The name variable is assigned in the constructor.
	public Employee (String empName) {
		name = empName;
	}

	// The salary variable is assigned a value
	public void setSalary(double empSal) {
		salary = empSal;
	}

	// This method prints the employee details.
	public void printEmp() {
		System.out.println("Name:       " + name);
		System.out.println("Salary:     " + salary);
		System.out.println("Department: " + DEPARTMENT);
	}
}