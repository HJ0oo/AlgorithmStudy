/*
[문제] k번째수
[작성자] HJ0oo
[풀이시간] 
[접근방식] 부분 벡터 생성, 부분 벡터 정렬, index 접근 반환
[시간복잡도] O(m * n log n) ; m개의 명령어, n개 원소
[공간복잡도] O(m+n)
[작성일] 2025-06-17
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int>command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];

        // 부분 벡터 추출 (i-1 ~ j-1)
        vector<int>partial = {};
        for (int q=i-1;q<=j-1;q++){ // O(n)
            partial.push_back(array[q]);
        }

        // 부분 배열 정렬 (오름차순) - O(n log n)
        sort(partial.begin(),partial.end());

        // k번째 원소를 결과에 추가 O(1)
        answer.push_back(partial[k-1]);
    }
    return answer;
}