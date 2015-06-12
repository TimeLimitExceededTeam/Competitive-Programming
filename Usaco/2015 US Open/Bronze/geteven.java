import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.StringTokenizer;

public class geteven {
	// http://usaco.org/index.php?page=viewproblem2&cpid=546
	/*
	 * Aldo Rincon Mora
	 * US Open 2015 Contes
	 * Nivel: Bronze
	 */
	static HashMap<String, Integer> odd = new HashMap<String, Integer>();
	static HashMap<String, Integer> even = new HashMap<String, Integer>();
	static HashMap<String, Integer> total = new HashMap<String, Integer>();

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream(new File("geteven.in")));
		System.setOut(new PrintStream(new File("geteven.out")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		StringTokenizer st;

		int rta = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String key = st.nextToken();
			int value = Integer.parseInt(st.nextToken());
			if (!even.containsKey(key)) {
				odd.put(key, 0);
				even.put(key, 0);
				total.put(key, 0);
			}
			if (value % 2 == 0)
				even.put(key, even.get(key) + 1);
			else
				odd.put(key, odd.get(key) + 1);
			total.put(key, total.get(key) + 1);

		}
		rta += (multEven("B", "I") + multOdd("B", "I"))
				* multTotal("E", "S", "G", "O", "M");

		final int oddBaseBessie = even.get("B") * odd.get("I") + odd.get("B")
				* even.get("I");

		rta += oddBaseBessie * multOdd() * multEven("G", "O", "E", "S")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("E", "S") * multEven("G", "O")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("O", "S") * multEven("G", "E")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("O", "E") * multEven("G", "S")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("G", "S") * multEven("O", "E")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("G", "E") * multEven("O", "S")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("G", "O") * multEven("E", "S")
				* multTotal("M");
		rta += oddBaseBessie * multOdd("G", "O", "E", "S") * multEven()
				* multTotal("M");

		final int oddBaseGoes =
				  multEven("G", "O", "E") * multOdd("S")
				+ multEven("G", "O", "S") * multOdd("E")
				+ multEven("G", "E", "S") * multOdd("O") 
				+ multEven("G")	* multOdd("O", "E", "S") 
				+ multEven("O", "E", "S")* multOdd("G") 
				+ multEven("O") * multOdd("G", "E", "S")
				+ multEven("E") * multOdd("G", "O", "S") 
				+ multEven("S")	* multOdd("G", "O", "E");

		rta += oddBaseBessie * oddBaseGoes * multEven("M");
		System.out.println(rta);

	}

	public static int multTotal(String... args) {
		int acum = 1;
		for (String key : args)
			acum *= total.get(key);
		return acum;
	}

	public static int multOdd(String... args) {
		int acum = 1;
		for (String key : args)
			acum *= odd.get(key);
		return acum;
	}

	public static int multEven(String... args) {
		int acum = 1;
		for (String key : args)
			acum *= even.get(key);
		return acum;
	}

}
