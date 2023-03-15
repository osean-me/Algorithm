## 예제로 이해하는 C++

### 입력과 출력

```c++
#include <bits/stdc++.h>
using namespace std;

int a;
double b;
char c;
string s;
long long l;

int main() {
  cin >> a; // --- (1)
  cout << a << "\n"; // --- (2)
  
  scanf("%d %lf %c %s %ld", &a, &b, &c, &s, &l); // --- (3)
  printf("%d %lf %c %s %ld", a, b, c, s.c_str(), l); // --- (4)
  return 0;
}
```

#### 코드 설명

1. `cin`
    - 사용자의 입력을 받고, 값을 지정한 변수에 할당하도록 한다.
2. `cout`
    - 변수 혹은 문자열을 출력한다.
3. `scanf()`
    - `scanf()` 는 첫 번째 매개변수로 받는 형식을 지정해서 입력을 받는다.
    - 한 줄에 모든 입력을 받도록 한다.
        - `%d` : int
        - `%lf` : double
        - `%c` : char
        - `%s` : string
        - `%ld` : long long
4. `printf()`
    - `printf()` 는 형식을 지정해 출력해야 할 때 유용하게 사용할 수 있다.

### 한글을 입력하면 어떻게 될까?

- 한글은 영어와 달리 한 글자에 3 byte 이다. 때문에 string 타입의 변수에
  하나의 한글 문자를 할당하고 해당 변수의 0 번째 메모리를 확인하면
  입력한 값이 아닌 특이한 문자가 나오게 된다.

```c++
#include <bits/stdc++.h>
using namespace std;

typedef string s;

int main() {

  s example = "심";
  cout << example[0] << "\n";

  example = "a";
  cout << example[0] << "\n";

  return 0;
}
```

### `string` 함수 정리

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
  string sentence = "love is ";
  sentence += "pain";
  
  sentence.pop_back(); // --- (1)
  
  cout << sentence
       << " : "
       << sentence.size() // --- (2)
       << "\n";
  
  cout << char(*sentence.begin()) // --- (3)
       << "\n";
  
  cout << char(*(sentence.end() - 1)) // --- (4)
       << "\n";
  
  sentence.insert(0, "test "); // --- (5)
  cout << sentence
       << " : "
       << sentence.size()
       << "\n";
  
  sentence.erase(0, 5); // --- (6)
  cout << sentence
       << " : "
       << sentence.size()
       << "\n";
  
  auto it = sentence.find("love"); // --- (7)
  
  if (it != string::npos) {
    cout << "포함되어 있다." << "\n";
  }
  cout << it << "\n";
  cout << string::npos << "\n"; // --- (8)
  cout << sentence.substr(5, 2) << "\n"; // --- (9)

  return 0;
}
```

#### 코드 설명

1. `pop_back()` : 문자열의 마지막 문자를 제거한다.
2. `size()` : 문자열의 길이를 리턴한다. O(1) 의 시간 복잡도를 가진다.
3. `begin()` : 문자열 첫 번째 요소를 가리키는 이터레이터를 반환한다.
4. `end()` : 문자열 마지막 요소 그 다음을 가리키는 이터레이터를 반환한다.
5. `insert()` : 특정 인덱스에 지정한 문자열을 추가한다. O(n) 의 시간 복잡도를 가진다.
6. `eraser()` : 특정 인덱스부터 지정된 크기만큼 문자열을 지운다. O(n) 의 시간 복잡도를 가진다.
7. `find()` : 해당 문자열에서 인자로 들어간 문자열을 찾아 해당 위치를 반환하며, 찾지 못하는 경우 string::npos 를 반환한다. O(n) 시간 복잡도를 가진다.
8. `string::npos` : size_t 타입의 최대값을 의미한다. 이는 OS 마다 상이하다.
9. `substr()` : 특정 위치부터 지정된 크기만큼 문자열을 추출한다. O(n) 의 시간 복잡도를 가진다.
