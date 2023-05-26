//
// Created by SeongHeon Sim on 2023/03/23.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void print(vector<string> target) {
  cout << "\n";

  for (string s: target) {
    cout << s << "\n";
  }
}

vector<string> split(string input, string delimiter) {
  vector<string> ret;
  long long pos;
  string token = "";

  while ((pos = input.find(delimiter)) != string::npos) {
    // 현재 문자열 처음부터 구분자까지 자른다.
    token = input.substr(0, pos);
    // 잘린 문자열을 vector 에 담는다.
    ret.push_back(token);
    // 현재 문자열에서 잘린 문자열만큼 지운다.
    input.erase(0, pos + delimiter.length());
  }
  // 마지막 구분자를 찾으면 반복문이 종료되는 그 뒤의 문자열은 바로 vector 에 담는다.
  ret.push_back(input);

  return ret;
}

int main() {
  string input = "00_11_22_";
  string delimiter = "_";
  vector<string> ret = split(input, delimiter);
  print(ret);
  return 0;
}
