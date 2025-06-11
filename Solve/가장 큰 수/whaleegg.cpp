#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return (a + b > b + a);
}

string solution(vector<int> numbers) {
    vector<string> str_numbers{};
    for (int i = 0; i < numbers.size(); ++i) {
        // (string)number은 틀린 문법. 기본 자료형, 포인터 타입간 가능
        str_numbers.push_back(to_string(numbers[i]));
    }

    // sort(str_numbers.begin(), str_numbers.end(), [](string a, string b) {return a+b > b+a;});
    sort(str_numbers.begin(), str_numbers.end(), compare);

    // answer 만들기 전에 빠르게 빠져나가도록 앞에서 판단
    if (str_numbers[0] == "0") return "0";

    string answer = "";
    for (string S : str_numbers) {
        answer += S;
    }

    // 주어진 모든 수가 0인 경우를 마지막에 고려한다면?
    // answer[0]는 char 타입, "0"은 C-스타일 문자열 리터럴 (정확히는 const char* 타입)이므로 직접 비교할 수 없음
    // return (answer[0] == '0') ? "0" : answer;
    return answer;
}