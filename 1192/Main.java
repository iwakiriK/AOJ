import java.util.*;
public class Main {
    void run() {
        Scanner scan = new Scanner(System.in);
        while (true) {
            int x = scan.nextInt(), y = scan.nextInt(), s = scan.nextInt();
            if (x == 0 && y == 0 && s == 0) break;
            int max = 0;
            for (int i = 1; i < s; i++) {
                for (int j = 1; j < s; j++) {
                    int goods1 = tax(i, x);
                    int goods2 = tax(j, x);
                    if (goods1 + goods2 != s) continue;
                    goods1 = tax(i, y);
                    goods2 = tax(j, y);
                    max = Math.max(max, goods1 + goods2);
                }
            }
            System.out.println(max);
        }
    }
    int tax(int price, int ratio) {
        return price * (100 + ratio) / 100;
    }

    public static void main(String args[]) {
        new Main().run();
    }
}