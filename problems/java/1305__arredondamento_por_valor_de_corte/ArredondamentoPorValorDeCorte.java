import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


/**
 * 
 * @author zeller
 *
 * @problem_name Arredondamento Por Valor de Corte
 * 
 * @problem_number 1305
 * 
 * @category Strings
 * 
 * @difficulty_level 3.1
 * 
 * @see <a href=
 *      "https://www.urionlinejudge.com.br/judge/pt/problems/view/1305">Link URI
 *      Online Judge</a>
 * 
 */
public class ArredondamentoPorValorDeCorte {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		StringBuilder sb = new StringBuilder();
		Float value, cutOff;
		
		while ( ( line = in.readLine() ) != null ) {
			value = Float.valueOf( line );
			cutOff = Float.valueOf( in.readLine() );
			
			if (value - value.intValue() > cutOff) {
				value += 1;
			}
			sb.append( value.intValue()  + "\n");
			
		}
		System.out.print(sb.toString());
	}

}