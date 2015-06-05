/*
UVA Problem	: 00272
Author		: Aldo Rincón Mora
Date		: 15/11/2014
Status		: Accepted
Super easy UVA problems
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String params = null;
		Boolean flag = true;
		try{
			while((params = br.readLine())!=null){
				while(params.contains("\"")){
					if(flag){
						params = params.replaceFirst("\"","``");flag = !flag;
					}else{
						params = params.replaceFirst("\"","''");flag = !flag;
					}
				}
				System.out.println(params);
			}
		}catch(Exception e){
			System.exit(0);
		}
	}
}
