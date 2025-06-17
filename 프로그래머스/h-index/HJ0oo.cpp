/*
[문제] h-index
[작성자] HJ0oo
[풀이시간] 
[접근방식] 정렬 후 값과 index와 비교
[시간복잡도] nlogn - sort()함수
[작성일] 2025-06-17
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();
}