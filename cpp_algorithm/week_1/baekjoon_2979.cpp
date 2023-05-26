#include <bits/stdc++.h>

using namespace std;

int timeCount[101], feeTable[3], parkingTime[3][2], amount;

int main() {
  // 요금 테이블 입력
  scanf("%d %d %d", &feeTable[0], &feeTable[1], &feeTable[2]);

  for (int i = 0; i < 3; i++) {
    // 주차시간 입력
    scanf("%d %d", &parkingTime[i][0], &parkingTime[i][1]);
    // 주차시간만큼 기록
    for (int t = parkingTime[i][0]; t < parkingTime[i][1]; t++) timeCount[t]++;
  }

  // 기록된 주차시간만큼 요금 계산
  for (int i = 1; i < 101; i++)
    amount += (feeTable[timeCount[i] - 1] * timeCount[i]);
  printf("%d", amount);
}
