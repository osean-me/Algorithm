package java_algorithm;

import java.io.*;

public class Baekjoon_1992 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static int[][] toAdj(int n) throws IOException {
        int[][] adj = new int[n][n];
        for (int i = 0; i < n; i++) {
            char[] chars = br.readLine().toCharArray();
            for (int j = 0; j < chars.length; j++) adj[i][j] = chars[j] - '0';
        }
        br.close();
        return adj;
    }

    private static String solution(int[][] adj, int y, int x, int size) {
        int target = adj[y][x];
        StringBuilder result = new StringBuilder();
        for (int yy = y; yy < y + size; yy++) {
            for (int xx = x; xx < x + size; xx++) {
                if (target != adj[yy][xx]) {
                    int next = size / 2;
                    result.append("(");
                    result.append(solution(adj, y, x, next));
                    result.append(solution(adj, y, x + next, next));
                    result.append(solution(adj, y + next, x, next));
                    result.append(solution(adj, y + next, x + next, next));
                    result.append(")");
                    return result.toString();
                }
            }
        }
        return String.valueOf(adj[y][x]);
    }

    public static void main(String[] args) throws IOException {
        int y = Integer.parseInt(br.readLine());
        String result = solution(toAdj(y), 0, 0, y);
        bw.write(result);
        bw.flush();
        bw.close();
    }
}
