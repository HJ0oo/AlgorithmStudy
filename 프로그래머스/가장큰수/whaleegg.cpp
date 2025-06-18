/*
[문제] 가장큰수
[작성자] whaleegg
[풀이시간] 
[접근방식] 문자열로 변환 후, 두 문자열을 이어붙였을 때 더 큰 값을 가지는 순서로 정렬
[시간복잡도] O(n log n) (n은 numbers.size(), 정렬 n log n)
[공간복잡도] O(n) (문자열 벡터 str_numbers를 저장하기 위한 공간)
[문제링크] https://programmers.co.kr/learn/courses/30/lessons/42746
[작성일] 2025-06-17
*/

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
        //(string)number은 틀린 문법. 기본 자료형, 포인터 타입간 가능
        str_numbers.push_back(to_string(numbers[i]));
    }

    //sort(str_numbers.begin(), str_numbers.end(), [](string a, string b) {return a+b > b+a;});
    sort(str_numbers.begin(), str_numbers.end(), compare);

    //answer 만들기 전에 빠르게 빠져나가도록 앞에서 판단
    if (str_numbers[0] == "0") return "0";

    string answer = "";
    for (string S : str_numbers) {
        answer += S;
    }

    //주어진 모든 수가 0인 경우를 마지막에 고려한다면?
    //answer[0]는 char 타입, "0"은 C-스타일 문자열 리터럴 (정확히는 const char* 타입)이므로 직접 비교할 수 없음
    //return (answer[0] == '0') ? "0" : answer;
    return answer;
}