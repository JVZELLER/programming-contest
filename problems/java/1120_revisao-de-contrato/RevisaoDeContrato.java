package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class RevisaoDeContrato {

    public static void main( String[] args ) throws IOException {

	BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
	String line, valor, end = "0 0", space = " ", empty = "", zero = "0";
	while ( !( line = in.readLine().trim() ).equals( end ) ) {
	    valor = line.split( space )[1].replace( line.split( space )[0], empty );
	    if ( valor.equals( empty ) ) {
		System.out.println( zero );
		continue;
	    }
	    System.out.println( new BigInteger(valor) );
	}

    }

}