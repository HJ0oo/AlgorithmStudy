#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map <string,int> clothes_map;
    
    for(auto cloth : clothes){
        clothes_map[cloth[1]]++;
    }
    
    int answer = 1;
    for (auto one_of_map : clothes_map){
        answer *= (one_of_map.second+1);
    }
    return answer-1;
}