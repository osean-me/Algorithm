package java_algorithm;

import java.io.*;
import java.util.*;

public class Baekjoon_2910 {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer commandTokenizer = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(commandTokenizer.nextToken());
        int c = Integer.parseInt(commandTokenizer.nextToken());

        StringTokenizer valueTokenizer = new StringTokenizer(br.readLine(), " ");
        br.close();

        Map<Long, Long> map = new LinkedHashMap<>();
        Map<Long, List<Long>> countMap = new TreeMap<>(Collections.reverseOrder());
        while (valueTokenizer.hasMoreTokens()) {
            long value = Long.parseLong(valueTokenizer.nextToken());
            map.putIfAbsent(value, 0L);
            map.computeIfPresent(value, (k, v) -> v + 1);
        }

        for (Map.Entry<Long, Long> entry : map.entrySet()) {
            countMap.putIfAbsent(entry.getValue(), new ArrayList<>());
            countMap.computeIfPresent(entry.getValue(), (k, v) -> {
                v.add(entry.getKey());
                return v;
            });
        }

        List<String> result = new ArrayList<>();
        for (Map.Entry<Long, List<Long>> entry : countMap.entrySet()) {
            for (Long value : entry.getValue()) {
                for (int i = 0; i < entry.getKey(); i++) {
                    result.add(String.valueOf(value));
                }
            }
        }
        bw.write(String.join(" ", result));
        bw.flush();
        bw.close();
    }
}
