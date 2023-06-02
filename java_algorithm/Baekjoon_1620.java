package java_algorithm;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Baekjoon_1620 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static List<String> pokemons = new ArrayList<>();
    private static Map<String, String> pokemonMap = new HashMap<>();

    private static void inputPokemons(int count) throws IOException {
        for (int i = 0; i < count; i++) {
            String pokemon = br.readLine();
            pokemons.add(pokemon);
            pokemonMap.put(pokemon, String.valueOf(i + 1));
        }
    }

    private static void findPokemons(int count) throws IOException {
        for (int i = 0; i < count; i++) {
            String input = br.readLine();
            String result = pokemonMap.get(input);
            if (result == null) {
                result = pokemons.get(Integer.parseInt(input) - 1);
            }
            bw.write(result);
            bw.newLine();
        }
    }

    private static void solution() throws IOException {
        String[] input = br.readLine().split(" ");
        int pokemonCount = Integer.parseInt(input[0]);
        int t = Integer.parseInt(input[1]);
        inputPokemons(pokemonCount);
        findPokemons(t);
    }


    public static void main(String[] args) throws IOException {
        solution();
        br.close();
        bw.close();
    }
}
