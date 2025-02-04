from itertools import combinations


if __name__ == '__main__':
    result = []

    while True:
        _result = []
        in_list = list(map(int, input().strip().split()))

        if len(in_list) == 1:
            break
        
        k, s = in_list[0], in_list[1:]
        
        for pair in list(combinations(s, 6)):
            _result.append(pair)
        result.append(_result)
        # print()

    for s in result:
        for _s in s:
            print(*_s)
        print()
        