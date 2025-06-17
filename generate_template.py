import os
from datetime import date

# 루트 디렉토리 경로 설정
base_dir = os.path.dirname(os.path.abspath(__file__))


username_map = {
    "1" : "HJ0oo",
    "2" : "whaleegg",

    "HJ0oo" : "HJ0oo",
    "whaleegg" : "whaleegg",
}

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
        print("    (Session 1 기준: '백준', '프로그래머스' 지원)")
        print("    - 1. BOJ (백준)")
        print("    - 2. Programmers (프로그래머스)")
        user_input = input("    : ").strip().lower().replace(" ", "")

        if user_input in platform_map:
            return platform_map[user_input]
        else:
            print("❌ 유효하지 않은 입력입니다. 다시 시도해주세요.")

def get_valid_problem_name(platform) :
    platform_dir = os.path.join(base_dir, platform)
    # 기존 문제 목록 읽기 (폴더 기준)
    existing_problems = []
    if os.path.exists(platform_dir):
        existing_problems = [d for d in os.listdir(platform_dir)
                             if os.path.isdir(os.path.join(platform_dir, d))]
    
    while True:
        print("\n☑️  문제를 선택하거나 새로 입력하세요")

        # 기존 문제 목록이 있으면 보여주기
        if existing_problems:
            print("    ✅ 기존 문제 목록:")
            print("      0. 새 문제 입력")
            for idx, name in enumerate(existing_problems, start=1):
                print(f"      {idx}. {name}")
            selection = input("    : ").strip()

            if selection == "0":
                pass  # 새로 입력으로 넘어감
            elif selection.isdigit() and 1 <= int(selection) <= len(existing_problems):
                return existing_problems[int(selection)-1]
            else:
                print("❌ 잘못된 번호입니다. 다시 선택하세요.")
                continue

        # 새 문제 이름 입력
        example = "1932-정수삼각형" if platform == "백준" else "가장큰수"
        user_input = input(f"    - 새 문제 입력 예시: {example}\n    : ").strip().replace(" ", "")
        if user_input:
            return user_input
        else:
            print("❌ 유효하지 않은 입력입니다. 다시 시도해주세요.")


def get_valid_username() :
    while True:
        print("\n☑️  이름(github ID)을 입력하세요(숫자 또는 직접 입력)")
        for key,value in username_map.items() :
            if key.isdigit():
                print(f"    - {key}. {value}")
        user_input = input("    : ")
        if user_input in username_map:
            return username_map[user_input]
        else:
            print("❌ 유효하지 않은 입력입니다. 다시 시도해주세요.")


def main():

    # 사용자 입력 받기
    platform = get_valid_platform()
    problem_name = get_valid_problem_name(platform)
    username = get_valid_username()

    # 오늘 날짜
    today = date.today().isoformat()

    # 디렉토리 경로 생성
    dir_path = os.path.join(base_dir, platform, problem_name) # 절대경로로 수정
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
    if os.path.exists(file_path):
        print(f"\n⚠️ 이미 존재하는 파일입니다. 생성하지 않았습니다: {file_path}")
    else:
        with open(file_path, "w", encoding="utf-8") as f:
            f.write(template)
        print(f"\n✅ 템플릿 생성 완료: {file_path}")

if __name__ == "__main__":
    main()
