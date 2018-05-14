import java.util.*;
public class Main {
    void run() {
        Scanner scan = new Scanner(System.in);
        final int limit = 150;
        while (true) {            
            int h = scan.nextInt(), w = scan.nextInt();
            if (h == 0 && w == 0) break;
            int dia = h * h + w * w;
            int hei = limit;
            int wid = limit;
            int min = limit * limit + limit * limit;
            for (int i = 1; i <= limit; i++) {
                for (int j = 1; j < i; j++) {
                    int ndia = i * i + j * j;
                    if (ndia < dia) continue;
                    if (ndia == dia && j <= h) continue;
                    if (ndia < min) {
                        min = ndia;
                        hei = j;
                        wid = i;
                    } else if(ndia == min && j < hei) {
                        hei = j;
                        wid = i;
                    }
                }
            }
            System.out.println(hei + " " + wid);
        }
    }
    public static void main(String args[]) {
        new Main().run();
    }
}