package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BotasPerdidas {

    public static void main( String[] args ) throws IOException {
	int n, numeroBota, contador = 0;
	String s, parBota;
	int[] direita = new int[60];
	int[] esquerda = new int[60];
	BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
	
	while ( (s = in.readLine()) != null ) {
	    n = Integer.parseInt( s );
	    Arrays.fill( esquerda, 0 );
	    Arrays.fill( direita, 0 );
	    contador = 0;
	    while ( n-- > 0 ) {
		String[] line = in.readLine().split( " " );
		numeroBota = Integer.parseInt( line[0] );
		parBota = line[1];
		if (parBota.equals( "D" )) {
		    direita[numeroBota - 1] += 1;
		} else {
		    esquerda[numeroBota - 1] += 1;
		}
	    }

	    for (int i = 0; i < esquerda.length; i++) {
		int j = esquerda[i] > direita[i] ? direita[i] : esquerda[i];
		contador += j;
	    }
		
	    System.out.println( contador );
	}
    }

}
