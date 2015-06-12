import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class mooomoo {

	static final int MAX_COWS = 100005;

	public static void main(String[] args) throws Exception {

		int[] min = new int[MAX_COWS];
		Arrays.fill(min, -1);
		min[0] = 0;

		System.setIn(new FileInputStream(new File("mooomoo.in")));
		System.setOut(new PrintStream(new File("mooomoo.out")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int cows = 0;
		int[] breeds = new int[b];
		int[] fields = new int[n];
		int max = 0;
		for (int i = 0; i < b; i++)
			breeds[i] = (Integer.parseInt(br.readLine()));

		for (int i = 0; i < n; i++) {
			fields[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(breeds);

		for (int i = n - 1; i > 0; i--) {
			if (fields[i - 1] > 0)
				fields[i] -= fields[i - 1] - 1;

			if (fields[i] > max)
				max = fields[i];
		}

		Queue<Integer> q = new LinkedList<Integer>();
		q.add(0);
		while (!q.isEmpty()) {

			int aPos = q.poll();
			int aCows = min[aPos];

			for (int breed : breeds) {
				if (aPos + breed < MAX_COWS)
					if (min[aPos + breed] == -1
							|| min[aPos + breed] > (aCows + 1)
							&& (aPos + breed) <= max) {
						min[aPos + breed] = aCows + 1;
						if (!q.contains(aPos + breed))
							q.add(aPos + breed);
					}
			}
		}
		boolean flag = true;
		for (int i : fields) {
			if (min[i] == Integer.MAX_VALUE)
				flag = false;
			cows += min[i];
		}
		if (flag)
			System.out.println(cows);
		else
			System.out.println(-1);
	}
}
