/*
UVA Problem	: 11172
Author		: Aldo Rincón Mora
Date		: 16/11/2014
Status		: Accepted
Super easy problems
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] params;
		try {
			int n = Integer.parseInt(br.readLine());
			for (int i = 0; i < n; i++) {
				params = br.readLine().split(" ");
				int a = Integer.parseInt(params[0]);
				int b = Integer.parseInt(params[1]);
				if(a==b)
					System.out.println("=");
				else if (a<b)
					System.out.println("<");
				else
					System.out.println(">");
			}
		} catch (Exception e) {
		} 
	}
}
