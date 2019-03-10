package com.maratona.problemas;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AmigosDeHabay {

    public static void main( String[] args ) throws IOException {

	BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
	String line, aux, vencedor = "", aceitos = "", negados = "", YES = "YES", append = "#", END = "FIM", space = " ", breakLine = "\n", friend = "\nAmigo do Habay:\n";
	String[] listaAceitos, listaNegados;
	StringBuilder out = new StringBuilder();
	boolean flg = true;
	int size;
	
	while ( !END.equals( ( line = in.readLine() ) ) ) {
	    if ( !aceitos.contains( line.split( space )[0] ) && !negados.contains( line.split( space )[0] ) ) {
		if ( line.contains( YES ) ) {
		    aceitos += line.split( space )[0] + append;
		} else {
		    negados += line.split( space )[0] + append;
		}
	    }
	}
	listaAceitos = aceitos.split( append );
	listaNegados = negados.split( append );
	if (listaAceitos.length > listaNegados.length) {
	    size = listaAceitos.length;
	} else {
	    size = listaNegados.length;
	}
	while(flg) {
	    flg = false;
	    for ( int i = 0; i < size - 1; i++) {
		if (listaAceitos.length - 1 >= i) {
		    if(listaAceitos[i].length() - 4 > vencedor.length() -4) {
			vencedor = listaAceitos[i];
		    }
		    if(listaAceitos[i].compareTo( listaAceitos[i+1] ) > 0) {
			aux = listaAceitos[i];
			listaAceitos[i] = listaAceitos[i+1];
			listaAceitos[i+1] = aux;
			flg = true;
		    }
		}
		if (listaNegados.length - 1 >= i + 1) {
		    if(listaNegados[i].compareTo( listaNegados[i+1] ) > 0) {
			aux = listaNegados[i];
			listaNegados[i] = listaNegados[i+1];
			listaNegados[i+1] = aux;
			flg = true;
		    }
		}
	    }
	}
	
	for (int i = 0; i < listaAceitos.length; i++) {
	    out.append( listaAceitos[i] + breakLine);
	}
	
	for (int i = 0; i < listaNegados.length; i++) {
	    out.append( listaNegados[i] + breakLine);
	}
	out.append( friend + vencedor);
	System.out.println( out.toString() );
	
    }

}
