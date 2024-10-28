# 퇴사 후, 파이썬으로 빠르게 준비해보자
## 현대그룹 softeer 언어 지원 현황
- C11
- C++17
- Java 11
- Python 3.6 *
- Node.js 12.18.3

## Python 3.6은 어떤 특징이 있나?
- format string 지원
    ```
        name = 'jaemu'
        print(f'hi, {name}!')
    ```
- 언더스코어 숫자
    ```
        billion = 1_000_000_000
        print(billion)
    ```

## Python 3.6 on Apple silicon
    ```
    ## create empty environment
    conda create -n py36

    ## activate
    conda activate py36

    ## use x86_64 architecture channel(s)
    conda config --env --set subdir osx-64

    ## install python, numpy, etc. (add more packages here...)
    conda install python=3.6
    ```

    출처: https://stackoverflow.com/questions/70205633/cannot-install-python-3-7-on-osx-arm64