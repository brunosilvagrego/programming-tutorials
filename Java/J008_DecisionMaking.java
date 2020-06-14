package Java_Sandbox;

public class J008_DecisionMaking {

	public static void main(String[] args) {
		
		int x = 30;

		/* if ... else */
		if (x == 10) {
			System.out.print("x = 10");
		}
		else if (x == 20) {
			System.out.print("x = 20");
		}
		else if (x == 30) {
			System.out.print("x = 30");
		}
		else {
			System.out.print("x value doesn't match any option");
		}
		
		System.out.print("\n\n");
		
		/* Switch Case */
		char grade = 'C';

		switch(grade) {
			case 'A' :
				System.out.println("Excellent!"); 
				break;
			case 'B' :	// If no break appears, the flow of control will fall through to subsequent cases until a break is reached
			case 'C' :
				System.out.println("Well done");
				break;
			case 'D' :
				System.out.println("You passed");
				break;
			case 'F' :
				System.out.println("Better try again");
				break;
			default :
				System.out.println("Invalid grade");
		}
		
		System.out.println("Your grade: " + grade + "\n");
		
		/* Conditional Operator */
		grade = 'A';
		System.out.println((grade == 'A') ? "Excellent!" : "You passed");
		System.out.println("Your grade: " + grade);
	}
}
