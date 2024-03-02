
import java.util.Scanner;

			


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int[] arr = new int[n];
		for(int i=0; i<n; i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		int j = n-1;
		int cnt = 0;
		while(m > 0) {
			if(m >= arr[j]) {
				m-=arr[j];
				cnt++;
			}
			else {
				j--;
			}
		}
		System.out.println(cnt);
	}

}