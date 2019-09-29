import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 
 * @author zeller
 *
 * @problem_name Duende Perdido
 * 
 * @problem_number 2294
 * 
 * @category Grafos
 * 
 * @difficulty_level 4
 * 
 * @see <a href="https://www.urionlinejudge.com.br/judge/pt/problems/view/2294">Link URI Online Judge</a>
 * 
 */
public class DuendePerdido {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String linha;
		int n, m;
		int trono = 1000;
		Queue<int[]> pilha = new LinkedList<>();
		linha = in.readLine();
		n = Integer.parseInt(linha.split(" ")[0]);
		m = Integer.parseInt(linha.split(" ")[1]);
		int[] percorrerX = { -1, 0, 1, 0 };
		int[] percorrerY = { 0, -1, 0, 1 };
		int[][] matAdj = new int[n][m];
		int[][] dist = new int[n][m];
		int[][] visited = new int[n][m];
		int[] posicao = new int[2];
		String[] entrada = new String[n];

		for (int i = 0; i < n; i++) {
			entrada = in.readLine().split(" ");
			for (int j = 0; j < m; j++) {
				matAdj[i][j] = Integer.parseInt(entrada[j]);
				if (matAdj[i][j] == 3) {
					posicao[0] = i;
					posicao[1] = j;
				}
				if (matAdj[i][j] == 2)
					visited[i][j] = 1;
				else
					visited[i][j] = -1;
			}
		}

		pilha.add(posicao);
		dist[posicao[0]][posicao[1]] = 0;
		visited[posicao[0]][posicao[1]] = 1;

		while (!pilha.isEmpty()) {
			posicao = pilha.poll();
			int x, y;
			x = posicao[0];
			y = posicao[1];
			visited[x][y] = 1;

			if (matAdj[x][y] == 0) {
				if(dist[x][y] <= trono) trono = dist[x][y];
				continue;
			}
			
			for (int x1 = 0; x1 < percorrerX.length; x1++) {

				if (x + percorrerX[x1] >= n || x + percorrerX[x1] < 0 || y + percorrerY[x1] >= m
						|| y + percorrerY[x1] < 0 || visited[x + percorrerX[x1]][y + percorrerY[x1]] == 1) {
					continue;
				}
				pilha.add(new int[] { x + percorrerX[x1], y + percorrerY[x1] });
				dist[x + percorrerX[x1]][y + percorrerY[x1]] = dist[x][y] + 1;
			}

		}
		System.out.println(trono);

	}
}