/*
[문제] 전화번호목록
[작성자] HJ0oo
[접근방식] 접두사 관계
        * 접근 1 - 정렬
        * 접근 2 - 해시맵
        * 접근 3 - trie (추후 구현 예정)
            공통 접두사(prefix)가 많은 문자열을 효율적으로 저장,검색하기 위한 트리 기반 자료구조
            단어 사전, 자동완성, 전화번호 접두사 문제 활용
[시간복잡도] 
[공간복잡도] 
[작성일] 2025-06-19
[문제링크] https://school.programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

    /* 접근 1 - 정렬 */
    sort(phone_book.begin(),phone_book.end());  // 앞에 있는 값이 prefix임을 보장하도록 sort
    int n = phone_book.size();                  // 이 문제의 경우 prefix가 나오면 바로 false 반환으로 종료되므로
    for (int i=1; i<n; i++){                    // 119 1191 1192 인접하지 않은 접두사 관계(119, 1192)를 고려할 필요가 없어서 가능한 접근.
        if (phone_book[i].substr(0,phone_book[i-1].size()) == phone_book[i-1]) {
            return false;
        } 
    }
    return true;


    /* 접근 2 - 해시맵 */
    set<string>prefix;
    for (string phone_num : phone_book) {   // 모든 원소를 일단 접두사 목록에 삽입
        prefix.insert(phone_num);    
    }
    
    int n = phone_book.size();
    string temp;
    for (int i=0; i<n; i++){
        // substr을 쓰지 않은 이유 - 매번 substr을 호출 시 시간복잡도가 커질 것을 고려.
        temp = "";  // 앞에서부터 하나씩 잘라가며 '해당 자른 부분이 접두사인지 = 접두사 목록에 있는지' 판별
        for (int j=0; j<phone_book[i].size()-1; j++){ // 본인은 제외해야하므로, -1을 해줘야 함
            temp += phone_book[i][j];
            if (prefix.find(temp) != prefix.end()) {
                return false;
            }
        }
    }
    return true;

    /* 접근 3 - trie (추후 구현 예정) */
}