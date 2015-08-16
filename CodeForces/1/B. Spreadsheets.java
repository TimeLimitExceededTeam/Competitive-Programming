import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Spreadsheets {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for (int _i = 0; _i < n; _i++) {
			String line = br.readLine();
			Pattern p = Pattern.compile("[A-Z]+[0-9]+");
			Matcher m = p.matcher(line);
			if (m.matches()) {
				p = Pattern.compile("[A-Z]+");
				m = p.matcher(line);
				String num = m.replaceFirst("");
				line = line.substring(0, line.lastIndexOf(num));
				char[] letras = line.toCharArray();
				int r = Integer.parseInt(num);
				int c = 0;
				int j = 0;
				for (int i = letras.length - 1; i >= 0; i--) {
					c += (letras[i] - 'A' + 1) * Math.pow(26, j);
					j++;
				}
				System.out.println("R" + r + "C" + c);
			} else {
				int r = Integer.parseInt(line.substring(1, line.indexOf("C")));
				int c = Integer.parseInt(line.substring(line.indexOf("C") + 1));
				int a, b;
				StringBuilder res = new StringBuilder();
				a = c;
				boolean f = false;
				while (a > 26) {
					a = c / 26;
					b = c % 26==0?26:c % 26;
					a = c % 26==0?a-1:a;
					c = a;
					res.append((char) (b + 'A' - 1));
				}
				b = c % 26==0?26:c % 26;
				res.append((char) (b + 'A' - 1));
				System.out.println(res.reverse().toString() + r);
			}

		}
	}
}
