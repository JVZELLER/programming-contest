package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Criptografia {

    public static void main( String[] args ) throws IOException {
	int n;
	char[] line;
	BufferedReader in = new BufferedReader(new InputStreamReader (System.in));
	
	n = Integer.parseInt( in.readLine() );
	
	while (n-- > 0) {
	    line = in.readLine().toCharArray();
	    for(int i = 0; i < line.length; i++) {
		if ( line[i] >= 65 && line[i] <= 122 )
		    line[i] = (char) ( line[i] + 3 );
	    }
	    
	    char[] reversed = new char[line.length];
	    for(int i = 0; i < line.length; i++) {
		reversed[i] = line[(line.length - 1) - i];
	    }
	    
	    for(int i = reversed.length / 2; i < line.length; i++) {
		reversed[i] = (char) ( reversed[i] - 1 );
	    }
	    
	    System.out.println( reversed );
	    
	}
	

    }

}
