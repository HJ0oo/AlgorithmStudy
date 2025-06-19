/*
[문제] 완주하지못한선수
[작성자] whaleegg
[접근방식] 참가자 목록 순회, 해시맵에 저장하여 각 참가자의 출현 횟수를 기록
            -> 완주자 목록 순회, 해시맵에서 해당 참가자의 출현 횟수를 감소
            -> 해시맵(참가자) 순회, 출현 횟수가 0이 아닌 참가자를 찾아 반환
[시간복잡도] O(n) (n = 최대 참가자 수 100,000명)
[공간복잡도] O(n) (해시맵 사용)
[링크] https://programmers.co.kr/learn/courses/30/lessons/42576
[작성일] 2025-06-18
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> race = {};

    for (string p : participant) {
        race[p] += 1;
    }

    for (string p : completion) {
        race[p] -= 1;
    }

    for (string p : participant) {
        if (race[p] != 0) {
            return p;
        }
    }

    return answer;
}