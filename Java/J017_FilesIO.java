package Java_Sandbox;


import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.List;

import java.io.BufferedReader; 
import java.io.InputStreamReader;
import java.util.Scanner; 


public class J017_FilesIO {
		
	public static void main(String[] args) throws IOException {
	    
		String fileIn = "FileIn.txt";
		String fileOut = "FileOut.txt";
		
		/* Read File */
		String content = FilesUtil.readTextFile(fileIn);
	    System.out.println(content);
	    System.out.print("\n");
	    
	    /* Write File */
	    FilesUtil.writeToTextFile(fileOut, content);
	    System.out.println(FilesUtil.readTextFile(fileOut));
	    System.out.print("\n");

	    /* readTextFileByLines() */
	    List<String> lines = FilesUtil.readTextFileByLines(fileIn);
	    for (String tmp : lines) {
	    	 System.out.println(tmp);
	    }
	    System.out.print("\n");
	    
	    
	    /* Using BufferedReader to read console */ 
	    //Enter data using BufferReader 
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); 
         
        // Reading data using readLine
        System.out.println("What's your first name?");
        String name = reader.readLine(); 
  
        // Printing the read line
        System.out.println("You entered string: " + name);
        System.out.print("\n");
        
        /* Using Scanner to read console */ 
        Scanner in = new Scanner(System.in); 
  
        System.out.println("What's your last name?");
        String s = in.nextLine(); 
        System.out.println("You entered string: " + s);
        System.out.print("\n");
  
        System.out.println("How old are you?");
        int i = in.nextInt(); 
        System.out.println("You entered integer: " + i);
        System.out.print("\n");
  
        System.out.println("What is your Java Knowledge percentage?");
        float f = in.nextFloat(); 
        System.out.println("You entered float: " + f);
        System.out.print("\n");
        
        in.close();
	}	
}


class FilesUtil {
	
	public static String readTextFile (String fileName) throws IOException {
		
		String content = new String(Files.readAllBytes(Paths.get(fileName)));
        return content;
    }

    public static List<String> readTextFileByLines (String fileName) throws IOException {
        
    	List<String> lines = Files.readAllLines(Paths.get(fileName));
        return lines;
    }

    public static void writeToTextFile (String fileName, String content) throws IOException {
     
    	Files.write(Paths.get(fileName), content.getBytes(), StandardOpenOption.CREATE);
    }   
}