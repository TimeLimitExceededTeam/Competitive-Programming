/* Luis David García(Natchz) 13/07/2015 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class dice {

	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String line = "";
		String line2[] = {};
		int sum = 0;
		int sum2 = 0;
		try {
			while ((line = br.readLine()) != null) {
				line2 = line.split(" ");
				for (int i = 0; i < 4; i++) {
					sum += Integer.parseInt(line2[i]);
				}
				line = br.readLine();
				line2 = line.split(" ");
				for (int i = 0; i < 4; i++) {
					sum2 += Integer.parseInt(line2[i]);
				}
				
				System.out.println(result(sum,sum2));
				sum=0;
				sum2=0;
			}
		} catch (NumberFormatException e) {
		} catch (IOException e) {
		}
	}
	public static String result(int a, int b){
		if(a>b)return "Gunnar";
	
		if(b>a)return "Emma";
		
		return "Tie";
	}
}
