//
// Created by SeongHeon Sim on 2023/04/05.
//
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
    int next = 0;
    for (int i = 0; i < cnt; i++) next += days[i];
    int biggest = next;
    for (int i = 1; i <= total - cnt; i++) {
        next = next - days[i - 1] + days[i + cnt - 1];
        if (biggest < next) biggest = next;
    }
    cout << biggest;
}
/**
 * 시간 복잡도 n-cnt
 * 이중 for문을 수행하지 않고 주어진 길이에서 cnt+1 만큼만 순회하면 된다.
 * 첫 번째 연속된 일자의 합을 구하고, 그 다음부터 이전에 더한 값을 빼고 다음 값을 더해주면 된다.
 * 첫 번째 아이디어와 비슷한 규칙을 가지지만 어떻게 구현하느냐에 따라 시간 복잡도가 달라진다.
 */
