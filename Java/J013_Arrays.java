package Java_Sandbox;

import java.util.Arrays;

/*
 * An array stores a fixed-size sequential collection of elements of the same type.
 */

public class J013_Arrays {

	public static void printArray (int[] array) {
		
		for (int i = 0; i < array.length; i++) {
			System.out.println(array[i]);
		}
	}
	
	public static int[] reverseArray (int[] array) {
		
		int[] result = new int[array.length];

		for (int i = 0, j = result.length - 1; i < array.length; i++, j--) {
			result[j] = array[i];
		}
		
		return result;
	}
	
	public static void main(String[] args) {
		
		/* Array declaration and definition */
		int i;
		double[] myList = {3.9, 1.9, 2.4, 6.5, 5.4, 4.3};

		/* Print all array elements */
		for (i = 0; i < myList.length; i++) {
			
			if (i == myList.length-1)
			{
				System.out.print(myList[i]);
			}
			else
			{
				System.out.print(myList[i] + ", ");
			}
		}
		
		System.out.print("\n\n");
		
		/* Print all array elements with for each loop */
		for (double element : myList) {
			System.out.println(element);
		}
		
		System.out.print("\n");
	    
		/* Summing all elements */
		double total = 0;
		
		for (i = 0; i < myList.length; i++) {
			total += myList[i];
		}
		
		System.out.printf("Total = %.2f\n", total);
		System.out.print("\n");
	      
		/* Finding the largest element */
		double max = myList[0];
		
		for (i = 1; i < myList.length; i++) {
			if (myList[i] > max)
			{
				max = myList[i];
			}
		}
		
		System.out.println("Max = " + max);
		System.out.print("\n");
		
		/* Passing an Array to a Method */
		int[] a1 = {3, 1, 2, 6, 5, 4};
		printArray(a1);
		System.out.print("\n");
		
		/* Returning an Array from a Method */
		int[] a2 = reverseArray(a1);
		printArray(a2);
		System.out.print("\n");
		
		/* Arrays.sort() */
		Arrays.sort(a1);
		printArray(a1);
		System.out.print("\n");
		
		Arrays.sort(a2);
		printArray(a2);
		System.out.print("\n");
		
		/* Arrays.equals() */
		System.out.print("Arrays.equals(a1, a2) = " + Arrays.equals(a1, a2));
		System.out.print("\n\n");
		
		/* Arrays.binarySearch() */
		System.out.print("Arrays.binarySearch(a1, 3) = " + Arrays.binarySearch(a1, 3));
		System.out.print("\n\n");
		
		/* Arrays.fill() */
		Arrays.fill(a1, 10);
		System.out.println("Arrays.fill(a1, 10):");
		printArray(a1);
		System.out.print("\n");
	}
}
