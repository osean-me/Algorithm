//
// Created by SeongHeon Sim on 2023/03/15.
// string 의 함수에 대해 학습하자.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  string sentence = "love is ";
  sentence += "pain";

  // pop_back() > 문자열의 마지막 문자를 제거한다.
  sentence.pop_back();

  // size() > 문자열의 길이를 리턴한다. O(1) 의 시간 복잡도를 가진다.
  // love is pai : 11
  cout << sentence
       << " : "
       << sentence.size()
       << "\n";

  // begin() > 문자열 첫 번째 요소를 가리키는 이터레이터를 반환한다.
  // l
  cout << char(*sentence.begin())
       << "\n";

  // end() > 문자열 마지막 요소 그 다음을 가리키는 이터레이터를 반환한다.
  // i
  cout << char(*(sentence.end() - 1))
       << "\n";

  // insert() > 특정 인덱스에 지정한 문자열을 추가한다. O(n) 의 시간 복잡도를 가진다.
  // test love is pai : 16
  sentence.insert(0, "test ");
  cout << sentence
       << " : "
       << sentence.size()
       << "\n";

  // eraser() > 특정 인덱스부터 지정된 크기만큼 문자열을 지운다. O(n) 의 시간 복잡도를 가진다.
  // love is pai : 11
  sentence.erase(0, 5);
  cout << sentence
       << " : "
       << sentence.size()
       << "\n";

  // find() > 해당 문자열에서 인자로 들어간 문자열을 찾아 해당 위치를 반환하며, 찾지 못하는 경우 string::npos 를 반환한다.
  // O(n) 시간 복잡도를 가진다.
  auto it = sentence.find("love");

  // 인자 문자열이 포함되어 있는 경우
  if (it != string::npos) {
    cout << "포함되어 있다." << "\n";
  }
  cout << it << "\n";

  // string::npos 란? > size_t 타입의 최대값을 의미한다. 이는 OS 마다 상이하다.
  cout << string::npos << "\n";

  // substr() > 특정 위치부터 지정된 크기만큼 문자열을 추출한다. O(n) 의 시간 복잡도를 가진다.
  cout << sentence.substr(5, 2) << "\n";

  return 0;
}
