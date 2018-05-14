/* 
   巣'S', チーズ工場'数字', 障害物'X', 空き地'.'
   自分の体力以下のチーズを食べることができる
   チーズ工場の上を歩くことは可 
   1つ食べると1体力上昇
*/
import java.util.*;
public class Main {
    final int limit = 1000;
    final int[] dx = {1, 0, -1, 0};    // 移動の4方向ベクトル
    final int[] dy = {0, 1, 0, -1};
    char[][] town = new char[limit][];
    int[][] d = new int[limit][limit];
    Queue<Pair> que = new ArrayDeque<Pair>();
    int h, w, n;
    int hp = 1;
    int gy, gx;
    boolean hasFound = false;

    class Pair {
        int y, x;
        Pair (int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    void run() {
        Scanner scan = new Scanner(System.in);
        h = scan.nextInt(); // high
        w = scan.nextInt(); // width
        n = scan.nextInt(); // チーズ工場
        int sy = -1, sx = -1;
        for(int i = 0; i < h; i++) {
            town[i] = scan.next().toCharArray();
            for (int j = 0 ; j < w; j++) {
                if (town[i][j] == 'S') {
                    sy = i;
                    sx = j;
                }
            }
        }
        que.add(new Pair(sy, sx));
        bfs();
        System.out.println(d[gy][gx]);
    }

    void bfs() {
        while(!que.isEmpty()) {
            Pair p = que.poll();
            for (int i = 0; i < 4; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (ny < 0 || nx < 0 || ny >= h|| nx >=w) continue;
                if (town[ny][nx] == 'X') continue;
                if (d[ny][nx] != 0) continue;
                int time = d[p.y][p.x] + 1;   
                if (town[ny][nx] - '0' == hp) {                    
                    // チーズ食べた                    
                    hp++;
                    init(d);
                    d[ny][nx] = time;                    
                    que.clear();
                    if (hp - 1 == n) {                        
                        gy = ny;
                        gx = nx;
                        hasFound = true;
                    } else {
                        que.add(new Pair(ny, nx));
                    }
                    break;
                } else {
                    // チーズ食べてない
                    d[ny][nx] = time;
                    que.add(new Pair(ny, nx));
                }
            }
        }
    }

    void init(int d[][]) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                d[i][j] = 0;
            }
        }
    }
    public static void main(String args[]) {
        new Main().run();
    }
}