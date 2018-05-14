import java.util.*;
public class Main {
    void run() {
        Scanner scan = new Scanner(System.in);
        final int INF = (1 << 27);
        while (true) {
            int n, a, b, c, V = 10;
            int[][] path = new int[V][V];
            // input & init
            n = scan.nextInt();
            if (n == 0) break;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    path[i][j] = INF;
                    if (i == j) path[i][j] = 0;
                }
            }
            V = 0;
            for (int i = 0; i < n; i++) {
                a = scan.nextInt();
                b = scan.nextInt();
                c = scan.nextInt();
                path[a][b] = c;
                path[b][a] = c;
                V = Math.max(V, a);
                V = Math.max(V, b);
            }
            V++;
            // warshall-floyd
            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        path[i][j] = Math.min(path[i][j], path[i][k]+path[k][j]);
                    }
                }
            }
            int Min = INF, mini = -1;
            for (int i = 0; i < V; i++) {
                int sum = 0;
                for (int j = 0; j < V; j++) {
                    sum += path[i][j];
                }
                if (sum < Min) {
                    Min = sum;
                    mini = i;
                }
            }
            System.out.println(mini + " " + Min);
        }
    }
    
    public static void main(String args[]) {
        new Main().run();
    }
}
