import java.util.*;
public class Main {
    final int rlimit = 10;
    final int climit = 10000;
    int r, c, ans;
    boolean[][] ose = new boolean[rlimit][climit];
    boolean[] flip = new boolean[rlimit];
    void run() {
        Scanner scan = new Scanner(System.in);
        while (true) {
            r = scan.nextInt();
            c = scan.nextInt();
            if (r == 0 && c == 0) break;
            int tmp;
            // 表.true, 裏.false
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    tmp = scan.nextInt();
                    if (tmp == 1) ose[i][j] = true;
                    else ose[i][j] = false;
                }
            }
            ans = 0;
            dfs(0);
            System.out.println(ans);
        }
    }

    void dfs(int i) {
        if (i == r) {
            int num = count();
            if (num > ans) ans = num;
        } else {
            flip[i] = false;
            dfs(i+1); // i行目そのまま
            flip[i] = true;
            dfs(i+1); // i行目反転
        }
    }

    int count() {
        int row, num = 0, rev;
        for (int i = 0; i < c; i++) {
            row = 0;
            // 反転後の数を計算(j列目)
            for (int j = 0; j < r; j++) {
                if (ose[j][i] ^ flip[j]) row++;
            }
            rev = r - row; // 反転
            if (rev > row) {
                num += rev;
            } else {
                num += row;
            }
        }
        return num;
    }

    public static void main(String args[]) {
        new Main().run();
    }
}