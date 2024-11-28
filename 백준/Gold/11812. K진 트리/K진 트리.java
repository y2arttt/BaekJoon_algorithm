import java.util.*;

public class Main {



    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            long n = sc.nextLong();
            long k = sc.nextLong();
            long q = sc.nextLong();

            for(int i = 1; i <= q; i++) {
                long a = sc.nextLong();
                long b = sc.nextLong();
                if(k == 1){
                    System.out.println(Math.abs(a - b));
                }
                else{
                    int cnt = 0;
                    while (a != b){
                        if(a > b){
                            a = (a-2) /k + 1;
                        }
                        else{
                            b = (b-2) /k + 1;
                        }
                        cnt++;
                    }
                    System.out.println(cnt);
                }


            }
    }
}