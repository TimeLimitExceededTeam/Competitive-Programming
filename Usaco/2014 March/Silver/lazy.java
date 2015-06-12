import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class lazy_silver {

	static int[][] grass;
	static int[][] grass_acum;
	static int k;
	static int n;
	static int max = 0;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream(new File("lazy.in")));
		System.setOut(new PrintStream(new File("lazy2.out")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		grass = new int[n][n];
		grass_acum = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				grass[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0)
					calcFirst();
				else {
					if (j == 0)
						calcWUp(i, j);
					else
						calcWLeft(i, j);
				}
			}
		}
		System.out.println(max);

	}

	public static void calcFirst() {
		int first = 0;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k - i; j++) {
				if(isValid(i, j))
					first += grass[i][j];
			}
		}
		grass_acum[0][0] = first;
	}

	public static int sumRigthBorder(int x, int y) {
		int border = 0;

		int i = x - k;
		int j = y;

		while (i <= x) {
			if (isValid(i, j))
				border += grass[i][j];
			i++;
			j++;
		}
		i--;
		j--;
		i++;
		j--;
		while (j >= y) {
			if (isValid(i, j))
				border += grass[i][j];
			i++;
			j--;
		}

		return border;
	}

	public static boolean isValid(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < n;
	}

	public static int sumUpBorder(int x, int y) {
		int border = 0;
		int i = x;
		int j = y - k;
		while (j <= y) {
			if (isValid(i, j))
				border += grass[i][j];
			i--;
			j++;
		}
		i++;
		j--;
		i++;
		j++;
		while (i <= x) {
			if (isValid(i, j))
				border += grass[i][j];
			i++;
			j++;
		}

		return border;
	}

	public static int sumDownBorder(int x, int y) {
		int border = 0;
		int i = x;
		int j = y - k;
		while (j <= y) {
			if (isValid(i, j))
				border += grass[i][j];
			i++;
			j++;
		}
		i--;
		j--;
		i--;
		j++;
		while (i >= x) {
			if (isValid(i, j))
				border += grass[i][j];
			i--;
			j++;
		}

		return border;
	}

	public static int sumLeftBorder(int x, int y) {
		int border = 0;

		int i = x - k;
		int j = y;

		while (i <= x) {
			if (isValid(i, j))
				border += grass[i][j];
			i++;
			j--;
		}
		i--;
		j++;
		i++;
		j++;
		while (j <= y) {
			if (isValid(i, j))
				border += grass[i][j];
			i++;
			j++;
		}

		return border;
	}

	public static void calcWUp(int x, int y) {
		int base = grass_acum[x - 1][y];
		base += sumDownBorder(x, y);
		base -= sumUpBorder(x - 1, y);
		if (base > max)
			max = base;
		grass_acum[x][y] = base;
	}

	public static void calcWLeft(int x, int y) {
		int base = grass_acum[x][y - 1];
		base += sumRigthBorder(x, y);
		base -= sumLeftBorder(x, y - 1);
		if (base > max)
			max = base;
		grass_acum[x][y] = base;
	}
}
