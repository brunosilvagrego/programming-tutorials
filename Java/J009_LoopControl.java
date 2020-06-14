package Java_Sandbox;

public class J009_LoopControl {

	public static void main(String[] args) {
		
		/* while */
		int x = 10;

		while (x < 20) {
			System.out.println("x = " + x);
			x++;
		}
		
		System.out.print("\n");
		
		/* do ... while */
		do {
			System.out.println("x = " + x);
			x--;
		} while (x >= 10);
		
		System.out.print("\n");
		
		/* for */
		for (x = 0; x <= 10; ++x) {
			System.out.println("x = " + x);
		}
		
		System.out.print("\n");
		
		/* Enhanced for loop */
		String [] names = {"James", "Larry", "Tom", "Lacy"};

		for (String name : names) {
			System.out.println(name);
		}
	}
}
