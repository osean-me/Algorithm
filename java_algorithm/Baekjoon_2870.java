package java_algorithm;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Baekjoon_2870 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<BigInteger> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            char[] input = br.readLine().toCharArray();
            StringBuilder sb = new StringBuilder();
            for (int k = 0; k < input.length; k++) {
                char c = input[k];
                if ('a' <= c && c <= 'z') {
                    if (k - 1 > -1 && ('0' <= input[k - 1] && input[k - 1] <= '9')) sb.append(",");
                    continue;
                }

                sb.append(input[k]);
            }
            if (sb.toString().length() > 0) {
                for (String number : sb.toString().split(",")) {
                    String tmp = number;
                    while (number.charAt(0) == '0' && tmp.charAt(0) == '0' && tmp.length() > 1) {
                        tmp = tmp.substring(1);
                    }
                    result.add(new BigInteger(tmp));
                }
            }
        }
        br.close();

        result.sort(Comparator.naturalOrder());
        for (BigInteger number : result) {
            bw.write(number.toString());
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}
