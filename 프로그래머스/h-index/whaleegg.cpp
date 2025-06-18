/*
[문제] h-index
[작성자] whaleegg
[풀이시간] 
[접근방식] 완전탐색
[시간복잡도] O(n^2) = O(1000^2) = O(10^6)
[공간복잡도] O(n) = O(1000) = O(10^3)
[문제링크] https://programmers.co.kr/learn/courses/30/lessons/42747
[작성일] 2025-06-17
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int papers = citations.size();
    for (int h = papers; h >= 0; --h) {
		// 지금은 h를 바꿀때마다 일일히 순회하며 확인한다. => 시간복잡도 O(n^2) (n = 1000)
		// 만약 정렬을 해놓으면 한번 순회에 갯수(=인덱스+1)와 각 자리 인용수를 비교해 (갯수 >= 인용수)로 h-index를 구할 수 있다. => 시간복잡도 O(n log n + n) = O(n log n)
		// 이진 탐색을 이용하면 더 빠르게 해결할 수 있다. => 시간복잡도 O(n log n + log n) = O(n log n)
        int count = 0;
        for (int c : citations) {
            if (c >= h) ++count;
        }

        // 처음에 count 값을 return해 일부 케이스에서 오답
        if (count >= h) return h;
        answer = h;
    }
    return answer;
}