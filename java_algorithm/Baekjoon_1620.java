package java_algorithm;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Baekjoon_1620 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static List<String> pokemons = new ArrayList<>();
    private static List<String> result = new ArrayList<>();

    private static void inputPokemons(int count) throws IOException {
        for (int i = 0; i < count; i++) {
            pokemons.add(br.readLine());
        }
    }

    private static void solution() throws IOException {
        String[] input = br.readLine().split(" ");
        int pokemonCount = Integer.parseInt(input[0]);
        int t = Integer.parseInt(input[1]);
        inputPokemons(pokemonCount);
    }


    public static void main(String[] args) throws IOException {
        solution();
    }
}
