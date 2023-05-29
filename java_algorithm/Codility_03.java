package java_algorithm;

import java.util.StringTokenizer;

public class Codility_03 {

    public int count = 0;
    public int[][] seats = new int[50][10];
    public int[][] direction = {{1, 2, 3, 4}, {3, 4, 5, 6}, {5, 6, 7, 8}}; // B C D E

    public void setReservation(String s) {
        StringTokenizer st = new StringTokenizer(s, " ");
        while (st.hasMoreTokens()) {
            String reservation = st.nextToken();
            int length = reservation.length();
            int y = Integer.parseInt(reservation.substring(0, length - 1));
            int x = reservation.substring(length - 1, length).toCharArray()[0] - 'A';
            seats[y][x] = 1;
        }
    }

    public void checkPossible(int y) {
        for (int[] nx : direction) {
            boolean isPossible = true;
            for (int k : nx) {
                if (seats[y][k] == 1) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                for (int i : nx) seats[y][i] = 1;
                count++;
            }
        }
    }

    public int solution(int N, String s) {
        setReservation(s);
        for (int i = 1; i <= N; i++) {
            checkPossible(i);
        }
        return count;
    }

    public static void main(String[] args) {
        Codility_03 solution = new Codility_03();
        solution.solution(2, "1A 2F 1C");
    }
}
