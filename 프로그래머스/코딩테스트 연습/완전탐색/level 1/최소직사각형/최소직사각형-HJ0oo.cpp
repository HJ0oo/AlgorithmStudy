#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<vector<int>> asc_pair;
    int w_max = -1;
    int h_max = -1;
    for (vector<int> size : sizes){
        if (size[0] < size[1]) { // h,w라고 가정
            h_max = max(h_max,size[0]);
            w_max = max(w_max,size[1]);
        }
        else { // 원래대로 w,h
            w_max = max(w_max,size[0]);
            h_max = max(h_max,size[1]);
        }
    }

    return w_max * h_max;
}