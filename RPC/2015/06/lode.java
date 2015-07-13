/* Luis David García(Natchz) 11/07/2015 */

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class lode {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int data[] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049,
				177147, 531441, 1594323, 4782969 };
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			String result = "";
			boolean flag = false;
			int K = Integer.parseInt(br.readLine()), r = 0;
			for (int j = 14; j >= 0; j--) {
				r = 0;
				if (K >= data[j]) {
					r = K / data[j];
					K = K - r * data[j];
					if (r > 0 && !flag)
						flag = true;
				}
				if (flag)
					result += " " + r;

			}
			System.out.println(result.trim());
		}
	}
}
