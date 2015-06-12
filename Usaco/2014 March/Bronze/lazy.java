import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class lazy {
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream(new File("lazy.in")));
		System.setOut(new PrintStream(new File("lazy.out")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int max_xi = 0;
		int[] g_i = new int[1000000];
		int[] acum = new int[1000000];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int value = Integer.parseInt(st.nextToken());
			int x_i = Integer.parseInt(st.nextToken());

			g_i[x_i] = value;
			if (max_xi < x_i)
				max_xi = x_i;
			if(x_i<=K){
				acum[0] += value;
			}
		}
		int max = 0;
		
		for (int i = 1; i < max_xi; i++) {
			int low_pos = i - K -1;
			int high_pos = i + K;
			acum[i] = acum[i-1];
			if (low_pos >= 0) {
				acum[i]-= g_i[low_pos];
			}
			if (high_pos <= max_xi) {
				acum[i]+= g_i[high_pos];
			}			
			if (acum[i] > max) {
				max = acum[i];
			}
		}
		System.out.println(max);
	}
}
