/* Luis David García(Natchz) 11/07/2015 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class train {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String data[] = br.readLine().split(" ");
			String result = "possible";
			int pas = 0;
			int cap = Integer.parseInt(data[0]);
			int est = Integer.parseInt(data[1]);
			int a,b,c = 0;
			for(int i = 0; i < est; i++){
				data = br.readLine().split(" ");
				a = Integer.parseInt(data[0]);
				b = Integer.parseInt(data[1]);
				c = Integer.parseInt(data[2]);
				
				if(a > pas){
					result = "impossible";
					break;
				}else
					pas-=a;
				
				if(b > cap - pas){
					result = "impossible";
					break;					
				}else
					pas+=b;
				
				if(c > 0 && (cap - pas) > 0){
					result = "impossible";
					break;							
				}
			}
			
			if(pas != 0 || c!= 0)
				result = "impossible";
			
			System.out.println(result);
		} catch (IOException e) {
		}
	}
}
