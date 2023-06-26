package java_algorithm;

import java.io.*;
import java.util.StringTokenizer;

public class Baekjoon_10709 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int i = Integer.parseInt(st.nextToken());
        int j = Integer.parseInt(st.nextToken());
        int[][] map = new int[i][j];
        int[][] result = new int[i][j];
        for (int y = 0; y < i; y++) for (int x = 0; x < j; x++) result[y][x] = -1;

        for (int y = 0; y < i; y++) {
            char[] chars = br.readLine().toCharArray();
            for (int x = 0; x < j; x++) {
                if (chars[x] == 'c') {
                    map[y][x] = 1;
                    result[y][x] = 0;
                }
            }

            for (int x = 0; x < j; x++) {
                if (map[y][x] != 1) {
                    for (int xx = x - 1; -1 < xx; xx--) {
                        if (map[y][xx] == 1) {
                            result[y][x] = x - xx;
                            break;
                        }
                    }
                }
                bw.write(result[y][x] + " ");
            }
            bw.newLine();
        }
        br.close();
        bw.flush();
        bw.close();
    }
}
