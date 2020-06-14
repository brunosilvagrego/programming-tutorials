package Java_Sandbox;

public class J010_Numbers {

	public static void main(String[] args) {
		
		/* typeValue() */
		Integer x = 5;
	      
		// Returns byte primitive data type
		System.out.println(x.byteValue());
	
		// Returns double primitive data type
		System.out.println(x.doubleValue());
		System.out.print("\n");
		
		/* compareTo() */
		System.out.println(x.compareTo(3));
		System.out.println(x.compareTo(5));
		System.out.println(x.compareTo(8)); 
		System.out.print("\n");
		
		/* equals() */
		System.out.println(x.equals(10));
		System.out.print("\n");
		
		/* valueOf() */
		Integer i = Integer.valueOf(9);
		Double d = Double.valueOf(5);
		Float f = Float.valueOf("80");          
		// static Integer valueOf(String s, int radix) -> radix = base 8, base 10, base 16
		Integer i2 = Integer.valueOf("444", 16);

		System.out.println(i); 
		System.out.println(d);
		System.out.println(f);
		System.out.println(i2);
		System.out.print("\n");
		
		/* toString() */
		System.out.println(x.toString());  
		System.out.println(Integer.toString(12));
		System.out.print("\n");
		
		/* parseType() */
		i = Integer.parseInt("9");
		d = Double.parseDouble("5");
		i2 = Integer.parseInt("444", 8);

		System.out.println(i);
		System.out.println(d);
		System.out.println(i2);
		System.out.print("\n");
		
		/* abs() */
		i = -8;
		d = -100.675;
		f = -90.0f;

		System.out.println(Math.abs(i));
		System.out.println(Math.abs(d));     
		System.out.println(Math.abs(f));
		System.out.print("\n");
		
		/* ceil() */
		System.out.println(Math.ceil(d));
		System.out.println(Math.ceil(f));
		System.out.print("\n");

		/* floor() */
		System.out.println(Math.floor(d));
		System.out.println(Math.floor(f));
		System.out.print("\n");
		
		/* rint() */
		d = 100.675;
		System.out.println(Math.rint(d));
		d = 100.500;
		System.out.println(Math.rint(d));
		d = 100.200;
		System.out.println(Math.rint(d));
		System.out.print("\n");
		
		/* max() */
		System.out.println(Math.max(12.123, 12.456));      
		System.out.println(Math.max(23.12, 23.0));
		System.out.print("\n");
		
		/* exp() */
		d = 2.5;
		System.out.printf("e = %.4f\n", Math.E);
		System.out.printf("exp(%.3f) = %.3f\n", d, Math.exp(d));
		System.out.print("\n");
		
		/* log() */
		System.out.printf("log(%.3f) = %.3f\n", d, Math.log(d));
		System.out.print("\n");
		
		/* pow() */
		double e = 2;
		System.out.printf("pow(%.3f, %.3f) = %.3f\n", d, e, Math.pow(d, e));
		System.out.print("\n");
		
		/* sqrt() */
		System.out.printf("sqrt(%.3f) = %.3f\n", d, Math.sqrt(d));
		System.out.print("\n");
		
		/* sin() */
		double degrees = 45.0;
		double radians = Math.toRadians(degrees);

		System.out.printf("PI = %.6f\n", Math.PI);
		System.out.printf("sin(%.1f) = %.4f\n", degrees, Math.sin(radians));
		System.out.print("\n");
		
		/* cos() */
		System.out.printf("cos(%.1f) = %.4f\n", degrees, Math.cos(radians));
		System.out.print("\n");
		
		/* tan() */
		System.out.printf("tan(%.1f) = %.4f\n", degrees, Math.tan(radians));
		System.out.print("\n");
		
		/* asin() */
		System.out.printf("asin(%.4f) = %.4f degrees\n", Math.sin(radians), Math.toDegrees(Math.asin(Math.sin(radians))));
		System.out.print("\n");
		
		/* acos() */
		System.out.printf("acos(%.4f) = %.4f degrees\n", Math.cos(radians), Math.toDegrees(Math.acos(Math.cos(radians))));
		System.out.print("\n");
		
		/* atan() */
		System.out.printf("atan(%.4f) = %.4f degrees\n", Math.tan(radians), Math.toDegrees(Math.atan(Math.tan(radians))));
		System.out.print("\n");
		
		/* random() */
		System.out.printf("%.6f\n", Math.random());
		System.out.printf("%.6f\n", Math.random());
		System.out.print("\n");
	}
}
