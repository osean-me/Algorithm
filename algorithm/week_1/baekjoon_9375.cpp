//
// Created by SeongHeon Sim on 2023/04/12.
//
#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
string types[35] = {};
set<string> clothes[35] = {};

/**
 * 의상 및 의류 자르기
 * @return [0] : 의상, [1] : 의류
 */
vector<string> split() {
    string input = "";
    string delimeter = " ";
    getline(cin, input);
    long long pos = 0;
    string token = "";
    vector<string> result;
    while ((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    result.push_back(input);
    return result;
}

/**
 * 주어진 의상 및 의류 별 데이터 맵핑
 * @param types 의류 리스트
 * @param clothes 의류 인덱스 별 의상 리스트
 */
void getTypeToClothes() {
    cin >> cnt;
    map<string, int> typeMap = map<string, int>();
    for (int i = 0; i <= cnt; i++) {
        // 의상 / 종류 입력
        vector<string> clotheToType = split();
        string clothe = clotheToType[0];
        string type = clotheToType[1];
        if (clothe.length() > 0 && type.length() > 0) {
            if (typeMap[type] == 0) {
                typeMap[type] = i;
            }
            types[typeMap[type]] = type;
            set<string> clotheSet = clothes[typeMap[type]];
            clotheSet.insert(clothe);
            clothes[typeMap[type]] = clotheSet;
        }
    }
}

void recursive(int typeIndex) {
    if (typeIndex >= cnt) return;
    string type = types[typeIndex];
    for (string clothe: clothes[typeIndex]) {
        cout << "k : " << typeIndex << " / " << type << " : " << clothe << "\n";
        recursive(typeIndex + 1);
    }
    cout << "\n";
}

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        getTypeToClothes();
        int typeSize = sizeof(types) / sizeof(types[0]);
        recursive(1);
        // 초기화
        fill_n(types, typeSize, "");
        fill_n(clothes, typeSize, set<string>());
    }
}
