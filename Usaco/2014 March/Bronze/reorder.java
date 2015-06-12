import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;


public class reorder {
	static String []_A;
	static String []_B;
	static HashMap<String, Integer> A;
	static HashMap<String, Integer> B;
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream(new File("reorder.in")));
		System.setOut(new PrintStream(new File("reorder.out")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		_A = new String[n];
		_B = new String[n];
		
		int ciclos = 0, largo = -1; 
		
		A = new HashMap<String, Integer>(101);
		B = new HashMap<String, Integer>(101);
		String l;
		for(int i = 0; i < n ; i++){
			l = br.readLine();
			A.put(l, i);
			_A[i] = l;
		}
		for (int i = 0; i < n; i++) {
			l = br.readLine();
			B.put(l, i);
			_B[i] = l;
		}
		for(int i = 0; i < n ; i++){
			if(!_A[i].equals(_B[i])){	 
				ciclos++;
				int temp = ajustar(_A[i]);
				if(temp> largo)
					largo = temp;
			}
		}
		System.out.println(""+ciclos+" "+largo);
	}
	
	public static  int ajustar(String inicial){
		int nextPos = B.get(inicial);
		int beginPos = A.get(inicial);
		String current = inicial;
		int counter = 0;
		while(nextPos!=beginPos){
			String next = _A[nextPos];
			_A[nextPos] = current;
			A.put(current, nextPos);

			nextPos = B.get(next);
			current = next;
			
			counter++;
		}
		
		_A[nextPos] = current;
		A.put(current, nextPos);
		
		return ++counter;
	}
}
