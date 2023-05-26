//
// Created by SeongHeon Sim on 2023/04/10.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> split(string input, string delimeter) {
    long long pos = 0;
    string token = "";
    vector<string> result;

    while ((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    result.push_back(input);
    return result;
}

vector<string> input(int n) {
    vector<string> result;
    for (int i = 0; i < n; i++) {
        string input = "";
        getline(cin, input);
        result.push_back(input);
    }
    return result;
}

map<string, int> createMap(vector<string> dictionary) {
    map<string, int> result;
    for (int i = 0; i < dictionary.size(); i++) {
        result[dictionary[i]] = i + 1;
    }
    return result;
}

int main() {
    // 포켓몬 수, 문제수 입력
    string nm = "";
    getline(cin, nm);
    vector<string> result = split(nm, " ");
    // Index To Name
    vector<string> indexToName = input(stoi(result[0]));
    // Name To Index
    map<string, int> nameToIndex = createMap(indexToName);
    // 문제의 포켓몬
    vector<string> pokemons = input(stoi(result[1]));
    for (string pokemon: pokemons) {
        // nameToIndex 의 값이 0 이면 이름 출력 아니면 인덱스 출력
        if (nameToIndex[pokemon] == 0) cout << indexToName[stoi(pokemon) - 1] << "\n";
        else cout << nameToIndex[pokemon] << "\n";
    }
}
