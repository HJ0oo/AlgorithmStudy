/*
[문제] 완주하지못한선수
[작성자] HJ0oo
[접근방식]  
    순서가 필요없으므로 map이 아닌 unordered_map 활용
    participant를 돌며 해당 이름 cnt값++하고, completion를 돌며 cnt값--
    마지막에 cnt 돌며 0이 아닌 값을 가진 요소 반환

[팁]
    1.  cnt[one_of_participant]++;
        one_of_participant라는 키가 없어도 자동으로 { one_of_participant, 0 }이 생성됨.
        ⚠️ 주의: 이 동작은 값 타입의 기본 생성자가 존재할 때만 가능하다

            if (cnt.find(one_of_participant) == cnt.end()) {     
                cnt.insert({one_of_participant,1});
            }
            else {
                cnt[one_of_participant]++;
            }

        이와 같이 find해서 없을 때를 따로 따져보지 않아도 됨.
        다만, 예상치 못한 값이 생성될 수 있으므로 이번 문제와 같이 보장되는 경우만 사용하는 것이 좋을 듯함.

    2.  set,map 에서는 .find(key) 없을 때 end() 반환
        if (cnt.find(one_of_participant) == cnt.end()) { ... }


[시간복잡도] O(n)
    unordered_map의 접근/삽입 : 평균 O(1) 
    
    cnt[one_of_participant]++
        키 존재 여부 검사 : 평균 O(1), 최악 O(n)(해시 충돌)
        새 요소 생성 (필요 시) : 평균 O(1), 최악 O(n) (리해시 또는 충돌)
        값 접근 : O(1)
        값 수정 : O(1)

[공간복잡도] O(n) 해시 저장
[문제링크] https://programmers.co.kr/learn/courses/30/lessons/42576
[작성일] 2025-06-18
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> cnt;  // 내부적으로는 알아서 pair<const Key, Value> 구조로 저장되기 때문에, 따로 pair를 만들 필요없음

    for (string one_of_participant : participant) { // O(n) : n번 * O(1)
        cnt[one_of_participant]++;                              
    }
    
    for (string one_of_completion : completion) {   // O(n) : n번 * O(1)
        cnt[one_of_completion]--;
    }
    
    for (pair<string,int> one_of_cnt : cnt){        // O(n) : n번 * O(1)
        if (one_of_cnt.second != 0) {   // value값이 0이 아닌 값이 단 하나일 것이므로, 바로 반환.
            return one_of_cnt.first;    // .first(), .second() 가 아니라 .first, .second임
        }   
    }
}