import java.util.*;
public class Main {
    void run() {
        Scanner scan = new Scanner(System.in);
        while(true) {
            int n = scan.nextInt(), m = scan.nextInt();
            if (n == 0 && m == 0) break;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scan.nextInt();
            }

            int max = 0, now = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    now = a[i] + a[j];
                    if (now > m) continue;
                    max = Math.max(max, now);
                }
            }
            if (max == 0) System.out.println("NONE");
            else System.out.println(max);
        }                
    }    
    
    public static void main(String args[]) {        
        new Main().run();        
    }
}