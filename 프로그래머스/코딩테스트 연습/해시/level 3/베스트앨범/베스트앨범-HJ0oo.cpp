#include <string>
#include <vector>
// #include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}

bool compare_cc(vector<int> a,vector<int> b){
    if (a[0] != b[0] ){
        return a[0] > b[0];
    }
    else {
        return a[1] < b[1];
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string,int> genres_cnt;
    // map <string,int> genres_cnt; // sort할수없음, 다만 key를 기준으로 자동 오름차순 정렬
    unordered_map <string,vector<vector<int>>> genres_map;
    
    
    for (int i=0; i<plays.size(); i++){
        genres_cnt[genres[i]] += plays[i];
        genres_map[genres[i]].push_back({plays[i],i});
    }
    
    vector<pair<string, int>> v(genres_cnt.begin(), genres_cnt.end()); // 
    sort(v.begin(),v.end(),compare);
    
    
    for (auto genre : v) {
        // cout << genre.first << " " << genre.second << endl;
        
        // genres_map[genre.first]는 vector<vector<int>> 형태 -  {[500,0], [600,1], [150,0], [600,1], [500,0]}
        // sort(genres_map[genre.first].rbegin(),genres_map[genre.first].rend());
        sort(genres_map[genre.first].begin(),genres_map[genre.first].end(),compare_cc);
        if (genres_map[genre.first].size() >= 2) {
            answer.push_back(genres_map[genre.first][0][1]);
            answer.push_back(genres_map[genre.first][1][1]);
        }
        else{
            answer.push_back(genres_map[genre.first][0][1]); //0개 일수도 없고, 0개라면 안돌아갈거니까
        }
        
        // for (auto a : genres_map[genre.first]){ // a는 vector 형태 -  [500,0]
        //     cout << a[0] << endl;
        // }
    }
    

    return answer;
}