import os
from datetime import date

def main():
    # 사용자 입력 받기
    platform = input("문제 출처 (예: boj, programmers): ").strip().lower()
    problem_name = input("문제 이름 (예: 1932-정수삼각형): ").strip().replace(" ", "_")
    username = input("이름 (영문): ").strip().lower()

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
[문제] 
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
