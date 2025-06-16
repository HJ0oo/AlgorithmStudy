# 🚀 Algorithm Study (알고리즘 스터디)

## 👀 스터디 소개 및 목표
📌 **일관성 있는 문제 풀이 구조** :
문제별 폴더 구조와 템플릿을 통해 코드 작성 방식을 통일하고, 브랜치를 나누어 작업합니다.<br>
📌 **코딩 규칙 적용을 통한 코드 품질 향상** : 
MISRA 코딩 규칙 일부를 적용하여, 명확한 변수·함수명, 중괄호 사용 등 기본적인 컨벤션을 지킵니다.<br>
📌 **템플릿 자동 생성 도구 사용** : 
반복적인 파일 생성과 주석 작성을 자동화하여 작업 효율성과 형식의 일관성을 높입니다.<br>
📌 **풀이 공유 및 코드 리뷰** :
서로의 코드를 리뷰하며 다양한 풀이를 이해하고 개선점을 나눕니다.<br>


***
## 프로젝트 폴더 구조 (Directory Structure)
문제 출처를 기준으로 폴더를 나누며, 한 문제에 대해 여러 명이 각자 `.cpp` 파일을 작성합니다.

```bash
├── 📁 /boj/
│   ├── /1932-정수삼각형/
│   │   ├── HJ0oo.cpp
│   │   ├── whaleegg.cpp
│   │   └── ...
│   └── /1000-A+B/
│       └── ...
├── 📁 /programmers/
│   └── /가장 큰 수/
│       └── ...
├── generate_template.py
└── README.md
```
***
## 템플릿 자동 생성 도구
문제 구조 및 주석 형식을 자동으로 생성해주는 Python 스크립트를 사용합니다.
### 🚀 사용 방법
#### 1. Python 설치 필요
#### 2. 루트 폴더에서 실행:

```bash
$ python generate_template.py
```
#### 3. 프롬프트에 따라 입력:
```bash
문제 출처 (예: boj, programmers): boj
문제 이름 (예: 1932-정수삼각형): 1932-정수삼각형
이름 (영문): HJ0oo
```
#### 4. 템플릿이 자동 생성됩니다:
```bash
📁 /boj/1932-정수삼각형/
    └── HJ0oo.cpp
```
```cpp
/*
[문제] 
[작성자] HJ0oo
[풀이시간] 
[접근방식] 
[시간복잡도] 
[작성일] 2025-06-12
*/

#include <iostream>
using namespace std;

int main() {
    // TODO: 여기에 코드 작성
    return 0;
}
```
<!-- #### 🧪 향후 자동화 도입 예정
VSCode snippet 연동 (자동 템플릿 입력)
Git hook (브랜치 생성 시 자동 템플릿 배치)
문제 플랫폼 API 연동 자동 분류
PR 템플릿 자동 적용 (.github/PULL_REQUEST_TEMPLATE.md)
코드 스타일 검사 도구 (clang-format, cpplint) 연동 -->
***

## 📌 핵심 원칙 (Ground Rules)

프로젝트의 일관성을 유지하기 위해 아래 규칙을 반드시 지켜주세요.


### 1. 커밋 메시지 컨벤션
커밋 메시지는 문제 출처와 문제 이름을 포함합니다.
> 형식: [문제출처] 문제이름 <br>
> 예시: <br>
> [백준] 1000번 A+B<br>
> [프로그래머스] 가장 큰 수<br>

### 2. 코딩 규칙 (MISRA 일부 반영)

* 변수/함수명은 명확하게 작성
* 매직 넘버 금지 → `const`, `constexpr` 사용
* 하나의 함수는 하나의 기능만 담당
* 조건문과 반복문은 항상 `{}` 사용
* 함수가 길어질 경우 적절히 분리
* 파일 상단 주석 템플릿 필수(파일 생성 시 자동 삽입됨)

### 3. 문제 해결 주기
* **주 최소 3문제** 이상 푸는 것을 목표로 합니다.
* 문제 해결 후 *반드시 Pull Request(PR)* 를 생성하여 코드 리뷰를 요청합니다.

***

## 💻 협업 절차 (Workflow)
스터디는 다음 절차에 따라 진행됩니다.

1.  **저장소 복제 (Clone)**: 로컬에 개인 작업 공간을 만듭니다.
    ```bash
    git clone [https://github.com/HJ0oo/AlgorithmStudy.git](https://github.com/HJ0oo/AlgorithmStudy.git)
    cd AlgorithmStudy
    ```

2.  **브랜치 생성 (Create a Branch)**: 문제 풀이를 시작하기 전, 기능 브랜치를 생성합니다.
    * **브랜치 이름**: `아이디`
    * **예시**: `git checkout -b HJ0oo`

3.  **문제 풀이 및 커밋 (Solve & Commit)**: 문제를 해결하고 정해진 양식에 따라 커밋합니다.
    ```bash
    # 코드 작성 후
    git add .
    git commit -m "[프로그래머스] 가장 큰 수"
    ```

4.  **푸시 (Push)**: 원격 저장소에 브랜치를 푸시합니다.
    ```bash
    git push origin HJ0oo
    ```

5.  **풀 리퀘스트 생성 (Create a Pull Request)**:
    * GitHub 레포지토리에서 `Pull Request` 버튼을 클릭합니다.
    * `base: main` ← `compare: 내-브랜치` 로 설정하고 PR을 생성합니다.

    * 다른 팀원에게 코드 리뷰를 요청합니다.

6.  **코드 리뷰 및 병합 (Review & Merge)**:
    * 리뷰어는 코드에 대한 피드백을 남깁니다.
    * **최소 1명 이상의 승인(Approve)**을 받으면 PR을 `main` 브랜치에 병합할 수 있습니다.
    * 병합 후에는 사용했던 브랜치를 삭제하여 저장소를 깔끔하게 유지합니다.

7.  **동기화 (Sync)**: 새로운 문제 풀이를 시작하기 전, `main` 브랜치의 최신 변경사항을 로컬에 반영합니다.
    ```bash
    git checkout main
    git pull origin main
    ```

***

## 📚 문제 풀이 순서

스터디는 아래 순서대로 문제 유형을 정복해 나갑니다.

### Session 1. 프로그래머스 코딩테스트 고득점 Kit
1.  **정렬**
2.  **해시**
3.  **완전탐색, DFS/BFS**
4.  **스택/큐, 힙**
5.  **탐욕법(Greedy), 다이나믹 프로그래밍(DP)**
6.  **이분탐색, 그래프**

***

## 👨‍👩‍👧‍👦 참여 인원 (Collaborators)
<table>
  <tr>
    <td align="center"><a href="https://github.com/HJ0oo"><img src="https://avatars.githubusercontent.com/HJ0oo" width="100px;" alt=""/><br /><sub><b>
임현주</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/whaleegg"><img src="https://avatars.githubusercontent.com/whaleegg" width="100px;" alt=""/><br /><sub><b>
유의민</b></sub></a><br /></td>
    <!-- <td align="center"><a href="https://github.com/{팀원github아이디}"><img src="https://avatars.githubusercontent.com/{팀원github아이디}" width="100px;" alt=""/><br /><sub><b>
{팀원이름}</b></sub></a><br /></td>
  </tr>
</table>