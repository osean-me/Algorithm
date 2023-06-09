package java_algorithm;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Baekjoon_1629 {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static List<Integer> stringToInteger() throws IOException {
        String input = br.readLine();
        br.close();
        List<Integer> result = new ArrayList<>();
        StringTokenizer tokenizer = new StringTokenizer(input, " ");
        while (tokenizer.hasMoreTokens()) result.add(Integer.parseInt(tokenizer.nextToken()));
        return result;
    }

    private static long solution(int x, int y, int z) {
        if (y == 1) return x % z;
        long result = solution(x, y / 2, z);
        result = (result * result) % z;
        if (y % 2 != 0) result = (result * x) % z;
        return result;
    }

    public static void main(String[] args) throws IOException {
        List<Integer> values = stringToInteger();
        long result = solution(values.get(0), values.get(1), values.get(2));
        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
    }
}
