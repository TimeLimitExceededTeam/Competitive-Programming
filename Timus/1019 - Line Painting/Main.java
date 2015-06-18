import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] a = new int[5005], b = new int[5005];
		char[] c = new char[5005];
		ArrayList<Integer> nums = new ArrayList<Integer>();
		HashMap<Integer, Integer> t = new HashMap<Integer, Integer>();
		String[] line;
		nums.add(0);
		for (int i = 0; i < n; i++) {
			line = br.readLine().split(" ");
			a[i] = Integer.parseInt(line[0]);
			b[i] = Integer.parseInt(line[1]);
			c[i] = line[2].charAt(0);
			if (!nums.contains(a[i]))
				nums.add(a[i]);
			if (!nums.contains(b[i]))
				nums.add(b[i]);
		}
		if (!nums.contains(1000000000))
			nums.add(1000000000);
		nums.add(1000000001);
		Collections.sort(nums);
		int m = nums.size();
		for (int i = 0; i < m; i++)
			t.put(nums.get(i), i);
		char[] wall = new char[m];
		wall[m - 2] = 'b';
		for (int i = 0; i < m-2; i++)
			wall[i] = 'w';
		for (int i = 0; i < n; i++)
			for (int j = t.get(a[i]); j < t.get(b[i]); j++)
				wall[j] = c[i];
		int ca = 0, max = -1, one = 0, two = 0;
		for (int i = 0; i < m; i++){
			if (wall[i] == 'w')
				ca = ca < 0 ? i : ca;
			if (wall[i] == 'b' ){
				if (ca >= 0)
					if (wall[ca] == 'w') {
						if (nums.get(i) - nums.get(ca) > max) {
							one = nums.get(ca);
							two = nums.get(i);
							max = nums.get(i) - nums.get(ca);
						}
					}
				ca = -1;
			}
		}
		System.out.println(one + " " + two);

	}
}
