#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return (a + b > b + a);
}

string solution(vector<int> numbers) {
    vector<string> str_numbers{};
    for (int i = 0; i < numbers.size(); ++i) {
        // (string)number�� Ʋ�� ����. �⺻ �ڷ���, ������ Ÿ�԰� ����
        str_numbers.push_back(to_string(numbers[i]));
    }

    // sort(str_numbers.begin(), str_numbers.end(), [](string a, string b) {return a+b > b+a;});
    sort(str_numbers.begin(), str_numbers.end(), compare);

    // answer ����� ���� ������ ������������ �տ��� �Ǵ�
    if (str_numbers[0] == "0") return "0";

    string answer = "";
    for (string S : str_numbers) {
        answer += S;
    }

    // �־��� ��� ���� 0�� ��츦 �������� ����Ѵٸ�?
    // answer[0]�� char Ÿ��, "0"�� C-��Ÿ�� ���ڿ� ���ͷ� (��Ȯ���� const char* Ÿ��)�̹Ƿ� ���� ���� �� ����
    // return (answer[0] == '0') ? "0" : answer;
    return answer;
}