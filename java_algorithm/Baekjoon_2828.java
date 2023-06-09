package java_algorithm;

import java.io.*;
import java.util.StringTokenizer;

public class Baekjoon_2828 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static int solution(int m, int games) throws IOException {
        int result = 0;
        int left = 1;
        for (int i = 0; i < games; i++) {
            int game = Integer.parseInt(br.readLine());
            int right = left + m - 1;
            if (left > game || game > right) {
                if (right < game) {
                    result += (game - right);
                    left += (game - right);
                } else {
                    result += (left - game);
                    left = game;
                }
            }
        }
        br.close();
        return result;
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        int games = Integer.parseInt(br.readLine());
        int result = solution(m, games);
        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}
