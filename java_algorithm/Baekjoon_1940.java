package java_algorithm;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Baekjoon_1940 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int solution(int sum, List<Integer> materials) {
        int result = 0;
        int n = materials.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (materials.get(i) + materials.get(j) == sum) result++;
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int sum = Integer.parseInt(br.readLine());
        StringTokenizer tokenizer = new StringTokenizer(br.readLine(), " ");
        br.close();

        List<Integer> materials = new ArrayList<>();
        while (tokenizer.hasMoreTokens()) materials.add(Integer.parseInt(tokenizer.nextToken()));

        int result = solution(sum, materials);
        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}
