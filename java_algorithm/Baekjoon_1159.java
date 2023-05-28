package java_algorithm;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

// https://www.acmicpc.net/problem/1159
public class Baekjoon_1159 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final String NO_RESULT = "PREDAJA";

    private static Map<String, List<String>> getNames(int count) throws IOException {
        List<String> names = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            names.add(br.readLine());
        }
        return names.stream().collect(Collectors.groupingBy(v -> v.substring(0, 1)));
    }

    private static String solution() throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<String> firstNames = getNames(n).entrySet()
                .stream()
                .filter(entry -> entry.getValue().size() >= 5)
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
        if (firstNames.size() == 0) return NO_RESULT;
        return firstNames.stream().sorted().collect(Collectors.joining());
    }

    public static void main(String[] args) throws IOException {
        String result = solution();
        bw.write(result);
        bw.newLine();
        bw.close();
        br.close();
    }
}
