import os
from datetime import date

username_map = [
    "HJ0oo",
    "whaleegg",
]

def get_valid_platform():
    platform_map = {
        "1": "백준",
        "2": "프로그래머스",
        "boj": "백준",
        "baekjoon": "백준",
        "백준": "백준",
        "programmers": "프로그래머스",
        "프로그래머스": "프로그래머스",
        "program": "프로그래머스",
    }
    while True:
        print("\n☑️  문제 출처를 선택하세요(숫자 또는 직접 입력)")
        print("   - (Session 1 기준: '백준', '프로그래머스' 지원)")
        print("    1. BOJ (백준)")
        print("    2. Programmers (프로그래머스)")
        user_input = input("    : ").strip().lower().replace(" ", "")

        if user_input in platform_map:
            return platform_map[user_input]
        else:
            print("❌ 유효하지 않은 입력입니다. 다시 시도해주세요.")

def get_valid_problem_name(platform) :
    while True:
        print("\n☑️  문제 이름을 입력하세요")
        if (platform == "백준") :
            user_input = input("   - (백준 입력 예시: 1932-정수삼각형)\n    : ").strip().lower().replace(" ", "")
            return user_input
        elif (platform == "프로그래머스") :
            user_input = input("   - (프로그래머스 입력 예시: 가장큰수)\n    : ").strip().lower().replace(" ", "")
            return user_input
        else :
            print("❌ 유효하지 않은 입력입니다. 다시 시도해주세요.")

def get_valid_username() :
    while True:
        user_input = input("\n☑️  이름(github ID)을 입력하세요\n    : ")
        if user_input in username_map:
            return user_input
        else:
            print("❌ 유효하지 않은 입력입니다. 다시 시도해주세요.")
            for user in username_map :
                print(f"{user} ")


def main():
    # 사용자 입력 받기
    platform = get_valid_platform()
    problem_name = get_valid_problem_name(platform)
    username = get_valid_username()

    # 오늘 날짜
    today = date.today().isoformat()

    # 디렉토리 경로 생성
    dir_path = os.path.join(platform, problem_name)
    os.makedirs(dir_path, exist_ok=True)

    # 파일 경로
    file_path = os.path.join(dir_path, f"{username}.cpp")

    # 템플릿 내용
    template = f"""\
/*
[문제] {problem_name}
[작성자] {username}
[풀이시간] 
[접근방식] 
[시간복잡도] 
[작성일] {today}
*/

#include <iostream>
using namespace std;

int main() {{
    // TODO: 여기에 코드 작성
    return 0;
}}
"""

    # 파일 생성
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(template)

    print(f"\n✅ 템플릿 생성 완료: {file_path}")

if __name__ == "__main__":
    main()
