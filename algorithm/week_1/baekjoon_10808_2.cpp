//
// Created by SeongHeon Sim on 2023/03/27.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

char s[100];
int ret[150];

int main() {
  // a = 97
  scanf("%s", &s);
  for (int i = 0; i < strlen(s); i++) ret[s[i] - 97]++;
  for (int i = 0; i <= 'z' - 'a'; i++) printf("%d ", ret[i]);
  return 0;
}
