package Java_Sandbox;

import java.util.*;
import java.text.*;

public class J014_DateTime {
	
	public static void main(String[] args) {
		
		/* Date() */
		// Instantiate a Date object
		Date date = new Date();

		// display time and date using toString()
		System.out.println("Date(): " + date.toString());
		System.out.print("\n");
		
		/* SimpleDateFormat() */
		SimpleDateFormat ft = new SimpleDateFormat("E yyyy/MM/dd 'at' hh:mm:ss a zzz");

		System.out.println("SimpleDateFormat(): " + ft.format(date));
		System.out.print("\n");
		
		/* Date with printf() */
		System.out.printf("Date with printf(): %tc\n", date);
		System.out.printf("%1$s %2$tB %2$td, %2$tY\n", "Date with printf():", date);
		System.out.printf("%s %tB %<te, %<tY\n", "Date with printf():", date);
		System.out.print("\n");
		
		/* Parsing String into Date */
		SimpleDateFormat sdt = new SimpleDateFormat ("yyyy-MM-dd"); 
		String input = args.length == 0 ? "1993-04-28" : args[0]; 

		System.out.print(input + " => Parses as: "); 
	      
		try {
			Date t;
			t = sdt.parse(input); 
			System.out.println(t); 
		}
		catch (ParseException e) { 
			System.out.println("Unparseable using " + sdt); 
		}
		
		System.out.print("\n");
		
		/* Thread.sleep() */
		try { 
			System.out.println(new Date( ) + "\n"); 
			Thread.sleep(1000);	// milliseconds
			System.out.println(new Date( ) + "\n"); 
		}
		catch (Exception e) {
			System.out.println("Exception!"); 
		}
		
		/* Measuring Elapsed Time */
		try {
			long start = System.currentTimeMillis( );
	         
			Thread.sleep(2000);	// milliseconds
			System.out.println(new Date( ) + "\n");
	         
			long end = System.currentTimeMillis( );
			long diff = end - start;
			System.out.println("Elapsed Time = " + diff + " milliseconds\n");
		}
		catch (Exception e) {
			System.out.println("Exception!"); 
		}
		
		/* GregorianCalendar() */
		String months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		      
		int year;
		      
		// Create a Gregorian calendar initialized with the current date and time in the default locale and timezone
		GregorianCalendar gcalendar = new GregorianCalendar();
		      
		// Display current time and date information.
		System.out.print("Date: ");
		System.out.print(months[gcalendar.get(Calendar.MONTH)]);
		System.out.print(" " + gcalendar.get(Calendar.DATE) + " ");
		System.out.println(year = gcalendar.get(Calendar.YEAR));
		System.out.print("Time: ");
		System.out.print(gcalendar.get(Calendar.HOUR) + ":");
		System.out.print(gcalendar.get(Calendar.MINUTE) + ":");
		System.out.println(gcalendar.get(Calendar.SECOND));

		// Test if the current year is a leap year
		if (gcalendar.isLeapYear(year)) {
			System.out.println("The current year is a leap year");
		}
		else {
			System.out.println("The current year is not a leap year");
		}
	}
}
