## 예제로 이해하는 C++

### 입력 받은 문자열 그대로 출력하는 프로그램 만들기

```c++
#include <bits/stds++.h> // --- (1)
using namespace std; // --- (2)

string a; // --- (3)

int main() {
    cin >> a; // --- (4)
    cout << a << "\n"; // --- (5)
    return 0; // --- (6)
}
```

#### 코드 설명

1. `bits/stdc++.h` 는 C++ 의 모든 표준 라이브러리를 포함하고 있는 헤더 파일이다. 이를 `include` 라는 명령어를 통해 해당 프로그램에 포함하도록 한다.
2. `std` 라는 네임 스페이스를 사용 한다는 의미이다.
    1. 네임 스페이스는 많은 라이브러리를 호출해 사용할 경우 변수명이 중복되는 경우가 발생할 수 있는데, 이를 방지하기 위해서 변수명의 범위를 설정한 것이다.
    2. `cin` 이나 `cout` 등을 사용할 때, 기존에는 std 라는 네임 스페이스를 통해 `std:cin` 와 같이 호출하도록 했으나, `std` 를 기본 네임 스페이스로 설정해
       단독으로 `cid`, `cout` 등을 호출할 수 있게 한다.
3. 문자열 변수 `a` 선언.
    1. `lvalue` 는 다시 사용할 수 있는 변수
    2. `rvalue` 는 한 번 사용된 후 재사용 할 수 없는 변수
4. 사용자의 입력을 받아 `a` 변수에 할당 하도록 한다.
5. `a` 변수에 할당된 값을 출력한다.
6. `main` 함수를 종료 하도록 한다. 즉, 실행된 프로세스를 정상적으로 마무리 한다는 의미를 가진다.
    1. C++ 은 cpp 파일 하나 당 하나의 `main` 함수를 만들 수 있다.

---

### `typedef`

> `typedef` 란 타입의 이름을 별칭으로 정의하고, 실제 타입이름을 설정한 별칭으로 사용할 수 있게끔 하는
> 예약어다.

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int i; // --- (1)

int main() {
    i a = 1; // --- (2)
    cin >> a;
    cout << a << "\n";
    return 0;
}
```

#### 코드 설명

1. `int` 의 타입을 `i` 라는 별칭으로 재정의한다.
2. `main` 함수 내부에서 `int` 타입의 변수 `a` 를 `i a = 1;` 로 선언 및 초기화를 진행한다.

---

### `define`

> 상수 및 메크로 등을 정의할 수 있는 예약어이다.

```c++
#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159
#define loop(x, n) for(int x = 0; x < n; x++)

int main() {
    // 원주기율 출력
    count << PI << "\n";
    
    // 정의된 루프 함수 호출
    int sum = 0;
    loop(i, 10) {
        sum += i;
    }
    
    // 결과 출력
    cout << sum << "\n";
    
    return 0;
}
```