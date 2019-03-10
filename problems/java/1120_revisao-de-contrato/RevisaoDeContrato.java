package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * 
 * @author zeller
 *
 * @problem_name Revisão de Contrato
 * 
 * @problem_number 1120
 * 
 * @category Strings
 * 
 * @difficulty_level 5
 * 
 * @see <a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/1120">Link URI Online Judge</a>
 * 
 */
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