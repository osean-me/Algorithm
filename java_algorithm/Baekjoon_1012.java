package java_algorithm;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

// https://www.acmicpc.net/problem/1012
public class Baekjoon_1012 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter((new OutputStreamWriter(System.out)));
    private static final int[] DIRECTION_Y = {-1, 0, 1, 0}, DIRECTION_X = {0, 1, 0, -1};
    private static int[][] map, visited;

    private static void setValue() throws IOException {
        String input = br.readLine();
        List<Integer> direction = Arrays.stream(input.split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        map[direction.get(0)][direction.get(1)] = 1;
    }

    private static void createMap() throws IOException {
        String input = br.readLine();
        List<Integer> conditions = Arrays.stream(input.split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        map = new int[conditions.get(0)][conditions.get(1)];
        visited = new int[conditions.get(0)][conditions.get(1)];
        for (int i = 0; i < conditions.get(2); i++) setValue();
    }

    private static void dfs(int y, int x) {
        visited[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + DIRECTION_Y[i];
            int nx = x + DIRECTION_X[i];
            if (ny < 0 || nx < 0 || ny >= map.length || nx >= map[0].length) continue;
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) dfs(ny, nx);
        }
    }

    private static List<String> solution() throws IOException {
        int t = Integer.parseInt(br.readLine());
        List<String> results = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            int count = 0;
            createMap();

            for (int y = 0; y < map.length; y++) {
                for (int x = 0; x < map[y].length; x++) {
                    if (map[y][x] == 1 && visited[y][x] == 0) {
                        count++;
                        dfs(y, x);
                    }
                }
            }
            results.add(String.valueOf(count));
        }
        return results;
    }

    public static void main(String[] args) throws IOException {
        List<String> results = solution();
        for (String result : results) {
            bw.write(result);
            bw.newLine();
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
