package Java_Sandbox;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


/*
 * A regular expression is a special sequence of characters that helps you match or find other strings or sets of strings,
 * using a specialized syntax held in a pattern. They can be used to search, edit, or manipulate text and data.
 */

public class J015_RegularExpressions {
	
	public static void main(String[] args) {
		
		/* Capturing Groups */
		// Pattern
		String regex1 = "(.*)(\\d+)(.*)";
		// String to be scanned to find the pattern.
		String str1 = "This order was placed for QT3000! OK?";
		
		// Create a Pattern object
		Pattern p1 = Pattern.compile(regex1);

		// Now create matcher object.
		Matcher m1 = p1.matcher(str1);
		
		System.out.println("regex1: " + regex1);
		System.out.println("str1:   " + str1);
		System.out.print("\n");
		
		if (m1.find( )) {
			System.out.println("m.group(0): " + m1.group(0));
			System.out.println("m.group(1): " + m1.group(1));
			System.out.println("m.group(2): " + m1.group(2));
			System.out.println("m.group(3): " + m1.group(3));
		}
		else {
			System.out.println("No Match");
		}
		
		System.out.print("\n\n");
		
		/* start() and end() */
		// this example uses word boundaries to ensure that the letters "c" "a" "t" are not merely a substring in a longer word.
		String regex2 = "\\bcat\\b";
		String str2 = "cat cat cat cattie cat";
		
		Pattern p2 = Pattern.compile(regex2);
		Matcher m2 = p2.matcher(str2);
		int count = 0;
		
		System.out.println("regex2: " + regex2);
		System.out.println("str2:   " + str2);
		System.out.print("\n");

		while (m2.find()) {
			count++;
			System.out.println("Match number: " + count);
			System.out.println("start(): " + m2.start());
			System.out.println("end(): " + m2.end());
			System.out.print("\n");
		}
		
		System.out.print("\n");
		
		/* matches() and lookingAt() */
		String regex3 = "fool";
		String str3 = "foolish";
		
		Pattern p3 = Pattern.compile(regex3);
		Matcher m3 = p3.matcher(str3);

		System.out.println("regex3: " + regex3);
		System.out.println("str3:   " + str3);
		System.out.print("\n");

		System.out.println("lookingAt(): " + m3.lookingAt());
		System.out.println("matches():   " + m3.matches());
		
		System.out.print("\n\n");
		
		/* replaceFirst() and replaceAll() */
		String regex4 = "dog";
		String str4 = "The dog says meow. All dogs say meow.";
		String replace = "cat";
		String tmp = "";
		
		Pattern p4 = Pattern.compile(regex4);
		Matcher m4 = p4.matcher(str4);

		System.out.println("regex4: " + regex4);
		System.out.println("str4:   " + str4);
		System.out.print("\n");

		tmp = m4.replaceFirst(replace);
		System.out.println("replaceFirst(): " + tmp);
		
		tmp = m4.replaceAll(replace);
		System.out.println("replaceAll():   " + tmp);
		
		System.out.print("\n\n");
		
		/* appendReplacement() and appendTail() */
		String regex5 = "a*b";
		String str5 = "aabfooaabfooabfoob";
		replace = "-";
		
		Pattern p5 = Pattern.compile(regex5);
		Matcher m5 = p5.matcher(str5);

		System.out.println("regex5: " + regex5);
		System.out.println("str5:   " + str5);
		System.out.print("\n");

		StringBuffer sb = new StringBuffer();
		
		while(m5.find()) {
			m5.appendReplacement(sb, replace);
		}
		
		m5.appendTail(sb);
		System.out.println(sb.toString());
	}
}
