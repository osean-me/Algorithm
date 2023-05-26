//
// Created by SeongHeon Sim on 2023/03/27.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

string s;
int result['z' + 1];

int main() {
  cin >> s;

  for (char c: s) {
    result[c]++;
  }

  for (int i = 'a'; i <= 'z'; i++) {
    cout << result[i] << " ";
  }

  return 0;
}
