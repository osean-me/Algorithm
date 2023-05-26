//
// Created by SeongHeon Sim on 2023/03/30.
//
#include <bits/stdc++.h>
using namespace std;

int playerCnt;
int cnt[26];
bool fail = true;

int main() {
  cin >> playerCnt;
  for (int i = 0; i < playerCnt; i++) {
    string input;
    cin >> input;
    cnt[input[0] - 'a']++;
  }
  for (int i = 0; i <= ('z' - 'a'); i++) {
    if (cnt[i] > 4) {
      string result;
      result = (char) 'a' + i;
      cout << result;
      fail = false;
    }
  }
  if (fail) cout << "PREDAJA";
}
