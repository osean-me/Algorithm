#include <bits/stdc++.h>

using namespace std;

int n, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    vector<int> numbers(n + 1, 0);
    vector<vector<int>> sizeToNums(n + 1, vector<int>());
    map<int, int> numToSize, visitied;

    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
        numToSize[numbers[i]]++;
    }

    for (int number : numbers) {
        int size = numToSize[number];
        sizeToNums[size].push_back(number);
    }

    for (int i = sizeToNums.size() - 1; 0 <= i; i--) {
        if (!sizeToNums[i].size()) continue;

        for (int number : sizeToNums[i]) {
            if (visitied[number]) continue;
            visitied[number] = 1;
            int size = numToSize[number];
            for (int j = 0; j < size; j++) cout << number << " ";
        }
    }
}