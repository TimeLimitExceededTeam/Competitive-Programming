import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class cowart {
	static final char RED = 'R', GREEN = 'G', BLUE = 'B';
	static int xIndex = 0, yIndex = 0;
	static int humans = 0, cows = 0, n;
	static boolean[][] checked;
	static char[][] art;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream(new File("cowart.in")));
		System.setOut(new PrintStream(new File("cowart.out")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		checked = new boolean[n][n];
		
		for (boolean[] b : checked)
			Arrays.fill(b, false);

		art = new char[n][n];

		for (int i = 0; i < n; i++) {
			art[i] = br.readLine().toCharArray();
		}
		while (checkPending()) {
			discoverArea(xIndex, yIndex);
			humans++;
		}
		
		for (boolean[] b : checked)
			Arrays.fill(b, false);
		
		for (int i = 0; i < checked.length ; ++i) {
			for (int j = 0; j < checked[i].length ; ++j) {
				if(art[i][j] == RED)
					art[i][j] = GREEN;
			}
		}
		
		while (checkPending()) {
			discoverArea(xIndex, yIndex);
			cows++;
		}
		
		System.out.println(humans+ " " + cows);
	}

	public static void discoverArea(int i, int j) {
		checked[i][j] = true;
		char toCheck = art[i][j];
		discoverArea(i, j, toCheck);
	}

	public static void discoverArea(int i, int j, char color) {
		if (color == art[i][j]) {
			checked[i][j] = true;
			if (i + 1 < n && !checked[i + 1][j])
				discoverArea(i + 1, j, color);
			if (j + 1 < n && !checked[i][j + 1])
				discoverArea(i, j + 1, color);
			if (i - 1 >= 0 && !checked[i - 1][j])
				discoverArea(i - 1, j, color);
			if (j - 1 >= 0 && !checked[i][j - 1])
				discoverArea(i , j - 1, color);
		}
	}

	public static boolean checkPending() {
		boolean flag = true;
		int i = 0;
		int j = 0;
		for (i = 0; i < checked.length & flag; ++i) {
			for (j = 0; j < checked[i].length & flag; ++j) {
				flag = flag & checked[i][j];
			}
		}
		xIndex = --i;
		yIndex = --j;
		return !flag;
	}
}
