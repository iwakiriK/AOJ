import java.util.*;
public class Main {
    void run() {
        Scanner scan = new Scanner(System.in);
        int l = scan.nextInt();
        int k = scan.nextInt();
        long[][] dp = new long[l+k+1][2]; // 0 == black, 1 == white
        dp[0][1] = 1;
        for (int i = 0; i < l; i++) {
            dp[i+1][0] += dp[i][1];
            dp[i+k][0] += dp[i][1];
            dp[i+1][1] += dp[i][0];
        }
        long ans = 0;
        for (int i = 1; i <= l; i++) {
            ans += dp[i][0];
        }
        System.out.println(ans);
    }
    
    public static void main(String args[]) {
        new Main().run();
    }
}
