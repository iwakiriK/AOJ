import java.util.*;
public class Main {
    class Pair {
        String board; // 盤面
        int zero;     // ゼロの位置
        Pair (String board, int zero) {
            this.board = board;
            this.zero = zero;
        }
    }
    HashMap<String, Integer> map = new HashMap<String, Integer>();
    void run() {
        Scanner scan = new Scanner(System.in);
        char[] paz = new char[8]; // 入力用
        bfs();
        while(scan.hasNext()) {
            for (int i = 0; i < 8; i++) {
                paz[i] = (char)(scan.nextInt() + '0');
            }
            String str = String.valueOf(paz);
            System.out.println(map.get(str));
        }
    }
    void bfs() {
        final int[] d = {-4, -1, 1, 4};
        Queue<Pair> que = new ArrayDeque<Pair>();
        que.add(new Pair("01234567", 0));
        map.put("01234567", 0);
        while(!que.isEmpty()) {
            Pair p = que.poll();   // キューから引っ張ってくる
            int time = map.get(p.board) + 1;
            for (int i = 0; i < d.length; i++) {
                char ch[] = p.board.toCharArray();   // char[]型に変換
                int n = p.zero + d[i];
                if (n > 7 || n < 0) continue;        // ありえないシリーズ
                if (n == 3 && d[i] == -1) continue;
                if (n == 4 && d[i] == 1) continue;
                ch[p.zero] = ch[n];                  // swap
                ch[n] = '0';
                String str = String.valueOf(ch);     // String型に変換
                if (map.containsKey(str)) continue;  
                que.add(new Pair(str, n));           // mapに無ければ追加
                map.put(str, time);
            }
        }
    }

    public static void main(String args[]) {
        new Main().run();
    }
}