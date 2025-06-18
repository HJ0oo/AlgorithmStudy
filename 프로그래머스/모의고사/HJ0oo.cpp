/*
[문제] 모의고사
[작성자] HJ0oo
[접근방식] %로 배열 내에서 반복순회
[시간복잡도] O(n)
[공간복잡도] O(1) : result벡터 크기 고정(굳이 벡터로 할 이유 없었을듯), answer벡터도 최대 3명임.
[작성일] 2025-06-18
[문제링크] https://school.programmers.co.kr/learn/courses/30/lessons/42840
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    int student1[5] = {1, 2, 3, 4, 5};
    int student2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<pair<int,int>> result = {
        {1,0},
        {2,0},
        {3,0},
    };
    
    for (int i=0; i<answers.size(); i++){
        if(answers[i] == student1[i%5]){result[0].second++;}
        if(answers[i] == student2[i%8]){result[1].second++;}
        if(answers[i] == student3[i%10]){result[2].second++;}
    }
    
    int max_value = max({result[0].second,result[1].second,result[2].second}); // 3개 이상의 값에서 max를 쓰고 싶다면 {a,b,c...} 로 묶어서 넣기
    
    vector<int> answer;
    for (int i = 0; i<result.size();i++){
        if ( max_value == result[i].second) {
        answer.push_back(result[i].first);
        }
    }

    return answer;
}