import java.util.Scanner;


public class Main {
	static int n,m;
	static boolean check[][];
	static String[] campus;
	static int c = 0;
	static void search(int x, int y) {
		if (0<=x && 0<=y && x<m && y<n) {
			if(campus[y].charAt(x)!='X' && check[y][x] == false) {
			check[y][x] = true;
			if (campus[y].charAt(x) == 'P') {
				c++;
			}
			search(x+1,y);
			search(x-1,y);
			search(x,y+1);
			search(x,y-1);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		int x = 0;
		int y = 0;
		check = new boolean[n][m];
		campus = new String[n];
		for(int i = 0; i < n; i++) {
			campus[i] = sc.next();
		}

		
		for(int i = 0; i < n; i++) {
			int tmp = campus[i].indexOf("I");
				if (tmp != -1) {
					x = tmp;
					y = i;
					break;
				}
				
		}
		search(x,y);
		if (c == 0) 
			System.out.println("TT");
		
		else
			System.out.println(c);

		
	}
}