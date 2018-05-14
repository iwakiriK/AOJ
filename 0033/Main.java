import java.util.*;
public class Main {
    int[] a = new int[10];
    void run() {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                a[j] = scan.nextInt();
            }
            String ans = "NO";
            if (dfs(0, 0, 0)) ans = "YES";
            System.out.println(ans);
        }
    }
    boolean dfs(int b, int c, int cnt) {        
        if (cnt == 10) {
            return true;
        } else {
            if (b < a[cnt]) return dfs(a[cnt], c, cnt+1);                
            if (c < a[cnt]) return dfs(b, a[cnt], cnt+1);
        }
        return false;
    }
    public static void main(String args[]) {
        new Main().run();
    }
}