package Java_Sandbox;

import java.io.*;
import java.util.Scanner;

/*
 * An exception (or exceptional event) is a problem that arises during the execution of a program. When an Exception occurs
 * the normal flow of the program is disrupted and the program/application terminates abnormally, which is not recommended.
 * Therefore, these exceptions need to be handled.
 * 
 * Errors are not exceptions, they are problems that arise beyond the control of the user or the programmer. Errors are
 * typically ignored in your code because you can rarely do anything about an error. For example, if a stack overflow occurs,
 * an error will arise. They are also ignored at the time of compilation.
 */

public class J018_Exceptions {
		
	public static void main(String[] args) {
		
		/* Catching Exceptions */
		int a[] = new int[2];
		
		try {
			
			System.out.println("Access element three :" + a[3]);
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Exception thrown -> " + e);
		}

		System.out.print("\n");
	    
		/* Multiple Catch Blocks */
		Scanner scn = new Scanner(System.in); 
        try
        { 
        	System.out.print("Please, enter a number: ");
        	
            int n = Integer.parseInt(scn.nextLine());
            
            if (99%n == 0) {
            	System.out.println(n + " is a factor of 99");
            }
            else {
            	System.out.println(n + " is not a factor of 99");
            }
        }
        catch (ArithmeticException ex) 
        { 
        	System.out.println("Arithmetic Exception -> " + ex); 
        } 
        catch (NumberFormatException ex) 
        { 
        	System.out.println("Number Format Exception -> " + ex); 
        }
        finally {	// The finally block always executes, regardless of the occurrence of an exception
        	scn.close();
        }
        
        System.out.print("\n");
        
        /* User-defined Exception */
        CheckingAccount c = new CheckingAccount(101);
        System.out.println("Depositing $500");
        c.deposit(500.00);
        
        try {
        	System.out.println("\nWithdrawing $100");
        	c.withdraw(100.00);
        	System.out.println("\nWithdrawing $600\n");
        	c.withdraw(600.00);
        }
        catch (InsufficientFundsException e) {
    		System.out.println("You would need more $" + e.getAmount() + " to make this withdrawal");
    		System.out.println("Current balance = $" + c.getBalance());
    		e.printStackTrace();
        }
        
        System.out.print("\nProgram End.\n");
	}	
}


class InsufficientFundsException extends Exception {
	private double amount;
	   
	public InsufficientFundsException (double amount) {
		this.amount = amount;
	}
	   
	public double getAmount() {
		return amount;
	}
}

class CheckingAccount {
	   
	private double balance;
	private int number;
	   
	public CheckingAccount (int number) {
		this.number = number;
	}
	   
	public void deposit (double amount) {
		balance += amount;
	}
	
	/*
	 * 'throws' is used to postpone the handling of a checked exception and 'throw' is used to invoke an exception explicitly.
	 * A method can declare that it throws more than one exception, in which case the exceptions are declared in a list
	 * separated by commas.
	 */
	public void withdraw (double amount) throws InsufficientFundsException {
		
		if(amount <= balance) {
			balance -= amount;
		}
		else {
			double needs = amount - balance;
			throw new InsufficientFundsException(needs);
		}
	}
	   
	public double getBalance() {
		return balance;
	}
   
	public int getNumber() {
		return number;
	}
}