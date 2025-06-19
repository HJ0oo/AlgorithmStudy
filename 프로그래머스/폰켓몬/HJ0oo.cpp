/*
[문제] 폰켓몬
[작성자] HJ0oo
[접근방식] set을 활용하여 중복 제거
[시간복잡도] O(n)
[공간복잡도] O(n)
[작성일] 2025-06-19
[문제링크] https://school.programmers.co.kr/learn/courses/30/lessons/1845
*/

#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set <int> pokemon_type; // 중복 제거하여 폰켓몬의 종류를 담을 set
    for (int pok_num : nums){
        pokemon_type.insert(pok_num);
    }
    
    return min(pokemon_type.size(), nums.size()/2); // 'N/2개를 고를 때 가장 많은 종류를 선택'해야하는 상황이므로 전체 종류의 개수와 N/2 중 작은 값을 반환함.
}