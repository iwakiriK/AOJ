import java.util.*;
public class Main {
    final int limit = 1000000;
    void run() {
        Scanner scan = new Scanner(System.in);
        while (true) {
            int m = scan.nextInt(), nmin = scan.nextInt(), nmax = scan.nextInt();
            if (m == 0 && nmin == 0 && nmax == 0) break;
            int[] p = new int[m];
            for (int i = 0; i < m; i++) {
                p[i] = scan.nextInt();
            }
            int gap = 0, ans = 0;            
            for (int i = nmin-1; i < nmax; i++) {
                int diff = p[i] - p[i+1];
                if (diff >= gap) {
                    gap = diff;
                    ans = i+1;
                }
            }
            System.out.println(ans);

        }        
    }
    
    public static void main(String args[]) {        
        new Main().run();        
    }
}