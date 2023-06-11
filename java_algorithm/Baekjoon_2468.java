package java_algorithm;

import java.io.*;
import java.util.*;

public class Baekjoon_2468 {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final int[] dy = {-1, 0, 1, 0};
    private static final int[] dx = {0, 1, 0, -1};
    private static final int[][] map = new int[100][100];
    private static int[][] visited = new int[100][100];
    private static int n = 0;

    private static void dfs(int y, int x, int h) {
        visited[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (map[ny][nx] < h) continue;
            if (visited[ny][nx] == 0) dfs(ny, nx, h);
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        Set<Integer> range = new HashSet<>();
        for (int y = 0; y < n; y++) {
            int x = 0;
            StringTokenizer tokenizer = new StringTokenizer(br.readLine(), " ");
            while (tokenizer.hasMoreTokens()) {
                map[y][x] = Integer.parseInt(tokenizer.nextToken());
                range.add(map[y][x]);
                x++;
            }
        }
        br.close();

        List<Integer> result = new ArrayList<>();
        for (int h : range) {
            int count = 0;
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    if (visited[y][x] == 0 && map[y][x] >= h) {
                        count++;
                        dfs(y, x, h);
                    }
                }
            }
            result.add(count);
            visited = new int[104][104];
        }
        int max = result.stream().max(Integer::compareTo).orElse(0);
        bw.write(String.valueOf(max));
        bw.flush();
        bw.close();
    }
}
