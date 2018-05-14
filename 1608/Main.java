import java.util.*;
public class Main {
    final int limit = 1000000;
    void run() {
        Scanner scan = new Scanner(System.in);                
        while(true) {
            int n = scan.nextInt();
            if (n == 0) break;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scan.nextInt();            
            }
            Arrays.sort(a);
            int min = limit;
            for (int i = 1; i < n; i++) {
                int diff = Math.abs(a[i-1] - a[i]);
                min = Math.min(min, diff);
            }
            System.out.println(min);
        }        
    }
    
    public static void main(String args[]) {        
        new Main().run();        
    }
}