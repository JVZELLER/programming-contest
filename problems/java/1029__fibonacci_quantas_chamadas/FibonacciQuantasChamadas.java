package com.maratona.problemas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 
 * @author zeller
 *
 * @problem_name Fibonacci, Quantas Chamadas?
 * 
 * @problem_number 1029
 * 
 * @category Paradigma
 * 
 * @difficulty_level 3.1
 * 
 * @see <a href=
 *      "https://www.urionlinejudge.com.br/judge/pt/problems/view/1029">Link URI
 *      Online Judge</a>
 * 
 */
public class FibonacciQuantasChamadas {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n, x, result;
		int[] memo = new int[39];
		memo[0] = memo[1] = 1;
		String calls = " calls = ";
		String openFib = "fib(";
		String closeFib = ") = ";

		n = Integer.parseInt(in.readLine());

		while (n-- > 0) {
			x = Integer.parseInt(in.readLine());
			if (x <= 2) {
				System.out.println(openFib + x + closeFib + x + calls + "1");
			} else {
				System.out.println(openFib + x + closeFib + x + calls + fibonacci(x));
			}
		}

	}
	
	public static int fibonacci(int fib) {
		if (memo[fib] == 0) {
			memo[fib] = fibonacci(fib - 1) + fibonacci(fib - 2);
		}
		return memo[fib];
	}

}
