#include <bits/stdc++.h>

using namespace std;

int main() {
    int prices[4] = {};
    cin >> prices[1] >> prices[2] >> prices[3];

    int table[101] = {};
    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int i = start; i < end; i++) table[i]++;
    }

    int result = 0;
    for (int i : table) result += (prices[i] * i);
    cout << result;
}