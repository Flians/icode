import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class k_sum_m {
    static int k, m;
    static List cur;
    static List res;
    static boolean first = true;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        k = scanner.nextInt();
        m = scanner.nextInt();
        scanner.close();
        res = new ArrayList<List<Integer>>();
        cur = new ArrayList<Integer>();
        DFS(0, 0);
        res.forEach(list -> {
            System.out.println(list.toString());
        });
        System.out.println("end");
    }

    private static void DFS(int nowK, int nowM) {
        if (nowK == k && nowM == m && ((int) cur.get(0)) != 0) {
            res.add(new ArrayList<>(cur));
            return;
        }

        if (nowK > k || nowM > m)
            return;

        for (int i = 0; i < 10; i++) {
            if (first) {
                first = false;
                continue;
            }
            cur.add(i);
            DFS(nowK + 1, nowM + i);
            cur.remove(cur.size() - 1);
        }
    }
}