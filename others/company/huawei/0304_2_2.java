// k小朋友分n糖果

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Huawei2 {
    static Scanner sc = new Scanner(System.in);
 
    public static void main(String[] args) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        List list = new ArrayList<String>();
        dfs(0, n, k - 1, n + k - 1, "", list);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
 
    public static void dfs(int index, int n, int k, int len, String path, List list) {
        if (index == len) {
            list.add(path);
        }
        if (n > 0) {
            dfs(index + 1, n - 1, k, len, path + "*", list);
        }
        if (k > 0) {
            dfs(index + 1, n, k - 1, len, path + "|", list);
        }
    }
}