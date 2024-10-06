import java.util.Vector;
import java.util.Scanner;

public class Main {

    static void qSort(int l, int r, Vector<Integer> v){
        if(l<r){
            int q = partiton(l,r,v);
            qSort(l,q-1,v);
            qSort(q+1,r,v);
        }

    }
    static int partiton(int l, int r,Vector<Integer> v){
        int p = v.get(r);
        int i = l-1;
        for(int j=l;j<r;j++){
            int tmp = v.get(j);
            if(tmp<=p){
                v.set(j, v.get(++i));
                v.set(i,tmp);
            }
        }
        int tmp = v.get(i+1);
        v.set(r,tmp);
        v.set(i + 1,p);
        return i+1;
    }

    public static void main(String[] args) {
        int[] arr = new int[50];
        Vector<Integer> positiveSort = new Vector<>();
        Vector<Integer> negativeSort = new Vector<>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        boolean zero = false;
        int one=0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                negativeSort.add(arr[i]);
            }
            else if (arr[i] == 0) zero =true;
            else if (arr[i] == 1) one ++;
            else {
                positiveSort.add(arr[i]);
            }
        }
        qSort(0,negativeSort.size()-1,negativeSort);
        qSort(0,positiveSort.size()-1,positiveSort);
        int sum = one;
        for(int i = 0;i<negativeSort.size();i+=2){
            if(i+1<negativeSort.size()){
                sum += negativeSort.get(i+1)*negativeSort.get(i);
            }
            else if(!zero){
                    sum += negativeSort.get(i);
            }
        }
        for(int i = positiveSort.size()-1;i>=0;i-=2){
            if(i-1>=0){
                sum += positiveSort.get(i-1)*positiveSort.get(i);
            }
            else {
                sum += positiveSort.get(i);
            }
        }
        System.out.println(sum);

    }


}
