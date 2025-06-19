/*
접근1 - 정렬
접근2 - trie
접근3 - 해시맵
*/

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std; //

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end()); // 앞에 있는 값이 prefix임을 보장하도록 - 이 문제의 경우 prefix가 나오면 바로 false 반환으로 종료되므로 보장됨.
    int n = phone_book.size();
    for (int i=1; i<n; i++){
        if (phone_book[i].substr(0,phone_book[i-1].size()) == phone_book[i-1]) {
            return false;
        } 
    }
    return true;
}