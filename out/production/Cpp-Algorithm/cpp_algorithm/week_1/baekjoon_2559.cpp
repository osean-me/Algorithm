#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> split() {
    string input = "";
    getline(cin, input);
    string delimeter = " ";
    long long pos;
    string token;
    vector<int> result;
    while ((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(stoi(token));
        input.erase(0, pos + delimeter.length());
    }
    result.push_back(stoi(input));
    return result;
}

int main() {
    vector<int> condition = split();
    int total = condition[0];
    int cnt = condition[1];
    vector<int> days = split();
    int biggest = days[0];
    for (int i = 0; i <= (total - cnt); i++) {
        int sum = 0;
        for (int k = i; k < (i + cnt); k++) sum += days[k];
        if (biggest <= sum) biggest = sum;
        if (biggest == (100 * cnt)) continue;
    }
    cout << biggest;
}
/**
 * 문제점
 * 풀 수는 있으나 시간 초과를 고려하지 못한 아이디어
 * 시간복잡도 n*cnt 이나 소요되는 문제. 때문에 최대 길이 100,000 인 경우 시간초과 발생
 */
