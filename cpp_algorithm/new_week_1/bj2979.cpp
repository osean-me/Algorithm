#include <bits/stdc++.h>

using namespace std;

int main() {
    // 주차된 트럭 수 별 시간당 이용금액
    int prices[4] = {};
    cin >> prices[1] >> prices[2] >> prices[3];

    // 주차장 이용시간
    int timeTable[101] = {};
    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            timeTable[j]++;
        }
    }

    int totalPrice = 0;
    for (int count : timeTable) totalPrice += (prices[count] * count);
    cout << totalPrice;

    return 0;
}