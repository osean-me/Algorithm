//
// Created by SeongHeon Sim on 2023/03/29.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int playerCnt;
string str, nameToCount;
vector<string> players, collection;

void add(vector<string> v) {
  for (int j = 0; j < v.size() - 1; j++) {
    if (v[j][0] != v[j + 1][0]) {
      return;
    }
  }
  char lastName = v[0][0];
  if (nameToCount.find(lastName) == string::npos) {
    nameToCount += lastName;
  }
}

void comb(int i, vector<string> v) {
  if (v.size() == 5) {
    add(v);
    return;
  }

  for (int j = i + 1; j < playerCnt; j++) {
    v.push_back(players[j]);
    comb(j, v);
    v.pop_back();
  }
}

int main() {
  cin >> playerCnt;
  for (int i = 0; i < playerCnt; i++) {
    getline(cin, str);
    players.push_back(str);
  }
  cout << "\n";
  sort(players.begin(), players.end());
  comb(-1, collection);
  if (nameToCount.length() == 0) {
    cout << "PREDAJA";
    return 0;
  }
  cout << nameToCount << "\n";
}
