/*
[문제] k번째수
[작성자] whaleegg
[풀이시간] 
[접근방식] 
[시간복잡도] 
[작성일] 2025-06-17
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i) {
		// commands[i][0] : 시작 인덱스, commands[i][1] : 끝 인덱스, commands[i][2] : 찾을 k번째 수
		// 주의: commands[i] 내부 값들은 1-indexed이므로, 0-indexed로 변환
        int start = commands[i][0] - 1, end = commands[i][1], find = commands[i][2] - 1;

        // 벡터에서 부분 벡터 자르는 방법
        // : 새로운 벡터를 만들면서 초기화를 할 때, 복사할 벡터의 시작주소를 기준으로 시작지점과 끝 지점을 지정한다.
        vector<int> sub_array(array.begin() + start, array.begin() + end);

        sort(sub_array.begin(), sub_array.end());

        answer.push_back(sub_array[find]);

    }
    return answer;
}
