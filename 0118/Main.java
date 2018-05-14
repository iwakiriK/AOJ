import java.util.*;
public class Main {
    final int limit = 100;
    final int[] dx = {1, 0, -1, 0};
    final int[] dy = {0, 1, 0, -1};
    int h, w;
    char fru;
    char[][] orc = new char[limit][];
    void run() {
        Scanner scan = new Scanner(System.in);
        while(true) {
            h = scan.nextInt();
            w = scan.nextInt();
            if (h == 0 && w == 0) break;
            for (int i = 0; i < h; i++) {
                orc[i] = scan.next().toCharArray();
            }
            int ans = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (orc[i][j] == '-') continue;
                    ans++;
                    fru = orc[i][j];
                    dfs(i, j);
                }
            }
            System.out.println(ans);
        }
    }
    void dfs(int y, int x) {
        orc[y][x] = '-';
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (orc[ny][nx] != fru) continue;
            dfs(ny, nx);
        }
    }
    public static void main(String args[]) {
        new Main().run();
    }
}