import java.util.*;
public class Main {
    Scanner scan = new Scanner(System.in);
    int[] balls = new int[10];
    void run() {
        int n = scan.nextInt();
        String ans;
        for (int i = 0; i < n; i++) {
            if(solve()) ans = "YES";
            else ans = "NO";
            System.out.println(ans);
        }
    }

    boolean solve() {
        int tube1 = 0, tube2 = 0;
        for (int i = 0; i < 10; i++) balls[i] = scan.nextInt();
        for (int i = 0; i < 10; i++) {
            if (balls[i] > tube1) tube1 = balls[i];
            else if(balls[i] > tube2) tube2 = balls[i];
            else return false;
        }
        return true;
    }
    
    public static void main(String args[]) {
        new Main().run();
    }
}
