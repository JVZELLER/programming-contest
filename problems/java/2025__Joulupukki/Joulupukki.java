import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 
 * @author zeller
 *
 * @problem_name Joulupukki
 * 
 * @problem_number 2025
 * 
 * @category Strings
 * 
 * @difficulty_level 3.5
 * 
 * @see <a href=
 *      "https://www.urionlinejudge.com.br/judge/pt/problems/view/2025">Link URI
 *      Online Judge</a>
 * 
 */
public class Joulupukki {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] line;
		String fixo = "oulupukk", semPonto = "Joulupukki", comPonto = "Joulupukki.", temp;
		char ponto='.';
		StringBuilder sb = new StringBuilder();
		int n, i;
		n = Integer.parseInt(in.readLine());
		
		while ( n-- > 0 ) {
			line = in.readLine().split(" ");
			for (i = 0; i < line.length; i++) {
				if (line[i].contains(fixo)) {
					if(line[i].charAt(line[i].length() - 1) != ponto) {
						line[i] = semPonto; 
					} else {
						line[i] = comPonto;
					}
				}
				sb.append(line[i] + " ");
			}
			sb.append("\n");
		}
		System.out.print(sb.toString().replace(" \n", "\n"));
	}
}