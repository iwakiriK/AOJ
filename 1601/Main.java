import java.util.*;
public class Main {
    void run() {
        Scanner scan = new Scanner(System.in);
        final int[] tanka = {5, 7, 5, 7, 7};
        while (true) {
            int n = scan.nextInt();
            if (n == 0) break;
            int[] w = new int[n];
            for (int i = 0; i < n; i++) {
                w[i] = scan.next().length();
            }

            int ans = 0, j = 0, let = 0;
            for (int i = 0; i < n; i++) {
                let += w[i];
                if (let == tanka[j]) {
                    j++;
                    let = 0;
                    if (j == 5) break;
                } else if(let > tanka[j]) {
                    j = 0;
                    let = 0;
                    i = ans;
                    ans++;
                }
            }
            System.out.println(ans+1);
        }        
    }
    
    public static void main(String args[]) {        
        new Main().run();
    }
}