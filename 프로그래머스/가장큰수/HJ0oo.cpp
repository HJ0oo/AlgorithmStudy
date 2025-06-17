/*
[문제] 가장큰수
[작성자] HJ0oo
[풀이시간] 40분

[접근방식]
    접근1) 단순 문자열 내림차순 정렬 (사전순 정렬 사용)
        - 숫자를 문자열로 변환 후, 내림차순 정렬
        - 반례: [3, 34, 30] → 올바른 답은 "34330"이지만 내림차순 정렬 시 "34303"
        - 접두사 관계도 이용할 수 없음(3은 34,30 모두에 대해 접두사임)
    접근2) 두 문자열을 합쳐서 비교(두 문자열 길이가 달라도 상관없음)

[반례]
    - [0, 0, 0] → "000" 아닌 "0" 출력 필요

[팁]
2자릿수 이상 number를 string으로 변환 : to_string() 함수 사용
stoi(answer)에서 abort 발생 : answer에 int 범위를 넘어가지 않는지 체크
내림차순 rbegin() rend() 사용 :
    sort(st_numbers.begin(),st_numbers.end(),greater<string>());
    sort(st_numbers.rbegin(),st_numbers.rend());

[시간복잡도] O(N log N)
[공간복잡도] O(N)

[작성일] 2025-06-17
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string>st_numbers;
    for (int number : numbers){
        st_numbers.push_back(to_string(number));
    }
    
    sort(st_numbers.begin(), st_numbers.end(), [](string a, string b) {
        return a+b > b+a; // stoi(a+b)로 비교하지 말고 문자열 자체로 비교
    }); // 람다 함수를 통해 a와 b의 문자열을 합쳐서 비교
    
    
    string answer = "";
    for (string st_number : st_numbers){
        answer += st_number;
    }
    
    if (answer[0] == '0'){
        return "0";
    } else {
        return answer;    
    }
    
}