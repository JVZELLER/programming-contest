package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FeiraDeAdocao {

    public static void main( String[] args ) throws IOException {
	String cachorro = "cachorro";
	BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
	int n, contador = 0;
	String line = "";

	n = Integer.parseInt( in.readLine() );

	while ( n-- > 0 ) {
	    line = in.readLine();
	    if ( line.contains( cachorro ) ) {
		for ( int i = 0; i < 2; i++ ) {
		    line += "*" + in.readLine();
		}

		String[] filhotes = line.split( "*" );
		if ( filhotes[0].contains( " " ) ) {
		    char[] caracter = filhotes[0].toCharArray();
		    if (filhotes[1].startsWith( String.valueOf( caracter[0] ) ) ) {
			contador += 1;
		    }
		}
	    }
	}

    }

}
