package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class SomaFatoriais {

    public static void main( String[] args ) throws IOException {
	BufferedReader in = new BufferedReader ( new InputStreamReader ( System.in ) );
	BigInteger n, m;
	BigInteger zero = new BigInteger( "1" );
	String line;
	
	while ( null != ( line = in.readLine() ) ) {
	    n = new BigInteger( line.split( " " )[0] );
	    m = new BigInteger( line.split( " " )[1] );
	    
	    if ( n.intValue() != 0) {
		for ( int i = n.intValue() - 1; i > 0; i-- ) {
			n = n.multiply( new BigInteger( String.valueOf( i ) ) );
		    }
	    } else {
		n = zero;
	    }
	    if ( m.intValue() != 0) {
		for ( int i = m.intValue() - 1; i > 0; i-- ) {
    			m = m.multiply( new BigInteger( String.valueOf( i ) ) );
		}
	    } else {
		m = zero;
	    }
	    
	    System.out.println( n.add( m ) );
	}
	
    }
}
