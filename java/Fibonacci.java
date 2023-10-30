package com.wissamfawaz;

import java.time.Duration;
import java.time.Instant;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		String nStr;

		int n;
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter n (q to quit): ");
		nStr = scan.nextLine();
		
		while(!nStr.equals("q")) {
			try {
				n = Integer.parseInt(nStr);
				System.out.println("Dynamic programming solution: " + 
						fib_imp(n, new long[n+1]));
				Instant before = Instant.now();
				System.out.println("Recursive solution: " + fib_rec(n));
				Instant after = Instant.now();
				
				System.out.println("Running time of recursive solution: " + 
						Duration.between(before, after).toMillis() + " ms");
			} catch(NumberFormatException e) {
				System.out.println("The only acceptable non-int value is q");
			}
			
			System.out.println("Enter n (q to quit): ");
			nStr = scan.nextLine();
		}
		
		
		scan.close();
	}

	private static long fib_rec(int n) {
		if(n == 0 || n == 1) {
			return (long) n;
		}
		
		return fib_rec(n-1) + fib_rec(n-2);
	}
	
	private static long fib_imp(int n,  long[] cache) {
		if(cache[n] != 0) {
			return cache[n];
		}
		
		long result;
		
		if(n == 0 || n == 1) {
			result = (long) n;
		} else {
			result = fib_imp(n-1, cache) + fib_imp(n-2, cache);
		}
		
		cache[n] = result;
		
		return result;
	}
	

}
