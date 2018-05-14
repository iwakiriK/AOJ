import java.util.*;
public class Main {
    int w, d; // 部屋サイズ
 
    class View implements Comparable<View> {
        int left;  // 視野の左端
        int right; // 視野の右端
        public View(int x, int y, char direction) {
            switch(direction) {
                case 'W':
                    left = -x + y;
                    right = x + y;
                    break;
                case 'N':
                    left = x + y;
                    right = 2*d + x - y;
                    break;
                case 'E':
                    left = 2*d + x - y;
                    right = 2*(d+w) - x - y;
                    break;
                case 'S':
                    left = 2*(d+w) - x - y;
                    right = 2*(d+w) - x + y;
                    break;
            }
        }
        public int compareTo(View that) {
            return this.right - that.right;
        }
    }
 
    void run() {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); // 人数
        w = scan.nextInt(); // 横幅
        d = scan.nextInt(); // 縦幅
        View[] views = new View[n];
        for (int i = 0; i < n; i++) {
            views[i] = new View(scan.nextInt(), scan.nextInt(), scan.next().charAt(0));
        }
        Arrays.sort(views); // 視野の右端でソート
        int loop = 2*(w + d); // 1周
        int ans = (1 << 30);
        for(int i = 0; i < n; i++) {
            View[] tmp = views.clone();
            for(int j = i-1; j >= 0; j--) {
                if(tmp[j].right < tmp[i].right) {
                    tmp[j].right += loop;
                    tmp[j].left += loop;
                }
            }
            Arrays.sort(tmp);
            int cnt = 1;
            int now = tmp[0].right;
            for(int j = 0; j < n; j++) {
                if(tmp[j].left > now) {
                    now = tmp[j].right;
                    cnt++;
                }
            }
            ans = Math.min(ans, cnt);
        }
        System.out.println(ans);
    }
 
 
    public static void main(String args[]) {
        new Main().run();
    }
}